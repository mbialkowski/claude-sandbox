extends SceneTree
## Loads every script so parse errors show up:  godot --headless --path remake --script res://tests/check.gd


func _initialize() -> void:
	var bad := 0
	for dir in ["res://scripts", "res://scripts/sim", "res://scripts/game", "res://scripts/view", "res://tests"]:
		for f in DirAccess.get_files_at(dir):
			if f.ends_with(".gd"):
				var s = load(dir.path_join(f))
				if s == null or not s.can_instantiate():
					print("FAILED: ", dir.path_join(f))
					bad += 1
	for f in ["game.json", "scripts.json", "text_pl.json", "text_en.json", "sounds.bin", "sprites.png",
			"tiles_platform.png", "tiles_background.png", "hud_panel.png", "font_body.png", "music_title.ogg"]:
		if not FileAccess.file_exists("res://data/" + f):
			print("MISSING: res://data/" + f)
			bad += 1
	print("scripts checked, %d failed" % bad)
	quit(1 if bad else 0)
