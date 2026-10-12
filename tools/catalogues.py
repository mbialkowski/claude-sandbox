"""Remake-oriented catalogues derived from the original data: enemies (with hits to kill per weapon),
a hero specification, where every sound effect is used, and content that the game never uses.

Used by extract_assets.py (export_catalogues).  Engine facts that come from code rather than data
(ENGINE_SOUNDS, HERO_STATES, ...) were read from the annotated decompilation in reference/lazarus.c;
the function names are given so they can be checked there.
"""
import json
import math
import os
import sys

from PIL import Image, ImageDraw

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lazarus_data as L  # noqa: E402
import lazarus_names as N  # noqa: E402
import world_analysis as WA  # noqa: E402

FULL_BAR = 0x2F0000

HERO_PHYSICS = {
    "walk_px": 1, "jump_v0": (0xFFFB1DF3 - 0x100000000) / 65536, "gravity": 0x3851 / 65536, "fall_cap": 10,
    "jet_v0": -2.0, "jet_thrust": 0x1800 / 65536, "jet_gravity": 0x1000 / 65536, "jet_friction": 0x400 / 65536,
    "jet_cap": 3.0, "fuel_per_tick": 0x800, "damage_per_hit": 0x6000, "hit_interval_ticks": 4,
    "full_bar": FULL_BAR, "bar_pixels": 47,
}

# Hero_Think state table at 0x7D310 (even = facing left, odd = right); frames from HeroStateNN.
HERO_STATES = [
    {"states": [0, 1], "name": "stand", "groups": [204, 205], "entry_frames": [1025, 1027],
     "sounds": [{"id": 46, "when": "on entering the state (landing)"}]},
    {"states": [2, 3], "name": "walk", "groups": [0, 1], "entry_frames": [3, 14],
     "sounds": [{"id": 46, "when": "footsteps on ticks 18 and 35 of the 37-tick walk cycle"}]},
    {"states": [4, 5], "name": "jump", "groups": [199, 200], "entry_frames": [1005, 1009], "sounds": []},
    {"states": [6, 7], "name": "fall", "groups": [199, 200], "entry_frames": [1005, 1009], "sounds": []},
    {"states": [8, 9], "name": "jetpack", "groups": [199, 200], "entry_frames": [1005, 1009],
     "sounds": [{"id": 27, "when": "idle loop while airborne"}, {"id": 28, "when": "thrust loop while a key is held"}]},
    {"states": [10, 11], "name": "crouch", "groups": [201, 202], "entry_frames": [1013, 1017],
     "sounds": [], "note": "animation plays forward while Down is held, backwards on release; picks up floor items"},
    {"states": [12, 13], "name": "(unused)", "groups": [], "entry_frames": [], "sounds": []},
    {"states": [14], "name": "teleport out", "groups": [211], "entry_frames": [1089],
     "sounds": [{"id": 41, "when": "start"}], "note": "empties the jetpack; then moves to the destination room"},
    {"states": [15], "name": "teleport in", "groups": [211], "entry_frames": [1105],
     "sounds": [{"id": 41, "when": "start"}], "note": "group 211 played backwards, then stand"},
]

# Constant sound ids played by engine code (everything else comes from data tables).
ENGINE_SOUNDS = [
    (46, "HeroState00-03", "footstep / landing"),
    (27, "HeroState08/09", "jetpack idle loop (started/stopped)"),
    (28, "HeroState08/09", "jetpack thrust loop (started/stopped)"),
    (41, "HeroState14/15", "teleport"),
    (40, "GameLoop", "fire pressed with an empty weapon"),
    (16, "Bomb_StartSound / Bomb_StopSound", "bomb ticking loop (60 s countdown)"),
    (5, "Hero_Explode", "bomb explosion"),
    (6, "Hero_Explode", "explosion echo (twice)"),
    (38, "item 36 use (FUN_0001b1e8)", "magazine reload"),
]

HERO_GROUPS = [0, 1, 199, 200, 201, 202, 204, 205, 211]
ENGINE_GROUPS = {208: "HUD inventory icons", 209: "HUD weapon pictures",
                 210: "full-screen pictures + HUD tubes", 226: "title menu (TitleMenu, frames 1178-1181)"}

# Messages no code path displays (checked against every Dlg_* call, menu option table and computed
# message index in reference/lazarus.c).
UNUSED_MESSAGES = {183: "orphaned reply line", 279: "pause text - the game has no pause"}

UNUSED_GROUP_NOTES = {
    17: "small green blob", 26: "8x1 line", 37: "parrot-like creature (single frame)",
    39: "parrot-like flying creature, 14 frames - a cut enemy",
    57: "blue wall turret", 59: "blue wall turret firing, 5 frames - the one turret placed, (6,1), uses the "
        "single-frame group 56; other cannons are animated tiles",
    180: "small grey bird/fish facing left", 181: "small grey bird/fish facing right",
    189: "green drop / leaf", 190: "green drop / leaf falling, 5 frames",
    203: "hero turning to face the camera, 3 frames", 206: "white flash ovals, 2 frames",
    207: "hero standing with a gun (single frame)",
    212: "mushroom-cloud explosion ending in a skull, 11 frames (the bomb death only flashes the palette)",
}

UNUSED_FILES = {
    "DATA18.RES": "older copy of the tile-type table (DATA32 is used)",
    "DATA37.RES": "older, shorter copy of PSIZES.BIN (DATA38 is used)",
    "DATA19.RES": "palette never loaded",
}

KNOWN_BUGS = [
    "Using the riddle scroll (item 28) re-shows riddle 1's picture (frame 1082) when riddle 2 was drawn "
    "(FUN_0001b0a4 uses 0x43a twice); the riddle man himself shows the right one (0x43b).",
    "Riddle answers: option 0 is never accepted - the check is `choice == 1 and riddle < 2` or "
    "`choice == 2 and riddle == 2`, which matches the intended answers 14 / 19 / 97 only because of the "
    "option order.",
]


def jdump(obj, *path):
    with open(os.path.join(*path), "w", encoding="utf-8") as f:
        json.dump(obj, f, ensure_ascii=False, indent=1)


def weapon_list(exe):
    out = []
    for w in exe.weapons():
        if w["facing"] == "right":
            out.append(dict(w, name=N.WEAPONS.get(w["weapon"])))
    return out


# ---------------------------------------------------------------------------
# enemies
# ---------------------------------------------------------------------------
def enemies(rooms, weapons):
    """Every harmful object and every shootable object, with hits to kill per weapon.
    Object_Hit (0x22A6C): HP 0xFF absorbs bullets, class usable or HP 0xFE lets them pass, otherwise
    HP -= damage (clamped at 0) and the object activates (dies) at 0 - so HP 0 dies to any hit."""
    out = []
    for (c, r), room in sorted(rooms.items(), key=lambda kv: (kv[0][1], kv[0][0])):
        for o in room.objects:
            cls = o.collision_class
            shootable = bool(cls & 0x78) and cls != 0x20 and o.hp not in (0xFE, 0xFF)
            if not (cls & 0x10 or shootable):
                continue
            if cls & 0x10:
                kind = "enemy" if shootable else ("hazard (absorbs bullets)" if o.hp == 0xFF
                                                  else "hazard (bullets pass)")
            else:
                kind = "destructible"
            g = o.steps[0].anim if o.steps else None
            e = {"room": [c, r], "object": o.index, "kind": kind, "class": WA.CLASS_NAMES.get(cls),
                 "sprite_group": g, "name": N.SPRITE_GROUPS.get(g),
                 "hp": o.hp if shootable else None, "hp_max": o.hp_max if shootable else None,
                 "visible": not o.flags & 0x0008, "active_at_start": bool(o.flags & 0x0001),
                 "end_mode": L.END_MODES.get(o.end_mode, "restart"), "flags": o.describe_flags()}
            if shootable:
                hp = max(o.hp, 1)
                e["hits_to_kill"] = {w["name"]: math.ceil(hp / w["damage"]) for w in weapons}
                e["ticks_to_kill_auto"] = {w["name"]: (math.ceil(hp / w["damage"]) - 1) * (w["cooldown_ticks"] + 1)
                                           for w in weapons if w["auto_fire"]}
                e["death_anim"] = o.activate_anim if o.activate_anim >= 0 else None
                e["death_sound"] = o.activate_sound or None
                if o.flags & 0x4000:
                    e["on_death"] = ({"script": o.target, "note": N.SCRIPTS.get(o.target)} if o.target >= 20
                                     else {"activates_object": o.target})
            e["path"] = WA.path_summary(o)
            out.append(e)
    return out


def enemy_summary(es):
    by = {}
    for e in es:
        k = (e["kind"], e["sprite_group"])
        s = by.setdefault(k, {"kind": e["kind"], "sprite_group": e["sprite_group"], "name": e["name"],
                              "count": 0, "hp": set(), "rooms": set(), "max_speed": 0.0})
        s["count"] += 1
        if e["hp"] is not None:
            s["hp"].add(e["hp"])
        s["rooms"].add(tuple(e["room"]))
        s["max_speed"] = max(s["max_speed"], e["path"]["max_speed"])
    out = []
    for s in sorted(by.values(), key=lambda s: (s["kind"], -s["count"])):
        s["hp"] = sorted(s["hp"])
        s["rooms"] = [list(k) for k in sorted(s["rooms"], key=lambda k: (k[1], k[0]))]
        out.append(s)
    return out


# ---------------------------------------------------------------------------
# hero
# ---------------------------------------------------------------------------
def hero_spec(frames, groups, exe):
    def frames_of(g):
        return [{"frame": i, "ticks": frames[i].duration, "size": [frames[i].width, frames[i].height],
                 "box": list(frames[i].box)} for i in groups[g]]

    return {
        "note": "Hero (Lucek) specification for the remake. Positions are the sprite's top-left; the "
                "collision box is relative to it. Ticks are 50 Hz. See docs 03-engine.md 3.2-3.6.",
        "collision_box": list(WA.HERO_BOX),
        "states": HERO_STATES,
        "animations": {N.SPRITE_GROUPS.get(g, str(g)): {"group": g, "frames": frames_of(g)} for g in HERO_GROUPS},
        "physics": HERO_PHYSICS,
        "room_transitions": {"left": "x + 11 < 0 -> col-1, x = 213", "right": "x + 11 > 224 -> col+1, x = -11",
                             "up": "y < 0 -> row-1, y = 197", "down": "y + 15 > 228 -> row+1, y = 0",
                             "world_border": "clamped"},
        "bullet_spawn": {"left": [-8, 10], "right": [16, 10]},
        "hurt_sounds": exe.hurt_sounds(),
        "start": {"room": [7, 0], "energy": FULL_BAR, "fuel": 0, "money": 10, "weapon": 0, "pockets": [24]},
        "death": "energy < 0 -> GAME OVER (DATA20). No lives, no saves. Bomb timeout -> Hero_Explode.",
    }


# ---------------------------------------------------------------------------
# sounds
# ---------------------------------------------------------------------------
def sound_usage(rooms, exe):
    sounds = {s["id"]: dict(s, name=N.SOUNDS.get(s["id"]), engine=[], weapons=[], hero_hurt=False,
                            object_activation=[], path_steps=[]) for s in exe.sounds()}
    for sid, where, what in ENGINE_SOUNDS:
        sounds[sid]["engine"].append({"code": where, "what": what})
    for w in exe.weapons():
        for sid in sorted(set(w["sounds"])):
            n = N.WEAPONS.get(w["weapon"])
            if n not in sounds[sid]["weapons"]:
                sounds[sid]["weapons"].append(n)
    for sid in exe.hurt_sounds():
        sounds[sid]["hero_hurt"] = True
    for (c, r), room in sorted(rooms.items(), key=lambda kv: (kv[0][1], kv[0][0])):
        for o in room.objects:
            g = o.steps[0].anim if o.steps else None
            if o.activate_sound and o.activate_sound in sounds:
                sounds[o.activate_sound]["object_activation"].append(
                    {"room": [c, r], "object": o.index, "sprite_group": g, "name": N.SPRITE_GROUPS.get(g)})
            for si, s in enumerate(o.steps):
                if s.sound_cmd in (1, 3) and s.sound in sounds:
                    sounds[s.sound]["path_steps"].append(
                        {"room": [c, r], "object": o.index, "step": si, "cmd": "play" if s.sound_cmd == 1 else "stop",
                         "invisible_emitter": bool(o.flags & 0x0008)})
    first = {}
    for sid in sorted(sounds):           # many ids are the same sample played at another rate (pitch)
        first.setdefault((sounds[sid]["offset"], sounds[sid]["length"]), sid)
    out = []
    for sid in sorted(sounds):
        s = sounds[sid]
        base = first[(s["offset"], s["length"])]
        s["same_sample_as"] = base if base != sid else None
        s["pitch_variants"] = [k for k in sorted(sounds) if k != sid and first[(sounds[k]["offset"],
                                                                                  sounds[k]["length"])] == base]
        s["used"] = bool(s["engine"] or s["weapons"] or s["hero_hurt"] or s["object_activation"] or s["path_steps"])
        out.append(s)
    return out


# ---------------------------------------------------------------------------
# unused content
# ---------------------------------------------------------------------------
def unused_content(rooms, frames, groups, exe, seqs, n_pl, n_bg, sounds):
    f2g = {i: g for g, idx in enumerate(groups) for i in idx}
    used_groups = set(HERO_GROUPS) | set(ENGINE_GROUPS)
    for w in exe.weapons():
        for f in (w["bob_frame"], w["impact_bob_frame"]):
            for k in range(f, f + 8):            # bullet/impact animations run through their group
                if k in f2g and frames[k] is not None:
                    used_groups.add(f2g[k])
                    break
    for room in rooms.values():
        for o in room.objects:
            used_groups |= {s.anim for s in o.steps}
            if o.activate_anim >= 0:
                used_groups.add(o.activate_anim)
    unused_groups = [{"group": g, "frames": [idx[0], idx[-1]], "count": len(idx),
                      "size": [frames[idx[0]].width, frames[idx[0]].height],
                      "note": UNUSED_GROUP_NOTES.get(g, "")}
                     for g, idx in enumerate(groups) if idx and g not in used_groups]

    used_seqs, used_pl, used_bg = set(), set(), set()
    for room in rooms.values():
        used_pl |= {t for row in room.tiles for t in row}
        used_bg |= {t for row in room.background for t in row}
        for (_c, _r, _fg, seq, _st) in room.tile_anims:
            used_seqs.add(seq)
    for seq in used_seqs:
        used_pl |= set(seqs[seq]) if seq < len(seqs) else set()
    unused_pl = [t for t in range(1, n_pl) if t not in used_pl]
    unused_bg = [t for t in range(n_bg) if t not in used_bg]

    msgs = exe.messages()
    scripts = exe.scripts()
    targeted = {o.target for room in rooms.values() for o in room.objects if o.flags & 0x4000 and o.target >= 20}
    return {
        "note": "Content present in the data that the game never uses - candidates for restoring in the remake. "
                "Sprite groups: not referenced by any room object, the hero, HUD, weapons or menus.",
        "sprite_groups": unused_groups,
        "sounds": [{"id": s["id"], "name": s["name"], "length": s["length"], "rate": s["rate"],
                    "note": f"same sample as sound {s['same_sample_as']} at a different rate"
                    if s["same_sample_as"] is not None else ""}
                   for s in sounds if not s["used"]],
        "messages": [{"id": i, "text": msgs[i], "note": n} for i, n in UNUSED_MESSAGES.items()],
        "platform_tiles": unused_pl,
        "background_tiles": unused_bg,
        "tile_anim_sequences": [i for i in range(len(seqs)) if i not in used_seqs],
        "script_handlers_never_targeted": [
            {"id": s["id"], "handler": s["on_trigger_fn"], "note": N.SCRIPTS.get(s["id"])}
            for s in scripts if s["on_trigger_fn"] != "1b2b0" and s["id"] not in targeted
            and s["id"] != 241 and s["id"] != 255],
        "hero_states": [12, 13],
        "files": UNUSED_FILES,
        "known_bugs": KNOWN_BUGS,
    }


def unused_sheet(frames, groups, pal, unused, dst):
    rows = unused["sprite_groups"]
    cell = 52
    im = Image.new("RGB", (60 + 8 * cell, len(rows) * cell), (36, 36, 56))
    d = ImageDraw.Draw(im)
    for r, u in enumerate(rows):
        d.text((4, r * cell + cell // 2 - 6), str(u["group"]), fill=(255, 255, 0))
        for c, i in enumerate(groups[u["group"]][:8]):
            f = frames[i]
            p = Image.new("RGBA", (f.width, f.height))
            p.putdata([(0, 0, 0, 0) if v == 0 else pal[v] + (255,) for v in f.pixels])
            if f.width > cell - 4 or f.height > cell - 4:
                p.thumbnail((cell - 4, cell - 4))
            im.paste(p, (60 + c * cell + (cell - p.width) // 2, r * cell + (cell - p.height) // 2), p)
    im.resize((im.width * 2, im.height * 2), Image.NEAREST).save(dst, optimize=True)


def export_catalogues(game_dir, out, exe, rooms, frames, groups, seqs, n_pl, n_bg):
    gd = os.path.join(out, "gamedata")
    os.makedirs(gd, exist_ok=True)
    weapons = weapon_list(exe)
    es = enemies(rooms, weapons)
    jdump({"note": "All harmful and shootable room objects. kind: enemy (harmful + shootable), hazard (harmful, "
                   "bullet-proof), destructible (harmless but shootable). Contact with anything harmful drains "
                   "0x6000 energy every 4 ticks (~10 s from full). hits_to_kill uses each weapon's damage; "
                   "ticks_to_kill_auto = (hits-1) * (cooldown+1) for auto-fire weapons held down. HP is "
                   "restored when the object's path restarts. path: one pass through the object's steps.",
           "weapons": [{"name": w["name"], "damage": w["damage"], "cooldown_ticks": w["cooldown_ticks"],
                        "auto_fire": w["auto_fire"]} for w in weapons],
           "summary": enemy_summary(es), "objects": es}, gd, "enemies.json")
    jdump(hero_spec(frames, groups, exe), gd, "hero.json")
    su = sound_usage(rooms, exe)
    jdump({"note": "Where each sound effect (DATA41 id) is played: engine code, weapons, hero hurt cycle, object "
                   "activation (header byte 5) and path steps (play/stop of looping emitters). The 54 ids use "
                   "only 23 distinct samples: same_sample_as / pitch_variants list ids that play the same PCM "
                   "data at another sample rate.", "sounds": su},
          gd, "sound_usage.json")
    un = unused_content(rooms, frames, groups, exe, seqs, n_pl, n_bg, su)
    jdump(un, gd, "unused_content.json")
    unused_sheet(frames, groups, L.load_palette(game_dir), un, os.path.join(out, "sprites", "unused_groups.png"))
    return es, su, un
