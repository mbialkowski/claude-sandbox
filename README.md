# Lazarus remake

Groundwork for a modern remake of **Lazarus** (Infinite Dreams, 1996, MS-DOS, Polish), a room-based
action-adventure platformer with a jetpack, guns, inventory puzzles and Polish humour.

This repository currently contains the **reverse-engineering results** of the original game:

* [`docs/reverse-engineering/`](docs/reverse-engineering/README.md) — complete write-up of the executable,
  every data file format, the engine rules and physics constants, and the full game content (items, NPCs,
  quests, endings), plus notes for the remake.
* [`tools/`](tools/) — Python tools that read the original files and export all assets (tiles, sprites,
  rooms, world map, sounds, music, animations, texts, game tables) to PNG/WAV/MOD/JSON.

The original game files are **not** included. Put your copy somewhere outside git (e.g. `original/`, which
is ignored) and run:

```bash
pip install -r tools/requirements.txt
python3 tools/extract_assets.py original/ extracted/
python3 tools/dump_rooms.py original/ --quests
```

## License

The code and documentation in this repository are MIT licensed (see `LICENSE`). Lazarus and its assets are
the property of their respective rights holders.
