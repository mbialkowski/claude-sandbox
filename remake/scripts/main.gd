extends Control
## Lazarus remake: title menu, options, the game, dialogues, pictures and endings.
## The game is drawn in palette indices into an indexed SubViewport (screen.gd) and coloured / scaled by
## palette.gdshader; the logical screen is 240 px high and as wide as the window's aspect (320..640),
## the hero's room centred with its neighbours around it and the original HUD panel on the right.

const Screen = preload("res://scripts/view/screen.gd")
const Palette = preload("res://scripts/view/palette.gd")
const TextLayer = preload("res://scripts/view/text_layer.gd")
const Touch = preload("res://scripts/view/touch.gd")
const Sim = preload("res://scripts/sim/sim.gd")
const Audio = preload("res://scripts/game/audio.gd")
const VM = preload("res://scripts/game/script_vm.gd")
const Strings = preload("res://scripts/game/strings.gd")

signal continue_pressed
signal menu_finished(index: int)

const H := 240
const ACTIONS := ["left", "right", "up", "down", "fire", "use", "jetpack", "item_prev", "item_next",
		"weapon_next", "weapon_1", "weapon_2", "weapon_3", "weapon_4", "weapon_5", "weapon_6", "pause",
		"fullscreen"]
const CONTINUE_ACTIONS := ["fire", "use", "jetpack"]
const LANGS := ["pl", "en"]
const INTRO_END_TICKS := 200                         # "WYDOSTAŃ MNIE STĄD!" stays 4 s before the title

var D
var viewport: SubViewport
var screen: Node2D
var display: TextureRect
var shader_mat: ShaderMaterial
var picture: TextureRect
var subtitle: Label
var intro_skip := false
var touch: Control
var audio
var vm
var palette
var text
var text_origin := Vector2(0, 6)
var sim = null

var mode := "boot"             # title, options, play, pause, gameover, ending, credits, anim
var hero_visible := true
var hud_visible := true
var logical_w := 320
var display_rect := Rect2()
var portrait := false

var held := {}
var pressed_now := {}
var released_now := {}
var carry_release := {}
var last_x := 0
var waiting := false
var menu = null                # {"items": [[index, msg]...], "sel", "origin", "base", "rows"}
var ui_sel := 0                # title / options / pause cursor
var picture_frame := -1        # ShowPicture (index space)
var anim_frame := ""           # file of an animation frame shown full screen (index space)
var anim_tex: Texture2D = null
var anim_cache := {}
var options_from := "title"
var cheat_buf := ""
var credits_y := 0.0
var notice := ""
var notice_ticks := 0
var last_saved_room := Vector2i(-1, -1)
var fullscreen_supported = null               # see can_fullscreen()
var phone = null                              # see is_phone()

const SAVE_PATH := "user://save.json"


func _ready() -> void:
	D = get_node("/root/Data")
	_setup_input_map()
	set_anchors_preset(Control.PRESET_FULL_RECT)
	mouse_filter = Control.MOUSE_FILTER_PASS
	viewport = SubViewport.new()
	viewport.size = Vector2i(320, H)
	viewport.disable_3d = true
	viewport.transparent_bg = false
	viewport.canvas_item_default_texture_filter = Viewport.DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_NEAREST
	viewport.render_target_update_mode = SubViewport.UPDATE_ALWAYS
	add_child(viewport)
	screen = Screen.new()
	viewport.add_child(screen)
	screen.setup(D, self)
	palette = Palette.new(D)
	text = TextLayer.new(D)
	display = TextureRect.new()
	display.texture = viewport.get_texture()
	display.expand_mode = TextureRect.EXPAND_IGNORE_SIZE
	display.stretch_mode = TextureRect.STRETCH_SCALE
	display.mouse_filter = Control.MOUSE_FILTER_IGNORE
	shader_mat = ShaderMaterial.new()
	shader_mat.shader = load("res://scripts/view/palette.gdshader")
	shader_mat.set_shader_parameter("idx_tex", viewport.get_texture())
	shader_mat.set_shader_parameter("pal_tex", palette.texture)
	display.material = shader_mat
	add_child(display)
	picture = TextureRect.new()
	picture.expand_mode = TextureRect.EXPAND_IGNORE_SIZE
	picture.stretch_mode = TextureRect.STRETCH_KEEP_ASPECT_CENTERED
	picture.texture_filter = CanvasItem.TEXTURE_FILTER_LINEAR
	picture.mouse_filter = Control.MOUSE_FILTER_IGNORE
	picture.visible = false
	var pm := ShaderMaterial.new()
	pm.shader = load("res://scripts/view/sharp.gdshader")
	picture.material = pm
	add_child(picture)
	subtitle = Label.new()
	subtitle.autowrap_mode = TextServer.AUTOWRAP_WORD_SMART
	subtitle.horizontal_alignment = HORIZONTAL_ALIGNMENT_CENTER
	subtitle.vertical_alignment = VERTICAL_ALIGNMENT_BOTTOM
	subtitle.add_theme_color_override("font_color", Color(1, 0.95, 0.8))
	subtitle.add_theme_color_override("font_outline_color", Color(0, 0, 0))
	subtitle.add_theme_constant_override("outline_size", 6)
	subtitle.mouse_filter = Control.MOUSE_FILTER_IGNORE
	subtitle.visible = false
	add_child(subtitle)
	touch = Touch.new()
	touch.main = self
	add_child(touch)
	audio = Audio.new()
	add_child(audio)
	audio.setup(D)
	vm = VM.new()
	add_child(vm)
	vm.setup(D, self)
	get_viewport().size_changed.connect(_layout)
	_layout()
	var autotest := ""
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--shots="):
			autotest = arg.substr(8)
		elif arg.begins_with("--intro-shots="):
			_intro_shots(arg.substr(14))
			return
	if autotest != "":
		_title()
		_autotest(autotest)
	elif OS.has_feature("web"):
		_press_key()                                   # browsers start audio only after an input
	else:
		_intro()


# ---------------------------------------------------------------------------
# automated smoke test: godot --path remake -- --shots=DIR  (screenshots, then quit)
# ---------------------------------------------------------------------------
func _shot(dir: String, name: String) -> void:
	await RenderingServer.frame_post_draw
	get_viewport().get_texture().get_image().save_png(dir.path_join(name + ".png"))


func _hold(a: String, ticks: int) -> void:
	action_press(a)
	await wait_ticks(ticks)
	action_release(a)


func _autotest(dir: String) -> void:
	DirAccess.make_dir_recursive_absolute(dir)
	D.settings["smooth_scaling"] = false                 # exact pixels for comparisons with the original
	await wait_ticks(40)
	await _shot(dir, "01_title")
	_new_game()
	await wait_ticks(60)
	await _shot(dir, "02_start")
	await _hold("right", 120)
	await wait_ticks(5)
	await _shot(dir, "03_walk")
	await _hold("up", 20)
	await wait_ticks(30)
	await _shot(dir, "04_jump")
	action_tap("use")
	await wait_ticks(10)
	await _shot(dir, "05_use")
	action_tap("use")
	await wait_ticks(10)
	# the merchant in (8,1): shop menu
	_warp(8, 1, 36, 80)
	await wait_ticks(5)
	action_tap("use")
	await wait_ticks(30)
	await _shot(dir, "06_shop")
	action_tap("down")
	await wait_ticks(5)
	await _shot(dir, "07_shop_down")
	action_tap("use")
	await wait_ticks(10)
	await _shot(dir, "08_shop_bought")
	action_tap("use")
	await wait_ticks(10)
	# jetpack flight with fuel
	sim.state.fuel = sim.state.FULL
	action_tap("jetpack")
	action_press("up")
	await wait_ticks(25)
	action_release("up")
	await _shot(dir, "09_jetpack")
	await wait_ticks(60)
	# pause and options
	action_tap("pause")
	await wait_ticks(5)
	await _shot(dir, "10_pause")
	action_tap("down")
	action_tap("use")
	await wait_ticks(5)
	await _shot(dir, "11_options")
	ui_sel = _option_list().map(func(r): return r[2]).find("sound")
	_options_input("use")                             # sound off: the levels are greyed out
	await wait_ticks(3)
	await _shot(dir, "11b_options_sound_off")
	_options_input("use")
	action_tap("pause")                               # back to the pause menu, then Controls
	await wait_ticks(3)
	action_tap("down")
	action_tap("use")
	await wait_ticks(3)
	await _shot(dir, "11c_controls")
	action_tap("use")
	await wait_ticks(3)
	action_tap("pause")
	await wait_ticks(3)
	# a picture (the shop map)
	sim.state.give(37)
	sim.state.key_enter = true
	await wait_ticks(120)
	await _shot(dir, "12_picture")
	action_tap("use")
	await wait_ticks(120)
	# shoot
	_warp(8, 0, 40, 160)
	await wait_ticks(5)
	for i in 4:
		action_tap("fire")
		await wait_ticks(3)
	await _shot(dir, "13_shoot")
	# death -> game over
	sim.state.energy = 0
	sim.hero.hit = true
	await wait_ticks(120)
	await _shot(dir, "14_game_over")
	action_tap("use")
	await wait_ticks(30)
	ui_sel = TITLE_ITEMS.find("credits")
	_title_input("use")
	await wait_ticks(40)
	await _shot(dir, "15_credits_anim")
	action_tap("use")
	await wait_ticks(20)
	_new_game()
	await wait_ticks(40)
	sim.end_state = "win"
	await wait_ticks(100 + 90 * 4)
	await _shot(dir, "16_ending_text")
	await wait_ticks(90 * 5 + 120)
	await _shot(dir, "17_ending_fist")
	await wait_ticks(300)
	await _shot(dir, "18_credits_scroll")
	print("autotest done")
	get_tree().quit()


func _intro_shots(dir: String) -> void:
	DirAccess.make_dir_recursive_absolute(dir)
	D.settings["language"] = "en"
	_intro()
	var elapsed := 0
	for t in [3, 12, 24, 40, 62, 75, 100, 108, 111, 115]:
		await wait_ticks(t * 50 - elapsed)
		elapsed = t * 50
		await _shot(dir, "intro_%03d" % t)
	get_tree().quit()


func _warp(c: int, r: int, x: int, y: int) -> void:
	sim.hero.place(c, r, x, y, 1)
	sim.on_hero_room_changed(true)
	screen.follow(c, r, true)


# ---------------------------------------------------------------------------
# layout
# ---------------------------------------------------------------------------
func _layout() -> void:
	var win := get_viewport_rect().size
	if win.x <= 0 or win.y <= 0:
		return
	var aspect := win.x / win.y
	var scale: float
	portrait = aspect < 1.0
	if not portrait:
		logical_w = clampi(roundi(H * aspect), 320, 640)
		scale = win.y / H
		if logical_w * scale > win.x + 0.5:
			scale = win.x / logical_w
		var w := logical_w * scale
		display_rect = Rect2((win.x - w) / 2.0, (win.y - H * scale) / 2.0, w, H * scale)
	else:
		logical_w = 320
		scale = win.x / 320.0
		display_rect = Rect2(0, maxf(0.0, (win.y * 0.42 - H * scale) / 2.0), win.x, H * scale)
	viewport.size = Vector2i(logical_w, H)
	screen.set_width(logical_w)
	display.position = display_rect.position
	display.size = display_rect.size
	picture.position = Vector2.ZERO
	picture.size = win
	shader_mat.set_shader_parameter("src_size", Vector2(logical_w, H))
	shader_mat.set_shader_parameter("out_scale", Vector2(scale, scale))
	shader_mat.set_shader_parameter("view_w", float(screen.view_w))
	touch.position = Vector2.ZERO
	touch.size = win
	touch.relayout()
	if sim:
		screen.follow(sim.hero.col, sim.hero.row, true)
	text_origin = screen.room_screen_origin()


func screen_to_logical(p: Vector2) -> Vector2:
	return (p - display_rect.position) / display_rect.size * Vector2(logical_w, H)


# ---------------------------------------------------------------------------
# input
# ---------------------------------------------------------------------------
func _setup_input_map() -> void:
	var keys := {
		"left": [KEY_LEFT, KEY_A], "right": [KEY_RIGHT, KEY_D], "up": [KEY_UP, KEY_W],
		"down": [KEY_DOWN, KEY_S], "fire": [KEY_CTRL, KEY_J, KEY_X], "use": [KEY_ENTER, KEY_KP_ENTER, KEY_E, KEY_K],
		"jetpack": [KEY_SPACE, KEY_L], "item_prev": [KEY_COMMA, KEY_Q, KEY_PAGEUP],
		"item_next": [KEY_PERIOD, KEY_TAB, KEY_PAGEDOWN], "weapon_next": [KEY_R],
		"weapon_1": [KEY_1], "weapon_2": [KEY_2], "weapon_3": [KEY_3], "weapon_4": [KEY_4],
		"weapon_5": [KEY_5], "weapon_6": [KEY_6], "pause": [KEY_ESCAPE, KEY_P], "fullscreen": [KEY_F11],
	}
	var pads := {
		"left": [JOY_BUTTON_DPAD_LEFT], "right": [JOY_BUTTON_DPAD_RIGHT], "up": [JOY_BUTTON_DPAD_UP, JOY_BUTTON_A],
		"down": [JOY_BUTTON_DPAD_DOWN], "fire": [JOY_BUTTON_X], "use": [JOY_BUTTON_B], "jetpack": [JOY_BUTTON_Y],
		"item_prev": [JOY_BUTTON_LEFT_SHOULDER], "item_next": [JOY_BUTTON_RIGHT_SHOULDER],
		"weapon_next": [JOY_BUTTON_BACK], "pause": [JOY_BUTTON_START],
	}
	var axes := {"left": [JOY_AXIS_LEFT_X, -1.0], "right": [JOY_AXIS_LEFT_X, 1.0],
			"up": [JOY_AXIS_LEFT_Y, -1.0], "down": [JOY_AXIS_LEFT_Y, 1.0], "fire": [JOY_AXIS_TRIGGER_RIGHT, 1.0]}
	for a in ACTIONS:
		if not InputMap.has_action(a):
			InputMap.add_action(a, 0.5)
		for k in keys.get(a, []):
			var e := InputEventKey.new()
			e.physical_keycode = k
			InputMap.action_add_event(a, e)
		for b in pads.get(a, []):
			var e := InputEventJoypadButton.new()
			e.button_index = b
			InputMap.action_add_event(a, e)
		if axes.has(a):
			var e := InputEventJoypadMotion.new()
			e.axis = axes[a][0]
			e.axis_value = axes[a][1]
			InputMap.action_add_event(a, e)
		held[a] = false


func _input(event: InputEvent) -> void:
	if event is InputEventKey and event.pressed and not event.echo:
		_cheat(event)
		if event.keycode == KEY_ENTER and event.alt_pressed:
			toggle_fullscreen()
			return
		if mode == "intro" and not event.is_action("fullscreen"):
			_skip_intro()
			return
	if event is InputEventMouseButton and event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
		tap(event.position)
		return
	for a in ACTIONS:
		if event.is_action_pressed(a, false):
			action_press(a)
		elif event.is_action_released(a):
			action_release(a)


func action_press(a: String) -> void:
	if held.get(a, false):
		return
	held[a] = true
	pressed_now[a] = true
	_on_press(a)


func action_release(a: String) -> void:
	if not held.get(a, false):
		return
	held[a] = false
	released_now[a] = true


func _on_press(a: String) -> void:
	"""Presses that act immediately (menus, dialogues), outside the 50 Hz game input."""
	if a == "fullscreen":
		toggle_fullscreen()
		return
	if menu != null:
		match a:
			"up":
				menu["sel"] = (menu["sel"] - 1 + menu["items"].size()) % menu["items"].size()
				_draw_menu()
			"down":
				menu["sel"] = (menu["sel"] + 1) % menu["items"].size()
				_draw_menu()
			"use", "jetpack":
				_choose(menu["sel"])
		return
	if mode == "intro":
		_skip_intro()
		return
	if waiting:
		if a in CONTINUE_ACTIONS:
			waiting = false
			continue_pressed.emit()
		return
	match mode:
		"press":
			_press_input(a)
			return
		"title":
			_title_input(a)
		"options":
			_options_input(a)
		"controls":
			if a in ["use", "jetpack", "fire", "pause"]:
				_leave_controls()
		"pause":
			_pause_input(a)
		"play":
			if a == "pause" and not vm.busy:
				_open_pause()
		"gameover", "credits":
			if a in CONTINUE_ACTIONS or a == "pause":
				_title()
		"anim":
			if a in CONTINUE_ACTIONS or a == "pause":
				anim_frame = ""
				_title()


func tap(pos: Vector2) -> void:
	"""A click or a touch that is not on a control: continue a dialogue, pick a menu entry, use the HUD."""
	var p := screen_to_logical(pos)
	if menu != null:
		for i in menu["rows"].size():
			var r: Rect2 = menu["rows"][i]
			if r.grow(2).has_point(p - text_origin):
				_choose(i)
				return
		return
	if mode == "press":
		var rects := _lang_rects()
		for i in rects.size():
			if rects[i].has_point(p):
				_set_language(LANGS[i])
		_intro()
		return
	if mode == "intro":
		_skip_intro()
		return
	if waiting:
		waiting = false
		continue_pressed.emit()
		return
	match mode:
		"title":
			var rects := _title_rects()
			for i in rects.size():
				if rects[i].has_point(p) and _title_enabled(TITLE_ITEMS[i]):
					ui_sel = i
					_title_input("use")
					return
		"options", "pause":
			var rows := _ui_rows()
			for i in rows.size():
				if rows[i].has_point(p):
					if mode == "options" and not _option_enabled(_option_list()[i][2]):
						return
					ui_sel = i
					if mode == "options":
						_options_input("use")
					else:
						_pause_input("use")
					return
		"controls":
			_leave_controls()
		"play":
			if p.x >= screen.view_w:
				var hp := p - Vector2(screen.view_w, 0)
				if Rect2(24, 202, 32, 32).has_point(hp):
					action_tap("item_next")
				elif Rect2(4, 10, 68, 26).has_point(hp):
					action_tap("weapon_next")
		"gameover", "credits", "anim":
			_on_press("use")


func action_tap(a: String) -> void:
	action_press(a)
	action_release(a)


func _cheat(e: InputEventKey) -> void:
	if mode != "play" or sim == null:
		return
	var k := e.keycode
	if k < KEY_A or k > KEY_Z:
		return
	cheat_buf = (cheat_buf + char(k)).right(6)
	var st = sim.state
	match cheat_buf:
		"IDMORT":
			st.immortal = not st.immortal
		"IDSIAR":
			st.infinite = not st.infinite
		"IDLUFA":
			for i in 6:
				st.owned[i] = true
		"IDBULL":
			st.energy = st.FULL
			st.ammo[st.weapon] = st.FULL
		_:
			return
	audio.play(33)
	_notice(cheat_buf)
	cheat_buf = ""


func _game_input() -> void:
	"""ProcessInput (0x2A614) on the latched events of this tick."""
	var st = sim.state
	var h = sim.hero
	for a in carry_release:
		released_now[a] = true
	carry_release.clear()
	for a in released_now.keys():
		if pressed_now.has(a):                         # pressed and released within one tick
			released_now.erase(a)
			carry_release[a] = true
	if pressed_now.has("left"):
		last_x = -1
	if pressed_now.has("right"):
		last_x = 1
	var l: bool = held["left"] or pressed_now.has("left")
	var r: bool = held["right"] or pressed_now.has("right")
	h.input_x = -1 if l and not r else (1 if r and not l else (last_x if l and r else 0))
	if (held["up"] or pressed_now.has("up")) and not st.key_up:
		h.input_y = -1
		st.key_up = true
	if released_now.has("up") and not held["up"]:
		h.input_y = 0
		st.key_up = false
	st.key_down = held["down"] or pressed_now.has("down")
	if held["fire"] or pressed_now.has("fire"):
		st.key_fire = true
	if released_now.has("fire") and not held["fire"]:
		st.key_fire = false
		st.fire_armed = not st.key_down and not st.plasma_out
	if pressed_now.has("use") and not st.key_down:
		st.key_enter = true
	elif released_now.has("use") and not held["use"]:
		st.key_enter = false
	if pressed_now.has("jetpack"):
		st.jet_on = not st.jet_on
		if st.fuel == 0:
			st.jet_on = false
	if pressed_now.has("item_prev"):
		st.prev_item()
	if pressed_now.has("item_next"):
		st.next_item()
	for i in 6:
		if pressed_now.has("weapon_%d" % (i + 1)) and st.owned[i]:
			_select_weapon(i)
	if pressed_now.has("weapon_next"):
		for k in range(1, 7):
			var w: int = (st.weapon + k) % 6
			if st.owned[w]:
				_select_weapon(w)
				break
	pressed_now.clear()
	released_now.clear()


func _drop_presses() -> void:
	"""While a dialogue or a fade holds the game, presses belong to it; releases still unlatch keys."""
	var st = sim.state
	for a in released_now.keys() + carry_release.keys():
		match a:
			"up":
				st.key_up = false
				sim.hero.input_y = 0
			"fire":
				st.key_fire = false
				st.fire_armed = not st.key_down and not st.plasma_out
			"use":
				st.key_enter = false
	pressed_now.clear()
	released_now.clear()
	carry_release.clear()


func _select_weapon(w: int) -> void:
	var st = sim.state
	st.weapon = w
	st.fire_armed = true
	st.shot_sound = 0


# ---------------------------------------------------------------------------
# frame loop
# ---------------------------------------------------------------------------
func _physics_process(_delta: float) -> void:
	if notice_ticks > 0:
		notice_ticks -= 1
		if notice_ticks == 0:
			screen.overlay_layer.queue_redraw()
	if mode != "play" or sim == null:
		pressed_now.clear()
		released_now.clear()
		return
	if vm.busy or palette.busy():
		_drop_presses()
		return
	if sim.end_state != "":
		_finish_game()
		return
	_game_input()
	sim.tick()
	if sim.room_entered:
		sim.room_entered = false
		screen.follow(sim.hero.col, sim.hero.row, sim.teleported)
		sim.teleported = false
	if not sim.script_queue.is_empty():
		vm.run_queue()
	elif Vector2i(sim.hero.col, sim.hero.row) != last_saved_room and sim.hero.state < 14 and not sim.dead:
		_save_game()


func _process(delta: float) -> void:
	palette.update(delta)
	screen.update_camera(delta)
	if sim:
		sim.update_visible(screen.visible_rooms)
	screen.dynamic_layer.queue_redraw()
	screen.hud_layer.queue_redraw()
	if mode in ["anim", "credits", "ending"]:
		screen.overlay_layer.queue_redraw()
	var f: Rect2 = screen.focus_rect()
	shader_mat.set_shader_parameter("focus", Vector4(f.position.x, f.position.y, f.end.x, f.end.y))
	var dim := 1.0
	if mode in ["play", "pause"] and D.settings["dim_neighbours"]:
		dim = 0.45
	shader_mat.set_shader_parameter("dim", dim)
	shader_mat.set_shader_parameter("smooth_scale", D.settings["smooth_scaling"])
	if mode == "credits":
		credits_y += delta * 15.0
		_update_credits()


func refresh_text() -> void:
	screen.text_layer.queue_redraw()


func _notice(s: String) -> void:
	notice = s
	notice_ticks = 100
	screen.overlay_layer.queue_redraw()


# ---------------------------------------------------------------------------
# helpers used by the script VM
# ---------------------------------------------------------------------------
func wait_continue() -> void:
	waiting = true
	await continue_pressed


func wait_ticks(n: int) -> void:
	for i in n:
		await get_tree().physics_frame


func run_menu(items: Array) -> int:
	menu = {"items": items, "sel": 0, "origin": Vector2(text.cx, text.cy), "base": text.glyphs.size(),
			"rows": []}
	_draw_menu()
	var r: int = await menu_finished
	return r


func _draw_menu() -> void:
	text.glyphs.resize(menu["base"])
	text.set_cursor(int(menu["origin"].x), int(menu["origin"].y))
	var rows := []
	for i in menu["items"].size():
		var y0: int = text.cy
		text.colour = 0x10 if i == menu["sel"] else 1
		var s: String = D.text(int(menu["items"][i][1]))
		text.write(s, true)
		var w: int = text.width_of(s.split("\n")[0])
		rows.append(Rect2(menu["origin"].x, y0, maxi(w, 40), maxi(text.cy - y0, 10)))
	menu["rows"] = rows
	refresh_text()


func _choose(i: int) -> void:
	menu["sel"] = i
	_draw_menu()
	var m = menu
	menu = null
	menu_finished.emit(i)


func show_picture(frame: int) -> void:
	"""ShowPicture (0x2D378): fade out, the picture centred with the picture palette, key, fade back."""
	audio.pause_all(true)
	palette.fade("", "black")
	await palette.faded
	picture_frame = frame
	hero_visible = false
	screen.overlay_layer.queue_redraw()
	palette.fade("black", "picture")
	await palette.faded
	await wait_continue()
	palette.fade("", "black")
	await palette.faded
	picture_frame = -1
	hero_visible = true
	screen.overlay_layer.queue_redraw()
	palette.fade("black", "game")
	await palette.faded
	audio.pause_all(false)


func show_tex(tex: Texture2D, region := Rect2()) -> void:
	"""A colour picture on the 4:3 part of the screen (Mode 13h's 320x200 is shown 4:3 like on a CRT)."""
	var win := get_viewport_rect().size
	var area := win.y * (0.8 if subtitle.visible else 1.0)          # leave a band for the subtitles
	var h := area
	var w := h * 4.0 / 3.0
	if w > win.x:
		w = win.x
		h = w * 3.0 / 4.0
	var src := region.size if region.size != Vector2.ZERO else Vector2(tex.get_width(), tex.get_height())
	if region.size != Vector2.ZERO:
		var at := AtlasTexture.new()
		at.atlas = tex
		at.region = region
		tex = at
	picture.texture = tex
	picture.stretch_mode = TextureRect.STRETCH_SCALE
	picture.position = Vector2((win.x - w) / 2.0, (area - h) / 2.0)
	picture.size = Vector2(w, h)
	picture.material.set_shader_parameter("out_scale", Vector2(w / src.x, h / src.y))
	picture.visible = true


func _subtitle(key: String) -> void:
	if key == "" or D.settings["language"] != "en":
		subtitle.visible = false
		return
	var win := get_viewport_rect().size
	var box := Vector2(win.x * 0.88, win.y * 0.2)
	var fs := int(clampf(win.y * 0.032, 12, 36))
	var font := ThemeDB.fallback_font
	var lines := []                                       # wrap by hand: an autowrapping Label that was
	var line := ""                                        # never shown measures itself too tall
	for word in Strings.t(key).split(" "):
		var t := word if line == "" else line + " " + word
		if line != "" and font.get_string_size(t, HORIZONTAL_ALIGNMENT_LEFT, -1, fs).x > box.x:
			lines.append(line)
			line = word
		else:
			line = t
	lines.append(line)
	subtitle.autowrap_mode = TextServer.AUTOWRAP_OFF
	subtitle.vertical_alignment = VERTICAL_ALIGNMENT_CENTER
	subtitle.add_theme_font_size_override("font_size", fs)
	subtitle.text = "\n".join(lines)
	subtitle.visible = true
	subtitle.position = Vector2(win.x * 0.06, win.y * 0.8)
	subtitle.size = box


func show_pcx(file: String) -> void:
	var name: String = {"DATA21.RES": "pic_joke_ending.png", "DATA20.RES": "pic_game_over.png"}.get(file, "")
	if name == "":
		return
	show_tex(load(Data.DATA_DIR + name))
	await wait_continue()


func explode() -> void:
	"""Hero_Explode (0x2CB9C): white flash, red, black, white, red - then the game is over."""
	audio.play(5)
	palette.set_now("white")
	palette.fade("white", "red")
	await palette.faded
	audio.play(6)
	palette.fade("red", "black", 0.65)
	await palette.faded
	audio.play(6)
	palette.set_now("white")
	palette.fade("white", "red")
	await palette.faded
	sim.dead = true
	sim.end_state = "death"


# ---------------------------------------------------------------------------
# modes
# ---------------------------------------------------------------------------
func _press_key() -> void:
	"""The browser's first screen (audio starts only after an input): pick the language, then any key."""
	mode = "press"
	palette.set_now("game")
	screen.refresh_all()


func _press_input(a: String) -> void:
	if a in ["left", "right", "up", "down"]:
		var i := LANGS.find(D.settings["language"])
		var step := -1 if a in ["left", "up"] else 1
		_set_language(LANGS[(i + step + LANGS.size()) % LANGS.size()])
	else:
		_intro()


func _set_language(lang: String) -> void:
	if D.settings["language"] == lang:
		return
	D.settings["language"] = lang
	D.save_settings()
	screen.refresh_all()


func _lang_rects() -> Array:
	"""Where the language names are on the first screen (logical pixels)."""
	var rects := []
	for i in LANGS.size():
		var label: String = Strings.T[LANGS[i]]["lang_name"]
		var w: int = screen.string_width(label)
		var cx: int = logical_w / 2 + (i * 2 - 1) * 45
		rects.append(Rect2(cx - w / 2 - 8, 132, w + 16, 18))
	return rects


func _intro_wait(ticks: int) -> void:
	for i in ticks:
		if intro_skip:
			return
		await get_tree().physics_frame


func _intro_frame(name: String, i: int) -> Texture2D:
	return load("%sintro/%s_%03d.png" % [Data.DATA_DIR, name, i])


func _intro_flc(name: String, ticks_per_frame: int, last: int, sub := "") -> void:
	"""PlayFLC: frames 0..last, looping the file if it is shorter (its ring frame brings back frame 0).
	320x240 files play in Mode X, flipping between two video pages, and PlayFLC ends by showing page 0:
	an odd number of frames leaves the second-to-last one on screen (DATA10 ends on the full sentence)."""
	if intro_skip:
		return
	_subtitle(sub)
	var info: Dictionary = D.game["intro"][name]
	var n: int = info["frames"]
	var mode_x: bool = int(info["size"][1]) > 200
	for f in last + 1:
		if intro_skip:
			return
		var i := f
		if mode_x and f == last and last % 2 == 0:
			i = last - 1                                   # drawn on page 1, never seen
		show_tex(_intro_frame(name, i % n))
		await _intro_wait(ticks_per_frame)


func _intro_still(name: String, hold: int, scroll := 0, after := 0, subs := ["", ""]) -> void:
	"""ShowPCX: the top 320x200, hold, scroll one line every 3 ticks, hold."""
	if intro_skip:
		return
	var tex: Texture2D = load("%sintro/%s.png" % [Data.DATA_DIR, name])
	_subtitle(subs[0])
	show_tex(tex, Rect2(0, 0, 320, 200))
	await _intro_wait(hold)
	for y in scroll:
		if intro_skip:
			return
		if y == scroll / 2:
			_subtitle(subs[1])
		show_tex(tex, Rect2(0, y + 1, 320, 200))
		await _intro_wait(3)
	await _intro_wait(after)


func _skip_intro() -> void:
	"""Any key, button or tap skips the intro, or ends its last picture."""
	intro_skip = true
	waiting = false
	continue_pressed.emit()


func _intro() -> void:
	"""PlayIntro (0x1E8D0), timings from docs 6.2; Space, Esc, Enter, fire or a tap skip it."""
	mode = "intro"
	intro_skip = false
	hud_visible = false
	text.clear()
	palette.set_now("black")
	screen.refresh_all()
	audio.play_music("intro")
	await _intro_wait(50)
	await _intro_still("DATA33", 150, 200, 200, ["intro_1", "intro_2"])
	await _intro_flc("DATA05", 4, 58)
	await _intro_flc("DATA06", 4, 90)
	await _intro_flc("DATA07", 4, 45)
	await _intro_wait(25)
	await _intro_flc("DATA08", 4, 59)
	await _intro_flc("DATA09", 4, 85)
	await _intro_still("DATA34", 250, 0, 0, ["intro_3", ""])
	await _intro_still("DATA35", 250)
	await _intro_still("DATA36", 300, 200, 300, ["intro_4", "intro_5"])
	await _intro_flc("DATA11", 3, 70)
	await _intro_flc("DATA12", 3, 50)
	await _intro_flc("DATA15", 8, 60, "intro_6")
	await _intro_flc("DATA13", 8, 30, "intro_7")
	await _intro_flc("DATA14", 10, 4)
	await _intro_flc("DATA10", 30, 6, "intro_8")
	# the original waits for Enter/Ctrl/Space here; the remake also goes on by itself after a while
	waiting = not intro_skip
	for t in INTRO_END_TICKS:
		if not waiting:
			break
		await get_tree().physics_frame
	waiting = false
	audio.stop_music()
	subtitle.visible = false
	if mode == "intro":
		_title()


func _title() -> void:
	mode = "title"
	sim = null
	vm.sim = null
	menu = null
	waiting = false
	picture.visible = false
	subtitle.visible = false
	picture_frame = -1
	anim_frame = ""
	hud_visible = false
	ui_sel = TITLE_ITEMS.find("continue" if _title_enabled("continue") else "new")
	text.clear()
	audio.stop_all()
	audio.pause_all(false)
	audio.play_music("title")
	palette.set_now("black")
	palette.fade("black", "menu", 0.4)
	screen.refresh_all()
	touch.refresh()


# The title menu is a list of text items centred horizontally; the picture behind it (with the original's
# painted GRA / AUTORZY / WYJŚCIE) is only a background, but the last item sits on its painted WYJŚCIE.
const TITLE_ITEMS := ["new", "continue", "options", "controls", "credits", "quit"]
const TITLE_DY := 17
const TITLE_LAST_Y := 172          # the painted WYJŚCIE: highlight frame 1180 at y 166, 21 high (centre 177)


func _title_enabled(item: String) -> bool:
	"""Continue is greyed out until there is a saved game."""
	return item != "continue" or FileAccess.file_exists(SAVE_PATH)


func _title_row_y(i: int) -> int:
	return TITLE_LAST_Y - (TITLE_ITEMS.size() - 1 - i) * TITLE_DY


func _title_rects() -> Array:
	var rects := []
	for i in TITLE_ITEMS.size():
		rects.append(Rect2(logical_w / 2 - 70, _title_row_y(i) - (TITLE_DY - 10) / 2, 140, TITLE_DY))
	return rects


func _next_title(step: int) -> int:
	var i := ui_sel
	for k in TITLE_ITEMS.size():
		i = (i + step + TITLE_ITEMS.size()) % TITLE_ITEMS.size()
		if _title_enabled(TITLE_ITEMS[i]):
			break
	return i


func _title_input(a: String) -> void:
	match a:
		"up":
			ui_sel = _next_title(-1)
			audio.play(33)
		"down":
			ui_sel = _next_title(1)
			audio.play(33)
		"use", "jetpack", "fire":
			if not _title_enabled(TITLE_ITEMS[ui_sel]):
				return
			match TITLE_ITEMS[ui_sel]:
				"new":
					_new_game()
				"credits":
					_credits_anim()
				"quit":
					if OS.has_feature("web"):
						_notice(Strings.t("thanks"))
					else:
						get_tree().quit()
				"continue":
					_new_game(true)
				"options":
					options_from = "title"
					_open_options()
				"controls":
					options_from = "title"
					_open_controls()
		"pause":
			ui_sel = TITLE_ITEMS.find("quit")
	screen.overlay_layer.queue_redraw()


func _new_game(resume := false) -> void:
	_game_music()
	mode = "play"
	sim = Sim.new(D)
	sim.audio = audio
	vm.sim = sim
	var saved = null
	if resume:
		saved = JSON.parse_string(FileAccess.get_file_as_string(SAVE_PATH))
	sim.hero.classic = D.settings["room_edges"] == "classic"
	if saved is Dictionary:
		sim.load_data(saved)
	else:
		sim.new_game()
	last_saved_room = Vector2i(-1, -1)
	hud_visible = true
	hero_visible = true
	text.clear()
	screen.follow(sim.hero.col, sim.hero.row, true)
	screen.refresh_all()
	palette.set_now("black")
	var bomb: bool = sim.state.vars.get("bomb_active", 0) != 0
	palette.fade("black", "alarm" if bomb else "game", 0.5)
	if bomb:
		audio.play(16)
	touch.refresh()


func _game_music() -> void:
	"""The original stops the music when a game starts; the remake plays its two modules unless turned off."""
	if D.settings["game_music"]:
		audio.play_playlist(["intro", "title"])
	else:
		audio.stop_music()


func _save_game() -> void:
	last_saved_room = Vector2i(sim.hero.col, sim.hero.row)
	var f := FileAccess.open(SAVE_PATH, FileAccess.WRITE)
	if f:
		f.store_string(JSON.stringify(sim.save_data()))


func _finish_game() -> void:
	var how: String = sim.end_state
	sim.end_state = "handled"
	audio.stop_all()
	audio.stop_music()
	match how:
		"win":
			_win_ending()
		"joke_ending":
			_title()
		"handled":
			pass
		_:
			_game_over()


func _game_over() -> void:
	mode = "gameover"
	palette.fade("", "black", 0.5)
	await palette.faded
	show_tex(load(Data.DATA_DIR + "pic_game_over.png"))
	hud_visible = false
	touch.refresh()


func _win_ending() -> void:
	"""EndingSequence (0x1EBC4): the narrator's desk, nine lines of text, the fist; then the credits."""
	mode = "ending"
	hud_visible = false
	hero_visible = false
	touch.refresh()
	_show_anim_frame("DATA17", 0)
	text.clear()
	text.outline = 0
	text_origin = Vector2((logical_w - 320) / 2, 6)
	await wait_ticks(100)
	for i in range(284, 293):
		text.write(D.text(i))
		refresh_text()
		await wait_ticks(90)
	text.clear()
	text.outline = 42
	refresh_text()
	for f in range(1, 6):
		_show_anim_frame("DATA17", f)
		await wait_ticks(20)
	await wait_ticks(200)
	anim_frame = ""
	text_origin = screen.room_screen_origin()
	_credits_scroller()


func _show_anim_frame(name: String, i: int) -> void:
	var fr: Dictionary = D.game["animations"][name][i]
	var key: String = fr["file"]
	if not anim_cache.has(key):
		anim_cache[key] = load(Data.DATA_DIR + key)
	anim_tex = anim_cache[key]
	anim_frame = key
	var pal := PackedByteArray()
	for v in fr["palette"]:
		pal.append(int(v))
	palette.current = pal
	palette.dirty = true
	screen.overlay_layer.queue_redraw()


func _credits_anim() -> void:
	"""AUTORZY: the credits animation (DATA04) loops until a key."""
	mode = "anim"
	var n: int = D.game["animations"]["DATA04"].size()
	var i := 0
	while mode == "anim":
		_show_anim_frame("DATA04", i)
		await wait_ticks(4)
		i = (i + 1) % n
	if mode == "title":
		palette.set_now("menu")
		ui_sel = TITLE_ITEMS.find("credits")
		screen.overlay_layer.queue_redraw()


func _credits_scroller() -> void:
	"""EndingCredits (0x299BC): the 640x2080 credits picture scrolls up with 'recollection'."""
	mode = "credits"
	audio.play_music("intro")
	picture.texture = load(Data.DATA_DIR + "pic_credits.png")
	picture.visible = true
	credits_y = 0.0
	_update_credits()


func _update_credits() -> void:
	if picture.texture == null:
		return
	var tex: Texture2D = picture.texture
	var win := get_viewport_rect().size
	var s := minf(win.x / 640.0, win.y / 480.0)
	var y := minf(credits_y, tex.get_height() - 480.0)
	picture.stretch_mode = TextureRect.STRETCH_SCALE
	picture.size = Vector2(640, tex.get_height()) * s
	picture.position = Vector2((win.x - 640 * s) / 2.0, -y * s + (win.y - 480 * s) / 2.0)
	picture.material.set_shader_parameter("out_scale", Vector2(s, s))


func _open_pause() -> void:
	mode = "pause"
	ui_sel = 0
	audio.pause_all(true)
	screen.overlay_layer.queue_redraw()
	touch.refresh()


const PAUSE_ITEMS := ["continue", "options", "controls", "quit_title"]


func _pause_input(a: String) -> void:
	var n := PAUSE_ITEMS.size()
	match a:
		"up":
			ui_sel = (ui_sel + n - 1) % n
		"down":
			ui_sel = (ui_sel + 1) % n
		"pause":
			_close_pause()
		"use", "jetpack", "fire":
			match PAUSE_ITEMS[ui_sel]:
				"continue":
					_close_pause()
				"options":
					options_from = "pause"
					_open_options()
				"controls":
					options_from = "pause"
					_open_controls()
				"quit_title":
					audio.pause_all(false)
					_title()
	screen.overlay_layer.queue_redraw()


func _close_pause() -> void:
	mode = "play"
	audio.pause_all(false)
	pressed_now.clear()
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _option_list() -> Array:
	"""[label, value, key] per row of the options screen."""
	var s: Dictionary = D.settings
	return [
		[Strings.t("opt_language"), Strings.t("lang_name"), "language"],
		[Strings.t("opt_neighbours"), Strings.t("on") if s["show_neighbours"] else Strings.t("off"), "show_neighbours"],
		[Strings.t("opt_dim"), Strings.t("on") if s["dim_neighbours"] else Strings.t("off"), "dim_neighbours"],
		[Strings.t("opt_smooth"), Strings.t("smooth") if s["smooth_scaling"] else Strings.t("sharp"), "smooth_scaling"],
		[Strings.t("opt_edges"), Strings.t("edges_" + str(s["room_edges"])), "room_edges"],
		[Strings.t("opt_touch"), Strings.t("touch_" + str(s["touch_controls"])), "touch_controls"],
		[Strings.t("opt_sound"), Strings.t("on") if s["sound"] else Strings.t("off"), "sound"],
		[Strings.t("opt_music"), "%d%%" % roundi(float(s["music_volume"]) * 100), "music_volume"],
		[Strings.t("opt_game_music"), Strings.t("on") if s["game_music"] else Strings.t("off"), "game_music"],
		[Strings.t("opt_sfx"), "%d%%" % roundi(float(s["sfx_volume"]) * 100), "sfx_volume"],
		[Strings.t("opt_fullscreen"), Strings.t("on") if is_fullscreen() else Strings.t("off"), "fullscreen"],
		[Strings.t("back"), "", "back"],
	].filter(func(row): return row[2] != "fullscreen" or can_fullscreen())


func _option_enabled(key: String) -> bool:
	"""The music and effect settings do nothing while the sound is off."""
	return D.settings["sound"] or not key in ["music_volume", "game_music", "sfx_volume"]


func _next_option(opts: Array, step: int) -> int:
	var i := ui_sel
	for k in opts.size():
		i = (i + step + opts.size()) % opts.size()
		if _option_enabled(opts[i][2]):
			break
	return i


func _open_options() -> void:
	mode = "options"
	ui_sel = 0
	if options_from == "title":
		palette.set_now("game")
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _options_input(a: String) -> void:
	var s: Dictionary = D.settings
	var opts := _option_list()
	var dirn := 1
	match a:
		"up":
			ui_sel = _next_option(opts, -1)
		"down":
			ui_sel = _next_option(opts, 1)
		"pause":
			_leave_options()
			return
		"left", "right", "use", "jetpack", "fire":
			dirn = -1 if a == "left" else 1
			if not _option_enabled(opts[ui_sel][2]):
				return
			match str(opts[ui_sel][2]):
				"sound":
					s["sound"] = not s["sound"]
					audio.apply_volumes()
				"language":
					s["language"] = "en" if s["language"] == "pl" else "pl"
				"show_neighbours", "dim_neighbours", "smooth_scaling":
					var k: String = opts[ui_sel][2]
					s[k] = not s[k]
				"room_edges":
					s["room_edges"] = "seamless" if s["room_edges"] == "classic" else "classic"
					if sim:
						sim.hero.classic = s["room_edges"] == "classic"
				"touch_controls":
					var modes := ["auto", "on", "off"]
					s["touch_controls"] = modes[(modes.find(s["touch_controls"]) + dirn + 3) % 3]
					touch.refresh()
				"music_volume":
					s["music_volume"] = clampf(snappedf(float(s["music_volume"]) + 0.1 * dirn, 0.1), 0.0, 1.0)
					audio.apply_volumes()
				"game_music":
					s["game_music"] = not s["game_music"]
					if sim:
						_game_music()
				"sfx_volume":
					s["sfx_volume"] = clampf(snappedf(float(s["sfx_volume"]) + 0.1 * dirn, 0.1), 0.0, 1.0)
					audio.apply_volumes()
					audio.pause_all(false)
					audio.play(33)
				"fullscreen":
					toggle_fullscreen()
				"back":
					_leave_options()
					return
			D.save_settings()
			screen.refresh_all()
	screen.overlay_layer.queue_redraw()


func _leave_options() -> void:
	D.save_settings()
	if options_from == "pause":
		mode = "pause"
		ui_sel = PAUSE_ITEMS.find("options")
	else:
		_title()
		ui_sel = TITLE_ITEMS.find("options")
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func is_phone() -> bool:
	"""A phone's browser: Android or iPhone, and a screen whose short side is under 600 CSS px (not a tablet)."""
	if phone == null:
		phone = OS.has_feature("web") and bool(JavaScriptBridge.eval(
				"/Android|iPhone|iPod/.test(navigator.userAgent) && Math.min(screen.width, screen.height) < 600", true))
	return phone


func can_fullscreen() -> bool:
	"""iPhone browsers cannot show a web page full screen (only "Add to Home Screen" gives a full-screen app),
	so the button and the option are hidden there."""
	if not OS.has_feature("web"):
		return true
	if fullscreen_supported == null:
		fullscreen_supported = bool(JavaScriptBridge.eval(
				"!!(document.fullscreenEnabled || document.webkitFullscreenEnabled)", true))
	return fullscreen_supported


func _open_controls() -> void:
	mode = "controls"
	if options_from == "title":
		palette.set_now("game")
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _leave_controls() -> void:
	if options_from == "pause":
		mode = "pause"
		ui_sel = PAUSE_ITEMS.find("controls")
	else:
		_title()
		ui_sel = TITLE_ITEMS.find("controls")
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _control_rows() -> Array:
	"""[what, keys] for the controls screen: the touch buttons when the touch controls are on, else keys."""
	var t: bool = touch.enabled
	var rows := []
	for k in ["walk", "jump", "crouch", "fire", "use", "jet", "item", "weapon", "pause", "dialogue", "menu"]:
		rows.append([Strings.t("ctl_" + k), Strings.t(("ctl_touch_" if t else "ctl_key_") + k)])
	return rows


func _draw_controls(ci: CanvasItem) -> void:
	if options_from == "title":
		screen.fill(ci, Rect2(0, 0, logical_w, H), 0)
	else:
		screen.fill(ci, Rect2(screen.view_w / 2 - 150, 14, 300, 212), 0)
	var cx: int = screen.view_w / 2
	var title := Strings.t("controls").to_upper()
	screen.draw_string_at(ci, title, Vector2(cx - screen.string_width(title) / 2, 22), 29)
	var rows := _control_rows()
	var x0 := cx - 140
	var x1 := mini(x0 + _max_width(rows, 0) + 12, cx + 145 - _max_width(rows, 1))
	for i in rows.size():
		var y := OPT_Y0 + i * OPT_DY
		screen.draw_string_at(ci, rows[i][0], Vector2(x0, y), 1)
		screen.draw_string_at(ci, rows[i][1], Vector2(x1, y), 13)
	var back := Strings.t("back")
	screen.draw_string_at(ci, back, Vector2(cx - screen.string_width(back) / 2, OPT_Y0 + rows.size() * OPT_DY + 8), 0x10)


func _max_width(rows: Array, column: int) -> int:
	var w := 0
	for r in rows:
		w = maxi(w, screen.string_width(r[column]))
	return w


func is_fullscreen() -> bool:
	return DisplayServer.window_get_mode() in [DisplayServer.WINDOW_MODE_FULLSCREEN,
			DisplayServer.WINDOW_MODE_EXCLUSIVE_FULLSCREEN]


func toggle_fullscreen() -> void:
	if is_fullscreen():
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
	else:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
	screen.overlay_layer.queue_redraw()
	touch.relayout.call_deferred()


# ---------------------------------------------------------------------------
# overlay drawing (index space)
# ---------------------------------------------------------------------------
const OPT_Y0 := 40                                   # options: first row, row spacing
const OPT_DY := 15


func _ui_rows() -> Array:
	var rows := []
	var n := _option_list().size() if mode == "options" else PAUSE_ITEMS.size()
	var y0 := OPT_Y0 if mode == "options" else 96
	var dy := OPT_DY if mode == "options" else 16
	for i in n:
		rows.append(Rect2(0, y0 + i * dy - 3, logical_w, dy))
	return rows


func draw_overlay(ci: CanvasItem) -> void:
	var W := logical_w
	match mode:
		"press", "intro":
			screen.fill(ci, Rect2(0, 0, W, H), 0)
			if mode == "press":
				var t := "LAZARUS"
				screen.draw_string_at(ci, t, Vector2(W / 2 - screen.string_width(t) / 2, 88), 29)
				var h: String = Strings.T["pl"]["opt_language"]
				screen.draw_string_at(ci, h, Vector2(W / 2 - screen.string_width(h) / 2, 114), 1)
				var rects := _lang_rects()
				for i in LANGS.size():
					var r: Rect2 = rects[i]
					var label: String = Strings.T[LANGS[i]]["lang_name"]
					var sel: bool = D.settings["language"] == LANGS[i]
					screen.draw_string_at(ci, label, Vector2(r.position.x + 8, r.position.y + 4), 0x10 if sel else 1)
					if sel:
						screen.fill(ci, Rect2(r.position.x + 6, r.end.y - 2, r.size.x - 12, 1), 0x10)
				var p := Strings.t("press_key")
				screen.draw_string_at(ci, p, Vector2(W / 2 - screen.string_width(p) / 2, 164), 12)
				if is_phone() and portrait:                    # sideways the picture is much larger
					var tip := Strings.t("landscape_tip")
					screen.draw_string_at(ci, tip, Vector2(W / 2 - screen.string_width(tip) / 2, 190), 13)
		"title":
			screen.fill(ci, Rect2(0, 0, W, H), 0)
			screen.draw_frame(ci, 1181, Vector2((W - 320) / 2, 0))
			var grey := _grey("menu", 270)
			for i in TITLE_ITEMS.size():
				var label := Strings.t(TITLE_ITEMS[i]).to_upper()
				var c := _brightest("menu") if ui_sel == i else _dimmest_text("menu")
				if not _title_enabled(TITLE_ITEMS[i]):
					c = grey
				screen.draw_string_at(ci, label, Vector2(W / 2 - screen.string_width(label) / 2, _title_row_y(i)), c, 0)
		"options":
			if options_from == "title":
				screen.fill(ci, Rect2(0, 0, W, H), 0)
			else:
				screen.fill(ci, Rect2(screen.view_w / 2 - 150, 14, 300, 212), 0)
			var title := Strings.t("options").to_upper()
			screen.draw_string_at(ci, title, Vector2(screen.view_w / 2 - screen.string_width(title) / 2, 22), 29)
			var opts := _option_list()
			var cx: int = screen.view_w / 2
			var grey := _grey("game", 300)
			for i in opts.size():
				var y := OPT_Y0 + i * OPT_DY
				var on := _option_enabled(opts[i][2])
				var c := (0x10 if i == ui_sel else 1) if on else grey
				screen.draw_string_at(ci, opts[i][0], Vector2(cx - 130, y), c)
				if opts[i][1] != "":
					screen.draw_string_at(ci, opts[i][1], Vector2(cx + 40, y), (12 if i == ui_sel else 13) if on else grey)
		"controls":
			_draw_controls(ci)
		"pause":
			var cx: int = screen.view_w / 2
			screen.fill(ci, Rect2(cx - 90, 60, 180, 116), 0)
			var t: String = Strings.t("paused")
			screen.draw_string_at(ci, t, Vector2(cx - screen.string_width(t) / 2, 72), 29)
			for i in PAUSE_ITEMS.size():
				var s: String = Strings.t(PAUSE_ITEMS[i])
				screen.draw_string_at(ci, s, Vector2(cx - screen.string_width(s) / 2, 96 + i * 16),
						0x10 if i == ui_sel else 1)
		"credits", "gameover":
			screen.fill(ci, Rect2(0, 0, W, H), 0)
		"anim", "ending":
			screen.fill(ci, Rect2(0, 0, W, H), 0)
			if anim_tex and anim_frame != "":
				ci.draw_texture(anim_tex, Vector2((W - anim_tex.get_width()) / 2, (H - anim_tex.get_height()) / 2))
	if picture_frame >= 0:
		screen.fill(ci, Rect2(0, 0, W, H), 0)
		var sz: Vector2 = screen.frame_size(picture_frame)
		# ShowPicture: (160 - w/2, 120 - h/2) in play-field coordinates
		screen.draw_frame(ci, picture_frame, Vector2(floori((W - sz.x) / 2), 120 - floori(sz.y / 2) + 6))
	if notice_ticks > 0 and notice != "":
		screen.draw_string_at(ci, notice, Vector2(4, 2), 29)


func _brightest(pal: String) -> int:
	var p: PackedByteArray = D.palettes[pal]
	var best := 0
	var bv := -1
	for i in range(1, 256):
		var v: int = p[i * 3] + p[i * 3 + 1] + p[i * 3 + 2]
		if v > bv:
			bv = v
			best = i
	return best


func _dimmest_text(pal: String) -> int:
	return _closest_brightness(pal, 300)


func _grey(pal: String, target: int) -> int:
	"""The most neutral palette grey (channels within 24) whose r + g + b is closest to target."""
	var p: PackedByteArray = D.palettes[pal]
	var best := _closest_brightness(pal, target)
	var bd := 9999
	for i in range(1, 256):
		var r: int = p[i * 3]
		var g: int = p[i * 3 + 1]
		var b: int = p[i * 3 + 2]
		if maxi(r, maxi(g, b)) - mini(r, mini(g, b)) <= 24 and absi(r + g + b - target) < bd:
			bd = absi(r + g + b - target)
			best = i
	return best


func _closest_brightness(pal: String, target: int) -> int:
	"""The palette entry whose r + g + b (0..765) is closest to target."""
	var p: PackedByteArray = D.palettes[pal]
	var best := 0
	var bd := 9999
	for i in range(1, 256):
		var v: int = p[i * 3] + p[i * 3 + 1] + p[i * 3 + 2]
		if absi(v - target) < bd:
			bd = absi(v - target)
			best = i
	return best
