extends SceneTree
## Replays assets/gamedata/walkthrough.json (tools/completability.py's route to the winning ending) through
## the remake's room objects and script VM: for each step the hero is put at the object in its room, the
## object is used / picked up / shot, the room runs until its scripts are done.  Movement is not simulated
## (the solver assumes free flight); this checks the object conditions, chains, flags and every handler on
## the way to the Door of Time.
##     godot --headless --path remake --script res://tests/walkthrough.gd

const DataScript = preload("res://scripts/game/data.gd")
const Sim = preload("res://scripts/sim/sim.gd")
const VM = preload("res://scripts/game/script_vm.gd")
const TextLayer = preload("res://scripts/view/text_layer.gd")
const Scenarios = preload("res://tests/scenarios.gd")

var D
var main
var vm
var item_ids := {}


func _initialize() -> void:
	D = DataScript.new()
	D.load_all(false)
	main = Scenarios.FakeMain.new()
	main.text = TextLayer.new(D)
	root.add_child(main)
	vm = VM.new()
	root.add_child(vm)
	vm.setup(D, main)
	var items: Array = D.game["items"]
	for i in items.size():
		item_ids[str(items[i]["en"])] = i
	_run.call_deferred()


func _run() -> void:
	var path := "res://data/walkthrough.json"
	var w = JSON.parse_string(FileAccess.get_file_as_string(path))
	if w == null:
		print("cannot read " + path)
		quit(1)
		return
	var sim = Sim.new(D, 1)
	sim.audio = main.audio
	vm.sim = sim
	var st = sim.state
	for k in w["seed"]:
		st.vars[k] = int(w["seed"][k])
	for i in 3:
		st.flags[76 + i] = 0
	st.flags[76 + int(w["seed"]["secret_door"])] = 1
	st.immortal = true
	sim.new_game()
	var re := RegEx.create_from_string("^(\\(auto\\) )?\\((\\d),(\\d)\\) (shoot|use|pick up)(?: with (.+?))?: .*\\[#(\\d+)\\]$")
	var n := 0
	var failed := 0
	for step in w["steps"]:
		n += 1
		var m := re.search(str(step["action"]))
		if m == null:
			print("? cannot parse: ", step["action"])
			failed += 1
			continue
		if m.get_string(1) != "":
			continue                                       # activated by itself when the room is entered
		var err: String = await _step(sim, int(m.get_string(2)), int(m.get_string(3)), m.get_string(4),
				m.get_string(5), int(m.get_string(6)), step["details"])
		if err != "":
			print("FAIL step %d %s: %s" % [n, step["action"], err])
			failed += 1
		if sim.end_state != "":
			break
	var won: bool = sim.end_state == "win"
	print("walkthrough: %d steps, %d failed, %s" % [n, failed, "WON" if won else "not won (" + sim.end_state + ")"])
	quit(0 if won and failed == 0 else 1)


func _step(sim, c: int, r: int, verb: String, item_name: String, index: int, details: Array) -> String:
	var st = sim.state
	if sim.hero.col != c or sim.hero.row != r or sim.live_room == null:
		sim.hero.place(c, r, 100, 100, 1)
		sim.on_hero_room_changed(true)
	main.choices.clear()
	if not details.is_empty():
		var first: String = str(details[0]).split(" | ")[0]
		for part in first.split("; "):
			if part.begins_with("choose option "):
				main.choices.append(int(part.substr(14)))
		for d in details.slice(1):
			if str(d).begins_with("choose option "):
				main.choices.append(int(str(d).substr(14)))
	var o = sim.live_room.object_by_index(index)
	if o == null:
		return "no such object"
	if o.flags & 1 == 0:
		return "object not present (flags %x, record %x)" % [o.flags, int(o.rec["flags"])]
	if verb == "shoot":
		for k in 60:
			if o.activated or o.flags & 1 == 0:
				break
			if not o.hit(50):
				return "shots pass through it"
	else:
		if item_name != "":
			if not item_ids.has(item_name):
				return "unknown item " + item_name
			var slot: int = st.find_item(item_ids[item_name])
			if slot < 0:
				return "the hero does not have " + item_name
			st.inv_sel = slot
		sim.hero.x = (o.x >> 16) + (o.bx0 + o.bx1) / 2 - 11
		sim.hero.y = (o.y >> 16) + (o.by0 + o.by1) / 2 - 16
		if verb == "pick up":
			sim.crouch_pick = true
			st.key_down = true
		else:
			st.key_enter = true
		o.interact()
		sim.crouch_pick = false
		st.key_down = false
		st.key_enter = false
		if not o.activated:
			if not sim.script_queue.is_empty():
				await vm.run_queue()
			return "did not activate (missing item / flag?)"
	for t in 400:
		sim.live_room.think()
		if not sim.script_queue.is_empty():
			await vm.run_queue()
		if sim.end_state != "":
			break
	return ""
