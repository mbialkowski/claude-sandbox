extends RefCounted
## A room built by EnterRoom (0x29304): its animated tiles (RoomTrigger_ctor / TileAnim_*) and objects.
## The hero's room is live; neighbouring rooms shown at the screen edges are built as previews (frozen at
## their first frame, never writing the persistent records) until the hero walks in.

const RoomObject = preload("res://scripts/sim/room_object.gd")

var sim
var col := 0
var row := 0
var data: Dictionary          # rooms[] entry of game.json (records are shared and mutable)
var objects := []
var anims := []               # [col, row, foreground, pointer, start] (pointer into tile_seq_flat)
var loop_sounds := []         # looping sound started by object i (DAT_0007d158)
var preview := true
var was_live := false


func _init(p_sim, p_col: int, p_row: int, p_preview: bool) -> void:
	sim = p_sim
	col = p_col
	row = p_row
	preview = p_preview
	was_live = not p_preview
	data = sim.state.rooms[p_row * 10 + p_col]
	loop_sounds.resize(20)
	loop_sounds.fill(-1)
	var D = sim.D
	for a in data["anims"]:
		var start: int = D.tile_seq_start[int(a[3])]
		anims.append([int(a[0]), int(a[1]), int(a[2]) != 0, start + int(a[4]), start])
	var i := 0
	for r in data["objects"]:
		if r["steps"].size() > 0:
			objects.append(RoomObject.new(sim, self, r, i, p_preview))
		else:
			objects.append(null)
		i += 1


func object_by_index(i: int):
	return objects[i] if i >= 0 and i < objects.size() else null


func anim_tile(a: Array) -> int:
	var D = sim.D
	var p: int = a[3]
	return D.tile_seq_flat[p] if p < D.tile_seq_flat.size() else -1


func think() -> void:
	"""One tick of GameLoop's object pass: tile animations, then objects in list order."""
	var D = sim.D
	for a in anims:
		a[3] += 1
		if a[3] >= D.tile_seq_flat.size() or D.tile_seq_flat[a[3]] == -1:
			a[3] = a[4]
	for o in objects:
		if o:
			o.think()


func anims_hit(x0: int, y0: int, x1: int, y1: int) -> bool:
	"""TileAnim_Overlaps with mask 0x11: an animated tile showing a harmful tile hurts the hero."""
	var D = sim.D
	for a in anims:
		var t := anim_tile(a)
		if t < 0 or t >= D.tile_types.size() or D.tile_types[t] & 0x11 == 0:
			continue
		var tx: int = a[0] * 16
		var ty: int = a[1] * 19
		if tx + D.tile_boxes[t * 4 + 2] < x0 or x1 < tx + D.tile_boxes[t * 4] \
				or ty + D.tile_boxes[t * 4 + 3] < y0 or y1 < ty + D.tile_boxes[t * 4 + 1]:
			continue
		return true
	return false


func stop_sounds() -> void:
	for s in loop_sounds:
		if s >= 0:
			sim.stop_sound(s)
	loop_sounds.fill(-1)
