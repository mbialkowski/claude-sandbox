extends RefCounted
## A shot: Bullet_Init 0x313D8, Bullet_Fly 0x31790, Bullet_Impact 0x31C00 (docs 3.6).
## x/y are 16.16 pixels relative to the room it was fired in.

var sim
var D
var col := 0
var row := 0
var kind := 0                 # weapon * 2 + facing
var x := 0
var y := 0
var v := 0
var a := 0
var frame := 0
var fcount := 0
var bx0 := 0
var by0 := 0
var bx1 := 0
var by1 := 0
var impact_frame := 0
var damage := 0
var lifetime := 0
var cost := 0
var phase := 0                # 0 flying, 2 impact
var impact_started := false
var hit := false              # 0x49
var dead := false


func _init(p_sim, p_kind: int, hero) -> void:
	sim = p_sim
	D = p_sim.D
	kind = p_kind
	col = hero.col
	row = hero.row
	var w: Dictionary = D.game["weapons"][kind]
	x = (int(w["spawn"][0]) + hero.x) * 65536
	y = (int(w["spawn"][1]) + hero.y) * 65536
	v = int(w["v"])
	a = int(w["a"])
	frame = int(w["frame"])
	impact_frame = int(w["impact"])
	damage = int(w["damage"])
	lifetime = int(w["lifetime"])
	cost = int(w["cost"])
	fcount = D.desc_dur[frame]
	_box()


func _box() -> void:
	bx0 = D.desc_box[frame * 4]
	by0 = D.desc_box[frame * 4 + 1]
	bx1 = D.desc_box[frame * 4 + 2]
	by1 = D.desc_box[frame * 4 + 3]


func think() -> void:
	if phase == 0:
		_fly()
	elif phase == 2:
		_impact()


func _fly() -> void:
	fcount -= 1
	if fcount == 0:
		frame += 1
		fcount = D.desc_dur[frame]
		if fcount != -1:
			_box()
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
		_box()
	var px := x >> 16
	var py := y >> 16
	var room = sim.live_room
	if room and room.col == col and room.row == row:
		for o in room.objects:
			if o and o.overlaps(0x78, px + bx0, py + by0, px + bx1, py + by1) and o.hit(damage):
				hit = true
				phase = 2
	var nx0 := bx0 + ((x + v) >> 16)
	var y0 := by0 + py
	var nx1 := bx1 + ((x + v) >> 16)
	var y1 := by1 + py
	var tx0 := nx0 >> 4
	var ty0 := floori(y0 / 19.0)
	for tx in range(tx0, tx0 + 2):
		if hit:
			break
		for ty in range(ty0, ty0 + 2):
			var t: int = sim.world_tile(col * 14 + tx, row * 12 + ty)
			var kindt: int = D.tile_types[t] if t < D.tile_types.size() else 4
			if kindt == 2 or kindt == 1:
				continue                               # harmful tiles do not stop shots (nor hurt the hero)
			var b := t * 4
			if tx * 16 + D.tile_boxes[b + 2] < nx0 or nx1 < tx * 16 + D.tile_boxes[b] \
					or ty * 19 + D.tile_boxes[b + 3] < y0 or y1 < ty * 19 + D.tile_boxes[b + 1]:
				continue
			hit = true
			break
	if hit:
		phase = 2
	v += a
	x += v
	if (x >> 16) < 224 - bx1 and bx0 < (x >> 16):
		if lifetime != 0:
			lifetime -= 1
			if lifetime == 0:
				dead = true
	else:
		dead = true


func _impact() -> void:
	if not impact_started:
		impact_started = true
		frame = impact_frame
		fcount = D.desc_dur[frame]
		_box()
		return
	var c := fcount
	fcount -= 1
	if c == 0:
		frame += 1
		fcount = D.desc_dur[frame]
		if fcount == -1:
			dead = true
		else:
			_box()
