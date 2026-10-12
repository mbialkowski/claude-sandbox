"""Reference implementation of the rules that move things in Lazarus, transcribed from the decompilation
(reference/lazarus.c), and the golden traces a remake can be tested against.

* Tile collision     TileCollide 0x230FC, Hero_MoveCollide 0x232C4
* Hero               HeroState00-09 (stand, walk, jump, fall, jetpack; both facings)
* Room objects       RoomObject_ResetPath 0x21958, Object_Think 0x23F4C, BobFindFrame 0x21884

Not modelled: solid objects (lifts/doors) pushing or carrying the hero, crouch, teleport states,
object activation (deaths, triggers). Integer and 16.16 arithmetic is reproduced exactly, including
Python-vs-C differences (C division truncates toward zero, >> is arithmetic).

    python3 tools/reference_sim.py original/ assets/gamedata/golden_traces.json
"""
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402

FIX = 1 << 16


def cdiv(a, b):
    """C integer division (truncates toward zero)."""
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q


def s32(v):
    v &= 0xFFFFFFFF
    return v - (1 << 32) if v & 0x80000000 else v


class World:
    def __init__(self, game_dir):
        self.rooms = L.load_rooms(game_dir)
        raw = open(os.path.join(game_dir, "DATA32.RES"), "rb").read()
        raw = raw + bytes(660 - len(raw))                      # the game reads 660 bytes into a zeroed buffer
        self.types = [4 if b == 0 else b for b in raw]
        self.boxes = [tuple(v & 0xFF for v in b) for b in L.load_tile_boxes(game_dir)]
        self.desc = self._load_desc(game_dir)
        self.override = {}                                    # (col,row) -> 12x14 tile grid for test rooms

    @staticmethod
    def _load_desc(game_dir):
        d = open(os.path.join(game_dir, "DATA03.RES"), "rb").read()
        _, count, _ = struct.unpack_from("<3I", d, 0)
        return [struct.unpack_from("<bI4B", d, 12 + i * 9) for i in range(count)]   # dur, off, x0,y0,x1,y1

    def tile(self, col, row, tx, ty):
        if (col, row) in self.override:
            return self.override[(col, row)][ty][tx]
        room = self.rooms.get((col, row))
        return room.tiles[ty][tx] if room else 0

    def tile_collide(self, room, x0, y0, x1, y1, tx, ty):
        """TileCollide: 0 free, 1 harmful (hero hit), 2 solid.  (tx,ty) may lie outside the room by one
        tile; the neighbouring room's edge tile is used then."""
        col, row = room
        dc = dr = 0
        cx, cy = tx, ty
        if tx < 0:
            dc, cx = -1, 13
        elif tx > 13:
            dc, cx = 1, 0
        if ty < 0:
            dr, cy = -1, 11
        elif ty > 11:
            dr, cy = 1, 0
        t = self.tile(col + dc, row + dr, cx % 14, cy % 12)
        kind = self.types[t]
        if kind == 2:
            return 0
        bx0, by0, bx1, by1 = self.boxes[t] if t < len(self.boxes) else (0, 0, 0, 0)
        if tx * 16 + bx1 < x0 or x1 < tx * 16 + bx0 or ty * 19 + by1 < y0 or y1 < ty * 19 + by0:
            return 0
        return 1 if kind == 1 else 2


# ---------------------------------------------------------------------------
# hero
# ---------------------------------------------------------------------------
STAND, WALK, JUMP, FALL, JET = 0, 2, 4, 6, 8
ENTRY_FRAME = {0: 1025, 1: 1027, 2: 3, 3: 14, 4: 1005, 5: 1009, 6: 1005, 7: 1009, 8: 1005, 9: 1009}
GRAVITY, JUMP_V0, FALL_CAP = 0x3851, s32(0xFFFB1DF3), 0xA0000


class Hero:
    def __init__(self, world, room, x, y, state=0, fuel=0x2F0000):
        self.w, self.room = world, tuple(room)
        self.x, self.y = x, y
        self.fx, self.fy = x * FIX, y * FIX
        self.vx = self.vy = 0
        self.state, self.fresh = state, True                  # fresh = 0x6e == -1 (run state entry)
        self.frame, self.counter = ENTRY_FRAME[state], 0
        self.fuel, self.jet_on = fuel, False
        self.flags = 0
        self.hit = False

    # -- helpers ------------------------------------------------------------
    def box(self):
        _, _, x0, y0, x1, y1 = self.w.desc[self.frame]
        return x0, y0, x1, y1

    def set_frame(self, f):
        self.frame = f
        self.counter = self.w.desc[f][0]

    def animate(self):
        """Frame counter: a frame of duration d is shown for d+1 ticks; separators loop."""
        c = self.counter
        self.counter -= 1
        if c == 0:
            self.frame += 1
            dur, off = self.w.desc[self.frame][:2]
            self.counter = dur
            if dur == -1:
                skip, self.frame = off >> 16, off & 0xFFFF
                self.counter = self.w.desc[self.frame][0]
                while skip:
                    d = self.w.desc[self.frame][0]
                    if skip < d:
                        self.counter, skip = d - skip, 0
                    else:
                        skip -= d
                        self.frame += 1
                        self.counter = self.w.desc[self.frame][0]

    def blocked(self, x0, y0, x1, y1, tx0, ty0):
        for tx in range(tx0, tx0 + 3):
            for ty in range(ty0, ty0 + 3):
                r = self.w.tile_collide(self.room, x0, y0, x1, y1, tx, ty)
                if r == 1:
                    self.hit = True
                if r == 2:
                    return True
        return False

    def move_collide(self, dx, dy):
        """Hero_MoveCollide: X then Y, each all-or-nothing against the 3x3 tiles around the target box;
        sets flags 1 (x blocked) / 2 (y blocked); then room transitions."""
        bx0, by0, bx1, by1 = self.box()
        x0, y0, x1, y1 = self.x + bx0, self.y + by0, self.x + bx1, self.y + by1
        if not self.blocked(x0 + dx, y0, x1 + dx, y1, (x0 + dx) >> 4, cdiv(y0, 19)):
            self.x += dx
            x0, x1 = x0 + dx, x1 + dx
        else:
            self.flags |= 1
        if not self.blocked(x0, y0 + dy, x1, y1 + dy, cdiv(x0, 16), cdiv(y0 + dy, 19)):
            self.y += dy
        else:
            self.flags |= 2
        col, row = self.room
        moved = False
        if self.x + 11 < 0:
            if col < 1:
                self.x = -11
            else:
                col, self.x, moved = col - 1, 213, True
        if self.x + 11 > 224:
            if col < 9:
                col, self.x, moved = col + 1, -11, True
            else:
                self.x = 213
        if self.y < 0:
            if row < 1:
                self.y = 0
            else:
                row, self.y, moved = row - 1, 197, True
        if self.y + 15 > 228:
            if row < 9:
                row, self.y, moved = row + 1, 0, True
            else:
                self.y = 213
        if moved or (col, row) != self.room:
            self.room = (col, row)
            self.fx, self.fy = self.x * FIX, self.y * FIX

    def enter(self, state):
        self.state, self.fresh = state, True

    # -- one tick -----------------------------------------------------------
    def tick(self, ix, up, jet_on=None):
        """ix: -1/0/1 (left/right held), up: Up held, jet_on: jetpack switched on (Space toggles it)."""
        if jet_on is not None:
            self.jet_on = jet_on and self.fuel > 0
        iy = -1 if up else 0
        prev_y = self.y
        s, face = self.state & ~1, self.state & 1
        if self.fresh:
            self.fresh = False
            if s == JET:
                self.set_frame(ENTRY_FRAME[self.state])
                self.vy, self.vx = -2 * FIX, 0
                self.fx, self.fy = self.x * FIX, self.y * FIX
            elif s == WALK:
                self.set_frame(ENTRY_FRAME[self.state])
            else:
                self.set_frame(ENTRY_FRAME[self.state])
                if s == JUMP:
                    self.vy = JUMP_V0
        elif s in (WALK, JET):
            self.animate()
        self.flags = 0
        if s in (STAND, WALK):
            # HeroState00-03: pressing towards the facing side walks, the other side turns (stand),
            # releasing stops; Down (crouch) is not modelled
            self.move_collide(ix, 1)
            falling = self.y > prev_y
            toward = (ix < 0) if face == 0 else (ix > 0)
            away = (ix > 0) if face == 0 else (ix < 0)
            if iy < 0:
                self.enter(JUMP + face)
            elif falling:
                self.vy = 0
                self.enter(FALL + face)
            elif s == STAND:
                if toward:
                    self.enter(WALK + face)
                elif away:
                    self.enter(STAND + 1 - face)
                elif self.jet_on:
                    self.enter(JET + face)
            else:
                if ix == 0:
                    self.enter(STAND + face)
                elif away:
                    self.enter(WALK + 1 - face)
                elif self.jet_on:
                    self.enter(JET + face)
        elif s == JUMP:
            self.vy += GRAVITY
            self.move_collide(ix, self.vy >> 16)
            if not self.flags & 6 and self.vy < 1 and iy < 0:
                if (ix > 0) if face == 0 else (ix < 0):
                    # turn in the air: keeps vy; the original loads the *standing* frame (1027 / 1025)
                    self.state, self.frame = JUMP + 1 - face, (1027 if face == 0 else 1025)
                    self.counter = self.w.desc[self.frame][0]
                elif self.jet_on:
                    self.enter(JET + face)
            else:
                self.vy = 0
                self.enter(FALL + face)
        elif s == FALL:
            self.vy = min(self.vy + GRAVITY, FALL_CAP)
            self.move_collide(ix, (self.vy >> 16) + 1)
            still = self.y == prev_y
            if self.jet_on:
                self.enter(JET + face)
            elif still:
                self.vy = 0
                self.enter(STAND + face)
            elif (ix > 0 and face == 0) or (ix < 0 and face == 1):
                self.enter(FALL + (ix > 0))
        elif s == JET:
            if ix > 0:
                self.vx += 0x1800
            elif ix < 0:
                self.vx -= 0x1800
            elif self.vx > 0:
                self.vx -= 0x400
            elif self.vx < 0:
                self.vx += 0x400
            self.vy += -0x1800 if iy < 0 else 0x1000
            self.vx = max(-0x30000, min(0x30000, self.vx))
            self.vy = max(-0x30000, min(0x30000, self.vy))
            self.fx += self.vx
            self.fy += self.vy
            self.move_collide((self.fx >> 16) - self.x, (self.fy >> 16) - self.y)
            if self.flags == 4:
                self.vx, self.vy = -(self.vx >> 1), -(self.vy >> 1)
                self.fx, self.fy = self.x * FIX, self.y * FIX
            else:                                            # flags 3 (corner): no bounce at all
                if self.flags == 1:
                    self.vx = -(self.vx >> 1)
                    self.fx = self.x * FIX
                if self.flags == 2:
                    self.vy = -(self.vy >> 1)
                    self.fy = self.y * FIX
            self.fuel -= 0x800
            if self.fuel < 0:
                self.fuel, self.jet_on = 0, False
            if not self.jet_on:
                self.enter(FALL + face)
            elif ix > 0 and face == 0:
                self.state = JET + 1
                self.frame = ENTRY_FRAME[self.state]
            elif ix < 0 and face == 1:
                self.state = JET
                self.frame = ENTRY_FRAME[self.state]

    def snapshot(self):
        return [self.room[0], self.room[1], self.x, self.y, self.state, self.frame,
                round(self.vx / FIX, 5), round(self.vy / FIX, 5)]


# ---------------------------------------------------------------------------
# room objects
# ---------------------------------------------------------------------------
class PathObject:
    """Path interpreter of one room object (no activation): a step of duration d lasts d+1 ticks - d ticks
    of `v += a; pos += v` and one tick that loads the next step (position jumps to its start)."""

    def __init__(self, world, obj):
        self.w, self.o = world, obj
        self.step, self.done, self.events = 0, None, []
        self.load(0)

    def load(self, i):
        st = self.o.steps[i]
        self.step, self.counter = i, 0
        self.frame = self.find_frame(st.anim, st.anim_start)
        self.fcount = self.w.desc[self.frame][0]
        self.x, self.y, self.vx, self.vy, self.ax, self.ay = st.x, st.y, st.vx, st.vy, st.ax, st.ay
        self.hidden = st.hidden
        if st.trigger_object is not None:
            self.events.append(("activate", st.trigger_object))

    def find_frame(self, group, start):
        """BobFindFrame: group's first descriptor + `start` ticks (the remainder inside the frame is
        dropped by the caller; it does not wrap at the group's end)."""
        i, g = 0, 0
        while g < group and i < len(self.w.desc):
            if self.w.desc[i][0] == -1:
                g += 1
            i += 1
        while start > 0:
            d = self.w.desc[i][0]
            if start < d:
                start = 0
            else:
                start -= d
                i += 1
        return i

    def sound(self, st):
        if st.sound_cmd == 1:
            self.events.append(("play", st.sound))
        elif st.sound_cmd == 3:
            self.events.append(("stop", st.sound))

    def tick(self):
        if self.done:
            return
        c = self.fcount
        self.fcount -= 1
        if c == 0:
            self.frame += 1
            dur, off = self.w.desc[self.frame][:2]
            self.fcount = dur
            if dur == -1:
                skip, self.frame = off >> 16, off & 0xFFFF
                self.fcount = self.w.desc[self.frame][0]
                while skip:
                    d = self.w.desc[self.frame][0]
                    if skip < d:
                        self.fcount, skip = d - skip, 0
                    else:
                        skip -= d
                        self.frame += 1
                        self.fcount = self.w.desc[self.frame][0]
        st = self.o.steps[self.step]
        n = self.counter
        self.counter += 1
        if n < st.duration:
            self.vx, self.vy = s32(self.vx + self.ax), s32(self.vy + self.ay)
            self.x, self.y = s32(self.x + self.vx), s32(self.y + self.vy)
            return
        nxt = self.step + 1
        if nxt < len(self.o.steps):
            self.sound(self.o.steps[nxt])
            self.load(nxt)
            return
        mode = self.o.end_mode
        if mode == 0:
            self.done = "stopped"
        elif mode == 1:
            self.done, self.hidden = "vanished", True
        elif mode == 2:
            self.sound(self.o.steps[self.o.loop_start])
            self.load(self.o.loop_start)
        elif mode == 3:
            self.done = "disabled"
        else:
            self.load(0)

    def snapshot(self):
        return [self.x >> 16, self.y >> 16, self.frame, self.step, int(self.hidden)]


# ---------------------------------------------------------------------------
# golden traces
# ---------------------------------------------------------------------------
TEST_ROOM = (99, 99)
SOLID_TILE = 93          # type 4, full 16x19 box


def test_room(world):
    """Empty room with a solid floor (rows 10-11), a solid ceiling (row 0) and walls (cols 0 and 13)."""
    g = [[0] * 14 for _ in range(12)]
    for x in range(14):
        g[0][x] = g[10][x] = g[11][x] = SOLID_TILE
    for y in range(12):
        g[y][0] = g[y][13] = SOLID_TILE
    world.override[TEST_ROOM] = g


def run_hero(world, room, x, y, script, state=0, fuel=0x2F0000):
    """script: list of (ticks, ix, up, jet) segments."""
    h = Hero(world, room, x, y, state, fuel)
    out = [h.snapshot()]
    for ticks, ix, up, jet in script:
        for _ in range(ticks):
            h.tick(ix, up, jet)
            out.append(h.snapshot())
    return out


def golden(game_dir):
    w = World(game_dir)
    assert w.types[SOLID_TILE] == 4 and w.boxes[SOLID_TILE] == (0, 0, 15, 18)
    test_room(w)
    floor_y = 10 * 19 - 31            # sprite top when standing on the floor (box bottom = 30)
    R = TEST_ROOM
    hero = {
        "stand_settle": (R, 100, floor_y - 12, [(20, 0, False, False)]),
        "walk_right": (R, 40, floor_y, [(60, 1, False, False)]),
        "walk_left_into_wall": (R, 40, floor_y, [(40, -1, False, False)]),
        "jump_hold_to_apex": (R, 100, floor_y, [(24, 0, True, False), (30, 0, False, False)]),
        "jump_hold_repeat": (R, 100, floor_y, [(80, 0, True, False)]),
        "jump_tap_3": (R, 100, floor_y, [(4, 0, True, False), (40, 0, False, False)]),
        "jump_right_hold": (R, 60, floor_y, [(60, 1, True, False)]),
        "jump_into_ceiling": (R, 100, 40, [(30, 0, True, False)]),
        "fall_from_top": (R, 100, 20, [(40, 0, False, False)]),
        "jetpack_up_release": (R, 100, floor_y, [(2, 0, False, True), (40, 0, True, True), (60, 0, False, True)]),
        "jetpack_right_coast": (R, 40, floor_y - 60, [(1, 0, False, True), (30, 1, True, True), (40, 0, True, True)]),
        "jetpack_out_of_fuel": (R, 100, floor_y, [(1, 0, False, True), (80, 0, True, True), (40, 0, False, True)]),
        "start_room_walk": ((7, 0), 22, 83, [(10, 0, False, False), (150, 1, False, False), (40, 1, True, False)]),
    }
    traces = {}
    for name, (room, x, y, script) in hero.items():
        fuel = 0x30000 if name == "jetpack_out_of_fuel" else 0x2F0000
        traces[name] = {"room": list(room), "start": [x, y], "fuel": fuel,
                        "input": [{"ticks": t, "x": ix, "up": up, "jetpack": jet} for t, ix, up, jet in script],
                        "ticks": run_hero(w, room, x, y, script, fuel=fuel)}
    objects = {}
    for col, row in [(7, 0), (8, 0), (0, 0), (8, 6), (3, 8), (5, 8)]:
        for o in w.rooms[(col, row)].objects:
            if not o.steps:
                continue
            p = PathObject(w, o)
            seq = [p.snapshot()]
            for _ in range(300):
                p.tick()
                seq.append(p.snapshot())
            objects[f"{col},{row}#{o.index}"] = {"end_mode": L.END_MODES.get(o.end_mode, "restart"),
                                                 "ticks": seq, "events_first_300": p.events}
    return {
        "note": "Golden traces from tools/reference_sim.py (a transcription of the original's movement code). "
                "Hero rows: [room_col, room_row, x, y, state, frame, vx, vy] per tick, x/y = sprite top-left, "
                "row 0 = before the first tick. States: 0/1 stand, 2/3 walk, 4/5 jump, 6/7 fall, 8/9 jetpack "
                "(even = facing left). Room 99,99 is a test room: solid border (tile 93) and floor rows 10-11. "
                "Object rows: [x, y, frame, step, hidden] for 300 ticks from room entry, no activation. "
                "Solid objects (lifts/doors) are not modelled.",
        "hero": traces, "objects": objects}


if __name__ == "__main__":
    data = golden(sys.argv[1])
    with open(sys.argv[2], "w", encoding="utf-8") as f:
        json.dump(data, f, separators=(",", ":"))
    for k, v in data["hero"].items():
        t = v["ticks"]
        print(f"{k:24s} {len(t) - 1:4d} ticks  start {t[0][2:4]}  end {t[-1][2:6]}  min y {min(r[3] for r in t)}")
