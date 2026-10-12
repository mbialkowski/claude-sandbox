extends RefCounted
## Everything a game remembers between rooms (NewGameState 0x2C300): energy, fuel, ammo, weapons,
## money, pockets, game flags, the script variables and the mutable OBJECTS.BIN records; plus the key
## latches of ProcessInput (0x2A614).

const FULL := 0x2F0000

var D
var rooms := []               # deep copy of game.json rooms: object records are mutated by play
var energy := FULL
var fuel := 0
var ammo := [FULL, FULL, FULL, FULL, FULL, FULL]
var weapon := 0
var owned := [true, false, false, false, false, false]
var money := 10
var pockets := []             # 40 slots of item ids, 0 = empty
var inv_sel := 0
var flags := PackedByteArray()
var vars := {}
var jet_on := false
var bomb_timer := 0
var immortal := false         # IDMORT
var infinite := false         # IDSIAR

# key latches (ProcessInput)
var key_enter := false
var key_fire := false
var key_down := false
var key_up := false
var fire_armed := true        # DAT_0005342c
var plasma_out := false       # DAT_000889a0
var auto_timer := 0           # DAT_000892e4
var shot_sound := 0           # DAT_000892e8
var hurt_sound := 0           # DAT_000c0050
var hit_timer := 0
var hit_colour := 0x1D
var rng := RandomNumberGenerator.new()


func _init(p_D, seed := -1) -> void:
	D = p_D
	if seed >= 0:
		rng.seed = seed
	else:
		rng.randomize()
	rooms = D.game["rooms"].duplicate(true)
	pockets.resize(40)
	pockets.fill(0)
	pockets[0] = 24                                    # the wallet
	flags.resize(256)
	for k in D.scripts["state"]:
		var init = D.scripts["state"][k]["init"]
		if init is Array:
			if init[0] == "random":
				vars[k] = rng.randi_range(0, int(init[1]) - 1)
			elif init[0] == "random_of":
				vars[k] = int(init[1][rng.randi_range(0, init[1].size() - 1)])
		elif init == null:
			vars[k] = 0
		else:
			vars[k] = int(init)
	flags[76 + int(vars["secret_door"])] = 1         # NewGameState marks the secret door


func flag(i: int) -> bool:
	return i >= 0 and i < 256 and flags[i] != 0


func set_flag(i: int) -> void:
	if i >= 0 and i < 256:
		flags[i] = 1


func selected_item() -> int:
	return pockets[inv_sel]


func give(item: int) -> void:
	"""Pocket_Add: first free slot, selected."""
	for i in 40:
		if pockets[i] == 0:
			pockets[i] = item
			inv_sel = i
			return


func find_item(item: int) -> int:
	for i in 40:
		if pockets[i] == item:
			return i
	return -1


func remove_slot(slot: int) -> void:
	"""Pocket_Remove: shift the rest down, select the first pocket."""
	if slot < 0:
		return
	for i in range(slot, 39):
		pockets[i] = pockets[i + 1]
	pockets[39] = 0
	inv_sel = 0


func next_item() -> void:
	if inv_sel < 39 and pockets[inv_sel + 1] != 0:
		inv_sel += 1


func prev_item() -> void:
	if inv_sel > 0:
		inv_sel -= 1


func add_third(value: int) -> int:
	return mini(value + FULL / 3, FULL)
