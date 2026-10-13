extends RefCounted
## The hero: Hero_Think 0x24A24, HeroState00-15, Hero_MoveCollide 0x232C4, TileCollide 0x230FC.
## Coordinates are pixels relative to the hero's room (as in the original); tile collision looks the
## world up seamlessly, and the hero changes room when his middle crosses an edge (docs remake notes).

const FIX := 65536
const GRAVITY := 0x3851
const JUMP_V0 := -0x4E20D              # 0xFFFB1DF3
const FALL_CAP := 0xA0000
const STAND := 0
const WALK := 2
const JUMP := 4
const FALL := 6
const JET := 8
const CROUCH := 10
const TELE_OUT := 14
const TELE_IN := 15

var sim
var D
var col := 7
var row := 0
var x := 0
var y := 0
var fx := 0                   # 16.16 position for the jetpack (0x86 / 0x8a)
var fy := 0
var vx := 0                   # 0x5e
var vy := 0                   # 0x62
var state := 0                # 0x7a
var fresh := true             # 0x6e == -1: run the state's entry code
var frame := 1025             # 0x10
var bob := 1025               # 0x08: the picture drawn, loaded with the box (a loop back to an earlier frame
                              # does not reload it: crouching stays on its last frame while Down is held)
var fcount := 0               # 0x38
var bx0 := 0
var by0 := 0
var bx1 := 0
var by1 := 0
var pbx0 := 0                 # box at the start of the tick (0x28..0x34)
var pby0 := 0
var pbx1 := 0
var pby1 := 0
var prev_x := 0               # 0x72 / 0x76
var prev_y := 0
var input_x := 0              # g_inputX (0x8e)
var input_y := 0              # g_inputY (0x92)
var move_flags := 0           # DAT_0008898c: 1 x blocked, 2 y blocked, 4 solid object
var falling := false          # DAT_00053428
var carried := false          # DAT_0008899c
var dir := 0                  # g_heroDir
var walk_ticks := 0           # DAT_000c0054
var jet_sound := 0            # DAT_000c0058
var crouch_dir := 1           # DAT_000b15ac
var hit := false              # g_heroHit
var tp_dest := [0, 0, 0, 0]
var room_changed := false
var classic := false          # true: the original's room-local collision and edge transitions (tests)


func _init(p_sim) -> void:
	sim = p_sim
	D = p_sim.D


func place(p_col: int, p_row: int, px: int, py: int, p_state := 0) -> void:
	col = p_col
	row = p_row
	x = px
	y = py
	fx = x * FIX
	fy = y * FIX
	vx = 0
	vy = 0
	state = p_state
	fresh = true
	_set_frame(1025 if p_state % 2 == 0 else 1027)


func _set_frame(f: int) -> void:
	frame = f
	fcount = D.desc_dur[f]
	_load_box()


func _load_box() -> void:
	bob = frame
	bx0 = D.desc_box[frame * 4]
	by0 = D.desc_box[frame * 4 + 1]
	bx1 = D.desc_box[frame * 4 + 2]
	by1 = D.desc_box[frame * 4 + 3]


func _animate() -> void:
	var c := fcount
	fcount -= 1
	if c == 0:
		frame += 1
		fcount = D.desc_dur[frame]
		if fcount != -1:
			_load_box()
	if D.desc_dur[frame] == -1:
		var off: int = D.desc_off[frame]
		var skip := off >> 16
		frame = off & 0xFFFF
		fcount = D.desc_dur[frame]
		while skip != 0:
			var d: int = D.desc_dur[frame]
			if skip < d:
				fcount = d - skip
				skip = 0
			else:
				skip -= d
				frame += 1
				fcount = D.desc_dur[frame]
		_load_box()


func enter(s: int) -> void:
	state = s
	fresh = true


# ---------------------------------------------------------------------------
# collision
# ---------------------------------------------------------------------------
func tile_collide(x0: int, y0: int, x1: int, y1: int, tx: int, ty: int) -> int:
	"""0 free, 1 harmful (sets hit), 2 solid.  Coordinates and tiles relative to the hero's room."""
	var t: int
	if classic:                                        # TileCollide: one tile into the neighbour room
		var dc := -1 if tx < 0 else (1 if tx > 13 else 0)
		var dr := -1 if ty < 0 else (1 if ty > 11 else 0)
		var cx := 13 if tx < 0 else (0 if tx > 13 else tx)
		var cy := 11 if ty < 0 else (0 if ty > 11 else ty)
		t = sim.world_tile((col + dc) * 14 + cx, (row + dr) * 12 + cy)
	else:
		t = sim.world_tile(col * 14 + tx, row * 12 + ty)
	var kind: int = D.tile_types[t] if t < D.tile_types.size() else 4
	if kind == 2:
		return 0
	var b := t * 4
	if t * 4 + 3 >= D.tile_boxes.size():
		return 0
	if tx * 16 + D.tile_boxes[b + 2] < x0 or x1 < tx * 16 + D.tile_boxes[b] \
			or ty * 19 + D.tile_boxes[b + 3] < y0 or y1 < ty * 19 + D.tile_boxes[b + 1]:
		return 0
	if kind == 1:
		hit = true
		return 1
	return 2


func _blocked(x0: int, y0: int, x1: int, y1: int, tx0: int, ty0: int) -> bool:
	for tx in range(tx0, tx0 + 3):
		for ty in range(ty0, ty0 + 3):
			if tile_collide(x0, y0, x1, y1, tx, ty) == 2:
				return true
	return false


func _fdiv(a: int, b: int) -> int:
	"""Tile index of a pixel: floor in the seamless world, C division in the original."""
	if classic or a >= 0:
		return a / b
	return floori(float(a) / b)


func move_collide(dx: int, dy: int) -> void:
	"""Hero_MoveCollide: X then Y, each all-or-nothing; then solid objects push / carry; then rooms."""
	var x0 := x + bx0
	var y0 := y + by0
	var x1 := x + bx1
	var y1 := y + by1
	if not _blocked(x0 + dx, y0, x1 + dx, y1, (x0 + dx) >> 4, _fdiv(y0, 19)):
		x += dx
		x0 += dx
		x1 += dx
	else:
		move_flags |= 1
	if not _blocked(x0, y0 + dy, x1, y1 + dy, _fdiv(x0, 16), _fdiv(y0 + dy, 19)):
		y += dy
	else:
		move_flags |= 2
	falling = false
	var room = sim.live_room
	if room:
		for o in room.objects:
			if o:
				o.overlaps(0x40, x + bx0, y + by0, x + bx1, y + by1)
		if move_flags & 6:
			for o in room.objects:
				if o:
					o.push_carry_hero(self)
	_room_transitions()


func _room_transitions() -> void:
	if classic:
		_classic_transitions()
		return
	var dc := 0
	var dr := 0
	if x + 11 < 0:
		if col < 1:
			x = -11
		else:
			dc = -1
	elif x + 11 > 224:
		if col < 9:
			dc = 1
		else:
			x = 213
	if y < 0 and row < 1:
		y = 0
	elif y + 15 < 0:
		dr = -1
	elif y + 15 > 228:
		if row < 9:
			dr = 1
		else:
			y = 213
	if dc or dr:
		col += dc
		row += dr
		x -= dc * 224
		y -= dr * 228
		fx -= dc * 224 * FIX
		fy -= dr * 228 * FIX
		prev_x -= dc * 224
		prev_y -= dr * 228
		room_changed = true
		sim.on_hero_room_changed()


func _classic_transitions() -> void:
	"""Hero_MoveCollide's edges: the hero is placed fully inside the new room."""
	var moved := false
	if x + 11 < 0:
		if col < 1:
			x = -11
		else:
			col -= 1
			x = 213
			moved = true
	if x + 11 > 224:
		if col < 9:
			col += 1
			x = -11
			moved = true
		else:
			x = 213
	if y < 0:
		if row < 1:
			y = 0
		else:
			row -= 1
			y = 197
			moved = true
	if y + 15 > 228:
		if row < 9:
			row += 1
			y = 0
			moved = true
		else:
			y = 213
	if moved:
		fx = x * FIX
		fy = y * FIX
		room_changed = true
		sim.on_hero_room_changed()


# ---------------------------------------------------------------------------
# objects
# ---------------------------------------------------------------------------
func _touch_objects() -> bool:
	"""Usable objects under the hero activate (Object_Interact); harmful ones and harmful animated
	tiles hit him.  Returns whether a usable object was touched."""
	var touched := false
	var room = sim.live_room
	if room == null:
		return false
	var x0 := x + bx0
	var y0 := y + by0
	var x1 := x + bx1
	var y1 := y + by1
	for o in room.objects:
		if o == null:
			continue
		if o.overlaps(0x20, x0, y0, x1, y1):
			o.interact()
			touched = true
		if o.overlaps(0x11, x0, y0, x1, y1):
			hit = true
	if room.anims_hit(x0, y0, x1, y1):
		hit = true
	return touched


func _harm_only() -> void:
	var room = sim.live_room
	if room == null:
		return
	var x0 := x + bx0
	var y0 := y + by0
	var x1 := x + bx1
	var y1 := y + by1
	for o in room.objects:
		if o and o.overlaps(0x11, x0, y0, x1, y1):
			hit = true
	if room.anims_hit(x0, y0, x1, y1):
		hit = true


func _use_item(touched: bool) -> void:
	var st = sim.state
	if st.key_enter and not touched:
		sim.queue_item_use()
		input_x = 0
		input_y = 0
		st.key_fire = false
		st.key_enter = false


# ---------------------------------------------------------------------------
# one tick (Hero_Think)
# ---------------------------------------------------------------------------
func think() -> void:
	prev_x = x
	prev_y = y
	pbx0 = bx0
	pby0 = by0
	pbx1 = bx1
	pby1 = by1
	room_changed = false
	match state:
		0, 1:
			_stand(state)
		2, 3:
			_walk(state)
		4, 5:
			_jump(state)
		6, 7:
			_fall(state)
		8, 9:
			_jet(state)
		10, 11:
			_crouch(state)
		14:
			_teleport_out()
		15:
			_teleport_in()
	carried = false


func _stand(s: int) -> void:
	var face := s & 1
	if fresh:
		sim.play_sound(46)
		dir = face
		fresh = false
		_set_frame(1027 if face else 1025)
	var touched := _touch_objects()
	_use_item(touched)
	move_collide(input_x, 1)
	if prev_y < y and not carried:
		falling = true
	if input_y < 0:
		enter(JUMP + face)
	elif falling:
		vy = 0
		enter(FALL + face)
	elif face == 0:
		if input_x < 0:
			enter(WALK)
		elif input_x >= 1:
			enter(STAND + 1)
		elif sim.state.jet_on:
			enter(JET)
		elif sim.state.key_down:
			enter(CROUCH)
	else:
		if input_x >= 1:
			enter(WALK + 1)
		elif input_x < 0:
			enter(STAND)
		elif sim.state.jet_on:
			enter(JET + 1)
		elif sim.state.key_down:
			enter(CROUCH + 1)


func _walk(s: int) -> void:
	var face := s & 1
	if fresh:
		sim.play_sound(46)
		walk_ticks = 0
		dir = face
		fresh = false
		_set_frame(14 if face else 3)
		sim.state.key_up = false
	else:
		if walk_ticks == 18 or walk_ticks == 35:
			sim.play_sound(46)
		walk_ticks += 1
		if walk_ticks == 37:
			walk_ticks = 0
		_animate()
	move_collide(input_x, 1)
	if prev_y < y and not carried:
		falling = true
	var touched := _touch_objects()
	_use_item(touched)
	if input_y < 0:
		enter(JUMP + face)
	elif falling:
		enter(FALL + face)
		vy = 0
	elif input_x == 0:
		enter(STAND + face)
	elif face == 0 and input_x > 0:
		enter(WALK + 1)
	elif face == 1 and input_x < 0:
		enter(WALK)
	elif sim.state.jet_on:
		enter(JET + face)
	elif sim.state.key_down:
		enter(CROUCH + face)


func _jump(s: int) -> void:
	var face := s & 1
	if fresh:
		dir = face
		fresh = false
		_set_frame(1009 if face else 1005)
		vy = JUMP_V0
	var touched := _touch_objects()
	_use_item(touched)
	move_flags = 0
	vy += GRAVITY
	move_collide(input_x, vy >> 16)
	if move_flags & 6 == 0 and vy < 1 and input_y < 0:
		if face == 0 and input_x >= 1:
			state = JUMP + 1                       # turn in the air: loads the standing frame (bug)
			fresh = false
			_set_frame(1027)
		elif face == 1 and input_x < 0:
			state = JUMP
			fresh = false
			_set_frame(1025)
		elif sim.state.jet_on:
			enter(JET + face)
	else:
		enter(FALL + face)
		vy = 0


func _fall(s: int) -> void:
	var face := s & 1
	if fresh:
		dir = face
		fresh = false
		_set_frame(1009 if face else 1005)
	vy = mini(vy + GRAVITY, FALL_CAP)
	move_collide(input_x, (vy >> 16) + 1)
	if y != prev_y:
		falling = true
	var touched := _touch_objects()
	_use_item(touched)
	if sim.state.jet_on:
		enter(JET + face)
	elif not falling:
		enter(STAND + face)
		vy = 0
		input_y = 0
	elif face == 0 and input_x > 0:
		enter(FALL + 1)
	elif face == 1 and input_x < 0:
		enter(FALL)


func _jet(s: int) -> void:
	var face := s & 1
	if fresh:
		jet_sound = 1
		sim.play_sound(27)
		dir = face
		fresh = false
		_set_frame(1009 if face else 1005)
		vy = -2 * FIX
		vx = 0
		fx = x * FIX
		fy = y * FIX
	else:
		_animate()
	if input_y < 0 and jet_sound != 2:
		sim.stop_sound(27)
		sim.play_sound(28)
		jet_sound = 2
	if input_y >= 0 and jet_sound != 1:
		sim.stop_sound(28)
		sim.play_sound(27)
		jet_sound = 1
	if input_x > 0:
		vx += 0x1800
	elif input_x < 0:
		vx -= 0x1800
	elif vx > 0:
		vx -= 0x400
	elif vx < 0:
		vx += 0x400
	vy += -0x1800 if input_y < 0 else 0x1000
	vx = clampi(vx, -0x30000, 0x30000)
	vy = clampi(vy, -0x30000, 0x30000)
	fx += vx
	fy += vy
	move_flags = 0
	move_collide((fx >> 16) - x, (fy >> 16) - y)
	if move_flags == 4:
		vx = -(vx >> 1)
		vy = -(vy >> 1)
		fx = x * FIX
		fy = y * FIX
	else:
		if move_flags == 1:
			vx = -(vx >> 1)
			fx = x * FIX
		if move_flags == 2:
			vy = -(vy >> 1)
			fy = y * FIX
	var touched := _touch_objects()
	_use_item(touched)
	var st = sim.state
	st.fuel -= 0x800
	if st.fuel < 0:
		st.fuel = 0
		st.jet_on = false
	if not st.jet_on:
		enter(FALL + face)
		sim.stop_sound(27)
		sim.stop_sound(28)
	elif face == 0 and input_x > 0:
		state = JET + 1
		fresh = false
		_set_frame(1009)
		dir = 1
	elif face == 1 and input_x < 0:
		state = JET
		fresh = false
		_set_frame(1005)
		dir = 0


func _crouch(s: int) -> void:
	var face := s & 1
	var st = sim.state
	crouch_dir = 1 if st.key_down else -1
	sim.crouch_pick = false
	if fresh:
		st.fire_armed = false
		dir = face
		fresh = false
		_set_frame(1017 if face else 1013)
		crouch_dir = 1
	else:
		var c := fcount
		fcount -= 1
		if c == 0:
			frame += crouch_dir
			fcount = D.desc_dur[frame]
			if fcount != -1:
				_load_box()
		if D.desc_dur[frame] == -1:
			frame -= crouch_dir * 2
			fcount = D.desc_dur[frame]
			if not st.key_down:
				enter(STAND + face)
				st.fire_armed = true
				return
		if st.key_down:
			sim.crouch_pick = true
			var room = sim.live_room
			if room:
				for o in room.objects:
					if o and o.overlaps(0x20, x + bx0, y + by0, x + bx1, y + by1):
						o.interact()
			sim.crouch_pick = false
	move_collide(0, 1)
	if prev_y < y and not carried:
		falling = true
	_harm_only()
	if st.key_enter:
		sim.queue_item_use()
		input_x = 0
		input_y = 0
		st.key_fire = false
		st.key_enter = false
	if falling:
		enter(FALL + face)
		st.fire_armed = true
		vy = 0


func _teleport_out() -> void:
	if fresh:
		sim.play_sound(41)
		fresh = false
		_set_frame(1089)
		input_x = 0
		vy = 0
		vx = 0
		fx = x * FIX
		fy = y * FIX
		return
	var c := fcount
	fcount -= 1
	if c == 0:
		frame += 1
		fcount = D.desc_dur[frame]
		if fcount != -1:
			_load_box()
	if D.desc_dur[frame] == -1:
		var st = sim.state
		st.jet_on = false
		state = TELE_IN
		fresh = true
		col = tp_dest[0]
		row = tp_dest[1]
		x = tp_dest[2]
		y = tp_dest[3]
		fx = x * FIX
		fy = y * FIX
		room_changed = true
		sim.on_hero_room_changed(true)
		input_x = 0
		input_y = 0
		st.key_fire = false
		st.key_enter = false
		st.key_down = false


func _teleport_in() -> void:
	if fresh:
		sim.play_sound(41)
		fresh = false
		_set_frame(1105)
		input_x = 0
		vy = 0
		vx = 0
		fx = x * FIX
		fy = y * FIX
		return
	var c := fcount
	fcount -= 1
	if c == 0:
		frame -= 1
		fcount = D.desc_dur[frame]
		if fcount != -1:
			_load_box()
	if D.desc_dur[frame] == -1:
		state = dir + 1                                # the original's quirk: the facing flips
		fresh = true
		sim.teleport_finished()


func start_teleport(c: int, r: int, px: int, py: int) -> void:
	"""Hero_StartTeleport."""
	tp_dest = [c, r, px, py]
	sim.state.jet_on = false
	state = TELE_OUT
	fresh = true


func box_world() -> Rect2i:
	return Rect2i(col * 224 + x + bx0, row * 228 + y + by0, bx1 - bx0 + 1, by1 - by0 + 1)
