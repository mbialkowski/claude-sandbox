# 4. Game content: story, world, items, quests

Derived from the room/object data and the script handlers in the EXE (`0x1AC50–0x1D530`).
Room coordinates are `(col,row)` in the 10×10 grid. Script/item ids are the engine's numbers.
The quest flow below is reconstructed from data, **not** from a full play-through — verify in DOSBox
before treating ordering details as final.

## 4.1 Story

(Full intro/ending transcriptions with translations: [06-cutscenes-and-music.md](06-cutscenes-and-music.md).)

The narrator (the player, an Amiga owner) buys a new game, *"LAZARUS czy jakoś tak"*, drives home at night,
the game will not start, he reads the manual — *"…pułkownik Colonel został zamknięty w labiryncie… ble ble
ble…"* — and the screen goes crazy. He wakes up inside the game: *"…a potem to już było tylko bummm… trach…
błyski… dymy… i te sprawy… aha… jeszcze jedna mała sprawa…  WYDOSTAŃ MNIE STĄD!"* (get me out of here).

| | | |
|---|---|---|
| ![](../images/screenshots/01_intro_text.png) | ![](../images/screenshots/03_intro_city.png) | ![](../images/screenshots/04_intro_desk.png) |
| ![](../images/screenshots/05_intro_manual.png) | ![](../images/screenshots/06_intro_arrival.png) | ![](../images/screenshots/07_intro_get_me_out.png) |

In the game world he is mistaken by the Devil's daughter for *"Syn Czarnego Pana / Książę Ciemności"*
(Son of the Dark Lord). Only the **Time Guardian (Strażnik Czasu)** can open the gate back to his world, but
the **Time Key (Klucz Czasu)** is lost: its last owner Jaś Wędrowniczek was eaten by a white shark; the pirate
**Jouler de Generat** found it in the shark's belly and is now dead and buried. The hero must resurrect the
pirate with an elixir brewed by the witch from three magic flowers.

Winning ending (`DATA17` + messages 284–292): *"HURRAA!!! Udało się…"* — he is back at his desk, but
everything is huge: *"Ale przecież miałem AMIGĘ a nie grzyba!!! … za duże buty, za duża łyżka do zupy… MAMOOO!!!"*
— he returned shrunk. Then the credits scroller (`DATA40`, music `DATA39`).

## 4.2 World

* 100 rooms, all used; 699 room objects, 505 animated tiles, 155 shootable enemies (7.5).
* Teleport network: booths in several rooms (script **241**) send the hero to the **hub (0,0)**; the
  hub terminal (script **240**) lists the destinations whose *passwords* the hero knows:

| password (menu text) | arrival room | arrival (x,y) | how the password is learned |
|---|---|---|---|
| Zapomniana Świątynia (Forgotten Temple) | (7,0) – start | (22,83) | known from the start |
| Zaświaty (Netherworld) | (7,8) | (38,178) | freed prisoner in the cage (9,4) |
| Otchłań (Abyss) | (1,6) | (27,64) | merchant (8,1) $10, undertaker (7,6) $10, or the burning-hat man (9,8) |
| Ukryta Dolina (Hidden Valley) | (4,2) | (100,121) | trigger at (2,9) (also teleports there) |
| Kraina Grozy (Land of Terror) | (1,1) | (94,26) | the Devil's daughter (0,7) |
| Sala treningowa (Training Room) | (5,5) | (124,26) | known from the start |

* A **damaged teleport** at (4,5) (warning text, script 204) sends you to (9,6) with probability ⅓ — a
  sealed corridor with all seven $10 coins whose booth (8,6) leads back to (4,5) — otherwise to (8,8),
  into a sealed pool of harmful liquid: certain death (7.1).
* **Teleporting empties the jetpack.** If there was fuel, the hero complains: *"Cholera jasna! Zmoczyłem
  sobie gacie paliwem z plecaka! Ach te teleporty…"*.
* Full-resolution renders: [`assets/rooms/world_map.png`](../../assets/rooms/world_map.png) (2240×2280, tiles only) and
  [`world_map_objects.png`](../../assets/rooms/world_map_objects.png); per room in `assets/rooms/png*/`.

![World map with room coordinates](../../assets/rooms/world_map_labeled.png)

## 4.3 Items (pocket ids)

`hud icon` = frame `1034 + icon` (sprite group 208). "Use" = Enter with the item selected while not
touching an object; most items just print their description.

| id | item | icon | obtained | used for |
|---|---|---|---|---|
| 0 | (empty slot) | 0 | | |
| 1 | Zestaw pierwszej pomocy – first-aid kit | 1 | crouch-pickup (6,0) [s130] | bleeding man (3,2) → red card |
| 2 | Czerwona karta magnetyczna – red card | 2 | bleeding man [s140] | card reader (5,2) |
| 3 | Fioletowa karta – purple card | 13 | pickup (4,1) [s129] | reader (6,1) |
| 4 | Bezpiecznik – fuse | 23 | touch (5,2) [s131] | fuse box (2,0) → repairs the teleport ("Naprawione!") |
| 5 | Paliwo – jetpack fuel can | 5 | (6,2), (1,7) [s128], (0,8) [s232] | use: fuel = full (consumed) |
| 6 | Czerwona karta (lift card) | 2 | pickup (9,3) [s33] or merchant (8,1) $10 | reader (9,0) – lift |
| 7 | Nożyce do drutu – wire cutters | 6 | merchant (8,1) $10 or merchant (9,3) $14 | defuse the bomb (5,3) |
| 8 | Klucz do klatki – cage key | 7 | crouch-pickup (5,3) [s41] | cage lock (9,4) |
| 9 | Puste wiaderko – empty bucket | 8 | pickup (7,8) [s66] | tap (8,9) → full bucket |
| 10 | Wiaderko pełne wody – full bucket | 8 | tap [s67] | burning-hat man (9,8) |
| 11 | Gwizdek – magic whistle | 9 | burning-hat man [s68] | *use* it in room (1,5) ("TARAPATY") → becomes the golden key |
| 12 | shaped key piece ("dziura o takim kształcie") | 10 | pickup (1,2) [s193] | the three locks of the secret doors (8,7) |
| 13 | Szara karta – grey card | 3 | pickup (8,7) [s70] | reader (6,7) |
| 14 | Eliksir Wskrzeszenia – resurrection elixir ("Muszę znaleźć jakiś grób!") | 15 | cauldron (7,8) after 3 flowers [s65] | Jouler de Generat's grave (7,6) |
| 15 | Stara mapa – old map | 14 | undertaker (7,6) $10 | use: shows map picture 1077 |
| 16 | Fioletowa karta #2 | 13 | pickup (5,7) [s97] | reader (1,7) |
| 17 | Bilet na prom – ferry ticket | 27 | vending machine $95 | ferryman (2,7) |
| 18–22 | Magiczny klucz – magic keys (5 shapes) | 17–21 | see 4.5 | the five slots in the hub (0,0) |
| 23 | Złoty klucz – golden key | 7 | from the whistle | door (1,5) |
| 24 | Portfel – wallet | 11 | start | use: *"Mam w portfelu $N"* |
| 25 | Skarpeta – stinking sock | 12 | random chest [s105] | the one-socked man (0,6) → decoder |
| 26 | Dekoder bełkotu – gibberish decoder | 16 | sock man [s104] | the gum-chewer (3,5) |
| 27 | Kawałek starej mapy – piece of old map | 14 | gum-chewer trade | use: picture 1080 *"Nie wszystko jest tym, czym się wydaje"* |
| 28 | riddle scroll | 14 | riddle man (0,3) [s195] | use: shows the riddle picture |
| 29 | Pluszowy misiaczek – teddy bear | 22 | (5,4) [s201] | the girl (4,3) → $100 |
| 30–32 | Czarodziejski kwiat – magic flowers | 24 | cut with the shears at (3,0) [s142], (0,2) [s202], (7,1) [s44] | the witch's cauldron (7,8) |
| 33 | "Pani Domu" – the newest issue of the magazine | 26 | Time Guardian [s163] | the witch (7,8) |
| 34 | Sekator – the witch's pruning shears | 28 | witch [s64] | cutting the magic flowers |
| 35 | Klucz Czasu – the Time Key | 25 | Jouler de Generat [s80] | the Time Guardian (1,0) → win |
| 36 | Magazynek – ammo clip (stackable) | 4 | vending machine $2 | use: +⅓ ammo for the current weapon |
| 37 | Mapa – map | 14 | vending machine $30 | use: one of two map pictures (random per game) |

Pickups that are not pocket items: coins **$1** (script 224, 127 of them), big coins **$10** (230, 7 of them),
ammo (231, +⅓ current weapon), fuel pick-ups (134, +⅓ — 6 of them in the Training Room), energy
potions (136/137, +⅓), full energy (233), weapons (scripts 225, 228,
226, 227, 229 = weapon 1–5; weapon 3, the Uzi, is also sold for $20).

## 4.4 Shops and NPCs

| where | who | script | content |
|---|---|---|---|
| (0,0) | vending machine *"Witamy w naszym sklepiku!"* | 160 | energy refill $5 (only listed if not full), clip $2, Uzi $20, ferry ticket $95, map $30 (Uzi/ticket/map disappear when bought) |
| (8,1) | merchant *"Drogi chłopcze! Jeśli masz kapuchę…"* | 32 | password Otchłań $10 · lift card $10 · wire cutters $10 · "maybe later"; talking to him sets flag 36 |
| (9,3) | his colleague *"Czyżbyś dał się zrobić w bambuko…"* — only appears once flag 36 is set | 37 | angora sweater $14 (joke) · cable cutters $14 · aqualung $14 (joke) |
| (7,6) | undertaker | 75 | password Otchłań $10 · coffin discount coupon $10 (nothing) · old map $10 |
| (3,2) | bleeding man | 139/140 | needs the first-aid kit → red card |
| (8,0) | man hanging on a cross | 34/35 | shoot the rope to get him down (*"Oj! Chyba upadł na głowę…"*): one of three colour rhymes = **which wire defuses the bomb** (random) |
| (9,4) | deaf man in a cage | 38/42 | shouting at him **arms the bomb** (60 s, red alarm palette); free him with the cage key → password Zaświaty |
| (5,3) | the bomb | 39 | needs wire cutters; choose red/green/blue; wrong = explosion |
| (9,8) | man with a burning hat | 69/68 | needs full bucket → magic whistle + password Otchłań |
| (7,6) | graves (Long John Silver, Gereon Świniopas, Jaksra Tokwili, a hand sticking out) | 71–74 | jokes |
| (7,6) | Jouler de Generat's grave | 255 → 80/81 | pour the elixir → the pirate rises, long dialogue → **Time Key** |
| (2,8) | man attacked by a monster | 100/101 | kill the monster → he tells which of the three doors in Zaświaty hides a magic key (random) |
| (0,6) | man missing a sock | 103/104 | sock → gibberish decoder |
| (1,6)…(5,9) | chests | 105/106 | one random chest of 11 contains the sock |
| (3,5) | gum-chewing guy speaking gibberish | 194 | with the decoder: walkman trade → 30 coins / piece of old map / "chwila przyjemności" |
| (0,3) | riddle man | 195/196 | gives a riddle scroll (random of 3); answer **14 / 19 / 97** → passage (flag 197) |
| (4,3) | crying girl | 198/199/200 | find her teddy bear → $100 |
| (0,7) | the Devil's daughter | 102 | dialogue → password Kraina Grozy |
| (2,7) | ferryman | 107 | needs the ferry ticket; flying over the water there drains the jetpack (script 108) |
| (7,8) | the witch + cauldron | 64/65 | see 4.6 |
| (1,0) | the Time Guardian | 163/164/162/165 | see 4.6 |

## 4.5 The five magic keys and the hub

The hub (0,0) has five shaped slots (objects need items 18–22). Each inserted key calls script 161; on the
fifth it activates object 12 — the red/white force field on the right edge dissolves and the way to the Time
Guardian (1,0) opens.

| key | found |
|---|---|
| 18 | (0,1), pickup [s192] |
| 19 | (6,5), touch [s43] |
| 20 | (0,8), pickup [s99] |
| 21 | (5,2), touch [s141] |
| 22 | (9,7), behind one of the three secret doors of (8,7); which one is random (the hint comes from the man at (2,8)); the doors open with the shaped piece (item 12) |

## 4.6 Main quest chain (dependency order)

1. Explore from the Forgotten Temple (7,0); collect money, weapons, cards; repair the teleport with the fuse
   → hub (0,0) with the vending machine and the teleport terminal.
2. Learn passwords (cage man, burning-hat man, merchants, Devil's daughter…) to reach other worlds.
3. Collect the **five magic keys** → open the force field in the hub → **Time Guardian** (1,0).
4. Time Guardian tells the Time Key legend, grants **infinite ammo and fuel**, and asks you to deliver the
   newest **"Pani Domu"** to his wife, the witch in Zaświaty.
5. **Witch** (7,8): give the magazine → she offers a drink:
   * *syrop Wiecznego Życia* → she messes it up → **death**;
   * *ziółka Szczęśliwego Zakończenia* → **joke "happy ending"** picture (DATA21) → game exits;
   * *eliksir Wskrzeszenia* → needs three magic flowers → gives the **pruning shears**.
6. Cut the three **magic flowers** (3,0), (0,2), (7,1) → drop them in the cauldron → **resurrection elixir**.
7. Pour it on **Jouler de Generat's grave** (7,6) → dialogue → **Time Key** → bury him again.
8. Back to the Time Guardian → *"Brawo chłopcze! Drzwi do twego świata stoją otworem!"* → walk through the
   door (script 165) → **winning ending**.

Side branches give money (teddy bear, gum-chewer), passwords and shortcuts. Freeing the prisoner (cage key)
is required for the Zaświaty password; the bomb itself turns out to be avoidable (7.9). Which items are
required and which optional was checked with `tools/completability.py` (7.9).

## 4.7 Script id reference

| id | handler | effect |
|---|---|---|
| 32 | `1B660` | merchant 1 shop |
| 33 | `1B794` | give item 6 |
| 34 | `1B7E8` | hanging man: "help me down" |
| 35 | `1B864` | hanging man rescued: colour rhyme hint for the bomb |
| 37 | `1B8E4` | merchant 2 shop |
| 38 | `1B9D8` | deaf man dialogue, **arms bomb** (alarm palette, timer 3000) |
| 39 | `1BA4C` | bomb: choose wire; correct → disarm & remove cutters, wrong → explosion |
| 41/43/44 | | give item 8 / 19 / 32 |
| 42 | `1BB58` | cage man freed → password Zaświaty |
| 45 | `1BBD8` | teleport to (4,5) (14,83) |
| 64 | `1BC08` | witch: potion menu (3 outcomes) |
| 65 | `1BD98` | cauldron: count flowers, give elixir |
| 66/67 | | bucket / fill bucket |
| 68/69 | | burning-hat man: reward / talk |
| 70 | | give grey card |
| 71–74 | | grave inscriptions |
| 75 | `1C0AC` | undertaker shop |
| 79 | | give magic key 22 |
| 80/81 | | Jouler de Generat: Time Key / burial |
| 96, 40, 197… | – | no handler: only set `g_gameFlags[id]` (opens platforms gated by "needs-flag") |
| 97/99 | | give item 16 / 20 |
| 98 | `1C288` | teleport to (4,2), learn Ukryta Dolina |
| 100/101 | | man & monster / secret-door hint |
| 102 | `1C388` | Devil's daughter → Kraina Grozy |
| 103/104 | | sock man / trade sock for decoder |
| 105/106 | | chest (sock if it is the chosen one) / empty chest |
| 107/108 | | ferryman / no-fly zone (fuel := 0) |
| 128–131 | | fuel can (+message) / purple card / first-aid kit / fuse |
| 132 | `1C610` | fuse fitted: "Naprawione!", teleport to hub |
| 134 | `1C654` | fuel +⅓ (sprite group 55) |
| 136/137 | `1C690` | energy +⅓ (group 53) |
| 138/139/140 | | "too far to jump" / bleeding man / heal him → red card |
| 141/142 | | magic key 21 / flower 30 |
| 160 | `1C7B0` | vending machine |
| 161 | `1CAB8` | magic-key slot counter → open force field |
| 162 | `1CB30` | Time Guardian takes the Time Key |
| 163 | `1CB70` | Time Guardian story; infinite ammo+fuel; give magazine |
| 164 | | "Zaufaj mocy, Lucek!" |
| 165 | `1CC2C` | **win** (`g_heroDead = 3`) |
| 192/193 | | magic key 18 / shaped piece |
| 194 | `1CCB0` | gum-chewer trade |
| 195/196 | | riddle man: give riddle / check answer |
| 198–201 | | teddy-bear quest |
| 202 | | flower 31 |
| 203/204 | | damaged teleport / its warning |
| 224 / 230 | | +$1 / +$10 |
| 225 / 228 / 226 / 227 / 229 | | give weapon 1 / 2 / 3 / 4 / 5 (note the order: 226 is the Uzi) |
| 231 / 232 / 233 | | ammo +⅓ / fuel can / full energy |
| 240 / 241 | | teleport menu / teleport to hub (0,0) |
| 255 | `1D4E0` | consume the selected item (used by every lock/reader) |

"Missing item" replies (by item id): 1 *"Nie tego mi potrzeba, kmiotku!"*, 2 *"Potrzebuję czerwonej karty…"*,
3/16 *"…przydałaby się fioletowa karta!"*, 4 *"Chyba przepalił się bezpiecznik…"*, 6 *"Przydałaby się czerwona
karta."*, 7 *"Rozbrojenie bomby to pestka… Jeśli ma się obcęgi…"*, 8 *"Wygląda na dziurkę od klucza"*,
10 *"Proszę! Pomóż mi, ugaś ten ogień"*, 12 *"Wygląda na jakiś dziwny zamek…"*, 13 *"Potrzebuję szarej karty."*,
14 grave inscription of Jouler, 17 ferryman's terms, 18–22 *"To tutaj nie pasuje…"*, 23 *"Skąd mam wytrzasnąć
taki klucz?"*, 25 *"To mi nie zastąpi mojej skarpety!"*, 26 gibberish, 29 *"Gdzie mój misio?!!"*, 33 the
witch is busy, 34 *"Po co mi jakiś kwiatek?!"* / *"Muszę użyć sekatora!"*, 35 *"To raczej nie jest Klucz Czasu…"*.

## 4.8 Known quirks of the original

* Using the riddle scroll when the third riddle was drawn shows the *second* riddle picture (the riddle man
  himself shows the right one).
* `/R<rate>` falls through to `/N` in the switch, so setting a sample rate also disables sound.
* Message 279 (pause) is never used; the game has no pause.
* The texts are stored three times in the EXE; only the first copy is referenced.
* Buying the wire cutters from the first merchant does not set flag 36, so his colleague at (9,3) only
  appears if you bought something else, refused, or could not pay.
* The vending machine's "energy" item restores only ⅓ of the bar, and is listed only when energy is not full.
* The second merchant's sweater and aqualung take your $14 and give nothing ("Mam wrażenie że dałem dupy…").
* The gum-chewer's "Chwila przyjemności" is a 5-second blackout (`delay(5000)` between two fades).

## 4.9 The handlers as data (`script_logic.json`)

All three handler tables of the EXE — 83 script handlers, 38 item-use handlers, 26 missing-item replies —
are transcribed op by op in [`tools/lazarus_scripts.py`](../../tools/lazarus_scripts.py) and exported to
`assets/gamedata/script_logic.json`. The extractor checks that every non-empty handler of the EXE tables is
covered (by handler address) and that every message, item and variable id is valid, so a remake can run
the quests from data instead of re-coding them. Example — the second merchant (script 37):

```json
["print", 45], ["menu", [46, 47, 48, 49]], ["clear"],
["if", ["eq", "choice", 3], [["say", 51]],
 [["if", ["money_lt", 14], [["say", 43]],
   [["say", 50], ["money", -14],
    ["if", ["eq", "choice", 1], [["give", 7]], [["wait"], ["clear"], ["say", 52]]]]]]]
```

| group | ops |
|---|---|
| dialogue | `say` (show, wait, clear), `say_keep` (show, wait), `print` (show only), `say_indexed m var` (message m + variable), `print_number`, `wait`, `clear`, `menu [options]` → `choice` (options may be conditional, `choice` is the index in the full list; `{"msg": m, "per_riddle_offset": 3}` shows message m + 3 × riddle). The menu leaves its text on screen; the handlers clear it right after (`Text_Clear` follows every `Dlg_Menu` in the EXE) |
| control | `if cond then else`, `switch var {value: ops}`, `call script` |
| inventory | `give item` (adds and selects it), `take item`, `take_selected` |
| state | `set`, `add`, `set_flag`, `money ±n`, `energy`/`fuel`/`ammo` (`full`, `+third`, `0`), `weapon n`, `activate_object i`, `random var n` |
| presentation | `teleport col row x y`, `picture frame`, `picture_var var`, `fade from to steps`, `show_pcx`, `sound`, `bomb_sound start/stop`, `delay ticks`, `delay_ms`, `explode`, `end_game death/joke_ending/win` |

Conditions: `money_lt`, `money_eq`, `has_item`, `eq`/`ne`/`lt` on a variable, `in_room`, `energy_full`,
`ammo_full`, `sock_here`, `and`/`or`/`not`. The variables (`state` in the JSON, with their EXE addresses and
new-game values) are the teleport passwords `pw_*`, the vending-machine stock `stock_*`, the random picks
(`bomb_wire`, `secret_door`, `sock_chest`, `riddle`, `shop_map`) and counters (`magazines`,
`cauldron_flowers`, `key_slots`). Messages not used by any handler belong to the engine: 251 (teleporting with
fuel), 280–283 (quit dialog), 284–292 (win sequence), and the unused 183 and 279.
