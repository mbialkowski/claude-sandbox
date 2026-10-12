#!/usr/bin/env python3
"""Human-readable dump of rooms and room objects (OBJECTS.BIN + NEWROOM.BIN).

    python3 tools/dump_rooms.py <game_dir>              # every object, every room
    python3 tools/dump_rooms.py <game_dir> --quests     # only scripted/quest objects
    python3 tools/dump_rooms.py <game_dir> --room 7 0   # one room in detail (incl. path steps)
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402

CLASS = {0x08: "inert", 0x10: "harmful", 0x20: "usable", 0x40: "solid"}


def obj_line(col, row, o):
    s0 = o.steps[0] if o.steps else None
    cls = CLASS.get(o.collision_class, hex(o.collision_class))
    tgt = "-"
    if o.flags & 0x4000:
        tgt = f"script {o.target}" if o.target >= 20 else f"object #{o.target}"
    need = "-"
    if o.flags & 0x8000 and o.interact & 2:
        need = f"item {o.item}"
    elif o.flags & 0x8000 and o.flags & 0x0004:
        need = f"flag {o.item}"
    hp = "inv" if o.hp in (254, 255) else str(o.hp_max)
    return (f"({col},{row}) #{o.index:<2d} {cls:<7} anim {s0.anim if s0 else '-':>3} at {s0.pos if s0 else '-'!s:<10} "
            f"hp {hp:<3} steps {o.step_count:<2} end {L.END_MODES.get(o.end_mode, o.end_mode):<15} "
            f"trigger {tgt:<10} needs {need:<8} [{','.join(o.describe_flags())}]")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("game_dir")
    ap.add_argument("--quests", action="store_true")
    ap.add_argument("--room", nargs=2, type=int, metavar=("COL", "ROW"))
    a = ap.parse_args()
    rooms = L.load_rooms(a.game_dir)
    keys = [(c, r) for r in range(10) for c in range(10)]
    if a.room:
        keys = [tuple(a.room)]
    for key in keys:
        room = rooms[key]
        for o in room.objects:
            quest = (o.flags & 0x4000 and o.target not in (224, 230)) or (o.flags & 0x8000)
            if a.quests and not quest:
                continue
            print(obj_line(*key, o))
            if a.room:
                for i, s in enumerate(o.steps):
                    print(f"      step {i}: pos {s.pos} v=({s.vx / 65536:+.3f},{s.vy / 65536:+.3f}) "
                          f"a=({s.ax / 65536:+.4f},{s.ay / 65536:+.4f}) ticks {s.duration} anim {s.anim}"
                          f"{' hidden' if s.hidden else ''}"
                          f"{f' sound {s.sound}' if s.sound_cmd == 1 else ''}"
                          f"{f' stop-sound {s.sound}' if s.sound_cmd == 3 else ''}"
                          f"{f' -> triggers #{s.trigger_object}' if s.trigger_object is not None else ''}")
        if a.room:
            print("tile animations:", room.tile_anims)


if __name__ == "__main__":
    main()
