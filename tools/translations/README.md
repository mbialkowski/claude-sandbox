# Translations

`<lang>.json` maps every message id (0–292, see `assets/text/messages.json`) to translated text.
`extract_assets.py` merges it into `assets/text/messages_<lang>.json` (with the original's `{x}{y}{c}`
position/colour tags and leading/trailing whitespace re-attached, so menus keep their spacing) and into the
`text_en` column of `assets/text/messages.csv`. It warns when a line drawn in the game's dialogue font would
run past 264 px (the widest Polish line) unless the original line was already that wide.

Rules: keep the line breaks of the original (each line is drawn where the original drew it); keep `$` prices,
the `|` prefix of the riddle answers (185–193) and the gibberish of 161/165 unchanged.

## English (`en.json`) — translator's notes

* Place names follow the teleport menu: Zapomniana Świątynia = Forgotten Temple, Zaświaty = Netherworld,
  Otchłań = Abyss, Ukryta Dolina = Hidden Valley, Kraina Grozy = Land of Terror, Sala treningowa =
  Training Room. Passwords in dialogue use the same names.
* 74: the whistle hint keeps the Polish word **TARAPATY** ("trouble") because the sign in room (1,5) that
  tells you where to whistle is a Polish graphic (sprite group 117). A remake that redraws the sign as
  TROUBLE should drop the Polish word.
* 11–13: the bomb-wire hints are nonsense rhymes whose only job is the colour word (red/green/blue).
* Names: Lucek (the hero; 207 parodies "Use the Force, Luke"), Jouler de Generat (pun on *degenerat*),
  Gereon Świniopas → Gereon Swineherd, Jaś Wędrowniczek → Johnny the Wanderer; Long John Silver and
  Jaksra Tokwili unchanged. "Pani Domu" (a real Polish women's magazine) → "Lady of the House".
* The original is deliberately crude in places (35, 52, 64, 172); the register was kept.
* 103 "To chluśniem, bo uśniem!" is a Polish drinking toast → "Bottoms up, before we doze off!";
  154 quotes a well-known Polish anti-drinking line → literal translation.
* Needs a review by a native English speaker who knows the Polish pop-culture references.
