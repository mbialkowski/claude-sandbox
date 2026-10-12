# 5. Notes for the remake

## 5.1 What the original is, in one paragraph

A single-screen, room-based action-adventure platformer (think *Abuse*/*Flashback*-era Amiga games):
10×10 rooms of 224×228 px, a hero who walks, jumps, crouches and flies a fuel-limited jetpack, six guns
with separate ammo, 127 shootable enemies, ~280 collectable/usable objects, inventory-based puzzles,
branching NPC dialogue in Polish, a teleport network unlocked by passwords, a 60-second bomb episode,
three endings. Everything runs at a fixed 50 Hz.

## 5.2 Recommended architecture

| layer | suggestion |
|---|---|
| data import | start from [`assets/`](../../assets/README.md) (PNG/WAV/MOD/JSON, Tiled maps, BMFont); regenerate with `tools/extract_assets.py` if the converter changes |
| simulation | fixed 50 Hz tick, integer/16.16 maths for the hero and the path interpreter so behaviour matches 1:1; interpolate only for rendering |
| rendering | render the 224×228 field (+ HUD) to an off-screen 320×240 canvas, scale with integer factors; optionally offer a widescreen HUD layout |
| rooms | load `assets/rooms/json/room_C_R.json` or the Tiled maps `assets/rooms/tiled/*.tmj` (tiles, background, tile animations, objects) |
| objects | one generic `RoomObject` driven by header + path steps (section 2.7 / 3.5) — do not hand-code enemies |
| scripts | port the ~110 script handlers (4.7) into data (e.g. a small dialogue/event DSL or Ink/Yarn), keyed by script id; keep ids so OBJECTS.BIN can be used unchanged |
| text | `assets/text/messages.json` (UTF-8, control codes as tags) and `messages_en.json` (English draft, same tags); add languages as `tools/translations/<lang>.json` |
| audio | MODs via libopenmpt / any tracker player; effects from `assets/sounds/*.wav` at their native rates; implement looping effects and per-object stop |

Engines that fit well: Godot 4 (TileMap + one generic scene for objects), or a small custom C/Rust/TS
engine — the rule set is small and fully specified here.

## 5.3 Fidelity checklist (numbers to copy)

* Tick 50 Hz; walk 1 px/tick; jump v₀ −4.883, g 0.22, hold-to-extend, max ≈ 64 px; fall cap 10.
* Jetpack: v₀y −2, thrust 0.09375, gravity 0.0625, friction 0.0156, cap ±3, bounce = −v/2, fuel 1504 ticks,
  teleporting empties fuel.
* Energy/fuel/ammo scale 0x2F0000 (47 HUD px); damage 0x6000 per 4 ticks of contact; pickups +⅓.
* Weapons table 3.6; bullets spawn at (−8,10)/(16,10).
* Room edge transition offsets (3.2) — they make the seams feel right.
* Tile collision boxes come from PSIZES, not from the full 16×19 cell.
* Animated tiles have no collision (only harm) — the secret passages depend on it (7.3).
* Replay the inputs of `assets/gamedata/golden_traces.json` and compare tick by tick (rules in 3.4,
  "Exact movement rules"); frames and path steps last duration + 1 ticks.
* Hero collision box (6,2)-(16,30) inside the sprite; regions/edges in `world_graph.json` are a regression
  test for a remake's collision code: the same edges must be open.
* Bomb 3000 ticks; menus wrap; dialogues wait for Ctrl/Enter/Space.
* Randomised per new game: bomb wire, secret door, sock chest, riddle, shop map.

### Verified against the original

`tools/pixel_check.py` patches a scratch copy of `LAZARUS.EXE` (two immediates of the new-game code at
`0x2A2A2`/`0x2A2AC` select the start room; `Object_Think`, `TileAnim_Step`, `Hero_Think` and `Hero_Draw`
are turned into `ret` so the first frame stays frozen and the hero is hidden), runs it in DOSBox under Xvfb,
takes DOSBox's own screenshot and compares the play-field with a render made from our reading of the data.
**Result: all 100 rooms are pixel-identical** (224×228 px each, 0 differing pixels). This confirms the room format, both tile sets and their palettes, the tile-animation
start frames and foreground pass, the object header/path fields used on entry, the constructor's visibility
rules for conditional objects and `BobFindFrame`. `assets/rooms/png_objects/` uses the same rules.

## 5.4 Things worth improving (optional)

* Save/continue (the original has none and a single death is game over).
* Remappable controls, gamepad support (the original uses Ctrl/Space/Enter/,/.).
* Other translations — an English draft exists (`tools/translations/en.json`, notes in its README) and
  still needs a native speaker's review; the sign graphic "TARAPATY" (sprite group 117) would need redrawing.
* Quality-of-life: pause (text exists but unused), map screen built from `assets/rooms/world_map.png`, hint for the
  whistle/"TARAPATY" puzzle.
* Fix the riddle-scroll picture bug (4.8).

## 5.5 Open questions / not yet verified

* Enemy AI: the only code that reads the hero position is bullet spawning and the moving-platform carry,
  so enemies are purely path-scripted (they never chase or aim at the player) — worth a quick check in play.
* The quest chain is now checked by `tools/completability.py` (7.9): the game can be finished in its
  model for every random setup tested. The model lets the hero fly anywhere (jetpack, no fuel or jump
  limits), so a play-through in DOSBox following `assets/gamedata/walkthrough.json` (cheats `IDMORT`,
  `IDSIAR` help) is still the final proof — in particular that the bomb can be skipped (7.9).
* Sound Blaster / GUS mixing details (volume curves, panning) — irrelevant if a modern MOD player is used.

## 5.6 Legal

The original game is copyrighted by its authors (Infinite Dreams, 1996). The original files (`original/`),
the converted assets (`assets/`) and the decompilation reference (`reference/`) are included at the
repository owner's request. Clarify the rights situation before shipping any original assets in the remake.

## 5.7 The Godot remake (`remake/`)

[`remake/`](../../remake/README.md) is a remake in Godot 4.7 built directly on these notes:

| part | how | checked by |
|---|---|---|
| hero, tiles, objects, shots | `HeroState00–15`, `Hero_MoveCollide`, `TileCollide`, `Object_Think/Interact/Hit/FireTrigger`, `Platform_PushCarryHero`, `Bullet_*`, `Hero_DamageTick`, the GameLoop order — ported from `reference/lazarus.c` with 32-bit/16.16 arithmetic at 50 Hz | `tests/golden.gd`: all 63 golden traces of 5.3 / 3.4 match tick for tick |
| quests, dialogue, shops | `script_logic.json` run by a small VM (`script_vm.gd`); dialogues freeze the game like `Dlg_Begin` | `tests/walkthrough.gd`: the 109 steps of `walkthrough.json` reach the Door of Time; `tests/scenarios.gd` |
| graphics | drawn in palette indices into a 240-px-high off-screen image, coloured by a shader with the VGA palette, so `FadePalette`, the alarm palette and `Hero_Explode` work exactly; sharp scaling to any HD size | rooms on entry match `assets/rooms/png_objects/` |
| screen | widescreen: the hero's room centred, neighbouring rooms shown dimmed (built as they look on entry, live only when entered), the original HUD panel on the right; 4:3 looks like the original | |
| controls | keyboard as the original plus WASD, gamepad, multi-touch on-screen pad and buttons; dialogues/menus by tap | `tests/web_smoke.mjs` (headless Chromium, desktop and phone) |
| extras | Polish/English (chosen on the first screen or in the options), music while playing (optional; the original has none), options, pause, saving on room entry + Continue | |

Deliberate differences: shots touching harmful tiles do not hurt the hero (in the original `TileCollide`
sets `g_heroHit` for them); room edges can optionally be seamless.
