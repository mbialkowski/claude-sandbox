"""Can Lazarus be finished? A static completability checker and walkthrough generator.

The game is modelled as a search over abstract states - items, game flags, script variables (passwords,
counters, shop stock, the random picks), money, which objects have fired or appeared, and the places the
hero has teleported to:

* Movement: free flight (as with the jetpack, fuel and gravity ignored) at pixel level over the whole
  stitched world: the hero's 11x29 box may occupy any position free of solid tile pixels; closed doors /
  parked lifts (static solid objects not yet activated) and the no-fly zone over the river (until the
  ferry is taken) are added as obstacles. Connected positions are found with PIL flood fills.
* Interaction: an object can be used when a reachable hero position overlaps its box; shootable objects
  when they are level with a reachable position in the same room. Object conditions, chaining and
  "waiting" objects follow RoomObject_ctor / Object_Interact / Object_FireTrigger.
* Scripts: the transcribed handlers of lazarus_scripts.py are executed abstractly; every menu option and
  every random outcome is a branch; death endings prune the branch; while the bomb ticks only the
  defusing is allowed.
* Coins in reachable places are assumed collected.

Actions with a single outcome that only add things are applied eagerly; the search branches on the rest
(shops, trades, consuming items, menus). The result is a verdict per random seed and a walkthrough.

    python3 tools/completability.py original/ assets/gamedata/walkthrough.json
"""
import json
import os
import sys
from collections import deque

from PIL import Image, ImageChops, ImageDraw

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402
import lazarus_names as N  # noqa: E402
import lazarus_scripts as S  # noqa: E402
import world_analysis as WA  # noqa: E402
from reference_sim import load_desc  # noqa: E402

W, H = L.ROOM_PX_W, L.ROOM_PX_H
BW, BH = WA.HERO_W, WA.HERO_H            # hero collision box 11 x 29
BOX_DX, BOX_DY = WA.HERO_BOX[0], WA.HERO_BOX[1]
FREE, REACHED = 255, 128
START = (7, 0, 22, 83)                   # new game: room (7,0), hero at the temple arrival point
NOISE_SCRIPTS = {224, 230, 231, 232, 233, 134, 136, 137, 225, 226, 227, 228, 229, 108}


# ---------------------------------------------------------------------------
# geometry
# ---------------------------------------------------------------------------
class Geometry:
    """Free-flight connectivity of hero positions (box top-left) over the stitched world.

    All positions are labelled once with every possible obstacle closed (union-find over horizontal runs
    of free positions). Each obstacle remembers which of those components it joins when it opens, so a
    reachability query is a small union-find over components."""

    def __init__(self, game_dir, rooms, obstacles, targets):
        types, boxes = L.load_tile_types(game_dir), L.load_tile_boxes(game_dir)
        seqs = L.load_tile_anim_sequences(os.path.join(game_dir, "LAZARUS.EXE"))
        free = Image.new("L", (10 * W + BW + 2, 10 * H + BH + 2), 0)
        for (c, r), room in rooms.items():
            m = WA.tile_masks(room, types, boxes, seqs)
            free.paste(Image.frombytes("L", (W, H), bytes(0 if v == 1 else FREE for v in m)), (c * W, r * H))
        fit = self._erode(self._erode(free, BW, True), BH, False)
        d = ImageDraw.Draw(fit)
        d.rectangle([10 * W - BW + 1, 0, fit.width, fit.height], fill=0)
        d.rectangle([0, 10 * H - BH + 1, fit.width, fit.height], fill=0)
        self.w, self.h = fit.width, fit.height
        self.fit = fit.tobytes()
        self.rects = {k: self.rect(b) for k, b in obstacles.items()}
        closed = fit.copy()
        d = ImageDraw.Draw(closed)
        for (x0, y0, x1, y1) in self.rects.values():
            d.rectangle([max(0, x0), max(0, y0), x1, y1], fill=0)
        self.closed = closed.tobytes()
        self._label()
        # obstacles whose rectangles overlap (the two halves of a door) only open a passage together
        keys = list(self.rects)
        parent = list(range(len(keys)))
        for i, a in enumerate(keys):
            for j in range(i):
                b = keys[j]
                (a0, a1, a2, a3), (b0, b1, b2, b3) = self.rects[a], self.rects[b]
                if a0 <= b2 + 1 and b0 <= a2 + 1 and a1 <= b3 + 1 and b1 <= a3 + 1:
                    parent[self._find(parent, i)] = self._find(parent, j)
        groups = {}
        for i, k in enumerate(keys):
            groups.setdefault(self._find(parent, i), set()).add(k)
        self.clusters = [frozenset(g) for g in groups.values()]
        self.links = {c: self._links(c) for c in self.clusters}
        self.target_comps = {k: self._comps_in(self.rect(box, wide)) for k, (box, wide) in targets.items()}
        self.cache = {}
        self.queries = 0

    @staticmethod
    def rect(box, wide=False):
        """Hero positions whose box overlaps `box` (inclusive) - or, for `wide`, is level with it in its room."""
        x0, y0, x1, y1 = box
        if wide:
            x0 = (x0 // W) * W
            x1 = x0 + W - 1
        return (x0 - BW + 1, y0 - BH + 1, x1, y1)

    @staticmethod
    def _erode(img, n, horizontal):
        """Minimum over shifts 0..n-1 towards +x (or +y), by doubling."""
        span, cur = 1, img
        while span * 2 <= n:
            cur = ImageChops.darker(cur, ImageChops.offset(cur, -span, 0) if horizontal
                                    else ImageChops.offset(cur, 0, -span))
            span *= 2
        rest = n - span
        if rest > 0:
            cur = ImageChops.darker(cur, ImageChops.offset(cur, -rest, 0) if horizontal
                                    else ImageChops.offset(cur, 0, -rest))
        return cur

    def _label(self):
        import re
        runs, parent, row_runs = [], [], []
        pat = re.compile(b"\xff+")
        prev = []
        for y in range(self.h):
            row = self.closed[y * self.w:(y + 1) * self.w]
            cur = []
            for m in pat.finditer(row):
                rid = len(runs)
                runs.append((y, m.start(), m.end() - 1))
                parent.append(rid)
                cur.append(rid)
            i = j = 0
            while i < len(prev) and j < len(cur):          # 4-connectivity: overlapping x ranges
                _, a0, a1 = runs[prev[i]]
                _, b0, b1 = runs[cur[j]]
                if a1 >= b0 and b1 >= a0:
                    ra, rb = self._find(parent, prev[i]), self._find(parent, cur[j])
                    if ra != rb:
                        parent[rb] = ra
                if a1 < b1:
                    i += 1
                else:
                    j += 1
            row_runs.append(cur)
            prev = cur
        self.runs, self.row_runs = runs, row_runs
        self.comp = [self._find(parent, i) for i in range(len(runs))]

    @staticmethod
    def _find(parent, i):
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def comp_at(self, x, y):
        if not (0 <= y < self.h):
            return None
        for rid in self.row_runs[y]:
            _, a0, a1 = self.runs[rid]
            if a0 <= x <= a1:
                return self.comp[rid]
        return None

    def _comps_in(self, rect):
        x0, y0, x1, y1 = rect
        out = set()
        for y in range(max(0, y0), min(self.h - 1, y1) + 1):
            for rid in self.row_runs[y]:
                _, a0, a1 = self.runs[rid]
                if a1 >= x0 and a0 <= x1:
                    out.add(self.comp[rid])
        return frozenset(out)

    def _links(self, cluster):
        """Groups of closed-world components that become connected through an obstacle cluster when all
        its members open: free positions inside their rectangles (not covered by other obstacles),
        grouped by connectivity, each with the components adjacent to it."""
        rects = [self.rects[k] for k in cluster]
        others = [r for kk, r in self.rects.items() if kk not in cluster]

        def inside(x, y, rs):
            return any(a <= x <= c and b <= y <= d for (a, b, c, d) in rs)

        free = set()
        for (x0, y0, x1, y1) in rects:
            for y in range(max(0, y0), min(self.h - 1, y1) + 1):
                for x in range(max(0, x0), min(self.w - 1, x1) + 1):
                    if self.fit[y * self.w + x] == FREE and not inside(x, y, others):
                        free.add((x, y))
        groups, seen = [], set()
        for p in free:
            if p in seen:
                continue
            stack, adj = [p], set()
            seen.add(p)
            while stack:
                x, y = stack.pop()
                for q in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                    if q in free:
                        if q not in seen:
                            seen.add(q)
                            stack.append(q)
                    elif not inside(q[0], q[1], rects):
                        c = self.comp_at(*q)
                        if c is not None:
                            adj.add(c)
            if len(adj) > 1:
                groups.append(frozenset(adj))
        return groups

    def anchor(self, c, r, x, y):
        """Sprite position -> component of the nearest free position."""
        bx, by = c * W + x + BOX_DX, r * H + y + BOX_DY
        for dist in range(0, 60):
            for dy in range(-dist, dist + 1):
                for dx in range(-dist, dist + 1):
                    if max(abs(dx), abs(dy)) == dist:
                        comp = self.comp_at(bx + dx, by + dy)
                        if comp is not None:
                            return comp
        return None

    def reach(self, open_obstacles, anchors, targets):
        """Targets touchable from the anchor components with `open_obstacles` open."""
        key = (open_obstacles, anchors)
        if key not in self.cache:
            self.queries += 1
            parent = {}

            def find(a):
                parent.setdefault(a, a)
                while parent[a] != a:
                    parent[a] = parent[parent[a]]
                    a = parent[a]
                return a
            for cluster, groups in self.links.items():
                if not cluster <= open_obstacles:
                    continue
                for group in groups:
                    it = iter(group)
                    first = find(next(it))
                    for c in it:
                        parent[find(c)] = first
            roots = {find(a) for a in anchors if a is not None}
            self.cache[key] = frozenset(k for k in targets
                                        if any(find(c) in roots for c in self.target_comps[k]))
        return self.cache[key]


# ---------------------------------------------------------------------------
# state
# ---------------------------------------------------------------------------
COSMETIC_VARS = {"choice", "magazines", "stock_energy", "witch_death", "unused_8935c", "shop_map"}


class State:
    __slots__ = ("items", "flags", "vars", "money", "fired", "enabled", "anchors", "won", "dead", "log")

    def key(self):
        return (self.items, self.flags, self.vars, self.money, self.fired, self.enabled, self.anchors)

    def progress_key(self, cosmetic_items):
        """The state without money and without things that cannot matter for finishing the game."""
        return (self.items - cosmetic_items, self.flags,
                tuple(kv for kv in self.vars if kv[0] not in COSMETIC_VARS), self.fired, self.enabled,
                self.anchors)

    def copy(self):
        s = State()
        for k in self.__slots__:
            setattr(s, k, getattr(self, k))
        return s


def mutable(st):
    s = st.copy()
    s.items, s.flags, s.vars = set(st.items), set(st.flags), dict(st.vars)
    s.fired, s.enabled, s.anchors, s.log = set(st.fired), set(st.enabled), set(st.anchors), []
    return s


def freeze(s):
    s.items, s.flags, s.fired = frozenset(s.items), frozenset(s.flags), frozenset(s.fired)
    s.enabled, s.anchors = frozenset(s.enabled), frozenset(s.anchors)
    s.vars = tuple(sorted(s.vars.items())) if isinstance(s.vars, dict) else s.vars
    return s


# ---------------------------------------------------------------------------
# the model
# ---------------------------------------------------------------------------
class Game:
    def __init__(self, game_dir):
        self.rooms = L.load_rooms(game_dir)
        self.frames, self.groups = L.load_bobs(game_dir)
        self.desc = load_desc(game_dir)
        self.sock_spots = [tuple(p) for p in __import__("lazarus_exe").LazarusExe(
            os.path.join(game_dir, "LAZARUS.EXE")).sock_spots()]
        self.obj = {}
        for (c, r), room in self.rooms.items():
            for o in room.objects:
                self.obj[(c, r, o.index)] = o
        self.boxes = {}
        for k, o in self.obj.items():
            b = WA.object_box(o, self.frames, self.groups, 0) if o.steps else None
            if b:
                c, r = k[0], k[1]
                b = (c * W + b[0], r * H + b[1], c * W + b[2], r * H + b[3])
            self.boxes[k] = b
        self.coins = {k: (1 if o.target == 224 else 10) for k, o in self.obj.items()
                      if o.flags & 0x4000 and o.target in (224, 230)}
        self.nofly = [k for k, o in self.obj.items() if o.flags & 0x4000 and o.target == 108]
        self.static_solid = {k for k, o in self.obj.items() if o.collision_class & 0x40 and self._static(o)}
        self.actors = [k for k, o in self.obj.items() if self._actor(o) and self.boxes[k]]
        self.targets = {k: (self.boxes[k], self.obj[k].collision_class != 0x20) for k in self.actors}
        # who can consume each item: actors that require it, scripts that take or test it
        self.consumers = {}
        for k in self.actors:
            o = self.obj[k]
            if self.conditional_kind(o) == "item":
                self.consumers.setdefault(o.item, set()).add(k)
        for sid, h in S.SCRIPTS.items():
            for item in _items_in(h["ops"]):
                for k in self.actors:
                    if self.obj[k].flags & 0x4000 and self.obj[k].target == sid:
                        self.consumers.setdefault(item, set()).add(k)
        self.targets.update({k: (self.boxes[k], False) for k in self.coins if self.boxes[k]})
        self.cosmetic_items = frozenset(i for i in N.ITEMS if i not in self.consumers)
        self.forbid = set()                             # items / variables made unobtainable (necessity test)
        self.spawners = [k for k, o in self.obj.items()
                         if self.conditional_kind(o) in ("item", "flag") and o.collision_class != 0x20
                         and o.flags & 0x4010]
        obstacles = {k: self.boxes[k] for k in self.static_solid | set(self.nofly) if self.boxes[k]}
        self.geo = Geometry(game_dir, self.rooms, obstacles, self.targets)

    @staticmethod
    def _static(o):
        return all(s.vx == 0 and s.vy == 0 and s.ax == 0 and s.ay == 0 and s.pos == o.steps[0].pos
                   for s in o.steps) if o.steps else False

    @staticmethod
    def _actor(o):
        if not o.flags & 0x4010:
            return False
        if o.flags & 0x4000 and o.target in NOISE_SCRIPTS:
            return False
        usable = o.collision_class == 0x20
        shootable = bool(o.collision_class & 0x18) and o.hp not in (0xFE, 0xFF)
        return usable or shootable

    # -- object presence ----------------------------------------------------
    @staticmethod
    def conditional_kind(o):
        if not o.flags & 0x8000:
            return None
        if o.interact & 2:
            return "item"
        if o.flags & 0x0004:
            return "flag"
        return "exists_if_flag" if o.item > 2 else "waits"

    def present(self, k, st):
        o = self.obj[k]
        if not o.flags & 0x0001 or o.flags & 0x0040:
            return False
        kind = self.conditional_kind(o)
        if kind == "waits":
            return k in st.enabled
        if kind == "exists_if_flag":
            return o.item in st.flags or k in st.enabled
        return True

    def spawns_activated(self, k, st):
        o = self.obj[k]
        kind = self.conditional_kind(o)
        return kind in ("item", "flag") and o.collision_class != 0x20 and o.item in st.flags

    def open_obstacles(self, st):
        """Obstacles that do not block in state st (doors opened, parked lifts moved, absent objects...)."""
        out = []
        for k in self.geo.rects:
            if k in self.nofly:
                if 107 in st.flags:                     # the river can only be crossed by ferry
                    out.append(k)
                continue
            if k in st.fired or k in st.enabled or self.spawns_activated(k, st) or not self.present(k, st):
                out.append(k)
        return frozenset(out)

    def reach_img(self, st):
        """The set of actor/coin keys the hero can currently touch (or shoot)."""
        return self.geo.reach(self.open_obstacles(st), st.anchors, self.targets)

    def money(self, st, img):
        return st.money + sum(v for k, v in self.coins.items() if k in img and self.present(k, st))

    # -- actions ------------------------------------------------------------
    def available(self, st, img):
        acts = []
        for k in self.actors:
            o = self.obj[k]
            if not self.present(k, st) or (k in st.fired and not o.flags & 0x0100):
                continue
            kind = self.conditional_kind(o)
            if kind == "item" and o.item not in st.items:
                continue
            if kind == "flag" and o.item not in st.flags:
                continue
            if k in img:
                acts.append(k)
        return acts

    def auto_activations(self, st):
        """Non-usable conditional objects whose item/flag condition is met spawn activated on room entry
        (RoomObject_ctor) and fire their chain - e.g. the (2,9) door once flag 96 is set."""
        return [k for k in self.spawners if k not in st.fired and self.spawns_activated(k, st)
                and self.present(k, st)]

    def activate(self, st, k, img, auto=False):
        """Player activates object k (use/touch/crouch or kill). Returns list of outcome states."""
        s = mutable(st)
        o = self.obj[k]
        s.log = [("(auto) " if auto else "") + describe(self, k, o)]
        # take_selected removes the pocket the player has selected - the item this object asked for -
        # even when the script runs on an object further down the chain (door locks -> script 255)
        self.selected = o.item if self.conditional_kind(o) == "item" and not auto else None
        outs = [s]
        outs = self._fire(outs, k, img, player=True)
        res = []
        for s in outs:
            if s.dead:
                continue
            s.vars["choice"] = 0                        # transient: the menu result of this action
            s.vars.pop("r", None)
            res.append(freeze(s))
        return res

    def _fire(self, outs, k, img, player=False):
        o = self.obj[k]
        res = []
        for s in outs:
            if s.dead or s.won:
                res.append(s)
                continue
            s.fired.add(k)
            res.append(s)
        outs = res
        c, r, i = k
        if o.flags & 0x0010:
            outs = self._activate_by_chain(outs, (c, r, i + 1), img)
        if not o.flags & 0x4000:
            return outs
        if o.target < 20:
            return self._activate_by_chain(outs, (c, r, o.target), img)
        res = []
        for s in outs:
            if s.dead or s.won:
                res.append(s)
                continue
            s.flags.add(o.target)
            res += self.run_script(s, o.target, k, img)
        return res

    def _activate_by_chain(self, outs, k, img):
        if k not in self.obj:
            return outs
        o = self.obj[k]
        if o.flags & 0x8000:                           # conditional: just appears (becomes usable)
            for s in outs:
                s.enabled.add(k)
            return outs
        return self._fire(outs, k, img)

    # -- scripts ------------------------------------------------------------
    def run_script(self, s, sid, k, img):
        h = S.SCRIPTS.get(sid)
        if not h:
            return [s]
        ctx = {"room": (k[0], k[1]), "item": self.selected, "img": img, "script": sid}
        s.log.append(f"script {sid}" + (f" ({h.get('name')})" if h.get("name") else ""))
        return self.run_ops([s], h["ops"], ctx)

    def run_ops(self, states, ops, ctx):
        for op in ops:
            nxt = []
            for s in states:
                if s.dead or s.won:
                    nxt.append(s)
                else:
                    nxt += self.op(s, op, ctx)
            states = nxt
        return states

    def cond(self, s, c, ctx):
        n, a = c[0], c[1:]

        def val(v):
            return s.vars.get(v["var"], 0) if isinstance(v, dict) else v
        if n == "money_lt":
            return self.money(s, ctx["img"]) < a[0]
        if n == "money_eq":
            return self.money(s, ctx["img"]) == a[0]
        if n == "has_item":
            return a[0] in s.items
        if n == "eq":
            return s.vars.get(a[0], 0) == val(a[1])
        if n == "ne":
            return s.vars.get(a[0], 0) != val(a[1])
        if n == "lt":
            return s.vars.get(a[0], 0) < val(a[1])
        if n == "in_room":
            return ctx["room"] == (a[0], a[1])
        if n in ("energy_full", "ammo_full"):
            return False
        if n == "sock_here":
            return self.sock_spots[s.vars["sock_chest"]] == ctx["room"]
        if n == "and":
            return all(self.cond(s, x, ctx) for x in a)
        if n == "or":
            return any(self.cond(s, x, ctx) for x in a)
        if n == "not":
            return not self.cond(s, a[0], ctx)
        raise ValueError(c)

    def op(self, s, op, ctx):
        n, a = op[0], op[1:]
        if n in ("say", "say_keep", "print", "say_indexed", "print_number", "wait", "clear", "picture",
                 "picture_var", "fade", "show_pcx", "sound", "delay", "delay_ms", "energy", "fuel", "ammo",
                 "weapon"):
            return [s]
        if n == "menu":
            outs = []
            for i, opt in enumerate(a[0]):
                if isinstance(opt, dict) and "if" in opt and not self.cond(s, opt["if"], ctx):
                    continue
                t = mutable(freeze(s.copy()))
                t.log = s.log + [f"choose option {i}"]
                t.vars["choice"] = i
                outs.append(t)
            return outs
        if n == "if":
            return self.run_ops([s], a[1] if self.cond(s, a[0], ctx) else a[2], ctx)
        if n == "switch":
            v = str(s.vars.get(a[0], 0))
            body = a[1].get(v, a[1].get("default", []))
            return self.run_ops([s], body, ctx)
        if n == "random":
            outs = []
            for v in range(a[1]):
                t = mutable(freeze(s.copy()))
                t.log = s.log + [f"random {a[0]} = {v}"]
                t.vars[a[0]] = v
                outs.append(t)
            return outs
        if n == "call":                                 # a direct C call: no game flag is set
            return self.run_ops([s], S.SCRIPTS[a[0]]["ops"], ctx)
        if n == "give":
            if a[0] in self.forbid:
                return [s]
            s.items.add(a[0])
            s.log.append(f"+ item {a[0]} ({N.ITEMS[a[0]][1]})")
        elif n == "take":
            s.items.discard(a[0])
        elif n == "take_selected":
            if ctx["item"] is not None:
                s.items.discard(ctx["item"])
        elif n == "set":
            v = a[1]
            if isinstance(v, list):
                v = int(self.cond(s, v, ctx))
            if a[0] in self.forbid:
                return [s]
            s.vars[a[0]] = v
            if a[0].startswith("pw_") and v:
                s.log.append(f"password {a[0][3:]}")
        elif n == "add":
            s.vars[a[0]] = s.vars.get(a[0], 0) + a[1]
        elif n == "set_flag":
            s.flags.add(a[0])
        elif n == "money":
            s.money += a[0]
        elif n == "activate_object":
            c, r = ctx["room"]
            outs = self._activate_by_chain([s], (c, r, a[0]), ctx["img"])
            return outs
        elif n == "teleport":
            s.anchors.add(self.geo.anchor(*a))
            s.log.append(f"teleport to ({a[0]},{a[1]})")
        elif n == "bomb_sound":
            pass
        elif n == "explode":
            s.dead = True
        elif n == "end_game":
            if a[0] == "win":
                s.won = True
            else:
                s.dead = True
        else:
            raise ValueError(op)
        return [s]


def _items_in(ops):
    """Items a script takes or tests."""
    out = set()
    for op in ops:
        if op[0] == "take":
            out.add(op[1])
        elif op[0] == "if":
            out |= _items_in(op[2]) | _items_in(op[3])
            stack = [op[1]]
            while stack:
                c = stack.pop()
                if c[0] == "has_item":
                    out.add(c[1])
                elif c[0] in ("and", "or", "not"):
                    stack += c[1:]
        elif op[0] == "switch":
            for body in op[2].values():
                out |= _items_in(body)
    return out


def describe(game, k, o):
    c, r, i = k
    g = o.steps[0].anim if o.steps else None
    what = N.SPRITE_GROUPS.get(g) or f"object {i}"
    how = "shoot" if o.collision_class != 0x20 else ("pick up" if o.interact & 4 else "use")
    if o.flags & 0x8000 and o.interact & 2:
        how += f" with {N.ITEMS[o.item][1]}"
    return f"({c},{r}) {how}: {what} [#{i}]"


# ---------------------------------------------------------------------------
# search
# ---------------------------------------------------------------------------
def initial_state(game, seed):
    s = State()
    s.items = {24}
    s.flags = {76 + seed["secret_door"]}
    s.vars = {k: (v["init"] if isinstance(v["init"], int) else 0) for k, v in S.STATE.items()}
    s.vars.update(seed)
    s.money, s.fired, s.enabled = 10, set(), set()
    s.anchors = {game.geo.anchor(*START)}
    s.won = s.dead = False
    s.log = []
    return freeze(s)


def pure_gain(game, st, n, k):
    """n only adds to st: no money spent, no bomb, and lost items had no other use."""
    lost = st.items - n.items
    return not (n.money < st.money or dict(n.vars).get("bomb_active") or n.won
                or any(game.consumers.get(i, set()) - {k} for i in lost))


def merge(states):
    m = mutable(states[0])
    for s in states[1:]:
        if dict(s.vars) != dict(states[0].vars) or s.items != states[0].items:
            return None
        m.flags |= s.flags
        m.fired |= s.fired
        m.enabled |= s.enabled
        m.anchors |= s.anchors
    m.log = [states[0].log[0], "all of: " + " | ".join("; ".join(s.log[1:]) for s in states)]
    return freeze(m)


def expand_free(game, st, path):
    """Apply actions that only add until none is left: single-outcome ones, and reusable (rearm) ones whose
    outcomes can all be had by repeating them (teleport menu, damaged teleport), merged."""
    changed = True
    while changed:                                     # one pass per reachability update
        changed = False
        img = game.reach_img(st)
        for k in game.auto_activations(st):
            outs = game.activate(st, k, img, auto=True)
            if len(outs) == 1:
                path = path + [outs[0].log]
                st = outs[0]
                changed = True
        for k in game.available(st, img):
            o = game.obj[k]
            if k in st.fired and not o.flags & 0x0100:
                continue                               # already used earlier in this pass
            kind = game.conditional_kind(o)
            if (kind == "item" and o.item not in st.items) or (kind == "flag" and o.item not in st.flags) \
                    or not game.present(k, st):
                continue
            outs = game.activate(st, k, img)
            if not outs:
                continue
            if len(outs) == 1:
                n = outs[0]
            elif o.flags & 0x0100 and all(pure_gain(game, st, x, k) for x in outs):
                n = merge(outs)
                if n is None:
                    continue
            else:
                continue
            if n.key() == st.key() or not pure_gain(game, st, n, k):
                continue
            path = path + [n.log]
            st = n
            changed = True
    return st, path


def solve(game, seed, limit=200000, verbose=False):
    start, path = expand_free(game, initial_state(game, seed), [])
    queue = deque([(start, path)])
    best = {start.progress_key(game.cosmetic_items): start.money}
    explored = 0
    while queue and explored < limit:
        st, path = queue.popleft()
        explored += 1
        if verbose and explored % 200 == 0:
            print(f"  explored {explored}, queue {len(queue)}, seen {len(best)}, queries {game.geo.queries}",
                  flush=True)
        img = game.reach_img(st)
        bomb = dict(st.vars).get("bomb_active")
        for k in game.available(st, img):
            if bomb and game.obj[k].target != 39:
                continue
            for n in game.activate(st, k, img):
                if n.progress_key(game.cosmetic_items) == st.progress_key(game.cosmetic_items) \
                        and n.money <= st.money:
                    continue                            # gained nothing (e.g. paid for a joke item)
                if n.won:
                    return {"won": True, "path": path + [n.log], "explored": explored}
                n2, p2 = expand_free(game, n, path + [n.log]) if not dict(n.vars).get("bomb_active") \
                    else (n, path + [n.log])
                if n2.won:
                    return {"won": True, "path": p2, "explored": explored}
                pk = n2.progress_key(game.cosmetic_items)
                if n2.money > best.get(pk, -10 ** 9):    # same progress with less money is never better
                    best[pk] = n2.money
                    queue.append((n2, p2))
    return {"won": False, "explored": explored, "path": None}


def seeds_to_check():
    """Every combination of the random picks that could interact (bomb wire x secret door x riddle), and
    every sock chest. The shop map only changes a picture."""
    out = [{"bomb_wire": w, "secret_door": d, "sock_chest": 0, "riddle": r, "shop_map": 1079}
           for w in range(3) for d in range(3) for r in range(3)]
    out += [{"bomb_wire": 0, "secret_door": 0, "sock_chest": c, "riddle": 0, "shop_map": 1079}
            for c in range(1, 11)]
    return out


DEFAULT_SEED = {"bomb_wire": 0, "secret_door": 0, "sock_chest": 0, "riddle": 0, "shop_map": 1079}


def necessity(game):
    """Which items and teleport passwords the game cannot be won without (default seed)."""
    obtainable = set()
    for h in S.SCRIPTS.values():
        stack = list(h["ops"])
        while stack:
            op = stack.pop()
            if op[0] == "give":
                obtainable.add(op[1])
            elif op[0] == "if":
                stack += op[2] + op[3]
            elif op[0] == "switch":
                for body in op[2].values():
                    stack += body
    out = {"required": [], "optional": []}
    for what in sorted(obtainable) + ["pw_netherworld", "pw_abyss", "pw_valley", "pw_terror"]:
        game.forbid = {what}
        game.geo.cache = {}
        r = solve(game, DEFAULT_SEED)
        name = N.ITEMS[what][1] if isinstance(what, int) else "password " + what[3:]
        out["required" if not r["won"] else "optional"].append(name)
        print("without", name, "->", "still winnable" if r["won"] else "NOT winnable", flush=True)
    game.forbid = set()
    return out


def walkthrough_json(game, res, seed, all_seeds=None):
    steps = []
    for log in res["path"] or []:
        first = log[0]
        effects = [e for e in log[1:] if e.startswith(("+ item", "password", "teleport", "all of"))
                   or e.startswith("choose")]
        steps.append({"action": first, "details": log[1:], "key_step": bool(effects) or "WIN" in " ".join(log)})
    multi = {i: sorted(f"({c},{r})#{k}" for c, r, k in ks) for i, ks in game.consumers.items() if len(ks) > 1}
    doc = {"note": "Output of tools/completability.py: free-flight reachability over the pixel collision map "
                   "(jetpack assumed available, fuel and gravity ignored), object conditions and chains as in "
                   "the EXE, the transcribed scripts with every menu choice and random outcome explored, coins "
                   "in reachable places assumed collected. 'won' = the door of time (script 165) is reachable.",
           "seed": seed, "won": res["won"], "states_explored": res["explored"],
           "steps": steps,
           "items_with_several_consumers": {N.ITEMS[i][1]: v for i, v in sorted(multi.items())}}
    if all_seeds is not None:
        doc["all_seeds"] = all_seeds
    return doc


def main():
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("game_dir")
    ap.add_argument("out", nargs="?")
    ap.add_argument("--all-seeds", action="store_true", help="check every relevant random setup (~6 min)")
    ap.add_argument("--necessity", action="store_true",
                    help="make each obtainable item / password unobtainable in turn and re-check (~7 min)")
    a = ap.parse_args()
    game = Game(a.game_dir)
    res = solve(game, DEFAULT_SEED)
    print("won" if res["won"] else "NOT won", "explored", res["explored"])
    all_seeds = None
    if a.all_seeds:
        all_seeds = []
        for seed in seeds_to_check():
            r = solve(game, seed)
            all_seeds.append({"seed": seed, "won": r["won"], "states_explored": r["explored"],
                              "steps": len(r["path"] or [])})
            print(seed, "won" if r["won"] else "NOT WON", r["explored"], flush=True)
    doc = walkthrough_json(game, res, DEFAULT_SEED, all_seeds)
    if a.necessity:
        doc["necessity"] = necessity(game)
    if a.out:
        with open(a.out, "w", encoding="utf-8") as f:
            json.dump(doc, f, ensure_ascii=False, indent=1)
    else:
        for st in doc["steps"]:
            print(("* " if st["key_step"] else "  ") + st["action"], "; ".join(st["details"]))


if __name__ == "__main__":
    main()
