extends SceneTree
## Plays short scripted scenarios through the simulation and the script VM (no rendering):
## coins, a shop menu, shooting, the teleport terminal, damage and death.
##     godot --headless --path remake --script res://tests/scenarios.gd

const DataScript = preload("res://scripts/game/data.gd")
const Sim = preload("res://scripts/sim/sim.gd")
const VM = preload("res://scripts/game/script_vm.gd")
const TextLayer = preload("res://scripts/view/text_layer.gd")


class FakeAudio:
	var played := []

	func play(id: int) -> void:
		played.append(id)

	func stop(_id: int) -> void:
		pass

	func pause_all(_on: bool) -> void:
		pass


class FakePalette:
	signal faded

	func fade(_a: String, _b: String, _s := 0.65) -> void:
		faded.emit.call_deferred()


class FakeMain:
	extends Node
	var text
	var audio := FakeAudio.new()
	var palette := FakePalette.new()
	var choices := []
	var said := []

	func refresh_text() -> void:
		pass

	func wait_continue() -> void:
		said.append(text.glyphs.size())
		await get_tree().process_frame

	func wait_ticks(n: int) -> void:
		for i in n:
			await get_tree().process_frame

	func run_menu(items: Array) -> int:
		await get_tree().process_frame
		return choices.pop_front() if not choices.is_empty() else 0

	func show_picture(_f: int) -> void:
		await get_tree().process_frame

	func show_pcx(_f: String) -> void:
		await get_tree().process_frame

	func explode() -> void:
		await get_tree().process_frame


var D
var main
var vm
var failures := 0


func _initialize() -> void:
	D = DataScript.new()
	D.load_all(false)
	main = FakeMain.new()
	main.text = TextLayer.new(D)
	root.add_child(main)
	vm = VM.new()
	root.add_child(vm)
	vm.setup(D, main)
	_run.call_deferred()


func _new_sim(c: int, r: int, x: int, y: int, state := 1):
	var sim = Sim.new(D, 7)
	sim.audio = main.audio
	vm.sim = sim
	sim.hero.place(c, r, x, y, state)
	sim.enter_room(c, r)
	return sim


func _ticks(sim, n: int) -> void:
	for i in n:
		sim.tick()
		if not sim.script_queue.is_empty():
			await vm.run_queue()


func _check(name: String, ok: bool, info := "") -> void:
	print(("PASS " if ok else "FAIL ") + name + ("" if ok else "  " + info))
	if not ok:
		failures += 1


func _run() -> void:
	# coin: touching it gives $1 (script 224) and it is gone for good
	var sim = _new_sim(7, 0, 106, 20)
	await _ticks(sim, 30)
	_check("coin +$1", sim.state.money == 11, "money %d" % sim.state.money)
	_check("coin removed from the record", int(sim.state.rooms[7]["objects"][0]["flags"]) & 1 == 0)

	# merchant 1 at (8,1): use, buy the lift card ($10)
	sim = _new_sim(8, 1, 36, 80)
	main.choices = [1]
	sim.state.key_enter = true
	await _ticks(sim, 40)
	_check("merchant sells the lift card", sim.state.find_item(6) >= 0 and sim.state.money == 0,
			"money %d pockets %s" % [sim.state.money, sim.state.pockets.slice(0, 4)])

	# shooting the green guard at (8,0) (HP 5, weapon 0 does 1 per shot)
	sim = _new_sim(8, 0, 40, 160)
	var guard = sim.live_room.objects[8]
	var hp0 := int(guard.rec["hp"])
	for i in 12:
		sim.state.key_fire = true
		sim.state.fire_armed = true
		await _ticks(sim, 12)
	_check("shots hurt the guard", int(guard.rec["hp"]) < hp0 or guard.flags & 1 == 0,
			"hp %d -> %d" % [hp0, int(guard.rec["hp"])])

	# hub terminal at (0,0): the teleport menu lists the known passwords; choose the training room
	sim = _new_sim(0, 0, 20, 160)
	main.choices = [1]
	sim.state.key_enter = true
	sim.state.fuel = 0x100000
	await _ticks(sim, 400)
	_check("teleport to the training room", sim.hero.col == 5 and sim.hero.row == 5 and sim.hero.state < 14,
			"room %d,%d state %d" % [sim.hero.col, sim.hero.row, sim.hero.state])
	_check("teleporting empties the jetpack", sim.state.fuel == 0)

	# damage from the turret shots in the start room, then death
	sim = _new_sim(7, 0, 40, 117)
	var e0: int = sim.state.energy
	var hurt := false
	for i in 400:
		sim.tick()
		if sim.state.energy < e0:
			hurt = true
			break
	_check("harmful objects hurt", hurt)
	sim.state.energy = 0x3000
	sim.hero.hit = true
	await _ticks(sim, 10)
	_check("energy below zero kills", sim.dead and sim.end_state == "death")

	print("scenarios: %d failed" % failures)
	quit(1 if failures else 0)
