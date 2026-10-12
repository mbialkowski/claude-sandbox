extends RefCounted
## Texts of the remake's own menus (the game's texts come from data/text_pl.json / text_en.json).
## Only characters of the original font may be used (Polish letters are fine).

const T := {
	"pl": {
		"options": "Opcje", "lang_name": "Polski", "opt_language": "Język / Language",
		"opt_neighbours": "Sąsiednie komnaty", "opt_dim": "Przyciemnij sąsiednie",
		"opt_smooth": "Skalowanie", "smooth": "gładkie", "sharp": "ostre",
		"opt_touch": "Sterowanie dotykowe", "touch_auto": "auto", "touch_on": "tak", "touch_off": "nie",
		"opt_music": "Muzyka", "opt_sfx": "Efekty", "opt_fullscreen": "Pełny ekran",
		"on": "tak", "off": "nie", "back": "Powrót", "paused": "Pauza", "continue": "Graj dalej",
		"quit_title": "Wyjdź do menu", "thanks": "Dzięki za grę w Lazarusa!",
		"fire": "OGIEŃ", "jump": "SKOK", "use": "UŻYJ", "jet": "PLECAK",
	},
	"en": {
		"options": "Options", "lang_name": "English", "opt_language": "Język / Language",
		"opt_neighbours": "Neighbouring rooms", "opt_dim": "Dim neighbours",
		"opt_smooth": "Scaling", "smooth": "smooth", "sharp": "sharp",
		"opt_touch": "Touch controls", "touch_auto": "auto", "touch_on": "on", "touch_off": "off",
		"opt_music": "Music", "opt_sfx": "Sound effects", "opt_fullscreen": "Full screen",
		"on": "on", "off": "off", "back": "Back", "paused": "Paused", "continue": "Continue",
		"quit_title": "Quit to title", "thanks": "Thanks for playing Lazarus!",
		"fire": "FIRE", "jump": "JUMP", "use": "USE", "jet": "JET",
	},
}


static func t(key: String) -> String:
	var D = Engine.get_main_loop().root.get_node("/root/Data")
	var lang: String = D.settings["language"]
	return T.get(lang, T["pl"]).get(key, key)
