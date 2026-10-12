extends RefCounted
## One OBJECTS.BIN object in the hero's room: RoomObject_ctor 0x21D5C, RoomObject_ResetPath 0x21958,
## Object_Think 0x23F4C, Object_Interact 0x23E0C, Object_Overlaps 0x227B0, Object_Hit 0x22A6C,
## Object_FireTrigger 0x2205C and Platform_PushCarryHero 0x228C4 (docs 3.5).  Positions are 16.16 room
## pixels.  `rec` is the persistent record (flags and HP survive room visits, as in the original's buffer).

var sim                       # sim.gd (sounds, flags, scripts, hero)
var room                      # room.gd
var rec: Dictionary           # mutable record: flags, hp (+ static header fields and steps)
var steps: Array
var index := 0

var flags := 0                # runtime copy of the flags (0xa5)
var step_i := 0               # 0x14
var step: Array               # current step (0x0c)
var counter := 0              # ticks into the step / activation phase (0x10)
var x := 0
var y := 0
var ax := 0
var ay := 0
var vx := 0
var vy := 0
var frame := 0                # descriptor index (0x3d)
var fcount := 0               # frame tick counter (0x79, signed char)
var bx0 := 0
var by0 := 0
var bx1 := 0
var by1 := 0
var prev_x := 0               # 0x7f / 0x83
var prev_y := 0
var prev_frame := 0           # 0x41
var removed := false          # 0x7e
var cls := 0                  # collision class 0x87
var activated := false        # 0x8b
var flash := false            # 0x8f
var act_done := false         # 0x93
var frozen := false           # 0x9b (end mode 0)
var hidden := false           # 0x9f
var act_ticks := 0            # 0xc7
var solid_touch := false      # 0xcb
var preview := false          # built for a neighbouring room: never writes the record


func _init(p_sim, p_room, p_rec: Dictionary, p_index: int, p_preview := false) -> void:
	sim = p_sim
	room = p_room
	rec = p_rec
	steps = rec["steps"]
	index = p_index
	preview = p_preview
	flags = int(rec["flags"])
	reset_path()
	counter = 0
	removed = false
	var item := int(rec["item"])
	if flags & 0x8000 == 0:
		if flags & 1 and int(rec["end_mode"]) == 3:
			_rec_or(0x40)
	elif int(rec["interact"]) & 2 == 0:
		if item < 3:
			flags &= ~1
		elif flags & 4 == 0:
			if not sim.state.flag(item):
				flags &= ~1
		elif flags & 0x1000 == 0 and sim.state.flag(item):
			activated = true
			flags |= 1
			counter = 0
	elif flags & 0x1000 == 0 and sim.state.flag(item):
		activated = true
		flags |= 1
		counter = 0


func _rec_or(bits: int) -> void:
	if not preview:
		rec["flags"] = int(rec["flags"]) | bits


func _rec_and(mask: int) -> void:
	if not preview:
		rec["flags"] = int(rec["flags"]) & mask


func _set_box() -> void:
	var D = sim.D
	bx0 = D.desc_box[frame * 4]
	by0 = D.desc_box[frame * 4 + 1]
	bx1 = D.desc_box[frame * 4 + 2]
	by1 = D.desc_box[frame * 4 + 3]


func find_frame(st: Array) -> int:
	"""BobFindFrame: the step's group advanced by its start offset; the remainder is dropped."""
	var D = sim.D
	var i: int = D.group_first[st[7] & 0x7FFF]
	var start: int = st[8] & 0x7FFF
	while start > 0:
		var d: int = D.desc_dur[i]
		if start < d:
			start = 0
		else:
			start -= d
			i += 1
	return i


func reset_path() -> void:
	var D = sim.D
	if flags & 0x40 == 0:
		step_i = 0
		step = steps[0]
		counter = 0
		frame = find_frame(step)
		fcount = D.desc_dur[frame]
		x = step[4]
		y = step[5]
		ax = step[0]
		ay = step[1]
		vx = step[2]
		vy = step[3]
	else:
		step = steps[steps.size() - 1]
		frame = find_frame(step)
		x = step[4]
		y = step[5]
	prev_x = x
	prev_y = y
	prev_frame = frame
	_set_box()
	cls = (flags & 0x3C00) >> 7
	activated = false
	act_done = false
	hidden = step[8] & 0x8000 != 0
	flash = false
	act_ticks = 0


func enable(keep: bool) -> void:
	"""vtable +0x14: make the object exist; without `keep` its path restarts."""
	flags |= 1
	if not keep:
		reset_path()
	if (step[9] >> 11) & 7 == 1:
		_play_step_sound(step)


func _play_step_sound(st: Array) -> void:
	var snd: int = st[9] & 0x3FF
	sim.play_sound(snd)
	if sim.D.is_sound_looping(snd):
		room.loop_sounds[index] = snd


func _step_sound(st: Array) -> void:
	match (st[9] >> 11) & 7:
		1:
			_play_step_sound(st)
		3:
			var who: int = st[9] & 0x3FF
			if who < room.loop_sounds.size() and room.loop_sounds[who] >= 0:
				sim.stop_sound(room.loop_sounds[who])


func _animate() -> void:
	var D = sim.D
	var c := fcount
	fcount -= 1
	if c == 0:
		frame += 1
		fcount = D.desc_dur[frame]
		if fcount != -1:
			_set_box()
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
		_set_box()


func think() -> void:
	var D = sim.D
	prev_x = x
	prev_y = y
	prev_frame = frame
	if activated:
		if counter != 0:                                  # playing the activation animation
			var c := fcount
			fcount -= 1
			if c == 0:
				frame += 1
				fcount = D.desc_dur[frame]
				if fcount != -1:
					_set_box()
			if D.desc_dur[frame] != -1:
				return
			act_done = true
			frame = prev_frame
			counter = 0
			return
		var n := act_ticks
		act_ticks += 1
		if n == 0 and int(rec["sound"]) != 0:
			sim.play_sound(int(rec["sound"]))
		if act_done:
			activated = false
			if flags & 0x4010:
				fire_trigger()
			if flags & 0x80 == 0:
				removed = true
				flags &= ~1
				if flags & 0x100:
					reset_path()
					flags |= 1
					removed = false
				if not preview:
					rec["hp"] = rec["hp_max"]
			else:
				_rec_and(~0xC001)
				flags &= ~0xC001
				removed = true
			act_done = false
			return
		if int(rec["anim"]) & 0x8000:
			act_done = true
			return
		frame = D.group_first[int(rec["anim"])]
		fcount = D.desc_dur[frame]
		_set_box()
		ax = 0
		ay = 0
		vx = 0
		vy = 0
		counter += 1
		return
	if flags & 1 == 0 or flags & 0x40 or frozen:
		return
	if int(rec["end_mode"]) == 3:
		_rec_or(0x40)
	_animate()
	var n := counter
	counter += 1
	if n < step[6] & 0x3FF:
		vx += ax
		vy += ay
		x += vx
		y += vy
		return
	# next step
	step_i += 1
	var nxt: Array = steps[step_i] if step_i < steps.size() else []
	if step_i < steps.size():
		_step_sound(nxt)
		_load_step(nxt)
		return
	match int(rec["end_mode"]):
		0:
			ax = 0
			ay = 0
			vx = 0
			vy = 0
			frame = prev_frame
			frozen = true
		1:
			removed = true
			if flags & 8:                                  # invisible objects are not erased: they stop
				frozen = true
			else:
				flags &= ~1
		2:
			step_i = int(rec["loop_start"])
			_step_sound(steps[step_i])
			_load_step(steps[step_i])
		3:
			flags |= 0x40
			_rec_or(0x40)
		_:
			step_i = 0
			_load_step(steps[0])


func _load_step(st: Array) -> void:
	var D = sim.D
	step = st
	counter = 0
	frame = find_frame(st)
	hidden = st[8] & 0x8000 != 0
	fcount = D.desc_dur[frame]
	_set_box()
	x = st[4]
	y = st[5]
	ax = st[0]
	ay = st[1]
	vx = st[2]
	vy = st[3]
	if st[6] & 0x8000:
		var who: int = (st[6] >> 10) & 0x1F
		var o = room.object_by_index(who)
		if o:
			o.enable(false)


func overlaps(mask: int, x0: int, y0: int, x1: int, y1: int) -> int:
	"""Object_Overlaps: class bits if the box touches (x0,y0)-(x1,y1) (inclusive)."""
	solid_touch = false
	if flags & 1 == 0 or activated:
		return 0
	if mask & cls == 0:
		return 0
	var ox := x >> 16
	var oy := y >> 16
	if ox + bx1 < x0 or x1 < ox + bx0 or oy + by1 < y0 or y1 < oy + by0:
		return 0
	if mask & 0x40:
		solid_touch = true
		sim.hero.move_flags |= 4
	return cls


func interact() -> void:
	"""Object_Interact: touch, Enter or crouch activates it (subject to the item / flag lock)."""
	var st = sim.state
	var inter := int(rec["interact"])
	var item := int(rec["item"])
	var no := flags & 0x20 == 0
	if inter & 4 and sim.crouch_pick:
		no = false
	if st.key_enter and inter & 4 == 0 and flags & 0x20 == 0:
		no = false
	if no:
		return
	if flags & 0x8000:
		if inter & 2 == 0:
			if flags & 4 and not st.flag(item):
				st.key_down = false
				st.key_enter = false
				return
		elif item != st.selected_item():
			sim.queue_missing_item(item)
			return
	activated = true
	counter = 0
	flags |= 1
	st.key_enter = false
	st.key_down = false


func hit(damage: int) -> bool:
	"""Object_Hit: true if the bullet stops here."""
	var hp := int(rec["hp"])
	if hp == 0xFF:
		flash = true
		return true
	if cls == 0x20 or hp == 0xFE:
		return false
	flash = true
	hp = 0 if hp < damage else hp - damage
	rec["hp"] = hp
	if hp == 0:
		activated = true
		counter = 0
	return true


func fire_trigger() -> void:
	"""Object_FireTrigger: chain to index+1 and/or activate object / run script hdr[12]."""
	if flags & 0x10:
		var o = room.object_by_index(index + 1)
		if o:
			_trigger(o)
		if flags & 0x4000 == 0:
			return
	var target := int(rec["target"])
	if target < 20:
		var o = room.object_by_index(target)
		if o:
			_trigger(o)
	else:
		sim.state.set_flag(target)
		sim.queue_script(target, room)


func _trigger(o) -> void:
	if o.flags & 0x8000 == 0:
		o.activated = true
		o.counter = 0
		o.enable(true)
	else:
		o.enable(true)
		if int(o.rec["item"]) == 0:
			o.flags &= ~0x8000
			o._rec_and(~0x8000)


func push_carry_hero(h) -> void:
	"""Platform_PushCarryHero: push the hero out of a solid object it touched, or carry it."""
	if not solid_touch:
		return
	var nx: int = h.x
	var ny: int = h.y
	var ox := x >> 16
	var oy := y >> 16
	var px := prev_x >> 16
	var py := prev_y >> 16
	if by0 + py < h.prev_y + h.pby1:
		if h.prev_y + h.pby0 < by1 + py:
			if bx0 + px < h.prev_x + h.pbx1:
				if bx1 + px <= h.prev_x + h.pbx0:
					nx = ox + bx1 - h.bx0 + 1
			else:
				nx = ox + bx0 - h.bx1 - 1
		else:
			ny = oy + by1 - h.by0 + 1
	else:
		var top: int = oy + by0 - h.by1
		ny = top - 1
		if vx != 0 or vy != 0:
			nx = h.x + (ox - px)
			h.carried = true
			if vy > 0:
				ny = top
	h.x = nx
	h.y = ny


func visible() -> bool:
	return flags & 1 != 0 and flags & 8 == 0 and not hidden and not removed
