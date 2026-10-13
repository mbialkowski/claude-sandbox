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
		"opt_music": "Muzyka", "opt_game_music": "Muzyka w grze", "opt_sfx": "Efekty",
		"opt_fullscreen": "Pełny ekran",
		"on": "tak", "off": "nie", "back": "Powrót", "paused": "Pauza", "continue": "Graj dalej",
		"quit_title": "Wyjdź do menu", "thanks": "Dzięki za grę w Lazarusa!",
		"fire": "STRZAŁ", "jump": "SKOK", "use": "UŻYJ", "jet": "JETPACK", "full": "[ ]", "inv": "RZECZ", "wpn": "BROŃ",
		"controls": "Sterowanie", "opt_sound": "Dźwięk",
		"ctl_walk": "Chodzenie", "ctl_key_walk": "strzałki <- ->, A D", "ctl_touch_walk": "krzyżak <- ->",
		"ctl_jump": "Skok, lot jetpackiem", "ctl_key_jump": "strzałka w górę, W", "ctl_touch_jump": "SKOK",
		"ctl_crouch": "Kucnij, podnieś", "ctl_key_crouch": "strzałka w dół, S", "ctl_touch_crouch": "krzyżak w dół",
		"ctl_fire": "Strzał", "ctl_key_fire": "Ctrl, J, X", "ctl_touch_fire": "STRZAŁ",
		"ctl_use": "Użyj, rozmawiaj", "ctl_key_use": "Enter, E, K", "ctl_touch_use": "UŻYJ",
		"ctl_jet": "Jetpack wł. / wył.", "ctl_key_jet": "Spacja, L", "ctl_touch_jet": "JETPACK",
		"ctl_item": "Zmień rzecz", "ctl_key_item": ",  .  Q  Tab", "ctl_touch_item": "RZECZ lub panel",
		"ctl_weapon": "Zmień broń", "ctl_key_weapon": "1-6, R", "ctl_touch_weapon": "BROŃ lub panel",
		"ctl_pause": "Pauza, opcje", "ctl_key_pause": "Esc, P", "ctl_touch_pause": "II",
		"ctl_dialogue": "Dalej w rozmowie", "ctl_key_dialogue": "Enter, Spacja, Ctrl",
		"ctl_touch_dialogue": "dotknij ekranu",
		"ctl_menu": "Wybór w menu", "ctl_key_menu": "strzałki, Enter", "ctl_touch_menu": "dotknij opcji",
		"portrait_tip": "Obróć telefon pionowo - wygodniej się gra",
		"press_key": "Naciśnij klawisz lub dotknij ekranu", "skip": "Spacja / Esc / dotknij - pomiń",
	},
	"en": {
		"options": "Options", "lang_name": "English", "opt_language": "Język / Language",
		"opt_neighbours": "Neighbouring rooms", "opt_dim": "Dim neighbours",
		"opt_smooth": "Scaling", "smooth": "smooth", "sharp": "sharp",
		"opt_edges": "Room edges", "edges_classic": "original",
		"edges_seamless": "seamless",
		"opt_touch": "Touch controls", "touch_auto": "auto", "touch_on": "on", "touch_off": "off",
		"opt_music": "Music", "opt_game_music": "Music while playing", "opt_sfx": "Sound effects",
		"opt_fullscreen": "Full screen",
		"on": "on", "off": "off", "back": "Back", "paused": "Paused", "continue": "Continue",
		"quit_title": "Quit to title", "thanks": "Thanks for playing Lazarus!",
		"fire": "FIRE", "jump": "JUMP", "use": "USE", "jet": "JETPACK", "full": "[ ]", "inv": "ITEM", "wpn": "GUN",
		"controls": "Controls", "opt_sound": "Sound",
		"ctl_walk": "Walk", "ctl_key_walk": "arrows <- ->, A D", "ctl_touch_walk": "pad <- ->",
		"ctl_jump": "Jump, jetpack thrust", "ctl_key_jump": "up arrow, W", "ctl_touch_jump": "JUMP",
		"ctl_crouch": "Crouch, pick up", "ctl_key_crouch": "down arrow, S", "ctl_touch_crouch": "pad down",
		"ctl_fire": "Fire", "ctl_key_fire": "Ctrl, J, X", "ctl_touch_fire": "FIRE",
		"ctl_use": "Use, talk", "ctl_key_use": "Enter, E, K", "ctl_touch_use": "USE",
		"ctl_jet": "Jetpack on / off", "ctl_key_jet": "Space, L", "ctl_touch_jet": "JETPACK",
		"ctl_item": "Change item", "ctl_key_item": ",  .  Q  Tab", "ctl_touch_item": "ITEM or the panel",
		"ctl_weapon": "Change weapon", "ctl_key_weapon": "1-6, R", "ctl_touch_weapon": "GUN or the panel",
		"ctl_pause": "Pause, options", "ctl_key_pause": "Esc, P", "ctl_touch_pause": "II",
		"ctl_dialogue": "Continue a dialogue", "ctl_key_dialogue": "Enter, Space, Ctrl",
		"ctl_touch_dialogue": "tap the screen",
		"ctl_menu": "Choose in a menu", "ctl_key_menu": "arrows, Enter", "ctl_touch_menu": "tap an option",
		"portrait_tip": "Turn your phone upright - it plays better",
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
