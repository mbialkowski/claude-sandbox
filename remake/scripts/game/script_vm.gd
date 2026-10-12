extends Node
## Runs the original's quest / dialogue / item handlers (assets/gamedata/script_logic.json, op set in
## docs 04 4.9 and tools/lazarus_scripts.py) between simulation ticks.  Ops that wait for the player
## (say, menu, pictures, delays, fades) are coroutines; the game stays frozen meanwhile, as in the original.

var D
var main                       # main.gd: text, palette, audio, input signals
var sim
var busy := false
var in_dialog := false


func setup(p_D, p_main) -> void:
	D = p_D
	main = p_main


func run_queue() -> void:
	"""Run every queued handler (they can queue more)."""
	if busy:
		return
	busy = true
	while sim and not sim.script_queue.is_empty():
		var e: Dictionary = sim.script_queue.pop_front()
		await _run(e)
		if sim.end_state != "":
			sim.script_queue.clear()
	busy = false


func _run(e: Dictionary) -> void:
	var h = null
	var id: int = e["id"]
	match e["kind"]:
		"script":
			h = D.script_by_id.get(id)
		"item":
			h = D.item_use_by_id.get(id)
		"missing":
			h = D.missing_item_by_id.get(id)
		"message":
			h = {"dialog": true, "ops": [["say", id]]}
		"explode":
			h = {"ops": [["explode"]]}
	if h == null or h["ops"].is_empty():
		return
	var ctx := {"room": e["room"], "item_slot": sim.state.inv_sel}
	var dialog: bool = h.get("dialog", false)
	if dialog:
		_begin()
	await _ops(h["ops"], ctx)
	if dialog:
		_end()
	elif not main.text.glyphs.is_empty():
		main.text.clear()
		main.refresh_text()


func _begin() -> void:
	"""Dlg_Begin: effects paused, text drawn over the frozen screen."""
	in_dialog = true
	main.audio.pause_all(true)


func _end() -> void:
	"""Dlg_End: text removed, movement keys released."""
	in_dialog = false
	main.text.clear()
	main.refresh_text()
	sim.hero.input_x = 0
	sim.hero.input_y = 0
	sim.state.key_fire = false
	sim.state.key_enter = false
	main.audio.pause_all(false)


func _ops(ops: Array, ctx: Dictionary) -> void:
	for op in ops:
		if sim.end_state == "death" and op[0] != "say":
			pass
		await _op(op, ctx)


func _var(name: String) -> int:
	if name == "money":
		return sim.state.money
	return int(sim.state.vars.get(name, 0))


func _val(v) -> int:
	if v is Dictionary:
		return _var(v["var"])
	return int(v)


func cond(c: Array, ctx: Dictionary) -> bool:
	var st = sim.state
	match c[0]:
		"money_lt":
			return st.money < int(c[1])
		"money_eq":
			return st.money == int(c[1])
		"has_item":
			return st.find_item(int(c[1])) >= 0
		"eq":
			return _var(c[1]) == _val(c[2])
		"ne":
			return _var(c[1]) != _val(c[2])
		"lt":
			return _var(c[1]) < _val(c[2])
		"in_room":
			return ctx["room"] == Vector2i(int(c[1]), int(c[2]))
		"energy_full":
			return st.energy >= st.FULL
		"ammo_full":
			return st.ammo[st.weapon] >= st.FULL
		"sock_here":
			var spot: Array = D.game["sock_spots"][int(st.vars.get("sock_chest", 0))]
			return ctx["room"] == Vector2i(int(spot[0]), int(spot[1]))
		"and":
			for x in c.slice(1):
				if not cond(x, ctx):
					return false
			return true
		"or":
			for x in c.slice(1):
				if cond(x, ctx):
					return true
			return false
		"not":
			return not cond(c[1], ctx)
	push_warning("unknown condition %s" % [c])
	return false


func _say(msg: int, keep := false, wait := true) -> void:
	main.text.write(D.text(msg))
	main.refresh_text()
	if wait:
		await main.wait_continue()
		if not keep:
			main.text.clear()
			main.refresh_text()


func _op(op: Array, ctx: Dictionary) -> void:
	var st = sim.state
	var n: String = op[0]
	match n:
		"say":
			await _say(int(op[1]))
		"say_keep":
			await _say(int(op[1]), true)
		"print":
			await _say(int(op[1]), true, false)
		"say_indexed":
			await _say(int(op[1]) + _var(op[2]))
		"print_number":
			main.text.write(str(_var(op[1])))
			main.refresh_text()
		"wait":
			await main.wait_continue()
		"clear":
			main.text.clear()
			main.refresh_text()
		"menu":
			await _menu(op[1], ctx)
		"if":
			await _ops(op[2] if cond(op[1], ctx) else op[3], ctx)
		"switch":
			var v := str(_var(op[1]))
			var body: Dictionary = op[2]
			await _ops(body.get(v, body.get("default", [])), ctx)
		"call":
			var h = D.script_by_id.get(int(op[1]))
			if h:
				await _ops(h["ops"], ctx)
		"give":
			st.give(int(op[1]))
		"take":
			st.remove_slot(st.find_item(int(op[1])))
		"take_selected":
			st.remove_slot(st.inv_sel)
		"set":
			var v = op[2]
			if v is Array:
				v = 1 if cond(v, ctx) else 0
			st.vars[op[1]] = int(v)
			if op[1] == "infinite_ammo_fuel":
				st.infinite = int(v) != 0
		"add":
			st.vars[op[1]] = int(st.vars.get(op[1], 0)) + int(op[2])
		"set_flag":
			st.set_flag(int(op[1]))
		"money":
			st.money = maxi(0, st.money + int(op[1]))
		"energy":
			st.energy = st.FULL if op[1] == "full" else st.add_third(st.energy)
		"fuel":
			match str(op[1]):
				"full":
					st.fuel = st.FULL
				"+third":
					st.fuel = st.add_third(st.fuel)
				_:
					st.fuel = 0
		"ammo":
			if op[1] == "all_full":
				for i in 6:
					st.ammo[i] = st.FULL
			else:
				st.ammo[st.weapon] = st.add_third(st.ammo[st.weapon])
		"weapon":
			var w := int(op[1])
			st.owned[w] = true
			st.shot_sound = 0
			st.weapon = w
			for _i in 3:
				st.ammo[w] = st.add_third(st.ammo[w])
		"activate_object":
			if sim.live_room:
				var o = sim.live_room.object_by_index(int(op[1]))
				if o:
					o.activated = true
		"random":
			st.vars[op[1]] = st.rng.randi_range(0, int(op[2]) - 1)
		"teleport":
			sim.hero.start_teleport(int(op[1]), int(op[2]), int(op[3]), int(op[4]))
		"picture":
			await main.show_picture(int(op[1]))
		"picture_var":
			await main.show_picture(_var(op[1]))
		"fade":
			main.palette.fade(str(op[1]), str(op[2]))
			await main.palette.faded
		"show_pcx":
			await main.show_pcx(str(op[1]))
		"sound":
			main.audio.play(int(op[1]))
		"bomb_sound":
			if op[1] == "start":
				main.audio.play(16)
			else:
				main.audio.stop(16)
		"delay":
			await main.wait_ticks(int(op[1]))
		"delay_ms":
			await main.wait_ticks(int(op[1]) / 20)
		"explode":
			await main.explode()
		"end_game":
			sim.end_state = str(op[1])
		_:
			push_warning("unknown op %s" % [op])


func _menu(options: Array, ctx: Dictionary) -> void:
	"""Dlg_Menu: options below the prompt, the chosen one in colour 0x10; result in vars.choice."""
	var shown := []
	for i in options.size():
		var o = options[i]
		if o is Dictionary:
			if o.has("if") and not cond(o["if"], ctx):
				continue
			shown.append([i, int(o["msg"])])
		else:
			shown.append([i, int(o)])
	main.text.write("\n")
	var choice: int = await main.run_menu(shown)
	sim.state.vars["choice"] = shown[choice][0] if choice >= 0 and choice < shown.size() else 0
