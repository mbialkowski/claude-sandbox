# 8. History of the game

Background for the remake. The in-game credits (6.5, credits scroller text) are first-hand; everything else comes
from web databases (MobyGames, Lemon Amiga, Lemon64, MyAbandonware, Commodore News), whose pages could only
be read through search-result summaries here, so treat dates marked *(db)* as unverified.

## 8.1 Three games called Lazarus

| year | platform | developer / publisher | people | relation |
|---|---|---|---|---|
| 1994 *(db)* | Commodore 64 | Inflexion Development / TimSoft | Krzysztof Augustyn (code, graphics) | the original idea; databases note it *looks similar to the Amiga game but plays differently* |
| 1995 *(db)* | Amiga (OCS, multi-screen platformer; disk images dated 1995-12-11) | Infinite Dreams / TimSoft | Marek Augustyn (code, per Lemon Amiga) | the direct ancestor of this version |
| 1996/1997 | MS-DOS (this repository) | Infinite Dreams / TimSoft | see 8.2 | port/remake of the Amiga game |

* The DOS credits say **"Na podstawie gry Lazarus by Krzysztof Augustyn"** — *based on the game Lazarus by
  Krzysztof Augustyn*, i.e. the C64 game.
* The DOS release year is uncertain: MobyGames and MyAbandonware list **1997**; this repository used 1996.
  The executable was built with Watcom C/C++ 10.x (run-time copyright 1988–1995) and contains no date.
* The DOS data files are big-endian Amiga formats (word order of NEWROOM/OBJECTS/PSIZES, MOD music,
  planar graphics converted to Mode X) — the levels were authored for the Amiga and converted, which
  matches the port history.
* In November 2015 a Polish group that wraps Amiga games in a preconfigured WinUAE added the Amiga Lazarus
  to its Windows collection *(db)*.

## 8.2 People (from the DOS credits)

| role | name |
|---|---|
| code | Marcin Pancewicz |
| graphics, intro | Tomasz Kostrzewski |
| music | Wojciech Panufnik ("Snoopy" of Scope / Energy) |
| story, ideas, dialogues | Marek Augustyn, Tomasz Kostrzewski |
| sound effects | Marek Augustyn |
| based on the game by | Krzysztof Augustyn |

## 8.3 The studio

Infinite Dreams is from **Gliwice, Poland**. Before the company was formally founded (1997, per
Wikipedia) the team released Amiga titles through publishers such as TimSoft and Mirage Media — e.g. the
puzzle game *Pinomania* (1994, Mirage Media; Marek Augustyn code, Tomasz Kostrzewski graphics). Databases
also list *Alien Target*, *Desert Wolf* and *Mr. Tomato* among its 1990s games. Tomasz Kostrzewski is the
company's CEO today; the studio is best known for the *Sky Force* series.

## 8.4 What this means for the remake

* The DOS version is the most complete and the one documented here; the Amiga version (1995) is the
  reference for the original look and possibly for differences in level design — comparing the two would
  need the Amiga disk images (not in this repository).
* The C64 game is a different design and not a useful reference.
* Rights: Infinite Dreams still exists and its CEO is one of the original authors — the natural contact
  for permission to reuse the original assets (5.6).

## Sources

* [MobyGames — Lazarus (1995)](https://www.mobygames.com/game/65635/lazarus/) and
  [Lazarus (1994, C64)](https://www.mobygames.com/game/39484/lazarus/)
* [Lemon Amiga — Lazarus](https://www.lemonamiga.com/game/lazarus),
  [Pinomania](https://www.lemonamiga.com/game/pinomania)
* [Lemon64 — Lazarus](https://www.lemon64.com/game/lazarus)
* [MyAbandonware — Lazarus](https://www.myabandonware.com/game/lazarus-7d8)
* [Commodore News — Windows releases of Polish Amiga games](https://commodore-news.com/news/item/4438/en/mobile)
* [Wikipedia — Infinite Dreams Inc.](https://en.wikipedia.org/wiki/Infinite_Dreams_Inc.)
