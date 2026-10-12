"""World-structure analysis for the Lazarus remake: which room edges the hero can cross, the regions
(connected groups of rooms) they form, the teleport links between regions, object trajectories, and
debug renders of collision and paths.

Used by extract_assets.py (export_world); can also be run on its own:

    python3 tools/world_analysis.py original/ assets/

Everything is derived from the original data with the engine rules documented in
docs/reverse-engineering/03-engine.md (tile collision 3.3, room transitions 3.2, object paths 3.5).
"""
import json
import os
import sys

from PIL import Image, ImageDraw

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402
import lazarus_names as N  # noqa: E402

W, H = L.ROOM_PX_W, L.ROOM_PX_H

# Hero collision box inside his 20/24x31 sprite (frames of groups 204/205), inclusive.
HERO_BOX = (6, 2, 16, 30)
HERO_W = HERO_BOX[2] - HERO_BOX[0] + 1          # 11 px
HERO_H = HERO_BOX[3] - HERO_BOX[1] + 1          # 29 px

# Every Hero_StartTeleport(col, row, x, y) call in LAZARUS.EXE and the script that makes it.
WARPS = [
    {"script": 241, "to": [0, 0], "pos": [53, 178], "note": "teleport booth -> hub"},
    {"script": 132, "to": [0, 0], "pos": [53, 178], "note": "fuse fitted: repaired booth -> hub (calls script 241)"},
    {"script": 98, "to": [4, 2], "pos": [100, 121], "note": "also teaches the password Ukryta Dolina"},
    {"script": 45, "to": [4, 5], "pos": [14, 83], "note": ""},
    {"script": 203, "to": [9, 6], "pos": [186, 178], "probability": 1 / 3, "note": "damaged teleport"},
    {"script": 203, "to": [8, 8], "pos": [108, 125], "probability": 2 / 3, "note": "damaged teleport"},
]
TELEPORT_MENU = [  # script 240 (hub terminal); destinations need their password
    ("Zapomniana Świątynia", "Forgotten Temple", [7, 0], [22, 83], True),
    ("Zaświaty", "Netherworld", [7, 8], [38, 178], False),
    ("Otchłań", "Abyss", [1, 6], [27, 64], False),
    ("Ukryta Dolina", "Hidden Valley", [4, 2], [100, 121], False),
    ("Kraina Grozy", "Land of Terror", [1, 1], [94, 26], False),
    ("Sala treningowa", "Training Room", [5, 5], [124, 26], True),
]
CLASS_NAMES = {0x08: "inert", 0x10: "harmful", 0x20: "usable", 0x40: "solid"}
CLASS_COLOURS = {0x08: (170, 170, 170), 0x10: (255, 70, 70), 0x20: (80, 255, 80), 0x40: (80, 220, 255)}


# ---------------------------------------------------------------------------
# collision masks
# ---------------------------------------------------------------------------
def tile_masks(room, types, boxes, seqs):
    """Per-pixel masks of one room: 1 = solid, 2 = harmful, from the static tile map (DATA32 types +
    DATA38 boxes).  Animated tiles never block: TileCollide reads only the NEWROOM map and
    TileAnim_Overlaps answers only the hero's harm test (mask 0x11), so an animated tile adds harm
    (if any frame of its sequence is harmful) but no solidity."""
    m = bytearray(W * H)

    def paint(c, r, t, val):
        x0, y0, x1, y1 = (v & 0xFF for v in boxes[t])
        for y in range(r * L.PL_TH + y0, min(r * L.PL_TH + y1 + 1, H)):
            for x in range(c * L.PL_TW + x0, min(c * L.PL_TW + x1 + 1, W)):
                if m[y * W + x] != 1:
                    m[y * W + x] = val

    for r in range(L.MAP_H):
        for c in range(L.MAP_W):
            t = room.tiles[r][c]
            if 0 < t < len(types) and types[t] != 2:
                paint(c, r, t, 1 if types[t] == 4 else 2)
    for (c, r, _fg, seq, _start) in room.tile_anims:
        for t in (seqs[seq] if seq < len(seqs) else []):
            if 0 < t < len(types) and types[t] == 1:
                paint(c, r, t, 2)
    return m


def fake_walls(rooms, types, seqs):
    """Animated tiles that look solid (a frame of type 4) over a cell that does not block: the hero
    walks through them, and foreground ones are drawn over him - the game's secret passages."""
    out = []
    for (col, row), room in sorted(rooms.items(), key=lambda kv: (kv[0][1], kv[0][0])):
        for (c, r, fg, seq, _start) in room.tile_anims:
            s = seqs[seq] if seq < len(seqs) else []
            under = room.tiles[r][c]
            if any(0 < t < len(types) and types[t] == 4 for t in s) and not (0 < under < len(types)
                                                                               and types[under] == 4):
                out.append({"room": [col, row], "cell": [c, r], "foreground": fg, "sequence": seq,
                            "tile": s[0] if s else None, "map_tile_below": under})
    return out


def runs(free):
    """[(start, end_inclusive)] of consecutive True values."""
    out, s = [], None
    for i, f in enumerate(free + [False]):
        if f and s is None:
            s = i
        elif not f and s is not None:
            out.append((s, i - 1))
            s = None
    return out


# ---------------------------------------------------------------------------
# objects
# ---------------------------------------------------------------------------
def simulate_path(o, max_ticks=4000):
    """Positions (x, y) of the object's top-left for every tick of one pass through its path
    (v += a; pos += v), as lists per step: [(step_index, hidden, [(x, y), ...]), ...]."""
    out, total = [], 0
    for si, s in enumerate(o.steps):
        x, y, vx, vy = s.x, s.y, s.vx, s.vy
        pts = [(x / 65536, y / 65536)]
        for _ in range(s.duration):
            vx += s.ax
            vy += s.ay
            x += vx
            y += vy
            pts.append((x / 65536, y / 65536))
        out.append((si, s.hidden, pts))
        total += s.duration
        if total > max_ticks:
            break
    return out


def object_box(o, frames, groups, step=0):
    """Collision box (x0, y0, x1, y1) in room pixels of the object's first frame at a path step."""
    if not o.steps:
        return None
    s = o.steps[step]
    g = groups[s.anim] if s.anim < len(groups) else []
    if not g:
        return None
    f = frames[g[0]]
    x, y = s.pos
    bx0, by0, bx1, by1 = f.box
    if bx1 < bx0 or by1 < by0:
        bx0, by0, bx1, by1 = 0, 0, f.width - 1, f.height - 1
    return (x + bx0, y + by0, x + bx1, y + by1)


def path_summary(o):
    sim = simulate_path(o)
    pts = [p for _, _, ps in sim for p in ps]
    speeds = []
    for _, _, ps in sim:
        speeds += [((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2) ** 0.5 for a, b in zip(ps, ps[1:])]
    xs, ys = [p[0] for p in pts], [p[1] for p in pts]
    return {"ticks": sum(s.duration for s in o.steps),
            "bbox": [round(min(xs), 1), round(min(ys), 1), round(max(xs), 1), round(max(ys), 1)] if pts else None,
            "max_speed": round(max(speeds), 3) if speeds else 0.0,
            "moves": bool(speeds and max(speeds) > 0)}


def warp_sources(rooms):
    """Objects that fire a teleporting script: {script: [(col,row,object index), ...]}."""
    want = {w["script"] for w in WARPS} | {240}
    out = {}
    for (c, r), room in sorted(rooms.items()):
        for o in room.objects:
            if o.flags & 0x4000 and o.target in want:
                out.setdefault(o.target, []).append((c, r, o.index))
    return out


# ---------------------------------------------------------------------------
# connectivity
# ---------------------------------------------------------------------------
def analyse(game_dir, rooms=None, frames=None, groups=None, seqs=None):
    rooms = rooms or L.load_rooms(game_dir)
    if frames is None:
        frames, groups = L.load_bobs(game_dir)
    if seqs is None:
        seqs = L.load_tile_anim_sequences(os.path.join(game_dir, "LAZARUS.EXE"))
    types, boxes = L.load_tile_types(game_dir), L.load_tile_boxes(game_dir)
    masks = {k: tile_masks(rm, types, boxes, seqs) for k, rm in rooms.items()}

    solids = {}
    for k, rm in rooms.items():
        solids[k] = []
        for o in rm.objects:
            if o.collision_class & 0x40 and o.steps:
                bxs = [object_box(o, frames, groups, i) for i in range(len(o.steps))]
                solids[k].append((o, [b for b in bxs if b]))

    def gates(k, band, span, horizontal):
        """Solid objects of room k whose box (at any path step) covers part of the opening."""
        hit = []
        (bx0, by0, bx1, by1), (s0, s1) = band, span
        for o, bxs in solids[k]:
            for (x0, y0, x1, y1) in bxs:
                if x1 < bx0 or x0 > bx1 or y1 < by0 or y0 > by1:
                    continue
                if (horizontal and not (y1 < s0 or y0 > s1)) or (not horizontal and not (x1 < s0 or x0 > s1)):
                    hit.append({"room": list(k), "object": o.index,
                                "sprite_group": o.steps[0].anim,
                                "name": N.SPRITE_GROUPS.get(o.steps[0].anim)})
                    break
        return hit

    def dedupe(g):
        seen, out = set(), []
        for x in g:
            if (tuple(x["room"]), x["object"]) not in seen:
                seen.add((tuple(x["room"]), x["object"]))
                out.append(x)
        return out

    edges = []
    for r in range(10):
        for c in range(10):
            a = masks[(c, r)]
            if c < 9:                               # a | b, the hero sweeps HERO_W px on each side
                b = masks[(c + 1, r)]
                free = [not any(a[y * W + x] == 1 for x in range(W - HERO_W, W)) and
                        not any(b[y * W + x] == 1 for x in range(HERO_W)) for y in range(H)]
                rs = [s for s in runs(free) if s[1] - s[0] + 1 >= HERO_H]
                g = []
                for s in rs:
                    g += gates((c, r), (W - HERO_W - 8, 0, W - 1, H - 1), s, True)
                    g += gates((c + 1, r), (0, 0, HERO_W + 8, H - 1), s, True)
                edges.append({"a": [c, r], "b": [c + 1, r], "dir": "east",
                              "open": bool(rs), "openings_y": [list(s) for s in rs], "gated_by": dedupe(g)})
            if r < 9:
                b = masks[(c, r + 1)]
                free = [not any(a[y * W + x] == 1 for y in range(H - HERO_H, H)) and
                        not any(b[y * W + x] == 1 for y in range(HERO_H)) for x in range(W)]
                rs = [s for s in runs(free) if s[1] - s[0] + 1 >= HERO_W]
                g = []
                for s in rs:
                    g += gates((c, r), (0, H - HERO_H - 8, W - 1, H - 1), s, False)
                    g += gates((c, r + 1), (0, 0, W - 1, HERO_H + 8), s, False)
                edges.append({"a": [c, r], "b": [c, r + 1], "dir": "south",
                              "open": bool(rs), "openings_x": [list(s) for s in rs], "gated_by": dedupe(g)})

    # union-find over open edges
    parent = {k: k for k in rooms}

    def find(k):
        while parent[k] != k:
            parent[k] = parent[parent[k]]
            k = parent[k]
        return k

    for e in edges:
        if e["open"]:
            ka, kb = find(tuple(e["a"])), find(tuple(e["b"]))
            if ka != kb:
                parent[ka] = kb
    comps = {}
    for k in sorted(rooms, key=lambda k: (k[1], k[0])):
        comps.setdefault(find(k), []).append(k)

    # name regions after the teleport destinations they contain
    dest_names = {tuple(t[2]): (t[0], t[1]) for t in TELEPORT_MENU}
    dest_names[(0, 0)] = ("Węzeł teleportów", "Teleport hub")
    regions = []
    for members in sorted(comps.values(), key=lambda m: (-len(m), m[0][1], m[0][0])):
        names = [dest_names[k] for k in members if k in dest_names]
        pl, en = names[0] if names else ("", "")
        regions.append({"id": len(regions), "name_pl": pl, "name_en": en, "rooms": [list(k) for k in members]})
    region_of = {tuple(k): rg["id"] for rg in regions for k in rg["rooms"]}

    src = warp_sources(rooms)
    warps = []
    for w in WARPS:
        for (c, r, i) in src.get(w["script"], []):
            warps.append(dict(w, **{"from": [c, r], "object": i}))
    for (c, r, i) in src.get(240, []):
        for pl, en, room, pos, known in TELEPORT_MENU:
            warps.append({"script": 240, "from": [c, r], "object": i, "to": room, "pos": pos,
                          "note": f"hub terminal menu: {pl}" + ("" if known else " (password needed)")})
    for w in warps:
        w["from_region"], w["to_region"] = region_of[tuple(w["from"])], region_of[tuple(w["to"])]

    return {"rooms": rooms, "frames": frames, "groups": groups, "seqs": seqs, "types": types,
            "boxes": boxes, "masks": masks, "edges": edges, "regions": regions,
            "region_of": region_of, "warps": warps, "fake_walls": fake_walls(rooms, types, seqs)}


def world_graph_json(an):
    return {
        "note": "Room-to-room connectivity computed from tile collision (DATA32 types + DATA38 boxes, animated "
                "tiles never block). An edge is open when a gap at least as large as the hero box "
                f"({HERO_W}x{HERO_H} px) exists across the shared border; openings_x/_y are pixel ranges along "
                "the border. gated_by lists solid objects (doors, lifts, force fields) overlapping an opening. "
                "Vertical edges may be one-way without the jetpack. Regions are connected components of open "
                "edges; warps are the scripted teleports between them. fake_walls are animated tiles that look "
                "solid but are not (secret passages; foreground ones hide the hero).",
        "hero_box": list(HERO_BOX),
        "regions": an["regions"],
        "edges": an["edges"],
        "warps": an["warps"],
        "fake_walls": an["fake_walls"],
        "teleport_menu": [{"name_pl": t[0], "name_en": t[1], "room": t[2], "pos": t[3], "known_at_start": t[4]}
                          for t in TELEPORT_MENU],
    }


# ---------------------------------------------------------------------------
# renders
# ---------------------------------------------------------------------------
REGION_COLOURS = [(230, 25, 75), (60, 180, 75), (255, 225, 25), (0, 130, 200), (245, 130, 48),
                  (145, 30, 180), (70, 240, 240), (240, 50, 230), (210, 245, 60), (250, 190, 190),
                  (0, 128, 128), (170, 110, 40)]


def render_regions(an, world_png, dst):
    """Half-size world map tinted per region, open edges green, gated edges cyan, warps as arrows."""
    base = Image.open(world_png).convert("RGB")
    s = 2
    img = base.resize((base.width // s, base.height // s), Image.LANCZOS)
    w, h = W // s, H // s
    tint = Image.new("RGB", img.size)
    td = ImageDraw.Draw(tint)
    for rg in an["regions"]:
        col = REGION_COLOURS[rg["id"] % len(REGION_COLOURS)]
        for c, r in rg["rooms"]:
            td.rectangle([c * w, r * h, c * w + w - 1, r * h + h - 1], fill=col)
    img = Image.blend(img, tint, 0.35)
    d = ImageDraw.Draw(img)
    for c in range(10):
        for r in range(10):
            d.rectangle([c * w, r * h, c * w + w - 1, r * h + h - 1], outline=(0, 0, 0))
    for e in an["edges"]:
        (ca, ra) = e["a"]
        col = (80, 220, 255) if e["gated_by"] else (60, 255, 60)
        if e["dir"] == "east":
            x = (ca + 1) * w
            for y0, y1 in e["openings_y"]:
                d.rectangle([x - 2, ra * h + y0 // s, x + 1, ra * h + y1 // s], fill=col)
        else:
            y = (ra + 1) * h
            for x0, x1 in e["openings_x"]:
                d.rectangle([ca * w + x0 // s, y - 2, ca * w + x1 // s, y + 1], fill=col)
    for rg in an["regions"]:
        if rg["name_en"]:
            c, r = rg["rooms"][0]
            label = f"{rg['id']}: {rg['name_en']}"
            d.rectangle([c * w + 2, r * h + 2, c * w + 6 + 6 * len(label), r * h + 14], fill=(0, 0, 0))
            d.text((c * w + 4, r * h + 3), label, fill=(255, 255, 255))
    seen = set()
    for wp in an["warps"]:
        key = (tuple(wp["from"]), tuple(wp["to"]))
        if key in seen or wp["from"] == wp["to"]:
            continue
        seen.add(key)
        (fc, fr), (tc, tr) = wp["from"], wp["to"]
        p0 = (fc * w + w // 2, fr * h + h // 2)
        p1 = (tc * w + wp["pos"][0] // s, tr * h + wp["pos"][1] // s)
        col = (255, 255, 255) if wp["script"] != 240 else (255, 200, 0)
        d.line([p0, p1], fill=col, width=1)
        d.ellipse([p1[0] - 3, p1[1] - 3, p1[0] + 3, p1[1] + 3], outline=col, width=2)
    for c in range(10):
        for r in range(10):
            d.text((c * w + w - 24, r * h + h - 12), f"{c},{r}", fill=(255, 255, 0))
    img.save(dst)


def render_room_debug(an, room, room_png, dst, scale=2):
    """Room art darkened, solid tile boxes blue, harmful red, animated tiles yellow (fake walls magenta),
    objects' boxes and full paths in class colours (dotted while hidden), object index labels,
    open room edges green (cyan when a solid object such as a door overlaps the opening)."""
    base = Image.open(room_png).convert("RGB").resize((W * scale, H * scale), Image.NEAREST)
    base = Image.eval(base, lambda v: v * 45 // 100)
    ov = Image.new("RGBA", base.size, (0, 0, 0, 0))
    d = ImageDraw.Draw(ov)
    m = an["masks"][(room.col, room.row)]
    for y in range(H):
        for x in range(W):
            v = m[y * W + x]
            if v:
                d.rectangle([x * scale, y * scale, x * scale + scale - 1, y * scale + scale - 1],
                            fill=(40, 90, 255, 120) if v == 1 else (255, 40, 40, 140))
    fake = {tuple(f["cell"]) for f in an["fake_walls"] if f["room"] == [room.col, room.row]}
    for (c, r, _fg, _seq, _st) in room.tile_anims:
        d.rectangle([c * L.PL_TW * scale, r * L.PL_TH * scale, (c + 1) * L.PL_TW * scale - 1,
                     (r + 1) * L.PL_TH * scale - 1],
                    outline=(255, 0, 255, 255) if (c, r) in fake else (255, 255, 0, 140),
                    width=2 if (c, r) in fake else 1)
    frames, groups = an["frames"], an["groups"]
    labels = []
    for o in room.objects:
        if not o.steps:
            continue
        cls = o.collision_class
        col = CLASS_COLOURS.get(cls, (255, 255, 255))
        b0 = object_box(o, frames, groups, 0)
        ox = oy = 0
        if b0:
            ox, oy = (b0[0] + b0[2]) / 2 - o.steps[0].pos[0], (b0[1] + b0[3]) / 2 - o.steps[0].pos[1]
        for si, hidden, pts in simulate_path(o):
            sp = [((x + ox) * scale, (y + oy) * scale) for x, y in pts]
            if len(sp) > 1:
                if hidden:
                    for i in range(0, len(sp) - 1, 4):
                        d.line(sp[i:i + 3], fill=col + (200,), width=1)
                else:
                    d.line(sp, fill=col + (230,), width=1)
            x, y = sp[0]
            d.rectangle([x - 1, y - 1, x + 1, y + 1], fill=col + (255,))
        if b0:
            alpha = 120 if o.flags & 0x0008 or not o.flags & 0x0001 else 255
            d.rectangle([b0[0] * scale, b0[1] * scale, b0[2] * scale + scale - 1, b0[3] * scale + scale - 1],
                        outline=col + (alpha,), width=1)
            labels.append((b0[0] * scale + 1, b0[1] * scale + 1, str(o.index), col))
    k = (room.col, room.row)
    for e in an["edges"]:
        if tuple(e["a"]) == k or tuple(e["b"]) == k:
            col = (80, 220, 255, 255) if e["gated_by"] else (60, 255, 60, 255)
            if e["dir"] == "east":
                x = W * scale - 3 if tuple(e["a"]) == k else 0
                for y0, y1 in e["openings_y"]:
                    d.rectangle([x, y0 * scale, x + 2, y1 * scale], fill=col)
            else:
                y = H * scale - 3 if tuple(e["a"]) == k else 0
                for x0, x1 in e["openings_x"]:
                    d.rectangle([x0 * scale, y, x1 * scale, y + 2], fill=col)
    for x, y, t, col in labels:
        d.rectangle([x, y, x + 6 * len(t) + 1, y + 10], fill=(0, 0, 0, 200))
        d.text((x + 1, y), t, fill=col + (255,))
    d.text((4, H * scale - 14), f"room {room.col},{room.row}  region {an['region_of'][k]}",
           fill=(255, 255, 255, 255))
    out = Image.alpha_composite(base.convert("RGBA"), ov).convert("RGB")
    out.quantize(colors=96, method=Image.MEDIANCUT, dither=Image.NONE).save(dst, optimize=True)


def render_world_collision(an, dst):
    """Whole world, collision only: solid blue, harmful red, object paths in class colours."""
    pal = [0, 0, 0, 30, 70, 200, 220, 40, 40, 40, 40, 40]
    cls_idx = {}
    for i, (cls, col) in enumerate(CLASS_COLOURS.items()):
        cls_idx[cls] = 4 + i
        pal += list(col)
    pal += [60, 255, 60]                         # 8: open edge
    pal += [0] * (768 - len(pal))
    img = Image.new("P", (10 * W, 10 * H), 0)
    img.putpalette(pal)
    px = img.load()
    for (c, r), m in an["masks"].items():
        for y in range(H):
            row = y * W
            for x in range(W):
                if m[row + x]:
                    px[c * W + x, r * H + y] = m[row + x]
    d = ImageDraw.Draw(img)
    for c in range(11):
        d.line([(c * W, 0), (c * W, 10 * H)], fill=3)
    for r in range(11):
        d.line([(0, r * H), (10 * W, r * H)], fill=3)
    for (c, r), room in an["rooms"].items():
        for o in room.objects:
            fill = cls_idx.get(o.collision_class, 4)
            b0 = object_box(o, an["frames"], an["groups"], 0)
            ox = oy = 0
            if b0:
                ox, oy = (b0[0] + b0[2]) / 2 - o.steps[0].pos[0], (b0[1] + b0[3]) / 2 - o.steps[0].pos[1]
                d.rectangle([c * W + b0[0], r * H + b0[1], c * W + b0[2], r * H + b0[3]], outline=fill)
            for _si, _hidden, pts in simulate_path(o):
                if len(pts) > 1:
                    d.line([(c * W + x + ox, r * H + y + oy) for x, y in pts], fill=fill)
    for e in an["edges"]:
        (ca, ra) = e["a"]
        if e["dir"] == "east":
            for y0, y1 in e["openings_y"]:
                d.rectangle([(ca + 1) * W - 1, ra * H + y0, (ca + 1) * W, ra * H + y1], fill=8)
        else:
            for x0, x1 in e["openings_x"]:
                d.rectangle([ca * W + x0, (ra + 1) * H - 1, ca * W + x1, (ra + 1) * H], fill=8)
    img.save(dst, optimize=True)


def export_world(game_dir, out, rooms=None, frames=None, groups=None, seqs=None):
    an = analyse(game_dir, rooms, frames, groups, seqs)
    gd = os.path.join(out, "gamedata")
    os.makedirs(gd, exist_ok=True)
    with open(os.path.join(gd, "world_graph.json"), "w", encoding="utf-8") as f:
        json.dump(world_graph_json(an), f, ensure_ascii=False, indent=1)
    rd = os.path.join(out, "rooms")
    dd = os.path.join(rd, "debug")
    os.makedirs(dd, exist_ok=True)
    render_regions(an, os.path.join(rd, "world_map_objects.png"), os.path.join(rd, "world_regions.png"))
    render_world_collision(an, os.path.join(rd, "world_collision.png"))
    for (c, r), room in sorted(an["rooms"].items()):
        render_room_debug(an, room, os.path.join(rd, "png", f"room_{c}_{r}.png"),
                          os.path.join(dd, f"room_{c}_{r}.png"))
    return an


if __name__ == "__main__":
    a = export_world(sys.argv[1], sys.argv[2])
    for rg in a["regions"]:
        print(rg["id"], rg["name_en"], len(rg["rooms"]), rg["rooms"])
