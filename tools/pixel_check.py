"""Pixel check: compare our understanding of the room data with the original game, room by room.

For each room a scratch copy of LAZARUS.EXE is patched to (1) start a new game in that room and (2) freeze
the world on its first frame: Object_Think, TileAnim_Step, Hero_Think and Hero_Draw return at once, so
objects stay at their path's first position/frame, animated tiles at their start frame and the hero is not
drawn. DOSBox runs it under Xvfb, the title menu is confirmed with Enter, and DOSBox's own screenshot
(Ctrl+F5, exact VGA pixels) is compared with an independent render of the same first frame from the data
(room layers, tile animations, objects with the constructor's visibility rules and BobFindFrame).

    python3 tools/pixel_check.py original/ OUT_DIR [--rooms 7,0 0,0 ...] [--workers 3]

Needs dosbox (0.74), Xvfb, xdotool and Pillow. Writes OUT_DIR/report.json, OUT_DIR/capture_C_R.png
and, for rooms that differ, OUT_DIR/diff_C_R.png (expected | original | differences in red).
Never touches the files in the game directory; the original EXE is only read.
"""
import argparse
import glob
import json
import os
import queue
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402
from le_loader import LEFile  # noqa: E402
from reference_sim import PathObject, World, object_present  # noqa: E402

START_COL_IMM, START_ROW_IMM = 0x2A2A2, 0x2A2AC        # mov [g_roomCol],7 / mov [g_roomRow],0 immediates
FREEZE = {0x23F4C: "Object_Think", 0x216A0: "TileAnim_Step", 0x24A24: "Hero_Think", 0x23A98: "Hero_Draw"}
PLAYFIELD = (0, 6)                                      # play-field origin on the 320x240 screen
W, H = L.ROOM_PX_W, L.ROOM_PX_H


def patch_exe(src, dst, col, row):
    le = LEFile(src)
    data = bytearray(open(src, "rb").read())
    for addr, expect in ((START_COL_IMM, 7), (START_ROW_IMM, 0)):
        fo = le.file_offset(addr)
        if data[fo:fo + 4] != expect.to_bytes(4, "little"):
            raise ValueError(f"unexpected bytes at {addr:#x} - not the known LAZARUS.EXE")
    data[le.file_offset(START_COL_IMM)] = col
    data[le.file_offset(START_ROW_IMM)] = row
    for addr in FREEZE:
        fo = le.file_offset(addr)
        if data[fo] != 0x53:                            # push ebx
            raise ValueError(f"unexpected prologue at {addr:#x}")
        data[fo] = 0xC3                                 # ret
    open(dst, "wb").write(data)


# ---------------------------------------------------------------------------
# expected first frame
# ---------------------------------------------------------------------------
def expected_room(world, seq_table, col, row, pl, bg):
    room = world.rooms[(col, row)]
    buf = bytearray(W * H)

    def blit(px, w, h, x0, y0, transparent=True):
        for y in range(h):
            yy = y0 + y
            if 0 <= yy < H:
                for x in range(w):
                    xx, c = x0 + x, px[y * w + x]
                    if 0 <= xx < W and (c or not transparent):
                        buf[yy * W + xx] = c

    for ty in range(L.BG_H):
        for tx in range(L.BG_W):
            blit(bg[room.background[ty][tx]], L.BG_TW, L.BG_TH, tx * L.BG_TW, ty * L.BG_TH, False)
    for ty in range(L.MAP_H):
        for tx in range(L.MAP_W):
            t = room.tiles[ty][tx]
            if 0 < t < len(pl):
                blit(pl[t], L.PL_TW, L.PL_TH, tx * L.PL_TW, ty * L.PL_TH)

    def anims(foreground):
        for (c, r, fg, seq, start) in room.tile_anims:
            if fg == foreground:
                base, _ = seq_table[seq]
                t = seq_flat[base + start] if base + start < len(seq_flat) else 0
                if 0 < t < len(pl):
                    blit(pl[t], L.PL_TW, L.PL_TH, c * L.PL_TW, r * L.PL_TH)

    seq_flat = seq_table["flat"]
    anims(False)
    frames, _ = world.bobs
    for o in room.objects:
        if object_present(o):
            p = PathObject(world, o)
            f = frames[p.frame]
            if f is not None:
                blit(f.pixels, f.width, f.height, p.x >> 16, p.y >> 16)
    anims(True)
    return bytes(buf)


def seq_table_of(exe_path):
    """The tile-animation sequences laid out as in memory (header word + entries + -1 per sequence), so a
    start offset past a sequence's end reads into the next one exactly like the game does."""
    seqs = L.load_tile_anim_sequences(exe_path)
    flat, table = [], {}
    for i, s in enumerate(seqs):
        flat.append(None)                               # header word
        table[i] = (len(flat), len(s))
        flat.extend(s)
        flat.append(-1)
    table["flat"] = [0 if v in (None, -1) else v for v in flat]
    return table


# ---------------------------------------------------------------------------
# DOSBox
# ---------------------------------------------------------------------------
def run_dosbox(game_dir, work, col, row, display, settle):
    c = os.path.join(work, "c")
    cap = os.path.join(work, "cap")
    shutil.rmtree(work, ignore_errors=True)
    os.makedirs(c)
    os.makedirs(cap)
    for f in os.listdir(game_dir):
        if f.upper().startswith("DATA") or f.upper() == "DOS4GW.EXE":
            os.symlink(os.path.abspath(os.path.join(game_dir, f)), os.path.join(c, f))
    patch_exe(os.path.join(game_dir, "LAZARUS.EXE"), os.path.join(c, "LAZARUS.EXE"), col, row)
    conf = os.path.join(work, "dosbox.conf")
    open(conf, "w").write(f"""[sdl]
fullscreen=false
output=surface
[dosbox]
machine=svga_s3
memsize=16
captures={cap}
[cpu]
core=dynamic
cycles=max
[mixer]
nosound=true
[sblaster]
sbtype=none
[gus]
gus=false
[autoexec]
mount c {c}
c:
LAZARUS.EXE /I /N
""")
    env = dict(os.environ, DISPLAY=display)
    xvfb = subprocess.Popen(["Xvfb", display, "-screen", "0", "800x600x24"], stdout=subprocess.DEVNULL,
                            stderr=subprocess.DEVNULL)
    time.sleep(1)
    box = subprocess.Popen(["dosbox", "-conf", conf], env=env, stdout=subprocess.DEVNULL,
                           stderr=subprocess.DEVNULL)
    try:
        win = None
        for _ in range(40):
            time.sleep(0.5)
            r = subprocess.run(["xdotool", "search", "--class", "dosbox"], env=env, capture_output=True,
                               text=True)
            if r.stdout.strip():
                win = r.stdout.split()[0]
                break
        if not win:
            raise RuntimeError("no DOSBox window")

        def key(k):
            subprocess.run(["xdotool", "key", "--window", win, k], env=env)

        time.sleep(settle)                              # DOS4GW start-up, logo, title menu
        key("Return")
        time.sleep(3)                                   # fade in of the first frame
        key("ctrl+F5")
        for _ in range(20):
            time.sleep(0.5)
            shots = sorted(glob.glob(os.path.join(cap, "*.png")))
            if shots:
                time.sleep(0.5)
                return Image.open(shots[-1]).convert("RGB")
        raise RuntimeError("no screenshot")
    finally:
        box.kill()
        xvfb.kill()
        box.wait()
        xvfb.wait()


def compare(expected, pal, shot, col, row, out):
    exp = Image.new("P", (W, H))
    exp.putpalette([v for c in pal for v in c])
    exp.putdata(expected)
    exp = exp.convert("RGB")
    got = shot.crop((PLAYFIELD[0], PLAYFIELD[1], PLAYFIELD[0] + W, PLAYFIELD[1] + H))
    ep, gp = exp.load(), got.load()
    bad = []
    for y in range(H):
        for x in range(W):
            a, b = ep[x, y], gp[x, y]
            if max(abs(a[i] - b[i]) for i in range(3)) > 6:     # VGA 6-bit -> 8-bit rounding differs
                bad.append((x, y))
    got.save(os.path.join(out, f"capture_{col}_{row}.png"))
    if bad:
        d = Image.new("RGB", (W * 3 + 8, H), (40, 40, 40))
        d.paste(exp, (0, 0))
        d.paste(got, (W + 4, 0))
        m = got.copy().point(lambda v: v // 3)
        mp = m.load()
        for x, y in bad:
            mp[x, y] = (255, 0, 0)
        d.paste(m, (2 * W + 8, 0))
        d.save(os.path.join(out, f"diff_{col}_{row}.png"))
        xs, ys = [p[0] for p in bad], [p[1] for p in bad]
        return {"room": [col, row], "differing_pixels": len(bad),
                "bbox": [min(xs), min(ys), max(xs), max(ys)]}
    return {"room": [col, row], "differing_pixels": 0}


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game_dir")
    ap.add_argument("out_dir")
    ap.add_argument("--rooms", nargs="*", help="col,row ... (default: all 100)")
    ap.add_argument("--workers", type=int, default=3)
    ap.add_argument("--settle", type=float, default=6.0, help="seconds until the title menu is up")
    a = ap.parse_args()
    os.makedirs(a.out_dir, exist_ok=True)
    rooms = ([tuple(int(v) for v in r.split(",")) for r in a.rooms] if a.rooms
             else [(c, r) for r in range(10) for c in range(10)])
    world = World(a.game_dir)
    world.bobs = L.load_bobs(a.game_dir)
    pal = L.load_palette(a.game_dir)
    pl, bg = L.load_platform_tiles(a.game_dir), L.load_background_tiles(a.game_dir)
    seq_table = seq_table_of(os.path.join(a.game_dir, "LAZARUS.EXE"))
    work_root = os.path.join(a.out_dir, "work")

    slots = queue.Queue()
    for s in range(a.workers):
        slots.put(s)

    def one(job):
        slot = slots.get()
        try:
            return run_one(job, slot)
        finally:
            slots.put(slot)

    def run_one(job, slot):
        _, (col, row) = job
        err = ""
        for attempt in range(2):
            try:
                shot = run_dosbox(a.game_dir, os.path.join(work_root, str(slot)), col, row,
                                  f":{90 + slot}", a.settle + 3 * attempt)
                res = compare(expected_room(world, seq_table, col, row, pl, bg), pal, shot, col, row,
                              a.out_dir)
                print(f"room {col},{row}: {res['differing_pixels']} differing pixels", flush=True)
                return res
            except Exception as e:                      # retry once with a longer start-up wait
                err = str(e)
        print(f"room {col},{row}: FAILED ({err})", flush=True)
        return {"room": [col, row], "error": err}

    jobs = list(enumerate(rooms))
    with ThreadPoolExecutor(a.workers) as ex:
        results = list(ex.map(one, jobs, chunksize=1))
    shutil.rmtree(work_root, ignore_errors=True)
    json.dump({"note": "Play-field of the patched original (frozen first frame, no hero) vs. our render.",
               "rooms": results}, open(os.path.join(a.out_dir, "report.json"), "w"), indent=1)
    ok = sum(1 for r in results if r.get("differing_pixels") == 0)
    print(f"{ok}/{len(results)} rooms pixel-identical")


if __name__ == "__main__":
    main()
