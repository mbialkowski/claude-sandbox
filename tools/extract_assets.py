#!/usr/bin/env python3
"""Export every Lazarus asset into modern, engine-ready formats.

    python3 tools/extract_assets.py <dir with LAZARUS.EXE + DATAxx.RES> <out dir>

Output layout (see assets/README.md for details):
    palettes/    .png swatch, .json, .gpl (GIMP/Aseprite), .pal (JASC) per palette
    tiles/       gapless tilesets (platform 16x19, background 32x38), single tiles,
                 HUD panel, tile_types.json, Tiled tilesets (*.tsj)
    sprites/     every BOB frame, one sheet + JSON per animation group, sprites.json,
                 labelled overview sheets, Tiled image-collection tileset
    rooms/       json/ (full room data), png/ (tiles only), png_objects/, tiled/ (*.tmj +
                 lazarus.world), debug/ (collision + object paths), world maps (art, regions,
                 collision)
    sounds/      54 WAV files at native rates + sounds.json (loops, names)
    music/       the two ProTracker modules (+ Ogg previews with --render-music), music.json
    pictures/    PCX stills as PNG
    animations/  FLC/FLI frames as PNG, storyboards/ contact sheets, animations.json
    font/        glyph sheet, gapless atlas, BMFont .fnt, font.json
    text/        messages.json (UTF-8, control codes as tags), messages_en.json (English, from
                 tools/translations/en.json) + messages.csv (both languages side by side)
    gamedata/    weapons, items, scripts, tile animations, misc tables, world graph (room
                 connectivity, regions, teleports, secret passages), enemies, hero spec, sound usage,
                 unused content (JSON)

Requires Pillow.
"""
import argparse
import csv
import json
import os
import re
import shutil
import struct
import sys
import wave

from PIL import Image, ImageDraw

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import catalogues  # noqa: E402
import flc  # noqa: E402
import lazarus_data as L  # noqa: E402
import lazarus_names as N  # noqa: E402
import lazarus_scripts  # noqa: E402
import mazovia  # noqa: E402
import reference_sim  # noqa: E402
import world_analysis  # noqa: E402
from lazarus_exe import LazarusExe  # noqa: E402

PALETTES = {"DATA25.RES": "game", "DATA27.RES": "picture", "DATA16.RES": "alarm",
            "DATA28.RES": "menu", "DATA19.RES": "unused"}
PL_COLS = 28          # platform tileset columns
BG_COLS = 12          # background tileset columns


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------
def mkdir(*p):
    path = os.path.join(*p)
    os.makedirs(path, exist_ok=True)
    return path


def jdump(obj, *path, indent=1):
    with open(os.path.join(*path), "w", encoding="utf-8") as f:
        json.dump(obj, f, ensure_ascii=False, indent=indent)


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
    out = Image.new("P", (cols * (w + gap) - gap, rows * (h + gap) - gap), 0)
    out.putpalette(flat_pal(pal))
    for i, t in enumerate(tiles):
        y, x = divmod(i, cols)
        out.paste(img_p(t, w, h, pal), (x * (w + gap), y * (h + gap)))
    if transparent is not None:
        out.info["transparency"] = transparent
    return out


# ---------------------------------------------------------------------------
# palettes
# ---------------------------------------------------------------------------
def export_palettes(g, out):
    d = mkdir(out, "palettes")
    res = {}
    for f, name in PALETTES.items():
        pal = L.load_palette(g, f)
        res[name] = {"file": f, "colors": pal}
        im = Image.new("RGB", (256, 256))
        for i, c in enumerate(pal):
            y, x = divmod(i, 16)
            im.paste(c, (x * 16, y * 16, x * 16 + 16, y * 16 + 16))
        im.save(os.path.join(d, f"{name}.png"))
        with open(os.path.join(d, f"{name}.gpl"), "w") as fp:
            fp.write(f"GIMP Palette\nName: Lazarus {name} ({f})\nColumns: 16\n#\n")
            for i, (r, gg, b) in enumerate(pal):
                fp.write(f"{r:3d} {gg:3d} {b:3d}\tindex {i}\n")
        with open(os.path.join(d, f"{name}.pal"), "w", newline="\r\n") as fp:
            fp.write("JASC-PAL\n0100\n256\n")
            for (r, gg, b) in pal:
                fp.write(f"{r} {gg} {b}\n")
    jdump(res, d, "palettes.json", indent=None)
    return L.load_palette(g, "DATA25.RES")


# ---------------------------------------------------------------------------
# tiles
# ---------------------------------------------------------------------------
def export_tiles(g, out, pal):
    d = mkdir(out, "tiles")
    pl = L.load_platform_tiles(g)
    bg = L.load_background_tiles(g)
    # gapless tilesets (engine ready) + spaced previews (easier to read)
    sheet(pl, L.PL_TW, L.PL_TH, PL_COLS, pal, gap=0, transparent=0).save(os.path.join(d, "platform_tileset.png"))
    sheet(bg, L.BG_TW, L.BG_TH, BG_COLS, pal, gap=0).save(os.path.join(d, "background_tileset.png"))
    sheet(pl, L.PL_TW, L.PL_TH, PL_COLS, pal, gap=1, transparent=0).save(os.path.join(d, "platform_tiles_preview.png"))
    sheet(bg, L.BG_TW, L.BG_TH, BG_COLS, pal, gap=1).save(os.path.join(d, "background_tiles_preview.png"))
    img_p(L.load_hud(g), 76, 240, pal).save(os.path.join(d, "hud_panel.png"))
    pd, bd = mkdir(d, "platform"), mkdir(d, "background")
    for i, t in enumerate(pl):
        img_p(t, L.PL_TW, L.PL_TH, pal, transparent=0).save(os.path.join(pd, f"{i:03d}.png"))
    for i, t in enumerate(bg):
        img_p(t, L.BG_TW, L.BG_TH, pal).save(os.path.join(bd, f"{i:03d}.png"))

    types = L.load_tile_types(g)
    boxes = L.load_tile_boxes(g)
    names = {4: "solid", 1: "harmful", 2: "passable"}
    info = []
    for i in range(len(pl)):
        t = types[i] if i < len(types) else 2
        box = list(boxes[i]) if i < len(boxes) else None
        info.append({"tile": i, "type": names.get(t, t), "box": box})
    jdump({"note": "box = x0,y0,x1,y1 inclusive, relative to the 16x19 cell; used for solid and harmful tiles. "
                   "Tile 0 is empty.", "tiles": info}, d, "tile_types.json")

    # Tiled tilesets
    td = mkdir(d, "tiled")
    tiles_meta = []
    for t in info:
        props = [{"name": "type", "type": "string", "value": t["type"]}]
        entry = {"id": t["tile"], "properties": props}
        if t["type"] in ("solid", "harmful") and t["box"]:
            x0, y0, x1, y1 = t["box"]
            entry["objectgroup"] = {"type": "objectgroup", "draworder": "index", "name": "", "opacity": 1,
                                    "visible": True, "x": 0, "y": 0, "id": 2,
                                    "objects": [{"id": 1, "name": t["type"], "type": "", "rotation": 0,
                                                 "visible": True, "x": x0, "y": y0,
                                                 "width": x1 - x0 + 1, "height": y1 - y0 + 1}]}
        tiles_meta.append(entry)
    rows = (len(pl) + PL_COLS - 1) // PL_COLS
    jdump({"type": "tileset", "version": "1.10", "tiledversion": "1.10.2", "name": "platform",
           "image": "../platform_tileset.png", "imagewidth": PL_COLS * L.PL_TW, "imageheight": rows * L.PL_TH,
           "tilewidth": L.PL_TW, "tileheight": L.PL_TH, "columns": PL_COLS, "tilecount": len(pl),
           "margin": 0, "spacing": 0, "transparentcolor": "#000000", "tiles": tiles_meta},
          td, "platform.tsj", indent=None)
    rows = (len(bg) + BG_COLS - 1) // BG_COLS
    jdump({"type": "tileset", "version": "1.10", "tiledversion": "1.10.2", "name": "background",
           "image": "../background_tileset.png", "imagewidth": BG_COLS * L.BG_TW, "imageheight": rows * L.BG_TH,
           "tilewidth": L.BG_TW, "tileheight": L.BG_TH, "columns": BG_COLS, "tilecount": len(bg),
           "margin": 0, "spacing": 0}, td, "background.tsj")
    return pl, bg


# ---------------------------------------------------------------------------
# sprites
# ---------------------------------------------------------------------------
def group_usage(rooms):
    use = {}
    for (c, r), room in rooms.items():
        for o in room.objects:
            anims = {s.anim for s in o.steps}
            if o.activate_anim >= 0:
                anims.add(o.activate_anim)
            for a in anims:
                u = use.setdefault(a, {"objects": 0, "rooms": set(), "scripts": set(), "classes": set()})
                u["objects"] += 1
                u["rooms"].add(f"{c},{r}")
                u["classes"].add(o.collision_class)
                if o.flags & 0x4000 and o.target >= 20:
                    u["scripts"].add(o.target)
    return use


def export_sprites(g, out, pal, rooms):
    d = mkdir(out, "sprites")
    fd, gd, od = mkdir(d, "frames"), mkdir(d, "groups"), mkdir(d, "overview")
    frames, groups = L.load_bobs(g)
    usage = group_usage(rooms)
    loops = L.load_bob_loops(g)
    meta = {"note": "frame 'box' = collision box x0,y0,x1,y1 relative to the frame's top-left; "
                    "a frame with 'duration' d is shown for d+1 ticks (50 Hz). Colour 0 is transparent. "
                    "loop_ticks: when a group loops it restarts that many ticks into its first frames "
                    "(an intro that plays once).",
            "frames": [], "groups": []}
    for f in frames:
        if f is None:
            continue
        img_p(f.pixels, f.width, f.height, pal, transparent=0).save(os.path.join(fd, f"{f.index:04d}.png"))
        meta["frames"].append({"index": f.index, "duration": f.duration, "width": f.width,
                               "height": f.height, "box": list(f.box)})
    for gi, idxs in enumerate(groups):
        u = usage.get(gi)
        entry = {"group": gi, "name": N.SPRITE_GROUPS.get(gi), "frames": idxs,
                 "loop_ticks": loops.get(gi, (0, 0))[1],
                 "used_by_objects": u["objects"] if u else 0,
                 "rooms": sorted(u["rooms"]) if u else [],
                 "scripts": sorted(u["scripts"]) if u else []}
        meta["groups"].append(entry)
        if not idxs:
            continue
        fr = [frames[i] for i in idxs]
        w = sum(f.width for f in fr) + 2 * (len(fr) - 1)
        h = max(f.height for f in fr)
        im = Image.new("P", (w, h), 0)
        im.putpalette(flat_pal(pal))
        x, rects = 0, []
        for f in fr:
            im.paste(img_p(f.pixels, f.width, f.height, pal), (x, 0))
            rects.append({"frame": f.index, "x": x, "y": 0, "w": f.width, "h": f.height,
                          "duration": f.duration, "box": list(f.box)})
            x += f.width + 2
        im.info["transparency"] = 0
        im.save(os.path.join(gd, f"group_{gi:03d}.png"))
        jdump({"group": gi, "name": N.SPRITE_GROUPS.get(gi), "image": f"group_{gi:03d}.png",
               "loop_ticks": loops.get(gi, (0, 0))[1], "frames": rects}, gd, f"group_{gi:03d}.json")
    jdump(meta, d, "sprites.json", indent=None)

    # labelled overview sheets (for humans)
    per_page = 58
    for page in range(0, len(groups), per_page):
        sel = list(range(page, min(page + per_page, len(groups))))
        heights = [max([frames[i].height for i in groups[gi]] + [10]) + 4 for gi in sel]
        W = 1100
        im = Image.new("RGB", (W, sum(heights)), (40, 0, 40))
        dr = ImageDraw.Draw(im)
        y = 0
        for gi, hh in zip(sel, heights):
            label = f"{gi}"
            dr.text((2, y + 1), label, fill=(255, 255, 0))
            nm = N.SPRITE_GROUPS.get(gi)
            x = 34
            for i in groups[gi]:
                f = frames[i]
                if x + f.width > W - 200:
                    break
                sp = img_p(f.pixels, f.width, f.height, pal).convert("RGB")
                mask = Image.frombytes("L", (f.width, f.height), bytes(255 if p else 0 for p in f.pixels))
                im.paste(sp, (x, y + 2), mask)
                x += f.width + 2
            if nm:
                dr.text((max(x + 6, W - 196), y + 1), nm[:32], fill=(180, 220, 255))
            y += hh
        im.save(os.path.join(od, f"overview_{page // per_page}.png"))

    # Tiled image-collection tileset: first frame of every group (used by the room maps)
    tiles = []
    for gi, idxs in enumerate(groups):
        if not idxs:
            continue
        f = frames[idxs[0]]
        tiles.append({"id": gi, "image": f"../frames/{f.index:04d}.png", "imagewidth": f.width,
                      "imageheight": f.height,
                      "properties": [{"name": "group", "type": "int", "value": gi},
                                     {"name": "name", "type": "string", "value": N.SPRITE_GROUPS.get(gi) or ""}]})
    mkdir(d, "tiled")
    jdump({"type": "tileset", "version": "1.10", "tiledversion": "1.10.2", "name": "sprites",
           "tilewidth": max(t["imagewidth"] for t in tiles), "tileheight": max(t["imageheight"] for t in tiles),
           "columns": 0, "tilecount": len(tiles), "margin": 0, "spacing": 0,
           "grid": {"orientation": "orthogonal", "width": 1, "height": 1}, "tiles": tiles},
          d, "tiled", "sprites.tsj", indent=None)
    return frames, groups


# ---------------------------------------------------------------------------
# rooms
# ---------------------------------------------------------------------------
def render_room(room, pl, bg, frames, groups, seqs, with_objects=True, desc=None):
    """The room as first seen in a new game: layers, animated tiles at their start frame (foreground ones
    over the sprites), objects drawn by the constructor's rules at their first path position and frame.
    Verified pixel-identical against the original by tools/pixel_check.py."""
    W, H = L.ROOM_PX_W, L.ROOM_PX_H
    buf = bytearray(W * H)

    def blit(px, w, h, x0, y0, transparent=True):
        for y in range(h):
            yy = y0 + y
            if not 0 <= yy < H:
                continue
            row = y * w
            for x in range(w):
                xx = x0 + x
                c = px[row + x]
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
            s = seqs[seq] if seq < len(seqs) else []
            if s and (fg == foreground or not with_objects):
                t = s[min(start, len(s) - 1)]
                if 0 < t < len(pl):
                    blit(pl[t], L.PL_TW, L.PL_TH, c * L.PL_TW, r * L.PL_TH)

    anims(False)
    if with_objects:
        for o in room.objects:
            if not reference_sim.object_present(o):
                continue
            st = o.steps[0]
            f = frames[reference_sim.find_frame(desc, st.anim, st.anim_start)]
            if f is not None:
                x, y = st.pos
                blit(f.pixels, f.width, f.height, x, y)
        anims(True)
    return bytes(buf)


def object_json(o):
    return {
        "index": o.index, "header_hex": o.raw_header.hex(),
        "loop_start": o.loop_start, "end_mode": L.END_MODES.get(o.end_mode, "restart"),
        "interact": o.interact, "flags": o.flags, "flag_names": o.describe_flags(),
        "collision_class": o.collision_class,
        "class_name": {0x08: "inert", 0x10: "harmful", 0x20: "usable", 0x40: "solid"}.get(o.collision_class),
        "hp": o.hp, "hp_max": o.hp_max, "activate_anim": o.activate_anim if o.activate_anim >= 0 else None,
        "activate_sound": o.activate_sound,
        "target": o.target, "target_kind": ("script" if o.target >= 20 else "object") if o.flags & 0x4000 else None,
        "script_note": N.SCRIPTS.get(o.target) if o.flags & 0x4000 and o.target >= 20 else None,
        "item": o.item,
        "steps": [{"x": s.x / 65536, "y": s.y / 65536, "vx": s.vx / 65536, "vy": s.vy / 65536,
                   "ax": s.ax / 65536, "ay": s.ay / 65536, "ticks": s.duration,
                   "anim": s.anim, "anim_start": s.anim_start, "hidden": s.hidden,
                   "sound": s.sound if s.sound_cmd in (1, 3) else None,
                   "sound_cmd": {1: "play", 3: "stop"}.get(s.sound_cmd),
                   "trigger_object": s.trigger_object} for s in o.steps],
    }


def tiled_props(d):
    out = []
    for k, v in d.items():
        if v is None:
            continue
        if isinstance(v, bool):
            out.append({"name": k, "type": "bool", "value": v})
        elif isinstance(v, int):
            out.append({"name": k, "type": "int", "value": v})
        elif isinstance(v, float):
            out.append({"name": k, "type": "float", "value": v})
        elif isinstance(v, str):
            out.append({"name": k, "type": "string", "value": v})
        else:
            out.append({"name": k, "type": "string", "value": json.dumps(v, ensure_ascii=False)})
    return out


def tiled_room(room, frames, groups, seqs, n_pl, n_bg, sprite_gid):
    pl_first, bg_first = 1, 1 + n_pl
    platform = [(t + pl_first if 0 < t < n_pl else 0) for row in room.tiles for t in row]
    # background tiles (32x38) sit on the 16x19 grid at every second cell; Tiled anchors large
    # tiles at the bottom-left of their cell, hence the odd rows.
    bgl = [0] * (L.MAP_W * L.MAP_H)
    for ty in range(L.BG_H):
        for tx in range(L.BG_W):
            bgl[(ty * 2 + 1) * L.MAP_W + tx * 2] = room.background[ty][tx] + bg_first
    anims = []
    oid = 1
    for (c, r, fg, seq, start) in room.tile_anims:
        s = seqs[seq] if seq < len(seqs) else []
        t = s[min(start, len(s) - 1)] if s else 0
        anims.append({"id": oid, "name": f"tile_anim_{seq}", "type": "tile_anim", "rotation": 0,
                      "visible": True, "x": c * L.PL_TW, "y": (r + 1) * L.PL_TH,
                      "width": L.PL_TW, "height": L.PL_TH, "gid": (t + pl_first) if 0 < t < n_pl else 0,
                      "properties": tiled_props({"sequence": seq, "start": start, "foreground": fg,
                                                 "frames": json.dumps(s)})})
        oid += 1
    objs = []
    for o in room.objects:
        s0 = o.steps[0] if o.steps else None
        anim = s0.anim if s0 else 0
        has = anim < len(groups) and groups[anim]
        f = frames[groups[anim][0]] if has else None
        x, y = s0.pos if s0 else (0, 0)
        js = object_json(o)
        props = {k: v for k, v in js.items() if k not in ("steps", "flag_names")}
        props["flag_names"] = ",".join(js["flag_names"])
        props["steps"] = js["steps"]
        e = {"id": oid, "name": N.SPRITE_GROUPS.get(anim) or f"group {anim}",
             "type": js["class_name"] or "object", "rotation": 0,
             "visible": not (o.flags & 0x0008), "x": x, "y": y + (f.height if f else 0),
             "width": f.width if f else 8, "height": f.height if f else 8,
             "properties": tiled_props(props)}
        if f and anim in sprite_gid:
            e["gid"] = sprite_gid[anim]
        objs.append(e)
        oid += 1
    layer = lambda lid, name, data: {"id": lid, "name": name, "type": "tilelayer", "width": L.MAP_W,
                                     "height": L.MAP_H, "x": 0, "y": 0, "opacity": 1, "visible": True,
                                     "data": data}
    return {
        "type": "map", "version": "1.10", "tiledversion": "1.10.2", "orientation": "orthogonal",
        "renderorder": "right-down", "infinite": False, "compressionlevel": -1,
        "width": L.MAP_W, "height": L.MAP_H, "tilewidth": L.PL_TW, "tileheight": L.PL_TH,
        "nextlayerid": 5, "nextobjectid": oid,
        "properties": tiled_props({"col": room.col, "row": room.row}),
        "tilesets": [{"firstgid": pl_first, "source": "../../tiles/tiled/platform.tsj"},
                     {"firstgid": bg_first, "source": "../../tiles/tiled/background.tsj"},
                     {"firstgid": bg_first + n_bg, "source": "../../sprites/tiled/sprites.tsj"}],
        "layers": [layer(1, "background", bgl), layer(2, "platforms", platform),
                   {"id": 3, "name": "tile_animations", "type": "objectgroup", "draworder": "index",
                    "x": 0, "y": 0, "opacity": 1, "visible": True, "objects": anims},
                   {"id": 4, "name": "objects", "type": "objectgroup", "draworder": "index",
                    "x": 0, "y": 0, "opacity": 1, "visible": True, "objects": objs}],
    }


def export_rooms(g, out, pal, pl, bg, frames, groups, seqs, rooms):
    d = mkdir(out, "rooms")
    jd, pd, po, td = mkdir(d, "json"), mkdir(d, "png"), mkdir(d, "png_objects"), mkdir(d, "tiled")
    W, H = L.ROOM_PX_W, L.ROOM_PX_H
    world = Image.new("P", (10 * W, 10 * H), 0)
    world.putpalette(flat_pal(pal))
    world_o = world.copy()
    # gid of each sprite group inside the sprites image-collection tileset
    sprite_first = 1 + len(pl) + len(bg)
    sprite_gid = {gi: sprite_first + gi for gi, idxs in enumerate(groups) if idxs}
    world_maps = []
    desc = reference_sim.load_desc(g)
    for (col, row), room in sorted(rooms.items()):
        im = img_p(render_room(room, pl, bg, frames, groups, seqs, False), W, H, pal)
        imo = img_p(render_room(room, pl, bg, frames, groups, seqs, True, desc), W, H, pal)
        im.save(os.path.join(pd, f"room_{col}_{row}.png"))
        imo.save(os.path.join(po, f"room_{col}_{row}.png"))
        world.paste(im, (col * W, row * H))
        world_o.paste(imo, (col * W, row * H))
        jdump({"col": col, "row": row,
               "background": room.background, "tiles": room.tiles,
               "tile_anims": [{"col": c, "row": r, "foreground": fg, "sequence": s, "start": st}
                              for (c, r, fg, s, st) in room.tile_anims],
               "objects": [object_json(o) for o in room.objects]}, jd, f"room_{col}_{row}.json")
        jdump(tiled_room(room, frames, groups, seqs, len(pl), len(bg), sprite_gid),
              td, f"room_{col}_{row}.tmj", indent=None)
        world_maps.append({"fileName": f"room_{col}_{row}.tmj", "x": col * W, "y": row * H,
                           "width": W, "height": H})
    jdump({"type": "world", "maps": world_maps, "onlyShowAdjacentMaps": False}, td, "lazarus.world")
    world.save(os.path.join(d, "world_map.png"))
    world_o.save(os.path.join(d, "world_map_objects.png"))
    small = world_o.convert("RGB").resize((10 * W // 2, 10 * H // 2), Image.LANCZOS)
    dr = ImageDraw.Draw(small)
    for r in range(10):
        for c in range(10):
            x, y = c * W // 2, r * H // 2
            dr.rectangle([x, y, x + W // 2 - 1, y + H // 2 - 1], outline=(255, 255, 255))
            dr.rectangle([x + 1, y + 1, x + 34, y + 11], fill=(0, 0, 0))
            dr.text((x + 3, y + 1), f"{c},{r}", fill=(255, 255, 0))
    small.save(os.path.join(d, "world_map_labeled.png"))


# ---------------------------------------------------------------------------
# audio, pictures, animations
# ---------------------------------------------------------------------------
def export_sounds(g, out, exe):
    d = mkdir(out, "sounds")
    bank = open(os.path.join(g, "DATA41.RES"), "rb").read()
    table = exe.sounds()
    for s in table:
        pcm = bytes((b + 128) & 0xFF for b in bank[s["offset"]:s["offset"] + s["length"]])
        s["file"] = f"sfx_{s['id']:02d}.wav"
        s["name"] = N.SOUNDS.get(s["id"])
        with wave.open(os.path.join(d, s["file"]), "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(1)
            w.setframerate(s["rate"])
            w.writeframes(pcm)
    jdump({"note": "8-bit mono PCM at the original Amiga-style rates. loop_start is a byte offset "
                   "inside the sample; several ids reuse the same sample at another pitch.",
           "sounds": table}, d, "sounds.json")


MUSIC = {
    "DATA23.RES": ("multifruit_juice", "title menu (loops); stops when a game starts - there is no in-game music"),
    "DATA39.RES": ("recollection", "intro sequence and the end-credits scroller"),
}


def mod_info(data):
    """ProTracker header summary (title, order list, pattern count)."""
    song_len = data[950]
    orders = list(data[952:952 + song_len])
    return {"title": data[:20].rstrip(b"\0").decode("latin1"), "format": data[1080:1084].decode("latin1"),
            "channels": 4, "orders": song_len, "patterns": max(list(data[952:1080])) + 1,
            "order_list": orders, "composer": "Wojciech Panufnik (Snoopy)"}


def export_music(g, out, render=False):
    d = mkdir(out, "music")
    meta = {}
    try:  # keep the durations of previews rendered by an earlier --render-music run
        old = json.load(open(os.path.join(d, "music.json"), encoding="utf-8"))["modules"]
    except (OSError, ValueError, KeyError):
        old = {}
    for src, (name, use) in MUSIC.items():
        data = open(os.path.join(g, src), "rb").read()
        shutil.copyfile(os.path.join(g, src), os.path.join(d, name + ".mod"))
        info = mod_info(data)
        info.update({"file": name + ".mod", "source": src, "use": use})
        if render:
            info.update(render_mod(os.path.join(d, name + ".mod"), os.path.join(d, name + ".ogg")))
        elif os.path.exists(os.path.join(d, name + ".ogg")):
            info["preview"] = name + ".ogg"
            if "duration" in old.get(name, {}):
                info["duration"] = old[name]["duration"]
        meta[name] = info
    jdump({"note": "4-channel ProTracker modules played by the game's own mixer. *.ogg files are previews "
                   "rendered with libopenmpt (tools/extract_assets.py --render-music), not the original mixer.",
           "modules": meta}, d, "music.json")


def render_mod(mod, ogg):
    """Render one pass of a module to Ogg Vorbis with openmpt123 + oggenc (optional tools)."""
    import subprocess
    import tempfile
    if not (shutil.which("openmpt123") and shutil.which("oggenc")):
        print("  (openmpt123/oggenc not installed - skipping music preview)")
        return {}
    with tempfile.TemporaryDirectory() as tmp:
        wav = os.path.join(tmp, "out.wav")
        subprocess.run(["openmpt123", "--batch", "--quiet", "--samplerate", "44100",
                        "--subsong", "0", "--output", wav, mod], check=True,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        subprocess.run(["oggenc", "-Q", "-q", "5", "-o", ogg, wav], check=True)
        info = subprocess.run(["openmpt123", "--info", mod], capture_output=True, text=True).stdout
    m = re.search(r"Duration\.*: (\S+)", info)
    return {"preview": os.path.basename(ogg), "duration": m.group(1) if m else None}


def export_pictures(g, out):
    d = mkdir(out, "pictures")
    meta = {}
    for f in ["DATA20", "DATA21", "DATA22", "DATA33", "DATA34", "DATA35", "DATA36", "DATA40"]:
        im = Image.open(os.path.join(g, f + ".RES"))
        im.save(os.path.join(d, f + ".png"))
        meta[f + ".png"] = {"size": list(im.size), "colors": 16 if im.size[0] == 640 else 256,
                            "use": N.PICTURES.get(f)}
    jdump(meta, d, "pictures.json")


def storyboard(frame_dir, count, dst, cols=8, width=160):
    """Contact sheet of every frame (scaled to `width`) with frame numbers."""
    frames = [Image.open(os.path.join(frame_dir, f"{i:03d}.png")).convert("RGB") for i in range(count)]
    w0, h0 = frames[0].size
    th = width * h0 // w0
    cols = min(cols, count)
    rows = (count + cols - 1) // cols
    sheet_im = Image.new("RGB", (cols * (width + 2), rows * (th + 2)), (32, 0, 32))
    dr = ImageDraw.Draw(sheet_im)
    for i, f in enumerate(frames):
        y, x = divmod(i, cols)
        sheet_im.paste(f.resize((width, th), Image.LANCZOS), (x * (width + 2), y * (th + 2)))
        dr.text((x * (width + 2) + 3, y * (th + 2) + 2), str(i), fill=(255, 255, 0))
    sheet_im.save(dst)


def export_animations(g, out):
    d = mkdir(out, "animations")
    meta = {}
    for n in [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17]:
        name = f"DATA{n:02d}"
        ad = mkdir(d, name)
        data = open(os.path.join(g, name + ".RES"), "rb").read()
        magic = struct.unpack_from("<H", data, 4)[0]
        count = 0
        for i, (px, pal, (w, h), speed) in enumerate(flc.frames(data)):
            img_p(px, w, h, pal).save(os.path.join(ad, f"{i:03d}.png"))
            count += 1
        storyboard(ad, count, os.path.join(mkdir(d, "storyboards"), name + ".png"))
        ms = speed if magic == 0xAF12 else round(speed * 1000 / 70)
        meta[name] = {"use": N.ANIMATIONS.get(name), "frames": count, "size": [w, h],
                      "frame_ms": ms, "format": "FLC" if magic == 0xAF12 else "FLI"}
    jdump({"note": "frame_ms comes from the file header; the game's PlayFLC overrides timing for some files.",
           "animations": meta}, d, "animations.json")


# ---------------------------------------------------------------------------
# font
# ---------------------------------------------------------------------------
def export_font(g, out):
    d = mkdir(out, "font")
    raw = open(os.path.join(g, "DATA26.RES"), "rb").read()
    widths = list(raw[:0xE0])
    bw, h = raw[0xE0], raw[0xE1]
    cw = bw * 4
    gsz = 2 + cw * h
    glyphs = [L.planar_to_linear(raw[0xE0 + i * gsz + 2:0xE0 + (i + 1) * gsz], cw, h) for i in range(0xE0)]
    pal = [(0, 0, 0), (255, 255, 255), (64, 64, 64)] + [(255, 0, 255)] * 253
    sheet(glyphs, cw, h, 16, pal, gap=2, transparent=0).save(os.path.join(d, "glyphs_preview.png"))
    # RGBA atlas: body white, outline dark grey, rest transparent; 16 x 14 cells
    atlas = Image.new("RGBA", (16 * cw, 14 * h), (0, 0, 0, 0))
    for i, px in enumerate(glyphs):
        y0, x0 = divmod(i, 16)
        for y in range(h):
            for x in range(cw):
                p = px[y * cw + x]
                if p == 1:
                    atlas.putpixel((x0 * cw + x, y0 * h + y), (255, 255, 255, 255))
                elif p == 2:
                    atlas.putpixel((x0 * cw + x, y0 * h + y), (40, 40, 40, 255))
    atlas.save(os.path.join(d, "font_atlas.png"))
    spacing, space_adv = -1, 4         # values set by main(): letter spacing -1, space width 4
    chars = []
    for i, wdt in enumerate(widths):
        code = 0x20 + i
        if wdt == 10 and code != 0x20:  # width 10 = empty placeholder glyph
            continue
        ch = mazovia.decode(bytes([code]))
        y0, x0 = divmod(i, 16)
        adv = (space_adv if code == 0x20 else wdt) + spacing
        chars.append((ord(ch), x0 * cw, y0 * h, wdt if code != 0x20 else 0, adv, ch))
    with open(os.path.join(d, "lazarus.fnt"), "w", encoding="utf-8") as f:
        f.write(f'info face="Lazarus" size={h} bold=0 italic=0 charset="" unicode=1 stretchH=100 '
                f'smooth=0 aa=1 padding=0,0,0,0 spacing=0,0 outline=0\n')
        f.write(f"common lineHeight={h} base={h - 1} scaleW={16 * cw} scaleH={14 * h} pages=1 packed=0 "
                f"alphaChnl=0 redChnl=4 greenChnl=4 blueChnl=4\n")
        f.write('page id=0 file="font_atlas.png"\n')
        f.write(f"chars count={len(chars)}\n")
        for uni, x, y, wdt, adv, _ch in chars:
            f.write(f"char id={uni} x={x} y={y} width={max(wdt, 1)} height={h} xoffset=0 yoffset=0 "
                    f"xadvance={adv} page=0 chnl=15\n")
    jdump({"cell": [cw, h], "first_char": 32, "encoding": "Mazovia",
           "letter_spacing": spacing, "space_advance": space_adv, "line_height": h,
           "pixel_values": {"0": "transparent", "1": "body (colour from {c:NNN})",
                            "2": "outline (palette index 42)"},
           "control_codes": {"0xE0 ddd": "set x", "0xE1 ddd": "set y", "0xE2 ddd": "set colour"},
           "glyphs": [{"char": ch, "unicode": uni, "x": x, "y": y, "width": wdt, "advance": adv}
                      for uni, x, y, wdt, adv, ch in chars]}, d, "font.json")
    return {ch: adv for uni, x, y, wdt, adv, ch in chars}, space_adv


# ---------------------------------------------------------------------------
# text + game tables
# ---------------------------------------------------------------------------
TAG = re.compile(r"\{([xyc]):(\d{3})\}")


TRANSLATIONS = os.path.join(os.path.dirname(os.path.abspath(__file__)), "translations")


def translate(msgs, lang):
    """Messages in another language from tools/translations/<lang>.json, with the original's control
    tags and leading/trailing whitespace (menu spacing) re-attached. Returns (texts, overflows)."""
    tr = json.load(open(os.path.join(TRANSLATIONS, lang + ".json"), encoding="utf-8"))
    out = []
    for i, m in enumerate(msgs):
        tags = "".join(t.group(0) for t in TAG.finditer(m))
        plain = TAG.sub("", m)
        lead = plain[:len(plain) - len(plain.lstrip())]
        trail = plain[len(plain.rstrip()):]
        out.append(tags + lead + tr[str(i)].strip() + trail)
    return out


def text_overflows(msgs, glyph_advance, space_advance, limit=264):
    """Lines whose right edge (x tag + width in the dialogue font) passes `limit` px and the original's."""
    res = []
    for i, m in enumerate(msgs):
        x = int(dict(TAG.findall(m)).get("x", 0))
        for ln in TAG.sub("", m).split("\n"):
            right = x + sum(space_advance if c == " " else glyph_advance.get(c, 12) for c in ln)
            if right > limit:
                res.append((i, right, ln))
    return res


def export_text(out, exe, glyph_advance=None, space_advance=4):
    d = mkdir(out, "text")
    msgs = exe.messages()
    jdump(msgs, d, "messages.json")
    en = translate(msgs, "en")
    jdump(en, d, "messages_en.json")
    if glyph_advance:
        too_long = {i for i, _, _ in text_overflows(msgs, glyph_advance, space_advance)}
        for i, right, ln in text_overflows(en, glyph_advance, space_advance):
            if i not in too_long:
                print(f"warning: English message {i} is {right} px wide: {ln!r}")
    with open(os.path.join(d, "messages.csv"), "w", encoding="utf-8", newline="") as f:
        w = csv.writer(f)
        w.writerow(["id", "x", "y", "color", "text_pl", "text_en", "raw"])
        for i, m in enumerate(msgs):
            tags = {k: int(v) for k, v in TAG.findall(m)}
            plain = TAG.sub("", m)
            w.writerow([i, tags.get("x", ""), tags.get("y", ""), tags.get("c", ""), plain,
                        TAG.sub("", en[i]), m])


def export_gamedata(out, exe):
    d = mkdir(out, "gamedata")
    weapons = exe.weapons()
    for wpn in weapons:
        wpn["name"] = N.WEAPONS.get(wpn["weapon"])
    jdump({"note": "12 entries = weapon*2 + facing. speed/accel in px per tick (50 Hz); "
                   "ammo scale 0x2F0000 = full bar.", "weapons": weapons}, d, "weapons.json")
    msgs = exe.messages()
    items = exe.items()
    for it in items:
        pl, en = N.ITEMS.get(it["id"], ("", ""))
        it.update({"name_pl": pl, "name_en": en, "hud_icon_frame": 1034 + it["hud_icon"]})
        m = N.ITEM_DESCRIPTION_MSG.get(it["id"])
        if m is not None:
            it["description_msg"] = m
            it["description"] = TAG.sub("", msgs[m])
    jdump({"note": "icon = sprite frame hud_icon_frame (group 208); see docs 04-game-content.md for "
                   "where items are found and used.", "items": items}, d, "items.json")
    scripts = [dict(s, note=N.SCRIPTS.get(s["id"])) for s in exe.scripts()
               if s["on_trigger_fn"] != "1b2b0" or s["on_missing_item_fn"] != "1b2b0" or s["id"] in N.SCRIPTS]
    jdump({"note": "on_trigger runs when an object with target=id finishes activating; "
                   "on_missing_item is indexed by ITEM id. 1b2b0 = no-op.", "scripts": scripts},
          d, "scripts.json")
    jdump(lazarus_scripts.export(exe), d, "script_logic.json")
    jdump({"note": "76 tile-animation sequences; one entry per 50 Hz tick, looping.",
           "sequences": exe.tile_anim_sequences()}, d, "tile_anims.json", indent=None)
    jdump({"sock_spots_col_row": exe.sock_spots(), "hurt_sounds": exe.hurt_sounds(),
           "teleports": [
               {"menu": "Zapomniana Świątynia", "room": [7, 0], "pos": [22, 83], "known_at_start": True},
               {"menu": "Zaświaty", "room": [7, 8], "pos": [38, 178], "known_at_start": False},
               {"menu": "Otchłań", "room": [1, 6], "pos": [27, 64], "known_at_start": False},
               {"menu": "Ukryta Dolina", "room": [4, 2], "pos": [100, 121], "known_at_start": False},
               {"menu": "Kraina Grozy", "room": [1, 1], "pos": [94, 26], "known_at_start": False},
               {"menu": "Sala treningowa", "room": [5, 5], "pos": [124, 26], "known_at_start": True}],
           "hub_room": [0, 0], "hub_pos": [53, 178], "start_room": [7, 0],
           "new_game": {"energy": 0x2F0000, "fuel": 0, "money": 10, "weapon": 0, "pockets": [24],
                        "bomb_timer_ticks": 3000},
           "hero": catalogues.HERO_PHYSICS},
          d, "misc.json")


# ---------------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game_dir")
    ap.add_argument("out_dir")
    ap.add_argument("--skip-animations", action="store_true", help="FLC decoding is the slow part")
    ap.add_argument("--render-music", action="store_true",
                    help="also render the MODs to Ogg previews (needs openmpt123 and oggenc)")
    a = ap.parse_args()
    g, out = a.game_dir, a.out_dir
    exe = LazarusExe(os.path.join(g, "LAZARUS.EXE"))
    rooms = L.load_rooms(g)
    pal = export_palettes(g, out)
    pl, bg = export_tiles(g, out, pal)
    frames, groups = export_sprites(g, out, pal, rooms)
    seqs = exe.tile_anim_sequences()
    export_rooms(g, out, pal, pl, bg, frames, groups, seqs, rooms)
    world_analysis.export_world(g, out, rooms, frames, groups, seqs)
    catalogues.export_catalogues(g, out, exe, rooms, frames, groups, seqs, len(pl), len(bg))
    with open(os.path.join(mkdir(out, "gamedata"), "golden_traces.json"), "w", encoding="utf-8") as f:
        json.dump(reference_sim.golden(g), f, separators=(",", ":"))
    export_sounds(g, out, exe)
    export_music(g, out, render=a.render_music)
    export_pictures(g, out)
    advance, space_adv = export_font(g, out)
    export_text(out, exe, advance, space_adv)
    export_gamedata(out, exe)
    if not a.skip_animations:
        export_animations(g, out)
    print("exported ->", out)


if __name__ == "__main__":
    main()
