# Original game files — Lazarus (Infinite Dreams, 1996, Polish DOS release)

The unmodified files of the original game, as received in `Lazarus_DOS_PL.zip` (file dates in the archive:
2018-06-30). They are included at the repository owner's request; the rights belong to their respective
holders. **Do not modify these files** — every tool in `tools/` and every address in the documentation refers
to exactly this version (check with `sha256sum -c` against the table below).

Added here (not part of the original set): this `README.md`, `dosbox.conf`, `CZYTAJ_utf8.txt` (UTF-8 copy of
`CZYTAJ.TO`).

## Running it

[DOSBox](https://www.dosbox.com/) 0.74 or newer (DOSBox-X / DOSBox Staging also work):

```bash
cd original
dosbox -conf dosbox.conf
```

The config emulates a Sound Blaster 16 at 220h / IRQ 7 / DMA 1 (verified: the game's `/D` detection confirms
the card). Useful switches (see `docs/reverse-engineering/01-executable.md`): `/I` skip intro, `/N` no sound,
`/M` FPS meter, `/D` sound detection report, undocumented `/E` invulnerable, `/G` all weapons, `/U` infinite
ammo and fuel. Cheats typed during play: `IDMORT`, `IDLUFA`, `IDSIAR`, `IDBULL`, `IDMTER`, `IDFRME`.

Controls: arrows walk/jump/crouch, **Ctrl** fire, **Space** jetpack on/off, **Enter** use, **,** / **.** select
inventory item, **1–6** weapon, **Esc** quit menu.

## Regenerating the converted assets

```bash
python3 tools/extract_assets.py original/ assets/ --render-music
```

## Files

| file | bytes | contents | sha256 |
|---|---|---|---|
| `CZYTAJ.TO` | 12 694 | readme / troubleshooting FAQ (Polish, Mazovia code page); UTF-8 copy: CZYTAJ_utf8.txt | `9ebbfdeeaed764307c09dcf2d3dfebe724190be5a4d247f934bd0a59c17489cb` |
| `DATA01.RES` | 145 920 | background tiles 32x38, Mode X planar (120 tiles) | `7a479260922482776ad424c1dc4407ebd49028b3f4b23872e9d256959a3734f8` |
| `DATA02.RES` | 760 804 | BOBY.BIN - sprite (BOB) frame pixel data | `6e0ed5052764ebf511d558be1cfc3b66e698f71d5e952d2e6edc2460c7af5727` |
| `DATA03.RES` | 10 668 | bob_make.bin - sprite frame descriptors / animation groups | `54f273fecbb57d3383bca61ea1599b56038d06f12f4f4153402d80126ee04ab5` |
| `DATA04.RES` | 856 901 | FLC 320x240 - credits (AUTORZY) animation | `860b24122269f7980ff68098bf8acc8df0a5a1958bd632f933e52de6205a7f27` |
| `DATA05.RES` | 430 577 | FLC 320x200 - intro part | `3316171bf66e8b7741ae75641ba958207c457f72c8f7001916f972dbbb6e5aae` |
| `DATA06.RES` | 905 440 | FLC 320x200 - intro part (92 frames) | `3b811bbd7a60eed247c003ffc8dcf2d40dd8ff6bf1569cc49fa5f5b4d69899ed` |
| `DATA07.RES` | 216 860 | FLC 320x200 - intro part (51 frames) | `60efdfc2af0e16b754b0278c7009f4b4c8e0207b2e9b79631883afaa9afe45f5` |
| `DATA08.RES` | 262 726 | FLC 320x200 - intro part (60 frames) | `7e204d198749b9e0f54033acac676be16aab11a06e7eb5f5ae4dbb73170c7261` |
| `DATA09.RES` | 429 701 | FLC 320x200 - intro part | `9721346328ab5bac50439948b55f716322b54dc34fc121e19f502fc285160f6e` |
| `DATA10.RES` | 30 985 | FLC 320x240 - intro part | `e1e78b6f3f8965a0b61ab4dca19a35cc1a126e58209f5ed14ec4bd6eda016aa6` |
| `DATA11.RES` | 137 059 | FLC 320x200 - intro part | `1c44636dd9ebe743fbc574040726eb7a246420866ed4c7732032f1588e5873d5` |
| `DATA12.RES` | 119 122 | FLI 320x200 - intro (narrator's face, flicker) | `48b55521417dfc7c0319d615550d9387c4951c0cc42b9f919718d613d76c5556` |
| `DATA13.RES` | 25 438 | FLC 320x240 - intro part | `80b92cd3af71d1c1de2e95c5628864e9f20b38d82358183a3bfb84992650ea36` |
| `DATA14.RES` | 26 882 | FLC 320x240 - intro part | `22707e177361440cbe88d4b6fe8fc4f101087ba91e19aa595a5faa0fdf3ee278` |
| `DATA15.RES` | 29 010 | FLC 320x240 - intro part | `dcc94bc790a0cdcbb14c4ba9ec6fb55387ef1c07d06189372a93485ee72e9bdc` |
| `DATA16.RES` | 768 | palette (alarm / bomb countdown) | `9f7d74e8e6c13a853d1dc1e4105782b30d0fc69608355022cac2387ce1e84bfa` |
| `DATA17.RES` | 89 353 | FLC 320x240 - intro (game-world arrival, speech bubbles) | `fbdbeaddb3082406ea09fdf0fe50117f89d2e13c0ca6aeb61dfa3e1eeb4d05cd` |
| `DATA18.RES` | 520 | unused older copy of tile type table | `910164fec99b35bd4f59e4086d40015b8998f27fe74e7872bd055779483980c3` |
| `DATA19.RES` | 768 | palette | `a0f1768a2c580665ec86ec1804a23770324d18c3ae3200feeee3653a969856d1` |
| `DATA20.RES` | 105 845 | PCX 640x480x16 - GAME OVER | `0289b8b2d6d04b20ea62d74c31b41858998594d16d45726aa9be1a4ac0e37889` |
| `DATA21.RES` | 96 722 | PCX 640x480x16 - joke 'happy ending' (witch's herbs) | `b9cfaa25583ba231434cb9077badd66327c2d5ce885dd181cc5403c9b5924e2c` |
| `DATA22.RES` | 5 217 | PCX 264x90x16 - Infinite Dreams logo shown by the DOS stub at start-up | `f0bdd03802d345a2d2bf458f058c784ec6bc9910c2fe093f5bcd3ce9ce433b2c` |
| `DATA23.RES` | 43 952 | MOD 'multifruit juice' - title-menu music (no in-game music) | `a011dba27a71f35c87f1916ce47606767b0d2e0d88cf8542ef72f7494d8c35ee` |
| `DATA24.RES` | 170 240 | KLOCKI.DAT - platform tiles 16x19, Mode X planar (560 tiles) | `6bb147692d9c0cdd51e300f38fdb5981b6a3e3a1c8a0dbfd6df4589522c2370f` |
| `DATA25.RES` | 768 | palette - main game palette | `f946b328117df7e9761cb2d830250e1ba1aafb8a5c96cd9771e56adca00d3fee` |
| `DATA26.RES` | 27 552 | proportional font (dialogue text) | `d9aa7b60eae5de5e4addbc7f12f2af99c17964c147ce80a7e0f577a0952a53d3` |
| `DATA27.RES` | 768 | palette - full-screen pictures (maps, riddles) | `b1deec3bc67f51149141331a2ebdd76dfafd2778336d58ce03ab22f44cab969f` |
| `DATA28.RES` | 768 | palette - title menu | `643c9be41414c1867206a243615a21ae8a0f486afe0a3b923f26fcdffbfa0509` |
| `DATA29.RES` | 45 800 | NEWROOM.BIN - 10x10 room maps | `ce0a4b556ed50c07710b64449022ab8c5c2ba6f9bd454952f22fe162fd4ef6b8` |
| `DATA30.RES` | 68 674 | OBJECTS.BIN - room objects (enemies, items, NPCs, triggers) | `3e32c23dabbea479ff2a1110d8680a2a1fdcba8b7b3511bcdd8a72c1dd823a21` |
| `DATA31.RES` | 18 240 | HUD side panel 76x240, Mode X planar | `33dbefbd80b7f0d63fc9eb1d8dfab97502ce2be0a80758de515ccb08a202f4c4` |
| `DATA32.RES` | 620 | tile type table (0=solid,1=harmful,2=passable) | `dd02d718d9a834543089fa0d842a66ca21e0f1e70d93d3a83dd67b530695a852` |
| `DATA33.RES` | 32 580 | PCX 320x400x256 - intro still | `779eb760fb2d01cf46a1cb07277904d68cc6f01fac365019c7b06a3c85119403` |
| `DATA34.RES` | 27 877 | PCX 320x200x256 - intro still | `5078d7f43cf476662c664fb243389ce3f9281e4dc34fbaab5753eb95f5291ac5` |
| `DATA35.RES` | 37 980 | PCX 320x200x256 - intro still | `6555cf6649d6b20f4882025067a405db8b991efb2a36c59de1c8b6a8aba12c85` |
| `DATA36.RES` | 100 139 | PCX 320x400x256 - intro still | `edaf7cab2ca83e4b8541e7027c62d2e6a90647ec494962a097068d38bdf4ad3f` |
| `DATA37.RES` | 4 160 | unused older copy of PSIZES.BIN | `f5e29f1fbc80db75d61daec64e83fda68c5a76653b8555cee407c6d53e239d2b` |
| `DATA38.RES` | 4 960 | PSIZES.BIN - per-tile collision boxes | `d69aaec85ec0261fea8759d4a1b616fcf866b7f55593c38b67f7c2f2635800f4` |
| `DATA39.RES` | 93 886 | MOD 'recollection' - intro / ending music | `e9e5405108631bdf639b00154156f345375d4922795129da9a978e7a9bd28741` |
| `DATA40.RES` | 65 660 | PCX 640x2080x16 - end credits scroller | `9ba8a29926578062545395da8b5120040321b78d3a918df12bd27931342b9d6b` |
| `DATA41.RES` | 71 016 | sound effects bank | `d18e6a05e5ed67b96a0b66032a3623c1427c6aea63bb39c5776b3067f4b765b7` |
| `DOS4GW.EXE` | 265 420 | Rational Systems DOS/4GW extender | `dd9f4f342533f99570475b62e53231a468de2e3d83e4fc31e80c27d3a7d6b49c` |
| `LAZARUS.EXE` | 358 841 | the game: 16-bit stub + DOS/4GW LE executable (Watcom C++) | `b57fddb2b7d2d64d8d12fe5c8b067abfd8358cd3550c19251f1e19f02073ae8c` |
| `LHA.DOC` | 31 840 | LHA documentation (installer leftover) | `70579a97f307c6b0c8b7a411b39f6777e4dd67213ae0911762b0fa61d147bead` |
| `LHA.EXE` | 26 115 | LHA archiver (installer leftover) | `7ed8029989b968f83c6f7b937353f2d9b37ca71b087a42617389efbf1d503210` |

## CZYTAJ.TO in short (English)

The readme is a troubleshooting FAQ ("ostatnie uwagi" — last notes):

* Requires a 386 or better and ~2.9 MB free memory; does not work under Windows 3.x; under Windows 95 run it
  in MS-DOS mode if sound misbehaves (SB latency through VxD drivers).
* Sound: Gravis UltraSound or Sound Blaster (preferably genuine Creative); the `BLASTER` / `ULTRASND`
  environment variables must be correct; IRQs above 7 are not supported (protected-mode limitation); SB16
  needs the high-DMA value in `BLASTER`.
* `/N` disables sound if the game hangs, `/D` prints the detection steps, `/S1` / `/S2` force SB / GUS when
  both cards are present.
* Performance: the frame counter (`/M` or typing `IDMTER`) should show a steady 50; `/T` or `IDFRME` disables
  waiting for the frame (benchmark). A 386DX/40 is enough.
* "stub exec failed dos4gw.exe" means `DOS4GW.EXE` is missing.
