# 7. World structure and catalogues

Data-derived views of the game for level design and balancing in the remake. Everything here is generated
by [`tools/world_analysis.py`](../../tools/world_analysis.py) and [`tools/catalogues.py`](../../tools/catalogues.py)
(run as part of `extract_assets.py`); the machine-readable versions are in `assets/gamedata/`:

| file | content |
|---|---|
| `world_graph.json` | every room edge (open?, pixel openings, doors/lifts on it), regions, teleports, secret passages |
| `enemies.json` | every harmful or shootable object: HP, hits to kill per weapon, path speed/extent, death trigger |
| `hero.json` | hero states, animations (frames, durations, boxes), physics, transitions, start state |
| `sound_usage.json` | for each of the 54 sound ids: who plays it, and which ids share one sample |
| `unused_content.json` | sprites, sounds, texts, tiles, sequences, files the game never uses; known bugs |

## 7.1 Regions

An edge between two rooms is **open** when a gap at least as large as the hero's collision box (11×29 px,
`(6,2)-(16,30)` inside his sprite) crosses the shared border, using the tile collision rules of 3.3. The
connected components of open edges are the game's **regions** — and they match the teleport network
exactly: every region is entered through a teleport and none is connected to another on foot.

![Regions, open edges and teleports](../../assets/rooms/world_regions.png)

*`assets/rooms/world_regions.png` — regions tinted, open edges green (cyan when a door or lift sits on the
opening), white lines = teleport booths/scripted teleports, yellow = hub terminal destinations.*

| # | region (menu name) | rooms | arrival | way back to the hub |
|---|---|---|---|---|
| 0 | Forgotten Temple (Zapomniana Świątynia) | 23: (7–9,0–2), (5–9,3), (7–9,4), (6–9,5), (8–9,6) | (7,0) — game start | booth (8,2) |
| 1 | Land of Terror (Kraina Grozy) | 23: (0–2,1–2), (0–4,3), (0–6,4), (0–4,5) | (1,1) | booth (0,1) |
| 2 | Abyss (Otchłań) | 23: (0–4,6), (0–5,7–9) | (1,6) | booth (4,7) |
| 3 | Netherworld (Zaświaty) | 15: (5–7,6), (6–9,7–9) | (7,8) | booth (6,7) |
| 4 | Hidden Valley (Ukryta Dolina) | 13: (2–6,0), (3–6,1–2) | (4,2) | booth (2,0) — works only after the fuse is fitted (script 132) |
| 5 | Teleport hub | (0,0) + Time Guardian (1,0) behind the force field | (0,0) | — |
| 6 | Training Room (Sala treningowa) | (5,5) | (5,5) | booth (5,5) |

Scripted teleports besides the booths and the hub terminal (all `Hero_StartTeleport` calls in the EXE):

* (4,5) **damaged teleport** (script 203; the warning next to it says use may be dangerous):
  * p = ⅓ → (9,6): a **sealed bonus corridor** along the bottom of (8,6)–(9,6) with all seven $10 coins of
    the game and an ammo pick-up; its only exit is the booth (8,6) (script 45), which leads back to (4,5);
  * p = ⅔ → (8,8): inside the **sealed pool of harmful liquid** in the middle shaft of that room — no
    exit, certain death.
  So it is neither a way into the Netherworld nor a way out of the Land of Terror.
* (2,9) Abyss trigger (script 98) → (4,2) Hidden Valley, and it teaches that password.

The room-level regions above treat each room as one space; the pixel-level model of 7.9 shows that these
two arrival points are pockets of their rooms. Every region except the Temple therefore needs its password
(Hidden Valley: the (2,9) trigger instead).

```mermaid
flowchart LR
  T["0 Forgotten Temple<br/>start (7,0)"]
  L["1 Land of Terror"]
  A["2 Abyss"]
  N["3 Netherworld"]
  V["4 Hidden Valley"]
  H(("hub (0,0)"))
  G["Time Guardian (1,0)"]
  S["6 Training Room"]
  T -- "booth (8,2)" --> H
  P["bonus corridor (8,6)-(9,6)<br/>7 × $10, sealed"]
  D["sealed pool (8,8)<br/>death"]
  L -- "damaged teleport (4,5) ⅓" --> P
  P -- "booth (8,6)" --> L
  L -- "damaged teleport (4,5) ⅔" --> D
  A -- "trigger (2,9)" --> V
  L -- "booth (0,1)" --> H
  A -- "booth (4,7)" --> H
  N -- "booth (6,7)" --> H
  V -- "booth (2,0), needs fuse" --> H
  S -- "booth" --> H
  H -- "terminal" --> T
  H -- "terminal" --> S
  H -- "terminal: password Otchłań<br/>(merchant (8,1) $10, undertaker $10,<br/>burning-hat man)" --> A
  H -- "terminal: password Zaświaty<br/>(freed prisoner (9,4))" --> N
  H -- "terminal: password Ukryta Dolina<br/>(trigger (2,9))" --> V
  H -- "terminal: password Kraina Grozy<br/>(Devil's daughter (0,7))" --> L
  H -- "force field: 5 magic keys" --> G
```

## 7.2 Gates inside regions

Solid objects (doors, lifts, force fields) that sit on an open edge (`gated_by` in `world_graph.json`). Only
four of them actually cut rooms off; the rest are shortcuts or obstacles.

| edge | gate | opened by | cuts off |
|---|---|---|---|
| (0,0)→(1,0) | force field (object 12) | the 5th magic key in the hub slots (script 161) | the Time Guardian (1,0) |
| (8,7)→(9,7) | three secret doors | the shaped key piece (item 12); the right door is random | (9,7) — magic key 5 |
| (6,1)↓(6,2) | lift platform | purple card (item 3) in the reader at (6,1) | (6,2) — fuel can |
| (4,4)→(5,4) | door pair | switch in the same room | (5,4), (6,4) — the teddy bear |
| (0,5)→(1,5) | door pair | golden key (item 23) at (1,5), consumed (script 255) | nothing — (0,5) is also reachable from (0,4) |
| (3,3)→(4,3), (8,4)↓(8,5), (8,9)→(9,9) | invisible blocker, trigger zone, moving lifts | — | nothing |

### All lifts, doors and gates and what opens them

Every static solid object (a door, a parked lift, an invisible wall) and the no-fly zone, with the object
chain followed back to what the player does (`world_graph.json → mechanisms`). Doors are two objects (upper
and lower half) opened by the same chain; "opens on room entry" objects check their flag when the room is
built, so the effect is seen after leaving and re-entering.

| room | mechanism | objects | opened by |
|---|---|---|---|
| (0,0) | force field before the Time Guardian | #12 | the fifth magic key in the hub slots (script 161) |
| (2,0) | two invisible walls | #8, #9 | shooting the two lizard men (#1, #3) |
| (9,0) | lift | #3 | lift card (item 6) in the card reader |
| (3,1) | lift | #1 | touching the panel #0 |
| (6,1) | lift | #3 | purple card (item 3) in the card reader |
| (5,2) | lift | #3 | red card (item 2) in the card reader |
| (1,3) | two platforms | #0, #1 | appear once flag 197 is set — answering the riddle man at (0,3) correctly |
| (5,3) | invisible wall | #4 | shooting the orange beast #3 |
| (6,3) | lift | #0 | flag 40 — the switch at (8,2); moves on room entry |
| (4,4) | door | #2, #4 | the switch #0 in the same room |
| (9,4) | cage door | #5 | cage key (item 8) in the keyhole |
| (1,5) | door | #3, #5 | golden key (item 23) in the keyhole |
| (8,5) | invisible wall | #4 | shooting the orange beast #3 |
| (1,7) | door | #3, #5 | the second purple card (item 16) in the card reader |
| (2,7) | no-fly zone over the river (fuel := 0) | #4 | — cross with the ferry (ticket, item 17) |
| (3,7) | lift | #1 | the panel #0 |
| (6,7) | lift | #4 | grey card (item 13) in the reader #1 |
| (8,7) | three secret doors | #2/#4, #8/#10, #14/#16 | the shaped key piece (item 12) in lock #0, #6 or #12 — there is only one piece |
| (7,8) | lift | #5 | the panel #4 |
| (2,9) | door | #0, #2 | flag 96 — the trigger at (0,9); opens on room entry |

## 7.3 Secret passages (animated tiles never block)

`TileCollide` reads only the static NEWROOM tile map. Animated tiles are separate objects whose
`TileAnim_Overlaps` is only ever asked by the hero's *harm* test (class mask `0x11`): an animated tile can
hurt the hero (when its current frame is a harmful tile type) but **never blocks anybody**. The designers
used this for fake walls: a foreground animated tile that looks solid, placed on an empty map cell, is
walked through and hides the hero while he is inside it.

`world_graph.json → fake_walls` lists all **40** such cells (an animated tile with a solid-looking frame
over a non-solid map cell), e.g. the wall between (7,4) and (8,4) in the Temple, the column at (8,4)
`col 0`, (6,5) — without them the Temple would fall apart into two regions. In the debug renders they are
outlined in magenta. A remake must not give animated tiles collision.

## 7.4 Debug renders

* `assets/rooms/debug/room_C_R.png` (2×): room art darkened; solid tile boxes blue, harmful red; animated
  tiles yellow (fake walls magenta); every object's box and full path in its class colour (harmful red,
  usable green, solid cyan, inert grey; dotted while the object is hidden), labelled with its object index;
  open room edges green / cyan.
* `assets/rooms/world_collision.png`: the whole world, collision and paths only.

![Room (8,4) debug render](../../assets/rooms/debug/room_8_4.png)

## 7.5 Enemies

`enemies.json` classifies the 262 harmful-or-shootable objects with the rules of `Object_Hit` (3.5):

| kind | count | rule |
|---|---|---|
| enemy | 155 | harmful, takes damage: HP 1–192 (127 objects) or **HP 0 = dies to any hit** (28: darts, falling stones, small bugs…) |
| hazard, bullets pass | 81 | HP `0xFE`: water/acid drips (55), turret fireballs (15), sparks, debris |
| hazard, absorbs bullets | 23 | HP `0xFF`: indestructible bouncing bombs, some mines |
| destructible | 3 | harmless but shootable: the rope of the hanging man, two blue capsules |

Contact with anything harmful costs `0x6000` energy every 4 ticks (3.4) — there is no per-enemy damage.
Hits to kill = ⌈HP / damage⌉ with damage 1 (starting gun), 2 (rocket, Uzi), 3 (heavy rocket, flame-thrower),
100 (plasma). Enemies never aim or chase: every one follows its scripted path (speeds below are the
fastest per-tick movement along the path). HP is restored whenever the path restarts.

| enemy (visual name) | sprite groups | count | HP | max px/tick | rooms |
|---|---|---|---|---|---|
| white energy ball | 30 | 19 | 0–15 | 5.1 | (3,1) (4,1) (5,1) (6,1) (1,3) … |
| red bug | 160 | 12 | 0–48 | 5.4 | (3,3) (3,5) (1,6) (3,6) (3,8) … |
| red / green / magenta / yellow spiked mine | 169 / 171 / 170 / 172 | 20 | 4–10 | 4.5 | (2,3) (0,4) (5,8) (5,9) |
| small dart | 152 | 9 | 0 | 7.3 | (3,0) (5,0) (6,0) (7,1) (8,4) |
| black spider | 164 | 6 | 0–48 | 6.6 | (9,2) (6,3) (9,3) (9,6) |
| green / orange / pink bug | 163 / 162 / 161 | 11 | 3–48 | 5.8 | (3,3) (3,5) (3,6) (3,8) (3,9) |
| grey ghoul | 150/151 | 6 | 3–32 | 0.2 | (8,1) (9,1) (8,2) (9,2) (8,3) (8,5) |
| thrown bone | 177/178 | 6 | 0–1 | 3.3 | (7,7) (6,8) (6,9) |
| winged gargoyle | 154/155 | 5 | 8–23 | 0.5 | (4,3) (2,4) (5,4) (2,5) (4,5) |
| hooded hunchback | 146/147 | 5 | 32–48 | 0.7 | (0,2) (2,2) (1,4) (3,5) |
| falling stone | 45 | 4 | 0 | 4.5 | (6,0) (4,2) (2,6) |
| orange ring | 165 | 4 | 0–21 | 3.4 | (9,1) (7,3) (2,4) (9,5) |
| green slime (flying / blob / bouncing) | 185 / 16 / 27 | 8 | 7–19 | 3.5 | (5,0) (2,2) (4,4) (2,5) (4,5) … |
| dragon | 191/192 | 4 | 16–48 | 1.9 | (2,6) (3,7) (2,8) (1,9) |
| zombie | 156/157 | 4 | 10–15 | 0.2 | (5,6) (6,6) (7,6) |
| orange beast | 2/168 | 4 | 6–19 | 0.5 | (5,3) (7,3) (8,3) (8,5) |
| skeleton | 136/137 | 3 | 6–9 | 0.6 | (6,8) (7,8) (9,8) |
| green parrot | 13/14 | 3 | 2–15 | 3.2 | (4,0) (6,0) (4,2) |
| blue beetle | 15 | 3 | 0–3 | 3.9 | (5,0) (3,8) |
| kneeling hag | 197 | 3 | 9–19 | 0.4 | (6,0) (5,1) (4,2) |
| small arrow | 179 | 3 | 0 | 2.5 | (5,6) (7,6) |
| lizard man | 193 | 2 | 19 | 0 | (2,0) |
| helmeted skeleton warrior | 149 | 2 | 5 | 0.7 | (8,0) (7,1) |
| caveman with a club | 3 | 2 | 8–31 | 0.4 | (3,2) (5,2) |
| bouncing bomb (shootable ones) | 176 | 2 | 19–24 | 5.5 | (3,4) (4,4) |
| orange crawler | 158/159 | 2 | 0–4 | 5.7 | (9,8) (7,9) |
| blue wall turret | 56 | 1 | 9 | 0 | (6,1) |
| metal ball | 31 | 1 | 7 | 1.3 | (3,2) |
| **green stone pillar** | 173 | 1 | **192** | 0.2 | (4,3) — 192 pistol shots, 2 plasma shots |

Visual names are guesses from the sprites (`lazarus_names.py` marks them with `?`); group numbers are exact.

## 7.6 Sounds

* The 54 sound ids use only **23 distinct samples** — most effects are one sample played at several rates
  (e.g. ids 11–14 and 16 are the same sample at 8–14 kHz; the four hurt sounds 50–53 likewise).
  `same_sample_as` / `pitch_variants` in `sound_usage.json`; a remake can load 23 files and vary pitch.
* Played by engine code: 46 footstep/landing, 27/28 jetpack loops, 41 teleport, 40 empty-weapon click,
  16 bomb ticking, 5/6 bomb explosion, 38 magazine reload; weapons and the hurt cycle come from EXE tables;
  everything else from object data (activation sound or path-step play/stop commands).
* Never played: **47, 48, 49** — the explosion sample (also ids 6 and 10) at 4.4/5.1/5.9 kHz.

## 7.7 Unused and cut content

![Unused sprite groups](../../assets/sprites/unused_groups.png)

* **Sprites** (`assets/sprites/unused_groups.png`): a 14-frame parrot-like flying creature (39, + a single
  frame 37), a firing blue wall turret (57/59 — the only turret placed uses the one-frame group 56; the
  other cannons are animated tiles with turret-shot objects), a mushroom-cloud explosion ending in a skull
  (212, 11 frames — the bomb death only flashes the palette), the hero turning to face the camera (203) and
  standing with a gun (207), white flash ovals (206), green drops/leaves (189/190), small grey birds or fish
  (180/181) and two tiny fragments (17, 26).
* **Texts**: 279 *"Pauza. Naciśnij fire."* (there is no pause) and 183 *"Chyba wiem o co chodzi!"*.
* **Tiles**: 22 platform tiles and 6 background tiles never placed; tile-animation sequences 5, 55 and 60.
* **Engine**: hero states 12/13 are empty; files DATA18 (old tile types), DATA37 (old PSIZES) and DATA19
  (palette) are never loaded.
* **Bugs**: re-reading the riddle scroll when riddle 2 was drawn shows riddle 1's picture (4.8); the riddle
  check accepts option 1 for riddles 0–1 and option 2 for riddle 2, which is right only because of the
  option order.

## 7.8 Quest dependency graph

Items (pocket ids, 4.3) and scripts (`[sNN]`) behind each step; locations in (col,row) with the region in
brackets. Everything not on a path to the WIN node is optional (money, shortcuts, jokes).

```mermaid
flowchart TD
  start(["start: Temple (7,0)"]) --> booth82["booth (8,2) → hub"]
  booth82 --> hub["hub (0,0): vending machine, terminal"]

  %% passwords
  m1["merchant (8,1) [T] $10"] --> pwA["password Otchłań"]
  pwA --> abyss["Abyss"]
  abyss --> t29["trigger (2,9) [s98]"] --> valley["Hidden Valley + its password"]
  abyss --> devil["Devil's daughter (0,7) [s102]"] --> pwL["password Kraina Grozy"]
  pwL --> terror["Land of Terror"]

  %% bomb and cage
  hang["shoot the hanging man's rope (8,0) [T]"] --> hint["wire colour hint [s35]"]
  cutters["wire cutters: merchant (8,1) $10 / (9,3) $14"] --> defuse
  shout["shout at the caged man (9,4) [s38]"] --> bomb["bomb armed, 60 s"] --> defuse["cut the right wire (5,3) [s39]"]
  hint --> defuse
  defuse --> cagekey["cage key (5,3) [s41]"] --> freed["free the prisoner (9,4) [s42]"] --> pwN["password Zaświaty"]
  pwN --> nether["Netherworld"]

  %% magic keys
  terror --> k1["magic key 1 (0,1) [s192]"]
  start --> k2["magic key 2 (6,5) [s43]"]
  abyss --> k3["magic key 3 (0,8) [s99]"]
  valley --> k4["magic key 4 (5,2) [s141]"]
  terror --> piece["shaped key piece (1,2) [s193]"]
  abyss --> monster["kill the monster, man at (2,8) [s100/101]"] --> doorhint["which secret door"]
  nether --> doors
  piece --> doors["secret doors (8,7)"]
  doorhint --> doors
  doors --> k5["magic key 5 (9,7) [s79]"]
  k1 & k2 & k3 & k4 & k5 --> slots["5 slots in the hub [s161] → force field opens"]
  hub --> slots
  slots --> guardian["Time Guardian (1,0) [s163]: infinite ammo + fuel, magazine 'Pani Domu'"]

  %% witch and elixir
  guardian --> witch["witch (7,8) [N] [s64]"]
  nether --> witch
  witch --> shears["pruning shears"]
  witch -. "other drinks" .-> endings["death / joke ending"]
  shears --> f1["flower (3,0) [V]"] & f2["flower (0,2) [L]"] & f3["flower (7,1) [T]"]
  f1 & f2 & f3 --> cauldron["cauldron (7,8) [s65]"] --> elixir["elixir of resurrection"]
  elixir --> grave["Jouler's grave (7,6) [s80]"] --> timekey["Time Key"]
  timekey --> guardian2["Time Guardian [s162]"] --> win(["door of time [s165] → WIN"])
```

Optional chains not shown: fuse (5,2) → fuse box (2,0) repairs the Hidden Valley booth [s132]; first-aid kit
(6,0) → bleeding man (3,2) → red card → reader (5,2); purple card (4,1) → lift (6,1); lift card → lift (9,0);
bucket (7,8) → tap (8,9) → burning-hat man (9,8) → magic whistle (+ password Otchłań) → *use* it in (1,5)
"TARAPATY" → golden key → door (1,5); random chest in the Abyss → sock → sock man (0,6) → decoder →
gum-chewer (3,5); riddle man (0,3) → answer → platforms at (1,3); teddy bear (5,4) → girl (4,3) → $100 →
ferry ticket $95 → ferryman (2,7). 7.9 checks this graph mechanically: which steps are required, which are
optional, and a complete route.

## 7.9 Can the game be finished? (`tools/completability.py`)

A search over abstract game states answers it from the data alone:

* **State:** items, game flags, the script variables of `script_logic.json` (passwords, counters, shop stock,
  the random picks), money, which objects have fired or appeared, and the places reached by teleport.
* **Movement:** free flight over the pixel collision map of the whole world — the hero's 11×29 box may be
  anywhere free of solid tile pixels (as with the jetpack; fuel and gravity are ignored). Closed doors,
  parked lifts and invisible walls (static solid objects that have not fired) and the no-fly zone over the
  river (until the ferry is taken) are obstacles. Connectivity is labelled once with all obstacles closed
  (union-find over horizontal runs of free positions); each door pair knows which components it joins.
* **Objects:** usable ones need the hero's box to overlap theirs, shootable ones to be level with a
  reachable position in the room. Conditions, "waiting" objects, chains and spawn-activation follow
  `RoomObject_ctor`, `Object_Interact` and `Object_FireTrigger`.
* **Scripts:** the transcribed handlers run abstractly; every menu option and random outcome is a branch,
  death and the joke ending prune it, and while the bomb ticks only the defusing is allowed. Coins in
  reachable places count as collected.
* Actions with one outcome that only add (or consume an item nothing else needs) are applied at once; the
  search branches on the rest (shops, trades, menus, the secret doors). Reusable actions whose outcomes can
  all be had by repeating them (hub terminal, damaged teleport) are merged.

### Results

* **The game can be finished** — for the default random setup and for all 37 setups checked
  (`--all-seeds`: every combination of bomb wire × secret door × riddle, and every sock chest). The search
  needs about 195 decision states and 10 seconds per setup. A full route (109 actions, 46 of them obtaining
  something) is in `assets/gamedata/walkthrough.json`.
* **Required** (`--necessity`: each item / password made unobtainable in turn): first-aid kit and red card
  (the lift to magic key 4), cage key (the prisoner's Netherworld password), the second purple card (the
  door at (1,7) on the way to magic key 3 and the Devil's daughter), the shaped key piece, the five magic
  keys, the magazine for the witch, the shears, the three flowers, the elixir, the Time Key, and the
  passwords Zaświaty, Otchłań and Kraina Grozy.
* **Optional:** the first purple card, fuse, lift card, wire cutters, bucket, whistle (and so the golden key
  and its door), grey card, ferry ticket, sock and decoder, old map and map piece, riddle scroll (the
  riddle's platforms at (1,3)), teddy bear, fuel cans, clips, the shop map and the Ukryta Dolina password
  (the (2,9) trigger teleports there anyway).
* **The bomb is optional.** The cage key lies in (5,3) from the start and the cage lock in (9,4) can be
  reached from below without touching the deaf man's trigger zone, so the prisoner can be freed without
  ever arming the bomb (to be confirmed in play: the model may fly where the hero cannot jump).
* **Soft-lock: the secret doors.** There is one shaped key piece and each of the three locks at (8,7)
  consumes it; only the door the rescued man named leads to magic key 5. A wrong door makes the game
  unwinnable (the search's branches through the other doors never reach the ending). The remake should
  keep the hint prominent or refund the piece.
* **The damaged teleport** is a gamble with no use for the quest: ⅓ a sealed bonus corridor with all seven
  $10 coins, ⅔ death in a sealed pool (7.1).
* **Not modelled:** jump heights and jetpack fuel (free flight is assumed everywhere), enemies and damage,
  solid objects that move on their own (lifts in motion are not obstacles), and the timing of the bomb
  beyond "only the defusing is allowed while it ticks".

### Key steps of the route found (default setup)

1. **Temple (start):** shoot the rope of the hanging man (8,0) and talk to him (wire hint); pick up the lift
   card (9,3) and the cage key (5,3); free the prisoner (9,4) → password **Zaświaty**; magic key 2 (6,5);
   booth (8,2) → hub; insert key 2.
2. **Netherworld** (hub terminal): bucket (7,8) → fill it at the tap (8,9) → put out the burning hat (9,8)
   → whistle + password **Otchłań**; grey card (8,7).
3. **Abyss:** sock from the chest → sock man (0,6) → decoder; purple card 2 (5,7) → door (1,7); the
   Devil's daughter (0,7) → password **Kraina Grozy**; magic key 3 (0,8); the man and the monster (2,8) →
   which secret door; trigger (0,9) opens the door at (2,9) → teleport to the Hidden Valley.
4. **Hidden Valley / Land of Terror:** first-aid kit (6,0) → bleeding man (3,2) → red card → lift (5,2)
   → fuse and magic key 4; magic key 1 (0,1); shaped key piece (1,2); purple card (4,1).
5. **Secret door** (8,7) named by the rescued man → magic key 5 (9,7); all five keys in the hub → the force
   field dissolves.
6. **Time Guardian** (1,0): infinite ammo and fuel, the newest "Pani Domu" → the **witch** (7,8): choose
   the *eliksir Wskrzeszenia* → shears → the flowers (3,0), (7,1), (0,2) → cauldron → elixir → Jouler's
   grave (7,6) → **Time Key** → Time Guardian → the door of time: **the end**.
