extends SceneTree
## Replays assets/gamedata/golden_traces.json (tools/reference_sim.py) through the remake's hero and
## object code and compares every tick.
##     godot --headless --path remake --script res://tests/golden.gd

const DataScript = preload("res://scripts/game/data.gd")
const Sim = preload("res://scripts/sim/sim.gd")
const RoomObject = preload("res://scripts/sim/room_object.gd")

const SOLID_TILE := 93


class StubRoom:
	var loop_sounds := []
	var col := 0
	var row := 0

	func _init() -> void:
		loop_sounds.resize(20)
		loop_sounds.fill(-1)

	func object_by_index(_i: int):
		return null


func _initialize() -> void:
	var D = DataScript.new()
	D.load_all(false)
	var traces = JSON.parse_string(FileAccess.get_file_as_string("res://data/golden_traces.json"))
	var failures := 0
	var total := 0
	for name in traces["hero"]:
		total += 1
		if not _hero_trace(D, name, traces["hero"][name]):
			failures += 1
	var obj_fail := 0
	for key in traces["objects"]:
		total += 1
		if not _object_trace(D, key, traces["objects"][key]):
			obj_fail += 1
	failures += obj_fail
	print("golden traces: %d/%d match" % [total - failures, total])
	D.free()
	quit(1 if failures else 0)


func _test_grid() -> Array:
	var g := []
	g.resize(168)
	g.fill(0)
	for x in 14:
		g[x] = SOLID_TILE
		g[10 * 14 + x] = SOLID_TILE
		g[11 * 14 + x] = SOLID_TILE
	for y in 12:
		g[y * 14] = SOLID_TILE
		g[y * 14 + 13] = SOLID_TILE
	return g


func _snap(h) -> Array:
	return [h.col, h.row, h.x, h.y, h.state, h.frame, snappedf(h.vx / 65536.0, 0.00001),
			snappedf(h.vy / 65536.0, 0.00001)]


func _same(a: Array, b: Array) -> bool:
	for i in a.size():
		if absf(float(a[i]) - float(b[i])) > 0.00002:
			return false
	return true


func _hero_trace(D, name: String, t: Dictionary) -> bool:
	var sim = Sim.new(D, 1)
	var room := Vector2i(int(t["room"][0]), int(t["room"][1]))
	if room == Vector2i(99, 99):
		sim.test_room[room] = _test_grid()
	var h = sim.hero
	h.classic = true
	h.place(room.x, room.y, int(t["start"][0]), int(t["start"][1]), 0)
	sim.state.fuel = int(t["fuel"])
	var rows: Array = t["ticks"]
	var i := 0
	if not _same(_snap(h), rows[0]):
		print("%s: start differs %s vs %s" % [name, _snap(h), rows[0]])
		return false
	for seg in t["input"]:
		for _k in int(seg["ticks"]):
			h.input_x = int(seg["x"])
			h.input_y = -1 if seg["up"] else 0
			if seg["jetpack"] != null:
				sim.state.jet_on = bool(seg["jetpack"]) and sim.state.fuel > 0
			h.think()
			i += 1
			var got := _snap(h)
			if not _same(got, rows[i]):
				print("%s: tick %d differs: got %s want %s (prev %s)" % [name, i, got, rows[i], rows[i - 1]])
				return false
	return true


func _object_trace(D, key: String, t: Dictionary) -> bool:
	var parts := key.split("#")
	var cr := parts[0].split(",")
	var sim = Sim.new(D, 1)
	var rec: Dictionary = sim.state.rooms[int(cr[1]) * 10 + int(cr[0])]["objects"][int(parts[1])]
	var o = RoomObject.new(sim, StubRoom.new(), rec, int(parts[1]), true)
	o.flags = (o.flags | 1) & ~0x40
	o.activated = false
	var rows: Array = t["ticks"]
	for i in rows.size():
		if i > 0:
			o.think()
		var got := [o.x >> 16, o.y >> 16, o.frame, mini(o.step_i, o.steps.size() - 1),
					1 if (o.hidden or (o.removed and o.flags & 1 == 0)) else 0]
		var want: Array = rows[i]
		if not _same(got, want):
			if o.frozen and got.slice(0, 2) == want.slice(0, 2):
				continue                                   # end mode "stop": the original restores the frame
			print("object %s (%s): tick %d differs: got %s want %s" % [key, t["end_mode"], i, got, want])
			return false
	return true
