# 1. The executable (`LAZARUS.EXE`)

## 1.1 Identity

| | |
|---|---|
| Title | **Lazarus** (Polish release) |
| Developer | Infinite Dreams, 1996 (menu: *"INFINITE DREAMS PRODUCTION 1996"*) |
| Credits (DATA04 FLC) | Marcin Pancewicz, Tomasz Kostrzewski, Wojciech Panufnik, and others |
| Platform | MS-DOS, 386DX/40+, ~2.9 MB free RAM, VGA, Sound Blaster / Gravis UltraSound |
| Language | Watcom C/C++ 10.x (C++ with vtables and exceptions), protected mode via DOS/4GW |
| Origin | Ported from the **Amiga** — all level data is big-endian, sprites are called *BOBs*, the intro jokes "but I had an AMIGA, not a PC!" |

`LAZARUS.EXE` is 358 841 bytes. `DOS4GW.EXE` is the stock Rational Systems extender. `LHA.EXE`/`LHA.DOC` are only the installer's archiver.

## 1.2 File layout

```
0x00000  MZ header (e_lfanew = 0x6AE0)
0x00360  16-bit real-mode stub (Watcom C/C++16 runtime)  -- see 1.3
0x06AE0  LE header
0x16C00  LE data pages (page size 0x1000, 65 pages)
```

LE objects (loaded at their preferred bases; 8 043 internal fixups, no imports):

| obj | base | size | contents |
|---|---|---|---|
| 1 | `0x10000` | `0x29B41` | code (game `0x10000-0x33000`, Watcom clib `0x33000-0x39B41`) |
| 2 | `0x40000` | `0x34` | small 16-bit helper (interrupt thunk) |
| 3 | `0x50000` | `0xC9CE0` | data; only the first `0x15DB9` bytes are initialised, the rest is BSS |

Entry point `0x33F18` (Watcom `_cstart_`), stack top `3:0xC9CE0`.

`tools/le_loader.py` loads the LE exactly like DOS/4GW would (applies fixups) so every address in these
documents is the real run-time address.

## 1.3 The 16-bit stub: boot logo and anti-tamper

The MZ part is a full Watcom 16-bit program, not the usual "this program requires DOS/4GW" stub. It

1. prints the `/?` help text (`lazarus.exe [/i] [/t] [/m] [/rsample_rate] [/n] [/d] [/sn] [/?]`),
2. switches to 640×480×16 and shows the **Infinite Dreams logo** from `DATA22.RES` on a white screen while
   DOS/4GW loads (~2 s; verified in DOSBox), aborting with `Error: blad odczytu naglowka!` if the PCX header
   cannot be read,
3. on mismatch prints a Caesar-shifted (+1) message — `Qsphsbn!kftu!vt{lpe{poz"…` = *"Program jest
   uszkodzony! Zainstaluj go ponownie"* (the program is damaged, reinstall),
4. spawns `DOS4GW.EXE LAZARUS.EXE ~ <args>`.

The protected-mode `main()` refuses to run unless the extra `~` argument is present (it prints
*"Uruchom program poleceniem: LAZARUS.EXE <Enter>"* and exits). Only the logo matters for a remake (see
[06-cutscenes-and-music.md](06-cutscenes-and-music.md)).

## 1.4 Command line (protected-mode `main`, `0x29AD4`)

| switch | documented | effect |
|---|---|---|
| `/I` | yes | skip the intro |
| `/T` | yes | do not wait for the 50 Hz tick (same as cheat `IDFRME`) |
| `/M` | yes | frame-rate meter (same as `IDMTER`) |
| `/Rnnnn` | yes | mixing rate 4000–44000 Hz (default 28000); also forces `/N` behaviour bug-for-bug (falls through) |
| `/N` | yes | no sound |
| `/D` | yes | print sound-card detection log and exit |
| `/S0` `/S1` `/S2` | yes | force no sound / Sound Blaster / Gravis UltraSound |
| `/E` | **no** | immortal (same as `IDMORT`) |
| `/G` | **no** | start a new game owning all six weapons |
| `/U` | **no** | start a new game with infinite ammo + fuel (same as `IDSIAR`) |
| `~` | internal | must be present; added by the 16-bit stub |

## 1.5 Cheat codes

Typed during play. `ProcessInput` (`0x2A614`) keeps a hash `h = h*64 + scancode` for scancodes
`0x12..0x32` (letters `E`…`M`, i.e. Q and W cannot be part of a code) and resets it when the prefix stops
matching. Recovered by brute-forcing the 32-bit constants:

| code | hash | effect |
|---|---|---|
| `IDMTER` | `0xE0C94493` | toggle frames-per-second meter (top-right) |
| `IDFRME` | `0xE0853C92` | toggle "don't wait for frame" (benchmark) |
| `IDSIAR` | `0xE07D7793` | toggle infinite ammo + jetpack fuel |
| `IDBULL` | `0xE0C169A6` | refill energy and the current weapon's ammo |
| `IDLUFA` | `0xE099685E` | give all six weapons |
| `IDMORT` | `0xE0C984D4` | toggle invulnerability |

`IDMTER`/`IDFRME` are the only ones mentioned in `CZYTAJ.TO`.

## 1.6 Program flow

```
main (0x29AD4)
 ├─ parse switches, detect sound card (GUS → SB → none), init timer/keyboard ISRs
 ├─ unless /I:  PlayModule(DATA39 "recollection")  PlayIntro()  StopModule()
 ├─ load assets: KLOCKI (DATA24/32/38), DATA01 bg tiles, DATA31 HUD, DATA26 font,
 │               DATA03+02 sprites, NEWROOM (DATA29), tile-anim table, palettes
 └─ loop:
      PlayModule(DATA23 "multifruit juice");  TitleMenu()  (palette DATA28)
        GRA      → LoadRoomsDef (DATA30), room (7,0), NewGameState(), GameLoop()
                   after the loop, by g_heroDead:
                     1 = died / blew up      → DATA20 "GAME OVER" picture → back to menu
                     2 = herbs ending        → (DATA21 already shown) → exit to DOS
                     3 = won                 → ending FLC + credits scroller → exit to DOS
        AUTORZY  → PlayFLC(DATA04) credits
        WYJŚCIE  → fade out, print "Dzieki za gre w Lazarusa", exit
```

`GameLoop` (`0x2ADE0`) runs once per 50 Hz timer tick:

1. wait for the tick flag (unless `IDFRME`), service the sound mixer, draw the FPS meter;
2. redraw the HUD parts flagged in `g_hudDirty`;
3. **erase** pass: every object's vtable `+4`, hero, bullets — restores background behind sprites;
4. **think** pass: `ProcessInput`, objects `+0x0C` (path interpreter), hero state machine, bullets;
5. **draw** pass: objects `+0`, hero, bullets; `Hero_DamageTick`; bomb countdown;
6. firing: if fire is held and the weapon's cool-down expired, spawn a bullet and subtract its ammo cost;
7. `IDSIAR`/Time-Guardian infinite mode re-fills fuel and ammo every tick.

Rendering is dirty-rectangle based on a Mode X back buffer — a remake can simply redraw everything every frame.

## 1.7 C++ classes recovered

All objects share a base with `next` at `+0` and a vtable pointer at `+4`.

| class | vtable | size | role |
|---|---|---|---|
| `Hero` | `0x658D8` | static at `0x7D3DC` | player, 16-state machine |
| `RoomObject` | `0x65908` | `0xCF` | everything from OBJECTS.BIN (enemies, items, NPCs, doors, triggers, moving platforms) |
| `TileAnim` | `0x65938` | `0x18` | animated tile from NEWROOM.BIN entry table |
| `Bullet` | — (plain struct) | `0x8F` | projectile list at `0xCEAF0` |
| sound drivers | `0x5282C`/`0x5286C`/`0x528AC` | `0x15C`/`0x162` | GUS / none / SB ("HIGHWAY … Driver v0.99"), MOD player "Przenosny MOD-ule loader v0.99" |

`RoomObject` vtable (offsets): `+0` draw, `+4` erase, `+8` flush-rect, `+0x0C` think (path interpreter
`0x23F4C`), `+0x10` get index, `+0x14` activate, `+0x18` force-activate, `+0x1C` hit(damage),
`+0x20` reset path, `+0x28` overlaps(classMask, box), `+0x2C` interact.

Selected `RoomObject` fields (packed struct): `+0x08` header ptr, `+0x0C` current step ptr, `+0x10`
tick in step, `+0x14` step index (byte), `+0x15/+0x19` x/y 16.16, `+0x25/+0x29` ax/ay, `+0x2D/+0x31` vx/vy,
`+0x3D` current BOB frame, `+0x49..+0x55` collision box, `+0x79` frame timer, `+0x7A` index in room,
`+0x87` collision class, `+0x8B` activated, `+0x8F` hit-flash, `+0x93` activation finished,
`+0x9B` path finished, `+0x9F` hidden this step, `+0xA5` flags word.

`Hero` fields: `+0x08` frame data, `+0x10` BOB frame index, `+0x18..+0x24` frame collision box,
`+0x38` frame timer, `+0x5E/+0x62` vx/vy (16.16), `+0x6E` "state just entered" (-1), `+0x7A` state,
`+0x7E/+0x82` x/y (pixels), `+0x86/+0x8A` x/y 16.16 (jetpack), `+0x8E/+0x92` input x/y (−1/0/1),
`+0x96` last damage source.

## 1.8 Important globals

The full list (≈150 names) is in [`tools/symbols.txt`](../../tools/symbols.txt). Highlights:

| addr | name | meaning |
|---|---|---|
| `7C338/7C33C` | `g_roomCol/Row` | current room |
| `7C474` | `g_tileType[660]` | DATA32 tile types |
| `7C708` | `g_tileBox[660][4]` | DATA38 collision boxes |
| `7D16C/70/78` | BOB descriptors / count / pixel data | DATA03 / DATA02 |
| `7D180` | `g_roomDefPtr[10][10]` | pointers into OBJECTS.BIN |
| `7D3D0` | `g_objList` | all live objects (tile anims first) |
| `7D474` | `g_roomMaps` | NEWROOM.BIN (100 × 458 bytes) |
| `892EC/892F0` | `g_fuel`, `g_energy` | 16.16, max `0x2F0000` (= 47 HUD pixels) |
| `892F4` | `g_ammo[6]` | per weapon, same scale |
| `8930C` | `g_curWeapon` | 0–5 |
| `89330` | `g_tpKnown[6]` | teleport passwords known |
| `89398` | `g_money` | "$" |
| `893BC` | `g_pockets[40]` | inventory (item ids) |
| `89394` | `g_invSel` | selected pocket |
| `8939C` | `g_weaponOwned[6]` | |
| `89484` | `g_gameFlags[256]` | quest flags; index = script id or object header byte 0x0D |
| `53438` | item table | 38 × {HUD icon, use() handler} (icon is the dword *before*) |
| `53564` | script table | 256 × {on_trigger(), on_missing_item()} |
| `53D64` | message table | 293 Mazovia strings |
| `5427C` | weapon table | 12 × 0x24 bytes |
| `51360` | sound table | 54 × 32 bytes |

## 1.9 Reproducing the analysis

```bash
pip install capstone pillow
python3 tools/le_loader.py LAZARUS.EXE                       # header / objects
python3 tools/disasm.py LAZARUS.EXE -o lazarus.asm -s tools/symbols.txt
# optional: Ghidra 11.x headless decompilation (pseudo-C for all ~1000 functions)
python3 tools/make_flat_image.py LAZARUS.EXE out/            # flat.bin + seeds.txt
analyzeHeadless proj laz -import out/flat.bin -processor x86:LE:32:default -cspec windows \
   -loader BinaryLoader -loader-baseAddr 0x10000 \
   -scriptPath tools/ghidra -postScript lazarus_decompile.py out/seeds.txt tools/symbols.txt out/laz.c
```

Watcom passes arguments in `EAX, EDX, EBX, ECX` and the callee pops stack arguments. Ghidra has no such
convention out of the box: `tools/ghidra/README.md` explains the `cspec` addition that makes the
decompiler output readable.
