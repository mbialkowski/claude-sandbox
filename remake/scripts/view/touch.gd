extends Control
## On-screen controls for touch screens: an 8-way pad (walk, jump/up, crouch/down) and buttons for fire,
## jump, use, jetpack, inventory, weapon and pause.  Multi-touch; touches that hit no control are taps
## (continue a dialogue, choose a menu entry, use the HUD).

const Strings = preload("res://scripts/game/strings.gd")

var main
var enabled := false
var seen_touch := false
var pad_center := Vector2.ZERO
var pad_radius := 80.0
var buttons := []              # {"action", "label", "center", "radius"}
var touches := {}              # index -> {"kind": "pad"|"button"|"tap", "actions": []}


func _ready() -> void:
	mouse_filter = Control.MOUSE_FILTER_IGNORE
	refresh()


func refresh() -> void:
	if main == null:
		return
	var setting: String = main.D.settings["touch_controls"]
	enabled = setting == "on" or (setting == "auto" and (seen_touch or DisplayServer.is_touchscreen_available()))
	visible = enabled and main.mode in ["play", "pause"]
	if not visible:
		_release_all()
	relayout()


func relayout() -> void:
	if main == null:
		return
	var win := size
	var dr: Rect2 = main.display_rect
	buttons.clear()
	var r: float
	var cy: float
	var cx_pad: float
	var cx_btn: float
	if main.portrait:
		var area_top := dr.end.y
		var area_h := win.y - area_top
		r = clampf(minf(win.x * 0.11, area_h * 0.16), 28.0, 90.0)
		cy = area_top + area_h * 0.55
		pad_radius = r * 2.0
		cx_pad = win.x * 0.27
		cx_btn = win.x * 0.73
	else:
		r = clampf(win.y * 0.085, 24.0, 80.0)
		pad_radius = r * 2.1
		cy = win.y - r * 1.45 - r * 1.25
		cx_pad = pad_radius + r * 0.5
		var hud_px: float = dr.size.x * 76.0 / main.logical_w
		cx_btn = dr.end.x - hud_px - r * 1.45 - r * 1.15
	pad_center = Vector2(cx_pad, win.y - pad_radius - r * 0.35 if not main.portrait else cy)
	var d := r * 1.45
	buttons.append({"action": "fire", "label": "fire", "center": Vector2(cx_btn + d, cy), "radius": r})
	buttons.append({"action": "up", "label": "jump", "center": Vector2(cx_btn, cy + d), "radius": r})
	buttons.append({"action": "use", "label": "use", "center": Vector2(cx_btn - d, cy), "radius": r})
	buttons.append({"action": "jetpack", "label": "jet", "center": Vector2(cx_btn, cy - d), "radius": r})
	var s := r * 0.55
	buttons.append({"action": "pause", "label": "II", "center": Vector2(s * 1.6, s * 1.6), "radius": s})
	if main.can_fullscreen() and not main.is_fullscreen():
		buttons.append({"action": "fullscreen", "label": "full", "center": Vector2(s * 4.2, s * 1.6), "radius": s})
	var top := cy - d - r * 2.3
	if main.portrait:
		top = main.display_rect.end.y + s * 1.5
	buttons.append({"action": "item_next", "label": "inv", "center": Vector2(cx_btn - d, top), "radius": s})
	buttons.append({"action": "weapon_next", "label": "wpn", "center": Vector2(cx_btn + d, top), "radius": s})
	queue_redraw()


func _input(event: InputEvent) -> void:
	if event is InputEventScreenTouch:
		if not seen_touch:
			seen_touch = true
			refresh()
		if event.pressed:
			_touch_start(event.index, event.position)
		else:
			_touch_end(event.index)
		get_viewport().set_input_as_handled()
	elif event is InputEventScreenDrag:
		var t = touches.get(event.index)
		if t and t["kind"] == "pad":
			_set_pad(event.index, event.position)
		get_viewport().set_input_as_handled()


func _touch_start(index: int, pos: Vector2) -> void:
	if visible:
		if pos.distance_to(pad_center) <= pad_radius * 1.15:
			touches[index] = {"kind": "pad", "actions": []}
			_set_pad(index, pos)
			return
		for b in buttons:
			if pos.distance_to(b["center"]) <= b["radius"] * 1.2:
				touches[index] = {"kind": "button", "actions": [b["action"]]}
				main.action_press(b["action"])
				queue_redraw()
				return
	touches[index] = {"kind": "tap", "actions": []}
	main.tap(pos)


func _touch_end(index: int) -> void:
	var t = touches.get(index)
	if t == null:
		return
	for a in t["actions"]:
		main.action_release(a)
	touches.erase(index)
	queue_redraw()


func _set_pad(index: int, pos: Vector2) -> void:
	var v := pos - pad_center
	var want := []
	if v.length() > pad_radius * 0.22:
		var ang := fposmod(rad_to_deg(v.angle()), 360.0)
		var sector := int(floor((ang + 22.5) / 45.0)) % 8   # 0 right, 2 down, 4 left, 6 up
		match sector:
			0:
				want = ["right"]
			1:
				want = ["right", "down"]
			2:
				want = ["down"]
			3:
				want = ["left", "down"]
			4:
				want = ["left"]
			5:
				want = ["left", "up"]
			6:
				want = ["up"]
			7:
				want = ["right", "up"]
	var t: Dictionary = touches[index]
	for a in t["actions"]:
		if not a in want:
			main.action_release(a)
	for a in want:
		if not a in t["actions"]:
			main.action_press(a)
	t["actions"] = want
	queue_redraw()


func _release_all() -> void:
	for i in touches.keys():
		_touch_end(i)


func _draw() -> void:
	if not visible:
		return
	var font := ThemeDB.fallback_font
	var held_pad := []
	for t in touches.values():
		if t["kind"] == "pad":
			held_pad += t["actions"]
	draw_circle(pad_center, pad_radius, Color(1, 1, 1, 0.08))
	draw_arc(pad_center, pad_radius, 0, TAU, 48, Color(1, 1, 1, 0.35), 2.0, true)
	var arrows := {"right": Vector2(1, 0), "left": Vector2(-1, 0), "up": Vector2(0, -1), "down": Vector2(0, 1)}
	for a in arrows:
		var dir: Vector2 = arrows[a]
		var c := pad_center + dir * pad_radius * 0.62
		var on: bool = a in held_pad
		var tri := PackedVector2Array([c + dir * pad_radius * 0.22, c + dir.orthogonal() * pad_radius * 0.17,
				c - dir.orthogonal() * pad_radius * 0.17])
		draw_colored_polygon(tri, Color(1, 1, 1, 0.75 if on else 0.35))
	for b in buttons:
		var on: bool = main.held.get(b["action"], false)
		var c: Vector2 = b["center"]
		var r: float = b["radius"]
		draw_circle(c, r, Color(1, 1, 1, 0.30 if on else 0.10))
		draw_arc(c, r, 0, TAU, 40, Color(1, 1, 1, 0.45), 2.0, true)
		var label: String = Strings.t(b["label"])
		var fs := int(maxf(10.0, r * 0.42))
		var w := font.get_string_size(label, HORIZONTAL_ALIGNMENT_LEFT, -1, fs).x
		draw_string(font, c + Vector2(-w / 2.0, fs * 0.35), label, HORIZONTAL_ALIGNMENT_LEFT, -1, fs,
				Color(1, 1, 1, 0.85))
