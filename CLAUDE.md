# CLAUDE.md

Context and conventions for AI assistants working in this repository.

## Repository overview

**claude-sandbox** now hosts the groundwork for a **remake of Lazarus** (Infinite Dreams, 1996, MS-DOS,
Polish). It contains reverse-engineering documentation and Python tools for the original game; the remake
itself has not been started yet.

- **License**: MIT (Copyright 2026 mbialkowski) for code/docs; the original game is not ours.
- **Primary branch**: `main`

## Structure

```
claude-sandbox/
├── README.md
├── CLAUDE.md
├── LICENSE
├── docs/reverse-engineering/   # 01 executable, 02 file formats, 03 engine, 04 content, 05 remake guide
└── tools/                      # Python RE tools (see docs/reverse-engineering/README.md)
    ├── extract_assets.py       # export all assets to PNG/WAV/MOD/JSON
    ├── dump_rooms.py           # human-readable room/object/quest listing
    ├── lazarus_data.py         # readers for DATAxx.RES formats
    ├── lazarus_exe.py          # tables embedded in LAZARUS.EXE
    ├── le_loader.py, disasm.py, make_flat_image.py, ghidra/   # executable analysis
    ├── flc.py, mazovia.py      # FLC decoder, Polish DOS code page
    └── symbols.txt             # recovered names (addresses are LE run-time addresses)
```

## Rules

- **Never commit original game files or derived assets** (`*.RES`, `LAZARUS.EXE`, extracted PNG/WAV,
  decompiled C). Keep them in `original/`, `extracted/`, `decomp/` — all git-ignored.
- Tools must run with Python 3.9+ and only `Pillow` + `capstone` (`tools/requirements.txt`).
- When you learn something new about the game, update the relevant `docs/reverse-engineering/*.md` and,
  for code addresses, `tools/symbols.txt`.
- Addresses in docs are run-time addresses (code object at `0x10000`, data at `0x50000`).

## Workflow

- Feature branches: `claude/<description>-<session-id>`; do not push to `main` without permission.
- Push with `git push -u origin <branch-name>`.
- Commit messages: imperative mood, one logical change per commit.
