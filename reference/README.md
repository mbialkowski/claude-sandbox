# Decompilation reference

`lazarus.c` is the full Ghidra 11.1.2 decompilation of `LAZARUS.EXE` (~1000 functions, pseudo-C), produced by
[`tools/ghidra/`](../tools/ghidra/README.md) with the Watcom register calling convention, the names from
[`tools/symbols.txt`](../tools/symbols.txt), and post-processed by `tools/ghidra/annotate.py`:

* dialogue calls show the message number and its text, e.g.
  `Dlg_Say(MSG_259) /* "Bezpiecznik." */`;
* functions that are script / item handlers carry a `/* role: script 64 on_trigger */` line.

It is pseudo-code: types are often wrong, packed struct fields appear as `*(int *)(param_1 + 0x7e)`, and C++
virtual calls appear as `(**(code **)(obj[1] + 0x28))(...)`. Use it together with the documents in
[`docs/reverse-engineering/`](../docs/reverse-engineering/README.md), which explain the structures
(`01-executable.md` §1.7 lists the class layouts and vtable slots).

Where to start reading:

| what | functions |
|---|---|
| main flow | `main`, `GameLoop`, `NewGameState`, `TitleMenu`, `PlayIntro`, `EndingSequence` |
| input & cheats | `ProcessInput` |
| hero | `Hero_Think`, `HeroState00`…`HeroState15`, `Hero_MoveCollide`, `TileCollide`, `Hero_DamageTick` |
| room objects | `EnterRoom`, `RoomObject_ctor`, `Object_Think`, `Object_Interact`, `Object_FireTrigger`, `Object_Hit` |
| weapons | `Bullet_ctor`, `Bullet_Init`, `Bullet_Fly`, `Bullet_Impact` |
| quests | `Script*` functions and everything marked `role:` between `0x1AC50` and `0x1D530` |
| loaders | `LoadRoomMaps`, `LoadRoomsDef`, `LoadFrames`, `LoadPlatformTiles`, `LoadPalettes`, `LoadFont` |

Addresses are run-time addresses (code at `0x10000`, data at `0x50000`). Regenerate after adding symbols —
never edit `lazarus.c` by hand.
