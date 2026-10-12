# Lazarus (1996) — reverse-engineering notes

Reverse engineering of the Polish DOS game **Lazarus** by Infinite Dreams (1996), done as groundwork for a
modern remake. The game was analysed from the release files (`LAZARUS.EXE` + `DATA01–41.RES`) by
disassembling/decompiling the DOS/4GW executable and verifying findings against the original running in
DOSBox.

| document | contents |
|---|---|
| [01-executable.md](01-executable.md) | binary layout, toolchain, startup, command-line switches, cheat codes, classes, globals, how to reproduce the disassembly/decompilation |
| [02-file-formats.md](02-file-formats.md) | every `DATAxx.RES` format: tiles, sprites (BOBs), rooms, room objects, font, sounds, palettes, FLC/PCX/MOD |
| [03-engine.md](03-engine.md) | game loop, collision, hero state machine and physics constants, object/path system, weapons, HUD, dialogue, sound, randomisation |
| [04-game-content.md](04-game-content.md) | story, world and teleports, all items, NPCs and shops, quest chain, script reference, endings |
| [05-remake-guide.md](05-remake-guide.md) | recommendations, fidelity checklist, open questions, legal note |

## Quick facts

* 10×10 single-screen rooms, play-field 224×228 px (14×12 tiles of 16×19 over 7×6 tiles of 32×38),
  Mode X 320×240, 256 colours, one palette for the whole world, 50 Hz fixed tick.
* 1 184 sprite frames in 229 animation groups, 560 platform tiles, 120 background tiles.
* 699 data-driven room objects (enemies, items, NPCs, doors, lifts, triggers) using one keyframe/physics
  "path" format; ~110 hard-coded script handlers for quests and dialogue; 293 Polish text strings.
* 6 weapons, jetpack with fuel, inventory of up to 40 items (38 item kinds), money, shops, 6 teleport
  destinations unlocked by passwords, 3 endings.
* Data authored on the Amiga (big-endian) and converted; the game itself is Watcom C++ for DOS/4GW.

## Tools (in `tools/`)

| tool | purpose |
|---|---|
| `extract_assets.py` | export everything to PNG/WAV/MOD/JSON (`python3 tools/extract_assets.py <game dir> extracted/`) |
| `dump_rooms.py` | readable listing of room objects / quest objects / one room with its path steps |
| `lazarus_data.py` | Python readers for all resource formats |
| `lazarus_exe.py` | tables embedded in the EXE: messages, sounds, weapons, items, scripts, tile animations |
| `le_loader.py` | LE (DOS/4GW) loader with fixups |
| `disasm.py` | annotated linear disassembly (capstone) using `symbols.txt` |
| `make_flat_image.py` + `ghidra/` | inputs and post-script for a full Ghidra decompilation |
| `mazovia.py` | Mazovia (Polish DOS code page) codec |
| `flc.py` | FLI/FLC decoder |
| `symbols.txt` | ~180 recovered function and variable names |

Requirements: Python 3.9+, `pip install -r tools/requirements.txt` (Pillow, capstone).

## Running the original for comparison

DOSBox 0.74: mount the game directory and run `LAZARUS.EXE` (add `/N` if sound causes trouble, `/I` to
skip the intro). Cheats `IDMORT` (invulnerable), `IDLUFA` (all weapons), `IDSIAR` (infinite ammo/fuel) help
when checking rooms.
