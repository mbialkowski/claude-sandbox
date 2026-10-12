# Lazarus — extracted assets

Every asset of the original **Lazarus** (Infinite Dreams, 1996) converted to modern formats for the remake.
All files here are **generated** by [`tools/extract_assets.py`](../tools/extract_assets.py) from the original
`LAZARUS.EXE` + `DATAxx.RES`; do not edit them by hand — fix the tool and regenerate:

```bash
python3 tools/extract_assets.py /path/to/original-game assets/
```

The assets are included at the repository owner's request; the rights belong to their respective holders.
Format details and engine rules are in [`docs/reverse-engineering/`](../docs/reverse-engineering/README.md).

![World map](rooms/world_map_labeled.png)

## Conventions

* **Palette**: everything in the world uses one 256-colour palette (`palettes/game.*`). PNGs are indexed
  (palette mode) so colours can be remapped; **index 0 is transparent** for tiles and sprites.
* **Time**: durations are in game **ticks at 50 Hz**; speeds in pixels per tick.
* **Coordinates**: room pixels, origin top-left of the 224×228 play-field. Rooms are addressed `(col,row)`
  in a 10×10 grid; room `(c,r)` sits at world pixel `(c*224, r*228)`.

## Contents

| folder | what | formats |
|---|---|---|
| `palettes/` | game, picture (maps/riddles), alarm (bomb), menu, unused | `.png` swatch, `.json`, `.gpl` (GIMP/Aseprite/Krita), `.pal` (JASC) |
| `tiles/` | 560 platform tiles 16×19 and 120 background tiles 32×38 as gapless tilesets, single tiles, spaced previews, the HUD side panel 76×240 | `.png`; `tile_types.json` (solid / harmful / passable + collision box per tile) |
| `tiles/tiled/` | Tiled tilesets with per-tile `type` property and collision rectangles | `.tsj` |
| `sprites/frames/` | all 956 sprite (BOB) frames | `NNNN.png` (global descriptor index; gaps are group separators) |
| `sprites/groups/` | 227 non-empty animation groups as horizontal strips + frame rectangles, per-frame duration and collision box | `group_NNN.png` + `.json` |
| `sprites/overview/` | labelled contact sheets of all groups (human reference) | `.png` |
| `sprites/sprites.json` | every frame and group, group names, which rooms/scripts use each group | `.json` |
| `sprites/tiled/` | image-collection tileset (first frame of each group) used by the room maps | `.tsj` |
| `rooms/json/` | full data of all 100 rooms: background + platform tile grids, animated tiles, every object with header fields and path steps | `.json` |
| `rooms/png/`, `rooms/png_objects/` | each room rendered without / with objects (first animation frames) | `.png` 224×228 |
| `rooms/tiled/` | one Tiled map per room + `lazarus.world` laying them out — open the world in Tiled | `.tmj`, `.world` |
| `rooms/world_map*.png` | whole world (2240×2280), with objects, and a half-size labelled overview | `.png` |
| `sounds/` | 54 sound effects at their original sample rates; `sounds.json` has loop flags/points and names | `.wav` (8-bit mono) |
| `music/` | "multifruit juice" (menu/game) and "recollection" (intro/credits) | ProTracker `.mod` |
| `pictures/` | GAME OVER, joke ending, intro text pages, end-credits scroller | `.png` |
| `animations/` | 13 intro/credits/ending animations as frames; `animations.json` has timing and purpose | `DATAxx/NNN.png` |
| `font/` | dialogue font: RGBA atlas + BMFont descriptor (Unicode, Polish letters mapped), preview, metrics | `.png`, `.fnt`, `.json` |
| `text/` | all 293 strings (dialogues, items, menus) in UTF-8; CSV with an empty `text_en` column for translation | `.json`, `.csv` |
| `gamedata/` | weapons, items (names PL/EN, HUD icon, description), script ids with notes, tile-animation sequences, teleports, hero/physics constants, new-game state | `.json` |

## Using the Tiled maps

* Open `rooms/tiled/lazarus.world` in [Tiled](https://www.mapeditor.org/) 1.10+ to see the whole world.
* Each map is 14×12 cells of 16×19 px. Layers:
  * `background` — 32×38 tiles placed on every second cell (odd rows, because Tiled anchors larger tiles at
    the bottom-left of their cell);
  * `platforms` — the collision/platform layer (tile `type` + collision rectangles come from the tileset);
  * `tile_animations` — animated tiles as tile objects with properties `sequence`, `start`, `foreground`,
    `frames` (tile ids, one per tick) — not Tiled tile animations, because the game starts each instance
    at its own offset;
  * `objects` — every room object as a tile object showing its first sprite frame, with all header fields
    and the full `steps` list (JSON string) as custom properties.
* Godot users can import the `.tmj` files with a Tiled importer plugin (e.g. YATI) or read `rooms/json/`
  directly; both carry the same data.

## Key ids

* Hero sprites: groups 0/1 walk, 199/200 jump & jetpack, 201/202 crouch, 204/205 stand, 211 teleport.
* HUD: group 208 inventory icons (`gamedata/items.json` → `hud_icon_frame`), 209 weapon pictures,
  frames 1084–1087 the energy/fuel/ammo tubes; full-screen maps/riddles are frames 1077–1083.
* Script ids, item ids and sound ids are the original engine numbers; see `gamedata/scripts.json`,
  `gamedata/items.json`, `sounds/sounds.json` and docs `04-game-content.md`.
