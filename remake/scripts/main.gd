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

var D
var viewport: SubViewport
var screen: Node2D
var display: TextureRect
var shader_mat: ShaderMaterial
var picture: TextureRect
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
	add_child(picture)
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
	_title()
	for arg in OS.get_cmdline_user_args():
		if arg.begins_with("--shots="):
			_autotest(arg.substr(8))


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
	action_tap("pause")
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
	ui_sel = 1
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
	if waiting:
		if a in CONTINUE_ACTIONS:
			waiting = false
			continue_pressed.emit()
		return
	match mode:
		"title":
			_title_input(a)
		"options":
			_options_input(a)
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
	if waiting:
		waiting = false
		continue_pressed.emit()
		return
	match mode:
		"title":
			for i in _title_rects().size():
				if _title_rects()[i].has_point(p):
					ui_sel = i
					_title_input("use")
					return
		"options", "pause":
			var rows := _ui_rows()
			for i in rows.size():
				if rows[i].has_point(p):
					ui_sel = i
					if mode == "options":
						_options_input("use")
					else:
						_pause_input("use")
					return
		"play":
			if p.x >= screen.view_w:
				var hp := p - Vector2(screen.view_w, 0)
				if Rect2(24, 196, 32, 32).has_point(hp):
					action_tap("item_next")
				elif Rect2(4, 4, 68, 26).has_point(hp):
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


func show_pcx(file: String) -> void:
	var name: String = {"DATA21.RES": "pic_joke_ending.png", "DATA20.RES": "pic_game_over.png"}.get(file, "")
	if name == "":
		return
	picture.texture = load(Data.DATA_DIR + name)
	picture.visible = true
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
func _title() -> void:
	mode = "title"
	sim = null
	vm.sim = null
	menu = null
	waiting = false
	picture.visible = false
	picture_frame = -1
	anim_frame = ""
	hud_visible = false
	ui_sel = 0
	text.clear()
	audio.stop_all()
	audio.pause_all(false)
	audio.play_music("title")
	palette.set_now("black")
	palette.fade("black", "menu", 0.4)
	screen.refresh_all()
	touch.refresh()


func _title_rects() -> Array:
	var ox := (logical_w - 320) / 2
	return [Rect2(ox + 110, 84, 100, 30), Rect2(ox + 105, 117, 110, 30), Rect2(ox + 105, 155, 110, 30),
			Rect2(ox + 100, 196, 120, 16)]


func _title_input(a: String) -> void:
	match a:
		"up":
			ui_sel = (ui_sel + 3) % 4
			audio.play(33)
		"down":
			ui_sel = (ui_sel + 1) % 4
			audio.play(33)
		"use", "jetpack", "fire":
			match ui_sel:
				0:
					_new_game()
				1:
					_credits_anim()
				2:
					if OS.has_feature("web"):
						_notice(Strings.t("thanks"))
					else:
						get_tree().quit()
				3:
					options_from = "title"
					_open_options()
		"pause":
			ui_sel = 2
	screen.overlay_layer.queue_redraw()


func _new_game() -> void:
	audio.stop_music()
	mode = "play"
	sim = Sim.new(D)
	sim.audio = audio
	vm.sim = sim
	sim.new_game()
	hud_visible = true
	hero_visible = true
	text.clear()
	screen.follow(sim.hero.col, sim.hero.row, true)
	screen.refresh_all()
	palette.set_now("black")
	palette.fade("black", "game", 0.5)
	touch.refresh()


func _finish_game() -> void:
	var how: String = sim.end_state
	sim.end_state = "handled"
	audio.stop_all()
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
	picture.texture = load(Data.DATA_DIR + "pic_game_over.png")
	picture.visible = true
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


func _open_pause() -> void:
	mode = "pause"
	ui_sel = 0
	audio.pause_all(true)
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _pause_input(a: String) -> void:
	var n := 3
	match a:
		"up":
			ui_sel = (ui_sel + n - 1) % n
		"down":
			ui_sel = (ui_sel + 1) % n
		"pause":
			_close_pause()
		"use", "jetpack", "fire":
			match ui_sel:
				0:
					_close_pause()
				1:
					options_from = "pause"
					_open_options()
				2:
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
	var s: Dictionary = D.settings
	return [
		[Strings.t("opt_language"), Strings.t("lang_name")],
		[Strings.t("opt_neighbours"), Strings.t("on") if s["show_neighbours"] else Strings.t("off")],
		[Strings.t("opt_dim"), Strings.t("on") if s["dim_neighbours"] else Strings.t("off")],
		[Strings.t("opt_smooth"), Strings.t("smooth") if s["smooth_scaling"] else Strings.t("sharp")],
		[Strings.t("opt_touch"), Strings.t("touch_" + str(s["touch_controls"]))],
		[Strings.t("opt_music"), "%d%%" % roundi(float(s["music_volume"]) * 100)],
		[Strings.t("opt_sfx"), "%d%%" % roundi(float(s["sfx_volume"]) * 100)],
		[Strings.t("opt_fullscreen"), Strings.t("on") if _is_fullscreen() else Strings.t("off")],
		[Strings.t("back"), ""],
	]


func _open_options() -> void:
	mode = "options"
	ui_sel = 0
	if options_from == "title":
		palette.set_now("game")
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _options_input(a: String) -> void:
	var s: Dictionary = D.settings
	var n := _option_list().size()
	var dirn := 1
	match a:
		"up":
			ui_sel = (ui_sel + n - 1) % n
		"down":
			ui_sel = (ui_sel + 1) % n
		"pause":
			_leave_options()
			return
		"left", "right", "use", "jetpack", "fire":
			dirn = -1 if a == "left" else 1
			match ui_sel:
				0:
					s["language"] = "en" if s["language"] == "pl" else "pl"
				1:
					s["show_neighbours"] = not s["show_neighbours"]
				2:
					s["dim_neighbours"] = not s["dim_neighbours"]
				3:
					s["smooth_scaling"] = not s["smooth_scaling"]
				4:
					var modes := ["auto", "on", "off"]
					s["touch_controls"] = modes[(modes.find(s["touch_controls"]) + dirn + 3) % 3]
					touch.refresh()
				5:
					s["music_volume"] = clampf(snappedf(float(s["music_volume"]) + 0.1 * dirn, 0.1), 0.0, 1.0)
					audio.apply_volumes()
				6:
					s["sfx_volume"] = clampf(snappedf(float(s["sfx_volume"]) + 0.1 * dirn, 0.1), 0.0, 1.0)
					audio.apply_volumes()
					audio.pause_all(false)
					audio.play(33)
				7:
					toggle_fullscreen()
				8:
					_leave_options()
					return
			D.save_settings()
			screen.refresh_all()
	screen.overlay_layer.queue_redraw()


func _leave_options() -> void:
	D.save_settings()
	if options_from == "pause":
		mode = "pause"
		ui_sel = 1
	else:
		_title()
		ui_sel = 3
	screen.overlay_layer.queue_redraw()
	touch.refresh()


func _is_fullscreen() -> bool:
	return DisplayServer.window_get_mode() in [DisplayServer.WINDOW_MODE_FULLSCREEN,
			DisplayServer.WINDOW_MODE_EXCLUSIVE_FULLSCREEN]


func toggle_fullscreen() -> void:
	if _is_fullscreen():
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
	else:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
	screen.overlay_layer.queue_redraw()


# ---------------------------------------------------------------------------
# overlay drawing (index space)
# ---------------------------------------------------------------------------
func _ui_rows() -> Array:
	var rows := []
	var n := _option_list().size() if mode == "options" else 3
	var y0 := 52 if mode == "options" else 96
	for i in n:
		rows.append(Rect2(0, y0 + i * 16 - 3, logical_w, 16))
	return rows


func draw_overlay(ci: CanvasItem) -> void:
	var W := logical_w
	match mode:
		"title":
			var ox := (W - 320) / 2
			screen.fill(ci, Rect2(0, 0, W, H), 0)
			screen.draw_frame(ci, 1181, Vector2(ox, 0))
			var hl := [[1178, 139, 89], [1179, 113, 122], [1180, 116, 160]]
			if ui_sel < 3:
				screen.draw_frame(ci, hl[ui_sel][0], Vector2(ox + hl[ui_sel][1], hl[ui_sel][2]))
			var label := Strings.t("options").to_upper()
			var lw: int = screen.string_width(label)
			var bright := _brightest("menu")
			screen.draw_string_at(ci, label, Vector2(ox + 160 - lw / 2, 200), bright if ui_sel == 3 else _dimmest_text("menu"), 0)
		"options":
			if options_from == "title":
				screen.fill(ci, Rect2(0, 0, W, H), 0)
			else:
				screen.fill(ci, Rect2(screen.view_w / 2 - 150, 20, 300, 200), 0)
			var title := Strings.t("options").to_upper()
			screen.draw_string_at(ci, title, Vector2(screen.view_w / 2 - screen.string_width(title) / 2, 28), 29)
			var opts := _option_list()
			var cx: int = screen.view_w / 2
			for i in opts.size():
				var y := 52 + i * 16
				var c := 0x10 if i == ui_sel else 1
				screen.draw_string_at(ci, opts[i][0], Vector2(cx - 130, y), c)
				if opts[i][1] != "":
					screen.draw_string_at(ci, opts[i][1], Vector2(cx + 40, y), 12 if i == ui_sel else 13)
		"pause":
			var cx: int = screen.view_w / 2
			screen.fill(ci, Rect2(cx - 90, 60, 180, 100), 0)
			var t: String = Strings.t("paused")
			screen.draw_string_at(ci, t, Vector2(cx - screen.string_width(t) / 2, 72), 29)
			var items := [Strings.t("continue"), Strings.t("options"), Strings.t("quit_title")]
			for i in 3:
				var s: String = items[i]
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
		screen.draw_frame(ci, picture_frame, Vector2(floori((W - sz.x) / 2), floori((H - sz.y) / 2)))
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
	var p: PackedByteArray = D.palettes[pal]
	var best := 0
	var target := 300
	var bd := 9999
	for i in range(1, 256):
		var v: int = p[i * 3] + p[i * 3 + 1] + p[i * 3 + 2]
		if absi(v - target) < bd:
			bd = absi(v - target)
			best = i
	return best
