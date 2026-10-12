#!/usr/bin/env python3
"""Build the data bundle of the Godot remake (remake/data/) from the original game files.

    python3 tools/build_remake_data.py original/ remake/data/

The remake renders in palette indices (like the VGA original) and maps them to colours in a shader, so all
images are written as *index images*: RGBA PNGs whose red channel is the palette index and whose alpha is 0
for transparent pixels.  Files (all generated - change this tool, never the output):

    game.json            frame descriptors + atlas rectangles, tile types/boxes, tile-animation sequences,
                         all 100 rooms with every object record (raw header fields and raw 16.16 path
                         steps), weapons, sounds, items, palettes, font metrics, new-game tables
    text_pl.json         the 293 messages (UTF-8, {x:}{y:}{c:} tags kept)
    text_en.json         the English translation (tools/translations/en.json)
    scripts.json         assets/gamedata/script_logic.json (quest/dialogue handlers as data)
    golden_traces.json   assets/gamedata/golden_traces.json (physics test vectors)
    sprites.png          every sprite frame (index image), rectangles in game.json "frames"
    sprites_mask.png     the same atlas as a white silhouette (hit flashes)
    tiles_platform.png   560 platform tiles 16x19, 20 per row (index image, colour 0 transparent)
    tiles_background.png 120 background tiles 32x38, 10 per row (index image, opaque)
    hud_panel.png        the 76x240 HUD side panel (index image)
    font_body.png, font_outline.png   glyph masks (white), 16 x 14 cells of 12x10
    sounds.bin           54 effects as signed 8-bit PCM, offsets/rates/loops in game.json "sounds"
    music_title.ogg, music_intro.ogg  the two modules rendered to Ogg (from assets/music/)
    pic_*.png            full-screen pictures (game over, joke ending, credits scroller) as RGB PNGs
    anim_DATAxx_NNN.png  the credits (DATA04) and winning-ending (DATA17) animation frames as index images,
                         their palettes in game.json "animations"

Needs Pillow and the assets/ folder produced by tools/extract_assets.py (for the music and pictures).
"""
import json
import os
import shutil
import struct
import sys

from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402
import reference_sim as R  # noqa: E402
from lazarus_exe import LazarusExe  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ATLAS_W = 1024


def index_image(pixels, w, h, opaque=False):
    """Palette indices -> RGBA (R = index, A = 0 for index 0 unless opaque)."""
    out = bytearray(w * h * 4)
    for i, p in enumerate(pixels):
        out[i * 4] = p
        out[i * 4 + 3] = 255 if (p or opaque) else 0
    return Image.frombytes("RGBA", (w, h), bytes(out))


def mask_image(pixels, w, h):
    out = bytearray(w * h * 4)
    for i, p in enumerate(pixels):
        if p:
            out[i * 4:i * 4 + 4] = b"\xff\xff\xff\xff"
    return Image.frombytes("RGBA", (w, h), bytes(out))


def save_png(im, *path):
    im.save(os.path.join(*path), optimize=True)


def pack_frames(frames):
    """Shelf packer: frames sorted by height; returns {index: (x, y)} and the atlas height."""
    order = sorted((f for f in frames if f), key=lambda f: (-f.height, -f.width))
    pos, x, y, shelf = {}, 0, 0, 0
    for f in order:
        if x + f.width > ATLAS_W:
            x, y, shelf = 0, y + shelf + 1, 0
        pos[f.index] = (x, y)
        x += f.width + 1
        shelf = max(shelf, f.height)
    return pos, y + shelf


def build_sprites(game_dir, out):
    frames, _ = L.load_bobs(game_dir)
    pos, height = pack_frames(frames)
    atlas = Image.new("RGBA", (ATLAS_W, height), (0, 0, 0, 0))
    mask = Image.new("RGBA", (ATLAS_W, height), (0, 0, 0, 0))
    rects = []
    for f in frames:
        if f is None:
            rects.append(None)
            continue
        x, y = pos[f.index]
        atlas.paste(index_image(f.pixels, f.width, f.height), (x, y))
        mask.paste(mask_image(f.pixels, f.width, f.height), (x, y))
        rects.append([x, y, f.width, f.height])
    save_png(atlas, out, "sprites.png")
    save_png(mask, out, "sprites_mask.png")
    return rects


def build_tiles(game_dir, out):
    pl = L.load_platform_tiles(game_dir)
    im = Image.new("RGBA", (20 * L.PL_TW, (len(pl) + 19) // 20 * L.PL_TH), (0, 0, 0, 0))
    for i, px in enumerate(pl):
        im.paste(index_image(px, L.PL_TW, L.PL_TH), ((i % 20) * L.PL_TW, (i // 20) * L.PL_TH))
    save_png(im, out, "tiles_platform.png")
    bg = L.load_background_tiles(game_dir)
    im = Image.new("RGBA", (10 * L.BG_TW, (len(bg) + 9) // 10 * L.BG_TH), (0, 0, 0, 0))
    for i, px in enumerate(bg):
        im.paste(index_image(px, L.BG_TW, L.BG_TH, opaque=True), ((i % 10) * L.BG_TW, (i // 10) * L.BG_TH))
    save_png(im, out, "tiles_background.png")
    save_png(index_image(L.load_hud(game_dir), 76, 240, opaque=True), out, "hud_panel.png")
    return len(pl), len(bg)


def build_font(game_dir, out):
    raw = open(os.path.join(game_dir, "DATA26.RES"), "rb").read()
    widths = list(raw[:0xE0])
    bw, h = raw[0xE0], raw[0xE1]
    cw = bw * 4
    gsz = 2 + cw * h
    body = Image.new("RGBA", (16 * cw, 14 * h), (0, 0, 0, 0))
    outline = Image.new("RGBA", (16 * cw, 14 * h), (0, 0, 0, 0))
    for i in range(0xE0):
        px = L.planar_to_linear(raw[0xE0 + i * gsz + 2:0xE0 + (i + 1) * gsz], cw, h)
        gy, gx = divmod(i, 16)
        for y in range(h):
            for x in range(cw):
                p = px[y * cw + x]
                if p:
                    (body if p == 1 else outline).putpixel((gx * cw + x, gy * h + y), (255, 255, 255, 255))
    save_png(body, out, "font_body.png")
    save_png(outline, out, "font_outline.png")
    # Text_Draw: x += width[c] + spacing; space advances 4 + spacing; '\n' returns to the line start, y += h.
    import mazovia
    glyphs = {}
    for i, wdt in enumerate(widths):
        code = 0x20 + i
        if wdt == 10 and code != 0x20:          # width 10 = empty placeholder glyph
            continue
        ch = mazovia.decode(bytes([code]))
        gy, gx = divmod(i, 16)
        glyphs[str(ord(ch))] = [gx * cw, gy * h, wdt]
    return {"cell": [cw, h], "line_height": h, "letter_spacing": -1, "space_advance": 4,
            "outline_index": 42, "glyphs": glyphs}


def build_sounds(game_dir, exe, out):
    """DATA41 samples (unsigned 8-bit) -> one signed 8-bit PCM blob."""
    bank = open(os.path.join(game_dir, "DATA41.RES"), "rb").read()
    blob, table = bytearray(), []
    for s in exe.sounds():
        pcm = bank[s["offset"]:s["offset"] + s["length"]]
        table.append({"offset": len(blob), "length": len(pcm), "rate": s["rate"],
                      "loop": s["loop"], "loop_start": min(s["loop_start"], max(len(pcm) - 1, 0))})
        blob += bytes((b - 128) & 0xFF for b in pcm)
    open(os.path.join(out, "sounds.bin"), "wb").write(blob)
    return table


def room_json(room):
    objs = []
    for o in room.objects:
        steps = []
        for st in o.steps:
            # raw words: duration word (bits 0-9 ticks, 15 = trigger, 10-14 object), anim word, offset word
            # (bit 15 hidden), sound word (bits 11-13 command, 0-9 id)
            w_dur = st.duration | ((st.trigger_object << 10 | 0x8000) if st.trigger_object is not None else 0)
            w_ofs = st.anim_start | (0x8000 if st.hidden else 0)
            w_snd = st.sound | (st.sound_cmd << 11)
            steps.append([st.ax, st.ay, st.vx, st.vy, st.x, st.y, w_dur, st.anim, w_ofs, w_snd])
        objs.append({"loop_start": o.loop_start, "interact": o.interact, "end_mode": o.end_mode,
                     "sound": o.activate_sound, "flags": o.flags, "hp": o.hp, "hp_max": o.hp_max,
                     "anim": o.activate_anim, "target": o.target, "item": o.item, "steps": steps})
    return {"bg": [v for row in room.background for v in row], "tiles": [v for row in room.tiles for v in row],
            "anims": [[c, r, int(fg), seq, start] for (c, r, fg, seq, start) in room.tile_anims],
            "objects": objs}


def tile_sequences(exe_path):
    """Flat copy of the sequence table as laid out in memory: a header word, the entries, -1.  A start offset
    past a sequence's end reads into the next one, exactly as the game does."""
    from le_loader import LEFile
    le = LEFile(exe_path)
    p, flat, starts = 0x50004, [], []
    for _ in range(76):
        flat.append(struct.unpack("<h", le.read(p, 2))[0])
        p += 2
        starts.append(len(flat))
        while True:
            v = struct.unpack("<h", le.read(p, 2))[0]
            p += 2
            flat.append(v)
            if v == -1:
                break
    return flat, starts


def build_animations(assets, out):
    """FLC frames (already decoded by extract_assets.py) -> index images + one palette per frame."""
    anims = {}
    for name in ("DATA04", "DATA17"):
        d = os.path.join(assets, "animations", name)
        frames = []
        for i, f in enumerate(sorted(x for x in os.listdir(d) if x.endswith(".png"))):
            im = Image.open(os.path.join(d, f))
            assert im.mode == "P", f
            w, h = im.size
            pal = (im.getpalette() + [0] * 768)[:768]
            save_png(index_image(im.tobytes(), w, h, opaque=True), out, f"anim_{name}_{i:03d}.png")
            frames.append({"file": f"anim_{name}_{i:03d}.png", "size": [w, h], "palette": pal})
        anims[name] = frames
    return anims


def main():
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    game_dir, out = sys.argv[1], sys.argv[2]
    assets = os.path.join(ROOT, "assets")
    os.makedirs(out, exist_ok=True)
    exe_path = os.path.join(game_dir, "LAZARUS.EXE")
    exe = LazarusExe(exe_path)

    desc = R.load_desc(game_dir)
    rects = build_sprites(game_dir, out)
    n_pl, n_bg = build_tiles(game_dir, out)
    font = build_font(game_dir, out)
    sounds = build_sounds(game_dir, exe, out)

    raw_types = open(os.path.join(game_dir, "DATA32.RES"), "rb").read()
    raw_types = raw_types + bytes(660 - len(raw_types))      # the game reads 660 bytes into a zeroed buffer
    tile_types = [4 if b == 0 else b for b in raw_types]
    tile_boxes = [[v & 0xFF for v in b] for b in L.load_tile_boxes(game_dir)]
    flat, starts = tile_sequences(exe_path)
    rooms = L.load_rooms(game_dir)

    group_first = [0]
    for i, d in enumerate(desc):
        if d[0] == -1:
            group_first.append(i + 1)

    weapons = []
    for i in range(12):
        b = exe.le.read(0x5427C + i * 0x24, 0x24)
        ox, oy = struct.unpack_from("<hh", b, 0)
        v, a, frame, impact = struct.unpack_from("<iiii", b, 4)
        auto, = struct.unpack_from("<H", b, 0x16)
        lifetime, = struct.unpack_from("<H", b, 0x1A)
        cost, snd_ptr = struct.unpack_from("<iI", b, 0x1C)
        weapons.append({"spawn": [ox, oy], "v": v, "a": a, "frame": frame, "impact": impact, "auto": auto,
                        "cooldown": b[0x18], "damage": b[0x19], "lifetime": lifetime, "cost": cost,
                        "sounds": exe._i16_list(snd_ptr) if snd_ptr else []})

    items = json.load(open(os.path.join(assets, "gamedata", "items.json"), encoding="utf-8"))
    misc = json.load(open(os.path.join(assets, "gamedata", "misc.json"), encoding="utf-8"))
    pals = {name: [c for rgb in L.load_palette(game_dir, f) for c in rgb]
            for name, f in (("game", "DATA25.RES"), ("picture", "DATA27.RES"), ("alarm", "DATA16.RES"),
                            ("menu", "DATA28.RES"))}

    game = {
        "note": "Generated by tools/build_remake_data.py - do not edit.",
        "desc": [list(d) for d in desc],
        "frames": rects,
        "group_first": group_first,
        "tile_types": tile_types,
        "tile_boxes": tile_boxes,
        "platform_tiles": n_pl,
        "background_tiles": n_bg,
        "tile_seq_flat": flat,
        "tile_seq_start": starts,
        "rooms": [room_json(rooms[(c, r)]) for r in range(10) for c in range(10)],
        "weapons": weapons,
        "sounds": sounds,
        "items": [{"icon_frame": 1034 + it["hud_icon"], "pl": it["name_pl"], "en": it["name_en"]}
                  for it in items["items"]],
        "sock_spots": exe.sock_spots(),
        "hurt_sounds": exe.hurt_sounds(),
        "teleports": misc["teleports"],
        "palettes": pals,
        "font": font,
        "animations": build_animations(assets, out),
    }
    with open(os.path.join(out, "game.json"), "w", encoding="utf-8") as f:
        json.dump(game, f, ensure_ascii=False, separators=(",", ":"))

    shutil.copy(os.path.join(assets, "text", "messages.json"), os.path.join(out, "text_pl.json"))
    shutil.copy(os.path.join(assets, "text", "messages_en.json"), os.path.join(out, "text_en.json"))
    shutil.copy(os.path.join(assets, "gamedata", "script_logic.json"), os.path.join(out, "scripts.json"))
    shutil.copy(os.path.join(assets, "gamedata", "golden_traces.json"), os.path.join(out, "golden_traces.json"))
    for src, dst in (("multifruit_juice.ogg", "music_title.ogg"), ("recollection.ogg", "music_intro.ogg")):
        shutil.copy(os.path.join(assets, "music", src), os.path.join(out, dst))
    for src, dst in (("DATA20.png", "pic_game_over.png"), ("DATA21.png", "pic_joke_ending.png"),
                     ("DATA40.png", "pic_credits.png")):
        Image.open(os.path.join(assets, "pictures", src)).convert("RGB").save(os.path.join(out, dst),
                                                                             optimize=True)
    print(f"wrote {out}: {len(desc)} descriptors, {sum(1 for r in rects if r)} frames, "
          f"{sum(len(r.objects) for r in rooms.values())} objects, {len(sounds)} sounds")


if __name__ == "__main__":
    main()
