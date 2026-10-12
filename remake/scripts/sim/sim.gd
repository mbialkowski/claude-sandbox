extends RefCounted
## The game world and its 50 Hz tick, in the order of GameLoop (0x2ADE0): objects of the hero's room
## think, the hero thinks, damage, bullets, the bomb timer, the teleport fuel loss, firing, cheats.
## Scripts fired during a tick are queued and run by the script VM between ticks.

const Room = preload("res://scripts/sim/room.gd")
const Hero = preload("res://scripts/sim/hero.gd")
const Bullet = preload("res://scripts/sim/bullet.gd")
const State = preload("res://scripts/sim/state.gd")

const START := [7, 0, 22, 83]

var D
var state
var hero
var live_room = null
var rooms := {}               # Vector2i -> room.gd (the live room and previews of visible neighbours)
var bullets := []
var crouch_pick := false      # DAT_00088988
var script_queue := []
var audio = null              # object with play(id) / stop(id) / stop_all()
var world_tiles := PackedInt32Array()
var test_room := {}           # Vector2i -> 168 tiles (golden-trace test rooms)
var dead := false
var end_state := ""           # "", "death", "joke_ending", "win"
var fuel_lost := false
var ticks := 0
var room_entered := false     # set when the hero changes room (camera)
var teleported := false


func _init(p_D, seed := -1) -> void:
	D = p_D
	state = State.new(D, seed)
	hero = Hero.new(self)
	world_tiles.resize(140 * 120)
	for r in 10:
		for c in 10:
			var tiles: Array = D.game["rooms"][r * 10 + c]["tiles"]
			for ty in 12:
				for tx in 14:
					world_tiles[(r * 12 + ty) * 140 + c * 14 + tx] = int(tiles[ty * 14 + tx])


func new_game() -> void:
	hero.place(START[0], START[1], START[2], START[3], 1)
	enter_room(START[0], START[1])


func world_tile(wtx: int, wty: int) -> int:
	if not test_room.is_empty():
		var k := Vector2i(floori(wtx / 14.0), floori(wty / 12.0))
		if test_room.has(k):
			return test_room[k][posmod(wty, 12) * 14 + posmod(wtx, 14)]
		return 0
	if wtx < 0 or wty < 0 or wtx >= 140 or wty >= 120:
		return 0
	return world_tiles[wty * 140 + wtx]


# ---------------------------------------------------------------------------
# rooms
# ---------------------------------------------------------------------------
func enter_room(c: int, r: int) -> void:
	"""EnterRoom: build the room live (objects reset to their first step)."""
	if live_room:
		live_room.stop_sounds()
	live_room = Room.new(self, c, r, false)
	rooms[Vector2i(c, r)] = live_room
	room_entered = true


func on_hero_room_changed(teleport := false) -> void:
	var key := Vector2i(hero.col, hero.row)
	if live_room:
		live_room.stop_sounds()
	var existing = rooms.get(key)
	if existing and existing.was_live and not teleport:
		live_room = existing                           # walked back into a room still on screen: resume
		room_entered = true
	else:
		enter_room(hero.col, hero.row)
	teleported = teleport


func teleport_finished() -> void:
	fuel_lost = true


func update_visible(keys: Array) -> void:
	"""Keep previews of the rooms on screen, drop the others."""
	var want := {}
	for k in keys:
		want[k] = true
		if not rooms.has(k) and k.x >= 0 and k.y >= 0 and k.x < 10 and k.y < 10:
			rooms[k] = Room.new(self, k.x, k.y, true)
	for k in rooms.keys():
		if not want.has(k) and rooms[k] != live_room:
			rooms.erase(k)


# ---------------------------------------------------------------------------
# events for the presentation layer
# ---------------------------------------------------------------------------
func play_sound(id: int) -> void:
	if audio:
		audio.play(id)


func stop_sound(id: int) -> void:
	if audio:
		audio.stop(id)


func queue_script(id: int, room) -> void:
	script_queue.append({"kind": "script", "id": id, "room": Vector2i(room.col, room.row)})


func queue_item_use() -> void:
	script_queue.append({"kind": "item", "id": state.selected_item(),
						 "room": Vector2i(hero.col, hero.row)})


func queue_missing_item(item: int) -> void:
	for q in script_queue:
		if q["kind"] == "missing":
			return
	script_queue.append({"kind": "missing", "id": item, "room": Vector2i(hero.col, hero.row)})


# ---------------------------------------------------------------------------
# the tick
# ---------------------------------------------------------------------------
func tick() -> void:
	ticks += 1
	if live_room:
		live_room.think()
	hero.think()
	_damage_tick()
	for b in bullets:
		b.think()
	for b in bullets.duplicate():
		if b.dead:
			if b.kind >> 1 == 5:
				state.plasma_out = false
			bullets.erase(b)
	if state.vars.get("bomb_active", 0):
		state.bomb_timer -= 1
		if state.bomb_timer == 0:
			script_queue.append({"kind": "explode", "id": 0, "room": Vector2i(hero.col, hero.row)})
	if fuel_lost:
		fuel_lost = false
		if state.fuel != 0:
			script_queue.append({"kind": "message", "id": 251, "room": Vector2i(hero.col, hero.row)})
		state.fuel = 0
	_fire()
	if state.infinite:
		state.fuel = State.FULL
		state.ammo[state.weapon] = State.FULL


func _damage_tick() -> void:
	"""Hero_DamageTick: while hit, energy -= 0x6000 every few ticks; flashing; death at < 0."""
	var st = state
	if not hero.hit or st.immortal:
		hero.hit = false
	elif st.hit_timer == 0:
		var hs: Array = D.game["hurt_sounds"]
		play_sound(int(hs[st.hurt_sound]))
		st.hurt_sound += 1
		if st.hurt_sound >= hs.size():
			st.hurt_sound = 0
		st.hit_timer = 4
		st.energy -= 0x6000
		if st.energy < 0:
			st.energy = 0
			dead = true
			end_state = "death"
		else:
			st.hit_colour = 0x1D
	else:
		st.hit_timer -= 1
		if st.hit_timer == 0:
			hero.hit = false
		elif st.hit_colour == 0x14:
			st.hit_colour = 0x1D
		else:
			st.hit_colour = 0x14


func _fire() -> void:
	var st = state
	var w: int = st.weapon
	var entry: Dictionary = D.game["weapons"][w * 2 + hero.dir]
	if hero.state >= 14:
		return
	if st.key_fire and st.fire_armed and st.ammo[w] >= 1:
		if int(entry["auto"]) == 0:
			_spawn_bullet()
			st.key_fire = false
			st.fire_armed = false
		else:
			st.auto_timer -= 1
			if st.auto_timer == -1:
				_spawn_bullet()
	elif st.key_fire and st.fire_armed:
		play_sound(40)
		st.fire_armed = false


func _spawn_bullet() -> void:
	var st = state
	var k: int = st.weapon * 2 + hero.dir
	var b = Bullet.new(self, k, hero)
	bullets.push_front(b)
	var entry: Dictionary = D.game["weapons"][k]
	st.auto_timer = int(entry["cooldown"])
	if st.weapon == 5:
		st.plasma_out = true
	var snds: Array = entry["sounds"]
	if snds.size() > 0:
		if st.shot_sound >= snds.size():
			st.shot_sound = 0
		play_sound(int(snds[st.shot_sound]))
		st.shot_sound += 1
	st.ammo[st.weapon] -= b.cost
