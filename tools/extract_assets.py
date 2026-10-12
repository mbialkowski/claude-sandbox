#!/usr/bin/env python3
"""Export every Lazarus asset into modern formats.

    python3 tools/extract_assets.py <dir with LAZARUS.EXE + DATAxx.RES> <out dir>

Produces (under <out dir>):
    palettes/        DATAxx palettes as .png swatches and .json
    tiles/           platform_tiles.png, background_tiles.png (+ per-tile PNGs), hud.png,
                     tile_types.json (type + collision box per platform tile)
    sprites/         one PNG per BOB frame (sprites/frames/NNNN.png), group sheets,
                     sprites.json (groups, durations, hotspots/boxes)
    rooms/           room_C_R.png + room_C_R.json for all 100 rooms, world_map.png
    sounds/          sfx_NN.wav (54 effects), sounds.json
    music/           *.mod (ProTracker modules, playable with any tracker)
    pictures/        PCX stills converted to PNG
    animations/      FLC/FLI intro animations as numbered PNG frames
    font/            font glyph sheet + widths.json
    text/            messages.json (all 293 dialogue strings, UTF-8)
    gamedata/        weapons.json, items.json, scripts.json, tile_anims.json, misc.json

Requires Pillow.  The original game files are NOT part of this repository.
"""
import argparse
import json
import os
import shutil
import struct
import sys
import wave

from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import flc  # noqa: E402
import lazarus_data as L  # noqa: E402
from lazarus_exe import LazarusExe  # noqa: E402

PALETTES = {"DATA25.RES": "game", "DATA27.RES": "picture", "DATA16.RES": "alarm",
            "DATA28.RES": "menu", "DATA19.RES": "unused"}


def mkdir(*p):
    path = os.path.join(*p)
    os.makedirs(path, exist_ok=True)
    return path


def flat_pal(pal):
    return [c for rgb in pal for c in rgb]


def img_p(pixels, w, h, pal, transparent=None):
    im = Image.frombytes("P", (w, h), bytes(pixels))
    im.putpalette(flat_pal(pal))
    if transparent is not None:
        im.info["transparency"] = transparent
    return im


def sheet(tiles, w, h, cols, pal, gap=1, transparent=None):
    rows = (len(tiles) + cols - 1) // cols
    out = Image.new("P", (cols * (w + gap), rows * (h + gap)), 0)
    out.putpalette(flat_pal(pal))
    for i, t in enumerate(tiles):
        y, x = divmod(i, cols)
        out.paste(img_p(t, w, h, pal), (x * (w + gap), y * (h + gap)))
    if transparent is not None:
        out.info["transparency"] = transparent
    return out


def export_palettes(g, out):
    d = mkdir(out, "palettes")
    res = {}
    for f, name in PALETTES.items():
        pal = L.load_palette(g, f)
        res[name] = {"file": f, "colors": pal}
        im = Image.new("RGB", (16 * 16, 16 * 16))
        for i, c in enumerate(pal):
            y, x = divmod(i, 16)
            im.paste(c, (x * 16, y * 16, x * 16 + 16, y * 16 + 16))
        im.save(os.path.join(d, f"{name}.png"))
    json.dump(res, open(os.path.join(d, "palettes.json"), "w"))
    return L.load_palette(g, "DATA25.RES")


def export_tiles(g, out, pal):
    d = mkdir(out, "tiles")
    pl = L.load_platform_tiles(g)
    bg = L.load_background_tiles(g)
    sheet(pl, L.PL_TW, L.PL_TH, 28, pal, transparent=0).save(os.path.join(d, "platform_tiles.png"))
    sheet(bg, L.BG_TW, L.BG_TH, 12, pal).save(os.path.join(d, "background_tiles.png"))
    img_p(L.load_hud(g), 76, 240, pal).save(os.path.join(d, "hud.png"))
    pd = mkdir(d, "platform")
    for i, t in enumerate(pl):
        img_p(t, L.PL_TW, L.PL_TH, pal, transparent=0).save(os.path.join(pd, f"{i:03d}.png"))
    bd = mkdir(d, "background")
    for i, t in enumerate(bg):
        img_p(t, L.BG_TW, L.BG_TH, pal).save(os.path.join(bd, f"{i:03d}.png"))
    types = L.load_tile_types(g)
    boxes = L.load_tile_boxes(g)
    names = {4: "solid", 1: "harmful", 2: "passable"}
    json.dump([{"tile": i, "type": names.get(types[i], types[i]),
                "box": list(boxes[i]) if i < len(boxes) else None}
               for i in range(len(types))],
              open(os.path.join(d, "tile_types.json"), "w"), indent=0)
    return pl, bg


def export_sprites(g, out, pal):
    d = mkdir(out, "sprites")
    fd = mkdir(d, "frames")
    gd = mkdir(d, "groups")
    frames, groups = L.load_bobs(g)
    meta = {"frames": [], "groups": []}
    for f in frames:
        if f is None:
            continue
        img_p(f.pixels, f.width, f.height, pal, transparent=0).save(os.path.join(fd, f"{f.index:04d}.png"))
        meta["frames"].append({"index": f.index, "duration": f.duration, "width": f.width,
                               "height": f.height, "box": list(f.box)})
    for gi, idxs in enumerate(groups):
        meta["groups"].append({"group": gi, "frames": idxs})
        if not idxs:
            continue
        fr = [frames[i] for i in idxs]
        w = sum(f.width + 2 for f in fr)
        h = max(f.height for f in fr)
        im = Image.new("P", (w, h), 0)
        im.putpalette(flat_pal(pal))
        x = 0
        for f in fr:
            im.paste(img_p(f.pixels, f.width, f.height, pal), (x, 0))
            x += f.width + 2
        im.info["transparency"] = 0
        im.save(os.path.join(gd, f"group_{gi:03d}.png"))
    json.dump(meta, open(os.path.join(d, "sprites.json"), "w"))
    return frames, groups


def render_room(room, pl, bg, frames, groups, seqs, with_objects=True):
    W, H = L.ROOM_PX_W, L.ROOM_PX_H
    buf = bytearray(W * H)

    def blit(px, w, h, x0, y0, transparent=True):
        for y in range(h):
            yy = y0 + y
            if not 0 <= yy < H:
                continue
            for x in range(w):
                xx = x0 + x
                c = px[y * w + x]
                if 0 <= xx < W and (c or not transparent):
                    buf[yy * W + xx] = c

    for ty in range(L.BG_H):
        for tx in range(L.BG_W):
            blit(bg[room.background[ty][tx]], L.BG_TW, L.BG_TH, tx * L.BG_TW, ty * L.BG_TH, False)
    for ty in range(L.MAP_H):
        for tx in range(L.MAP_W):
            t = room.tiles[ty][tx]
            if t < len(pl):
                blit(pl[t], L.PL_TW, L.PL_TH, tx * L.PL_TW, ty * L.PL_TH)
    for (c, r, _fg, seq, start) in room.tile_anims:
        s = seqs[seq] if seq < len(seqs) else []
        if s:
            t = s[min(start, len(s) - 1)]
            if 0 < t < len(pl):
                blit(pl[t], L.PL_TW, L.PL_TH, c * L.PL_TW, r * L.PL_TH)
    if with_objects:
        for o in room.objects:
            if not o.steps or o.flags & 0x0008 or not o.flags & 0x0001:
                continue
            st = o.steps[0]
            if st.anim >= len(groups) or not groups[st.anim]:
                continue
            f = frames[groups[st.anim][0]]
            x, y = st.pos
            blit(f.pixels, f.width, f.height, x, y)
    return bytes(buf)


def export_rooms(g, out, pal, pl, bg, frames, groups, seqs):
    d = mkdir(out, "rooms")
    rooms = L.load_rooms(g)
    W, H = L.ROOM_PX_W, L.ROOM_PX_H
    world = Image.new("P", (10 * W, 10 * H), 0)
    world.putpalette(flat_pal(pal))
    for (col, row), room in sorted(rooms.items()):
        px = render_room(room, pl, bg, frames, groups, seqs)
        im = img_p(px, W, H, pal)
        im.save(os.path.join(d, f"room_{col}_{row}.png"))
        world.paste(im, (col * W, row * H))
        js = {
            "col": col, "row": row,
            "background": room.background, "tiles": room.tiles,
            "tile_anims": [{"col": c, "row": r, "foreground": fg, "sequence": s, "start": st}
                           for (c, r, fg, s, st) in room.tile_anims],
            "objects": [{
                "index": o.index, "header_hex": o.raw_header.hex(),
                "loop_start": o.loop_start, "end_mode": L.END_MODES.get(o.end_mode, o.end_mode),
                "interact": o.interact, "flags": o.flags, "flag_names": o.describe_flags(),
                "collision_class": o.collision_class, "hp": o.hp, "hp_max": o.hp_max,
                "activate_anim": o.activate_anim, "activate_sound": o.activate_sound,
                "target": o.target, "item": o.item,
                "steps": [{"x": s.x / 65536, "y": s.y / 65536, "vx": s.vx / 65536, "vy": s.vy / 65536,
                           "ax": s.ax / 65536, "ay": s.ay / 65536, "ticks": s.duration,
                           "anim": s.anim, "anim_flag": s.anim_flag, "anim_start": s.anim_start,
                           "hidden": s.hidden, "sound_cmd": s.sound_cmd, "sound": s.sound,
                           "trigger_object": s.trigger_object} for s in o.steps],
            } for o in room.objects],
        }
        json.dump(js, open(os.path.join(d, f"room_{col}_{row}.json"), "w"), indent=1)
    world.save(os.path.join(d, "world_map.png"))
    world.resize((10 * W // 2, 10 * H // 2)).save(os.path.join(d, "world_map_small.png"))


def export_sounds(g, out, exe):
    d = mkdir(out, "sounds")
    bank = open(os.path.join(g, "DATA41.RES"), "rb").read()
    table = exe.sounds()
    for s in table:
        pcm = bytes((b + 128) & 0xFF for b in bank[s["offset"]:s["offset"] + s["length"]])
        with wave.open(os.path.join(d, f"sfx_{s['id']:02d}.wav"), "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(1)
            w.setframerate(s["rate"])
            w.writeframes(pcm)
    json.dump(table, open(os.path.join(d, "sounds.json"), "w"), indent=1)


def export_music(g, out):
    d = mkdir(out, "music")
    shutil.copyfile(os.path.join(g, "DATA23.RES"), os.path.join(d, "DATA23_multifruit_juice.mod"))
    shutil.copyfile(os.path.join(g, "DATA39.RES"), os.path.join(d, "DATA39_recollection.mod"))


def export_pictures(g, out):
    d = mkdir(out, "pictures")
    for f in ["DATA20.RES", "DATA21.RES", "DATA22.RES", "DATA33.RES", "DATA34.RES",
              "DATA35.RES", "DATA36.RES", "DATA40.RES"]:
        Image.open(os.path.join(g, f)).save(os.path.join(d, f.replace(".RES", ".png")))


def export_animations(g, out):
    d = mkdir(out, "animations")
    for n in [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17]:
        name = f"DATA{n:02d}"
        ad = mkdir(d, name)
        data = open(os.path.join(g, name + ".RES"), "rb").read()
        for i, (px, pal, (w, h), _speed) in enumerate(flc.frames(data)):
            img_p(px, w, h, pal).save(os.path.join(ad, f"{i:03d}.png"))


def export_font(g, out, pal):
    d = mkdir(out, "font")
    raw = open(os.path.join(g, "DATA26.RES"), "rb").read()
    widths = list(raw[:0xE0])
    bw, h = raw[0xE0], raw[0xE1]
    gsz = 2 + bw * 4 * h
    glyphs = []
    for i in range(0xE0):
        g0 = 0xE0 + i * gsz
        glyphs.append(L.planar_to_linear(raw[g0 + 2:g0 + gsz], bw * 4, h))
    # pixel 1 = glyph body (drawn in the {c:NNN} colour), 2 = dark outline/shadow
    gray = [(0, 0, 0), (255, 255, 255), (96, 96, 96)] + [(255, 0, 255)] * 253
    sheet(glyphs, bw * 4, h, 16, gray, gap=2, transparent=0).save(os.path.join(d, "glyphs.png"))
    json.dump({"first_char": 32, "cell": [bw * 4, h], "widths": widths,
               "pixel_values": {"0": "transparent", "1": "body", "2": "outline"},
               "note": "glyph i = character 0x20+i, Mazovia code page"},
              open(os.path.join(d, "font.json"), "w"), indent=1)


def export_gamedata(out, exe):
    d = mkdir(out, "gamedata")
    td = mkdir(out, "text")
    json.dump(exe.messages(), open(os.path.join(td, "messages.json"), "w", encoding="utf-8"),
              ensure_ascii=False, indent=1)
    json.dump(exe.weapons(), open(os.path.join(d, "weapons.json"), "w"), indent=1)
    json.dump(exe.items(), open(os.path.join(d, "items.json"), "w"), indent=1)
    json.dump(exe.scripts(), open(os.path.join(d, "scripts.json"), "w"), indent=1)
    json.dump(exe.tile_anim_sequences(), open(os.path.join(d, "tile_anims.json"), "w"))
    json.dump({"sock_spots": exe.sock_spots(), "hurt_sounds": exe.hurt_sounds()},
              open(os.path.join(d, "misc.json"), "w"), indent=1)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game_dir")
    ap.add_argument("out_dir")
    ap.add_argument("--skip-animations", action="store_true", help="FLC decoding is the slow part")
    a = ap.parse_args()
    g, out = a.game_dir, a.out_dir
    exe = LazarusExe(os.path.join(g, "LAZARUS.EXE"))
    steps = []
    pal = export_palettes(g, out); steps.append("palettes")
    pl, bg = export_tiles(g, out, pal); steps.append("tiles")
    frames, groups = export_sprites(g, out, pal); steps.append("sprites")
    seqs = exe.tile_anim_sequences()
    export_rooms(g, out, pal, pl, bg, frames, groups, seqs); steps.append("rooms")
    export_sounds(g, out, exe); steps.append("sounds")
    export_music(g, out); steps.append("music")
    export_pictures(g, out); steps.append("pictures")
    export_font(g, out, pal); steps.append("font")
    export_gamedata(out, exe); steps.append("gamedata/text")
    if not a.skip_animations:
        export_animations(g, out); steps.append("animations")
    print("exported:", ", ".join(steps), "->", out)


if __name__ == "__main__":
    main()
