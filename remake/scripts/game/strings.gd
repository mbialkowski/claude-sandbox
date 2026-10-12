extends RefCounted
## Texts of the remake's own menus (the game's texts come from data/text_pl.json / text_en.json).
## Only characters of the original font may be used (Polish letters are fine).

const T := {
	"pl": {
		"options": "Opcje", "lang_name": "Polski", "opt_language": "Język / Language",
		"opt_neighbours": "Sąsiednie komnaty", "opt_dim": "Przyciemnij sąsiednie",
		"opt_smooth": "Skalowanie", "smooth": "gładkie", "sharp": "ostre",
		"opt_edges": "Przejścia między komnatami", "edges_classic": "jak w oryginale",
		"edges_seamless": "płynne",
		"opt_touch": "Sterowanie dotykowe", "touch_auto": "auto", "touch_on": "tak", "touch_off": "nie",
		"opt_music": "Muzyka", "opt_sfx": "Efekty", "opt_fullscreen": "Pełny ekran",
		"on": "tak", "off": "nie", "back": "Powrót", "paused": "Pauza", "continue": "Graj dalej",
		"quit_title": "Wyjdź do menu", "thanks": "Dzięki za grę w Lazarusa!",
		"fire": "OGIEŃ", "jump": "SKOK", "use": "UŻYJ", "jet": "PLECAK", "full": "[ ]", "inv": "RZECZ", "wpn": "BROŃ",
		"press_key": "Naciśnij klawisz lub dotknij ekranu", "skip": "Spacja / Esc / dotknij - pomiń",
	},
	"en": {
		"options": "Options", "lang_name": "English", "opt_language": "Język / Language",
		"opt_neighbours": "Neighbouring rooms", "opt_dim": "Dim neighbours",
		"opt_smooth": "Scaling", "smooth": "smooth", "sharp": "sharp",
		"opt_edges": "Room edges", "edges_classic": "original",
		"edges_seamless": "seamless",
		"opt_touch": "Touch controls", "touch_auto": "auto", "touch_on": "on", "touch_off": "off",
		"opt_music": "Music", "opt_sfx": "Sound effects", "opt_fullscreen": "Full screen",
		"on": "on", "off": "off", "back": "Back", "paused": "Paused", "continue": "Continue",
		"quit_title": "Quit to title", "thanks": "Thanks for playing Lazarus!",
		"fire": "FIRE", "jump": "JUMP", "use": "USE", "jet": "JET", "full": "[ ]", "inv": "ITEM", "wpn": "GUN",
		"press_key": "Press a key or tap the screen", "skip": "Space / Esc / tap - skip",
		# subtitles for the text painted into the intro's pictures (docs 06, 6.2)
		"intro_1": "...it all started quite normally, and I would never have guessed it would end so badly...",
		"intro_2": "I went to the shop for the newest game - LAZARUS or something like that... I'd heard it was really good, so I got a bit excited. Everything went normally... well, except that this time the shop was a bit far. And the way back dragged on and on...",
		"intro_3": "And finally I got to my cosy little cottage on the allotment. Now only seconds separated me from the moment I'd put the disk in and...",
		"intro_4": "...what the [censored], what's going on!!! - I swore horribly, because things looked really grim - the game wouldn't start. I'd had enough of staring at the screen and nervously grabbed the manual for help...",
		"intro_5": "\"...Colonel Colonel has been locked in a labyrinth... blah blah blah...\" - just some silly story and a note saying the game should simply start! BUT SUDDENLY THE SCREEN WENT CRAZY!!!...",
		"intro_6": "...and then it was just boom... crash... flashes... smoke... and all that. And in the end I ended up here. Hmm... I guess that's all...",
		"intro_7": "oh... one more little thing...",
		"intro_8": "GET ME OUT OF HERE!",
	},
}


static func t(key: String) -> String:
	var D = Engine.get_main_loop().root.get_node("/root/Data")
	var lang: String = D.settings["language"]
	return T.get(lang, T["pl"]).get(key, key)
