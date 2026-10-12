"""Parsers for the Lazarus (1996, Infinite Dreams) DATAxx.RES resource files.

Everything here was recovered by reverse engineering LAZARUS.EXE; see
docs/reverse-engineering/ for the format write-ups.  Only the Python standard
library is required (numpy/Pillow are used by the exporters, not here).
"""
import os
import struct

# ---------------------------------------------------------------------------
# Resource file map (DATAxx.RES -> original name / purpose)
# ---------------------------------------------------------------------------
RESOURCES = {
    "DATA01.RES": "background tiles 32x38, Mode X planar (120 tiles)",
    "DATA02.RES": "BOBY.BIN - sprite (BOB) frame pixel data",
    "DATA03.RES": "bob_make.bin - sprite frame descriptors / animation groups",
    "DATA04.RES": "FLC 320x240 - credits (AUTORZY) animation",
    "DATA05.RES": "FLC 320x200 - intro part",
    "DATA06.RES": "FLC 320x200 - intro part (92 frames)",
    "DATA07.RES": "FLC 320x200 - intro part (51 frames)",
    "DATA08.RES": "FLC 320x200 - intro part (60 frames)",
    "DATA09.RES": "FLC 320x200 - intro part",
    "DATA10.RES": "FLC 320x240 - intro part",
    "DATA11.RES": "FLC 320x200 - intro part",
    "DATA12.RES": "FLI 320x200 - intro part",
    "DATA13.RES": "FLC 320x240 - intro part",
    "DATA14.RES": "FLC 320x240 - intro part",
    "DATA15.RES": "FLC 320x240 - intro part",
    "DATA16.RES": "palette (alarm / bomb countdown)",
    "DATA17.RES": "FLC 320x240 - intro (game-world arrival, speech bubbles)",
    "DATA18.RES": "unused older copy of tile type table",
    "DATA19.RES": "palette",
    "DATA20.RES": "PCX 640x480x16 - picture (game over / end screen)",
    "DATA21.RES": "PCX 640x480x16 - 'happy ending' picture (witch's herbs)",
    "DATA22.RES": "PCX 264x90x16 - checked by the DOS stub (integrity check)",
    "DATA23.RES": "MOD 'multifruit juice' - in-game / menu music",
    "DATA24.RES": "KLOCKI.DAT - platform tiles 16x19, Mode X planar (560 tiles)",
    "DATA25.RES": "palette - main game palette",
    "DATA26.RES": "proportional font (dialogue text)",
    "DATA27.RES": "palette - full-screen pictures (maps, riddles)",
    "DATA28.RES": "palette - title menu",
    "DATA29.RES": "NEWROOM.BIN - 10x10 room maps",
    "DATA30.RES": "OBJECTS.BIN - room objects (enemies, items, NPCs, triggers)",
    "DATA31.RES": "HUD side panel 76x240, Mode X planar",
    "DATA32.RES": "tile type table (0=solid,1=harmful,2=passable)",
    "DATA33.RES": "PCX 320x400x256 - intro still",
    "DATA34.RES": "PCX 320x200x256 - intro still",
    "DATA35.RES": "PCX 320x200x256 - intro still",
    "DATA36.RES": "PCX 320x400x256 - intro still",
    "DATA37.RES": "unused older copy of PSIZES.BIN",
    "DATA38.RES": "PSIZES.BIN - per-tile collision boxes",
    "DATA39.RES": "MOD 'recollection' - intro / ending music",
    "DATA40.RES": "PCX 640x2080x16 - end credits scroller",
    "DATA41.RES": "sound effects bank",
}

ROOM_COLS = ROOM_ROWS = 10
MAP_W, MAP_H = 14, 12          # platform tile grid per room
BG_W, BG_H = 7, 6              # background tile grid per room
PL_TW, PL_TH = 16, 19          # platform tile size
BG_TW, BG_TH = 32, 38          # background tile size
ROOM_PX_W, ROOM_PX_H = MAP_W * PL_TW, MAP_H * PL_TH   # 224 x 228
ROOM_RECORD = 458


def _read(game_dir, name):
    with open(os.path.join(game_dir, name), "rb") as f:
        return f.read()


# ---------------------------------------------------------------------------
# Palettes
# ---------------------------------------------------------------------------
def load_palette(game_dir, name="DATA25.RES"):
    """768-byte VGA palette (6-bit components) -> list of 256 (r,g,b) 8-bit."""
    d = _read(game_dir, name)[:768]
    return [tuple((d[i * 3 + k] * 255) // 63 for k in range(3)) for i in range(256)]


# ---------------------------------------------------------------------------
# Mode X planar tiles
# ---------------------------------------------------------------------------
def planar_to_linear(buf, w, h):
    """4 planes x h rows x (w/4) bytes -> h rows of w pixel indices."""
    bpr = w // 4
    out = bytearray(w * h)
    for p in range(4):
        base = p * h * bpr
        for y in range(h):
            row = base + y * bpr
            for b in range(bpr):
                out[y * w + b * 4 + p] = buf[row + b]
    return bytes(out)


def load_tiles(game_dir, name, w, h):
    d = _read(game_dir, name)
    sz = w * h
    return [planar_to_linear(d[i * sz:(i + 1) * sz], w, h) for i in range(len(d) // sz)]


def load_platform_tiles(game_dir):
    return load_tiles(game_dir, "DATA24.RES", PL_TW, PL_TH)


def load_background_tiles(game_dir):
    return load_tiles(game_dir, "DATA01.RES", BG_TW, BG_TH)


def load_hud(game_dir):
    return planar_to_linear(_read(game_dir, "DATA31.RES"), 76, 240)


def load_tile_types(game_dir):
    """DATA32: one byte per platform tile. The game replaces 0 by 4.
    4 = solid, 1 = harmful (hurts the hero), 2 = passable/decoration."""
    return [4 if b == 0 else b for b in _read(game_dir, "DATA32.RES")]


def load_tile_boxes(game_dir):
    """DATA38 (PSIZES.BIN): per tile 4 big-endian words x0,y0,x1,y1
    (collision rectangle inside the 16x19 cell)."""
    d = _read(game_dir, "DATA38.RES")
    return [struct.unpack_from(">4H", d, i * 8) for i in range(len(d) // 8)]


# ---------------------------------------------------------------------------
# Sprites (BOBs)
# ---------------------------------------------------------------------------
class BobFrame:
    __slots__ = ("index", "duration", "offset", "box", "width", "height", "pixels")


def load_bobs(game_dir):
    """Returns (frames, groups).

    frames: list indexed by descriptor index (separators are None).
    groups: list of animation groups, each a list of descriptor indices.
    """
    desc = _read(game_dir, "DATA03.RES")
    data = _read(game_dir, "DATA02.RES")
    _, count, _ = struct.unpack_from("<3I", desc, 0)
    frames, groups = [], [[]]
    for i in range(count):
        dur, off, x0, y0, x1, y1 = struct.unpack_from("<bI4B", desc, 12 + i * 9)
        if dur == -1:
            frames.append(None)
            groups.append([])
            continue
        f = BobFrame()
        f.index, f.duration, f.offset, f.box = i, dur, off, (x0, y0, x1, y1)
        bw, h = data[off], data[off + 1]
        f.width, f.height = bw * 4, h
        f.pixels = planar_to_linear(data[off + 2:off + 2 + bw * 4 * h], bw * 4, h)
        frames.append(f)
        groups[-1].append(i)
    return frames, groups


# ---------------------------------------------------------------------------
# Rooms (NEWROOM.BIN)
# ---------------------------------------------------------------------------
class Room:
    def __init__(self, col, row, raw):
        self.col, self.row = col, row
        self.tile_anims = []   # (col, row, foreground, sequence, start)
        for i in range(20):
            c, r, seq, start = raw[i * 4:i * 4 + 4]
            if seq == 0xFF:
                continue
            self.tile_anims.append((c & 0x7F, r, bool(c & 0x80), seq, start))
        self.background = [list(raw[0x50 + y * 7:0x57 + y * 7]) for y in range(BG_H)]
        self.tiles = [[struct.unpack_from(">H", raw, 0x7A + (y * MAP_W + x) * 2)[0]
                       for x in range(MAP_W)] for y in range(MAP_H)]
        self.objects = []


def load_rooms(game_dir):
    d = _read(game_dir, "DATA29.RES")
    rooms = {}
    for row in range(ROOM_ROWS):
        for col in range(ROOM_COLS):
            off = (row * ROOM_COLS + col) * ROOM_RECORD
            rooms[(col, row)] = Room(col, row, d[off:off + ROOM_RECORD])
    for (col, row), objs in load_objects(game_dir).items():
        rooms[(col, row)].objects = objs
    return rooms


# ---------------------------------------------------------------------------
# Tile animation sequences (hard-coded table in LAZARUS.EXE at 0x50004)
# ---------------------------------------------------------------------------
def load_tile_anim_sequences(exe_path):
    """76 sequences of platform tile ids; one entry per game tick (50 Hz)."""
    import sys
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from le_loader import LEFile
    le = LEFile(exe_path)
    p, seqs = 0x50004, []
    for _ in range(76):
        p += 2                       # skip header word
        s = []
        while True:
            v = struct.unpack("<h", le.read(p, 2))[0]
            p += 2
            if v == -1:
                break
            s.append(v)
        seqs.append(s)
    return seqs


# ---------------------------------------------------------------------------
# Room objects (OBJECTS.BIN)
# ---------------------------------------------------------------------------
END_MODES = {0: "stop", 1: "vanish", 2: "loop-from", 3: "disable-forever"}


class PathStep:
    """32-byte keyframe.  Motion is integrated every tick:
    v += a; pos += v  (all 16.16 fixed point) for `duration` ticks."""

    def __init__(self, raw):
        (self.ax, self.ay, self.vx, self.vy, self.x, self.y,
         w_dur, w_anim, w_ofs, w_snd) = struct.unpack(">6i4H", raw)
        self.duration = w_dur & 0x3FF
        self.trigger_object = (w_dur >> 10) & 0x1F if w_dur & 0x8000 else None
        self.anim = w_anim & 0x7FFF
        self.anim_flag = bool(w_anim & 0x8000)  # masked off by the engine (editor-only)
        self.anim_start = w_ofs & 0x7FFF
        self.hidden = bool(w_ofs & 0x8000)     # object not drawn during this step
        self.sound_cmd = (w_snd >> 11) & 7     # 1 = play, 3 = stop
        self.sound = w_snd & 0x3FF

    @property
    def pos(self):
        return (self.x >> 16, self.y >> 16)


class RoomObject:
    """14-byte header + N path steps."""

    def __init__(self, index, hdr, steps):
        self.index = index
        self.raw_header = hdr
        self.loop_start = hdr[0]
        self.step_count = hdr[1]
        self.interact = hdr[2]          # bit1: needs item hdr[13] selected; bit2: activate by crouching
        self.end_mode = hdr[3]
        self.activate_sound = hdr[5]
        self.flags = struct.unpack(">H", hdr[6:8])[0]
        self.hp = hdr[8]
        self.hp_max = hdr[9]
        self.activate_anim = struct.unpack(">h", hdr[10:12])[0]
        self.target = hdr[12]           # <20: object index to trigger; >=20: script id
        self.item = hdr[13]             # required item / game flag index
        self.steps = steps

    @property
    def collision_class(self):
        """Bitmask: 0x08 shootable, 0x10 harmful, 0x20 usable, 0x40 solid."""
        return (self.flags & 0x3C00) >> 7

    def describe_flags(self):
        f, names = self.flags, []
        table = [(0x0001, "active"), (0x0002, "bit1"), (0x0004, "needs-flag"), (0x0008, "invisible"),
                 (0x0010, "chain-next"), (0x0020, "touch-activates"), (0x0040, "disabled"),
                 (0x0080, "keep-after-use"), (0x0100, "rearm"), (0x4000, "fires-trigger"),
                 (0x8000, "conditional")]
        for bit, n in table:
            if f & bit:
                names.append(n)
        return names


def load_objects(game_dir):
    d = _read(game_dir, "DATA30.RES")
    p, rooms = 0, {}
    for row in range(ROOM_ROWS):
        for col in range(ROOM_COLS):
            n = struct.unpack_from(">H", d, p)[0]
            p += 10
            objs = []
            for k in range(n):
                hdr = d[p:p + 14]
                m = hdr[1]
                steps = [PathStep(d[p + 14 + s * 32:p + 14 + (s + 1) * 32]) for s in range(m)]
                objs.append(RoomObject(k, hdr, steps))
                p += 14 + m * 32
            rooms[(col, row)] = objs
    return rooms
