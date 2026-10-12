# Lazarus remake

A modern remake of **Lazarus** (Infinite Dreams, 1996, MS-DOS, Polish), a room-based action-adventure
platformer with a jetpack, guns, inventory puzzles and Polish humour — and the reverse-engineering
groundwork it is built on.

**[`remake/`](remake/README.md)** — the game in Godot 4.7: plays in a web browser, widescreen / HD with
crisp pixels, keyboard, gamepad and on-screen touch controls, Polish or English, the original's rules
ported tick for tick. **Play it in the browser: <https://mbialkowski.github.io/claude-sandbox/>**

| widescreen | phone (touch) |
|---|---|
| ![](docs/images/remake/start_room_16x9.png) | ![](docs/images/remake/phone_touch.png) |

The original:

| title | gameplay | dialogue |
|---|---|---|
| ![](docs/images/screenshots/08_title_menu.png) | ![](docs/images/screenshots/09_gameplay_start_room.png) | ![](docs/images/screenshots/11_dialogue_wallet.png) |

## What is here

* [`docs/reverse-engineering/`](docs/reverse-engineering/README.md) — complete write-up of the executable,
  every data file format, the engine rules and physics constants, and the full game content (items, NPCs,
  quests, endings), plus notes for the remake.
* [`assets/`](assets/README.md) — every asset of the original converted to modern formats: tilesets,
  sprites with animation/collision metadata, all 100 rooms as JSON and **Tiled** maps (+ world file),
  world maps, region/collision debug maps, WAV sound effects, MOD music, intro/ending animation frames, pictures, a BMFont of the
  dialogue font, all texts (Polish + English draft), game tables (weapons, items, scripts, physics) and
  catalogues (world graph, enemies, hero spec, sound usage, unused content).
* [`reference/`](reference/README.md) — annotated Ghidra decompilation of `LAZARUS.EXE` for porting exact
  behaviour.
* [`original/`](original/README.md) — the unmodified original game files, with checksums and a DOSBox
  config to run it for comparison.
* [`tools/`](tools/) — the Python tools that produced all of the above from the original files.
* [`remake/`](remake/README.md) — the Godot 4 remake (web export, tests).

![World map](assets/rooms/world_map_labeled.png)

## Regenerating

```bash
pip install -r tools/requirements.txt
python3 tools/extract_assets.py original/ assets/ --render-music   # --render-music needs openmpt123 + oggenc
python3 tools/dump_rooms.py original/ --quests
cd original && dosbox -conf dosbox.conf                              # play the original
python3 tools/build_remake_data.py original/ remake/data/           # the remake's data bundle
godot --path remake                                                  # play the remake (Godot 4.7)
```

## License

The code and documentation in this repository are MIT licensed (see `LICENSE`). Lazarus, its files and
everything derived from them (`original/`, `assets/`, `reference/`) are the property of their respective
rights holders and are included at the repository owner's request.
