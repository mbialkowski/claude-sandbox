extends Node2D
## Draws the game in palette indices into the indexed SubViewport (red channel = index): the visible
## rooms around the hero's room (static tiles cached in one layer), animated tiles, objects clipped to
## their room, the hero, shots, the HUD panel, dialogue text and full-screen overlays.

const Layer = preload("res://scripts/view/layer.gd")

const H := 240
const HUD_W := 76
const ROOM_W := 224
const ROOM_H := 228

var D
var game                       # main.gd
var width := 320
var view_w := 244              # pixels left of the HUD
var cam := Vector2.ZERO        # world pixel at the view's top-left
var cam_from := Vector2.ZERO
var cam_to := Vector2.ZERO
var cam_t := 1.0
var visible_rooms := []        # Vector2i, drawn order: neighbours first, the hero's room last
var static_keys := []

var static_layer: Node2D
var dynamic_layer: Node2D
var hud_layer: Node2D
var text_layer: Node2D
var overlay_layer: Node2D


func setup(p_D, p_game) -> void:
	D = p_D
	game = p_game
	static_layer = _layer(_draw_static)
	dynamic_layer = _layer(_draw_dynamic)
	hud_layer = _layer(_draw_hud)
	text_layer = _layer(_draw_text)
	overlay_layer = _layer(_draw_overlay)


func _layer(f: Callable) -> Node2D:
	var l := Layer.new()
	l.painter = f
	add_child(l)
	return l


func set_width(w: int) -> void:
	width = w
	view_w = w - HUD_W
	hud_layer.position = Vector2(view_w, 0)
	refresh_all()


func refresh_all() -> void:
	static_keys = []
	for l in [static_layer, dynamic_layer, hud_layer, text_layer, overlay_layer]:
		l.queue_redraw()


# ---------------------------------------------------------------------------
# camera
# ---------------------------------------------------------------------------
func room_target(c: int, r: int) -> Vector2:
	"""Camera position that shows room (c,r) centred in the view, 6 px from the top like the original."""
	return Vector2(c * ROOM_W - floori((view_w - ROOM_W) / 2.0), r * ROOM_H - 6)


func room_screen_origin() -> Vector2:
	"""Where the hero's room sits on screen once the camera settled (dialogue text is placed by it)."""
	return Vector2(floori((view_w - ROOM_W) / 2.0), 6)


func follow(c: int, r: int, cut: bool) -> void:
	var t := room_target(c, r)
	if cut:
		cam = t
		cam_to = t
		cam_t = 1.0
	elif t != cam_to:
		cam_from = cam
		cam_to = t
		cam_t = 0.0


func update_camera(delta: float) -> void:
	if cam_t < 1.0:
		cam_t = minf(1.0, cam_t + delta / 0.35)
		var e := 1.0 - pow(1.0 - cam_t, 3.0)
		cam = cam_from.lerp(cam_to, e)
	var p := Vector2(-roundf(cam.x), -roundf(cam.y))
	static_layer.position = p
	dynamic_layer.position = p
	# rooms on screen
	var keys := []
	var live: Vector2i = Vector2i(game.sim.hero.col, game.sim.hero.row) if game.sim else Vector2i(-1, -1)
	var c0 := floori(cam.x / ROOM_W)
	var c1 := floori((cam.x + view_w - 1) / ROOM_W)
	var r0 := floori(cam.y / ROOM_H)
	var r1 := floori((cam.y + H - 1) / ROOM_H)
	for r in range(r0, r1 + 1):
		for c in range(c0, c1 + 1):
			if c >= 0 and r >= 0 and c < 10 and r < 10 and Vector2i(c, r) != live:
				if D.settings["show_neighbours"] or cam_t < 1.0:
					keys.append(Vector2i(c, r))
	keys.append(live)
	visible_rooms = keys
	if keys != static_keys:
		static_keys = keys.duplicate()
		static_layer.queue_redraw()


func focus_rect() -> Rect2:
	"""The hero's room on screen (outside it the shader dims the neighbours)."""
	if game.sim == null:
		return Rect2(0, 0, width, H)
	var o := Vector2(game.sim.hero.col * ROOM_W, game.sim.hero.row * ROOM_H) - Vector2(roundf(cam.x), roundf(cam.y))
	return Rect2(o, Vector2(ROOM_W, ROOM_H))


# ---------------------------------------------------------------------------
# primitives
# ---------------------------------------------------------------------------
func frame_size(f: int) -> Vector2:
	var r = D.frame_rect[f] if f >= 0 and f < D.frame_rect.size() else null
	return Vector2.ZERO if r == null else r.size


func draw_frame(ci: CanvasItem, f: int, pos: Vector2, clip = null, silhouette := -1) -> void:
	if f < 0 or f >= D.frame_rect.size():
		return
	var src = D.frame_rect[f]
	if src == null:
		return
	var dst := Rect2(pos, src.size)
	if clip != null:
		var cut: Rect2 = dst.intersection(clip)
		if cut.size.x <= 0 or cut.size.y <= 0:
			return
		src = Rect2(src.position + (cut.position - dst.position), cut.size)
		dst = cut
	if silhouette >= 0:
		ci.draw_texture_rect_region(D.tex_sprites_mask, dst, src, Color(silhouette / 255.0, 0, 0, 1))
	else:
		ci.draw_texture_rect_region(D.tex_sprites, dst, src)


func draw_frame_rows(ci: CanvasItem, f: int, pos: Vector2, row0: int, row1: int) -> void:
	"""Rows row0..row1-1 of a frame (the HUD tubes)."""
	var src = D.frame_rect[f]
	if src == null or row1 <= row0:
		return
	var s := Rect2(src.position + Vector2(0, row0), Vector2(src.size.x, row1 - row0))
	ci.draw_texture_rect_region(D.tex_sprites, Rect2(pos + Vector2(0, row0), s.size), s)


func fill(ci: CanvasItem, r: Rect2, index: int) -> void:
	ci.draw_rect(r, Color(index / 255.0, 0, 0, 1))


func draw_platform_tile(ci: CanvasItem, t: int, pos: Vector2) -> void:
	if t <= 0 or t >= int(D.game["platform_tiles"]):
		return
	ci.draw_texture_rect_region(D.tex_platform, Rect2(pos, Vector2(16, 19)),
			Rect2((t % 20) * 16, (t / 20) * 19, 16, 19))


func draw_glyph(ci: CanvasItem, code: int, pos: Vector2, colour: int, outline := 42) -> void:
	var g = D.glyphs.get(code)
	if g == null:
		return
	var cell: Array = D.font["cell"]
	var src := Rect2(g[0], g[1], cell[0], cell[1])
	var dst := Rect2(pos, src.size)
	ci.draw_texture_rect_region(D.tex_font_outline, dst, src, Color(outline / 255.0, 0, 0, 1))
	ci.draw_texture_rect_region(D.tex_font_body, dst, src, Color(colour / 255.0, 0, 0, 1))


func draw_string_at(ci: CanvasItem, s: String, pos: Vector2, colour: int, outline := 42) -> void:
	var x := pos.x
	var f: Dictionary = D.font
	var spacing := int(f["letter_spacing"])
	for i in s.length():
		var code := s.unicode_at(i)
		if code == 32:
			x += int(f["space_advance"]) + spacing
		var g = D.glyphs.get(code)
		if g == null:
			continue
		if code != 32:
			draw_glyph(ci, code, Vector2(x, pos.y), colour, outline)
		x += int(g[2]) + spacing


func string_width(s: String) -> int:
	var w := 0
	var f: Dictionary = D.font
	var spacing := int(f["letter_spacing"])
	for i in s.length():
		var code := s.unicode_at(i)
		if code == 32:
			w += int(f["space_advance"]) + spacing
		var g = D.glyphs.get(code)
		if g != null:
			w += int(g[2]) + spacing
	return w


# ---------------------------------------------------------------------------
# layers
# ---------------------------------------------------------------------------
func _draw_static(ci: CanvasItem) -> void:
	for k in static_keys:
		if k.x < 0 or k.y < 0 or k.x > 9 or k.y > 9:
			continue
		var room: Dictionary = D.game["rooms"][k.y * 10 + k.x]
		var ox: int = k.x * ROOM_W
		var oy: int = k.y * ROOM_H
		var bg: PackedInt32Array = room["bg"]
		for ty in 6:
			for tx in 7:
				var t: int = bg[ty * 7 + tx]
				ci.draw_texture_rect_region(D.tex_background, Rect2(ox + tx * 32, oy + ty * 38, 32, 38),
						Rect2((t % 10) * 32, (t / 10) * 38, 32, 38))
		var tiles: PackedInt32Array = room["tiles"]
		for ty in 12:
			for tx in 14:
				draw_platform_tile(ci, tiles[ty * 14 + tx], Vector2(ox + tx * 16, oy + ty * 19))


func _draw_dynamic(ci: CanvasItem) -> void:
	var sim = game.sim
	if sim == null:
		return
	var live: Vector2i = Vector2i(sim.hero.col, sim.hero.row)
	for k in visible_rooms:
		var room = sim.rooms.get(k)
		if room == null:
			continue
		var ox: int = k.x * ROOM_W
		var oy: int = k.y * ROOM_H
		var clip := Rect2(ox, oy, ROOM_W, ROOM_H)
		_draw_anims(ci, room, false, ox, oy)
		for o in room.objects:
			if o and o.visible():
				draw_frame(ci, o.frame, Vector2(ox + (o.x >> 16), oy + (o.y >> 16)), clip,
						0x1D if o.flash else -1)
		if k == live:
			_draw_hero(ci, sim)
		_draw_anims(ci, room, true, ox, oy)
		if k == live:
			for b in sim.bullets:
				draw_frame(ci, b.frame, Vector2(b.col * ROOM_W + (b.x >> 16), b.row * ROOM_H + (b.y >> 16)),
						Rect2(b.col * ROOM_W, b.row * ROOM_H, ROOM_W, ROOM_H))


func _draw_anims(ci: CanvasItem, room, foreground: bool, ox: int, oy: int) -> void:
	for a in room.anims:
		if a[2] == foreground:
			draw_platform_tile(ci, room.anim_tile(a), Vector2(ox + a[0] * 16, oy + a[1] * 19))


func _draw_hero(ci: CanvasItem, sim) -> void:
	var h = sim.hero
	if not game.hero_visible:
		return
	var pos := Vector2(h.col * ROOM_W + h.x, h.row * ROOM_H + h.y)
	draw_frame(ci, h.frame, pos, null, sim.state.hit_colour if h.hit else -1)


func _draw_hud(ci: CanvasItem) -> void:
	if not game.hud_visible:
		return
	ci.draw_texture(D.tex_hud, Vector2.ZERO)
	var sim = game.sim
	if sim == null:
		return
	var st = sim.state
	_tube(ci, Vector2(16, 111), st.energy, 1085)
	_tube(ci, Vector2(32, 111), st.ammo[st.weapon], 1087)
	_tube(ci, Vector2(48, 111), st.fuel, 1086)
	draw_frame(ci, 1064 + st.weapon * 2, Vector2(11, 8))
	var item: int = st.selected_item()
	draw_frame(ci, int(D.game["items"][item]["icon_frame"]), Vector2(32, 204))


func _tube(ci: CanvasItem, pos: Vector2, value: int, fill_frame: int) -> void:
	var empty := clampi(47 - (value >> 16), 0, 47)
	draw_frame_rows(ci, 1084, pos, 0, empty)
	draw_frame_rows(ci, fill_frame, pos, empty, 47)


func _draw_text(ci: CanvasItem) -> void:
	var t = game.text
	if t == null or t.glyphs.is_empty():
		return
	var o: Vector2 = game.text_origin
	for g in t.glyphs:
		draw_glyph(ci, g[2], o + Vector2(g[0], g[1]), g[3], t.outline)


func _draw_overlay(ci: CanvasItem) -> void:
	game.draw_overlay(ci)
