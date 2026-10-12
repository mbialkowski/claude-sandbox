extends RefCounted
## The VGA palette: the screen is rendered in palette indices and coloured by this palette in a shader,
## so FadePalette (0x2C988, 65 steps of 10 ms), the bomb's alarm palette and the explosion's white/red
## flashes work exactly like the original.

signal faded

var D
var current := PackedByteArray()      # the palette shown (768 bytes, 8-bit components)
var target_name := "game"             # g_curPalette
var image: Image
var texture: ImageTexture
var _from := PackedByteArray()
var _to := PackedByteArray()
var _t := 1.0
var _duration := 0.65
var dirty := true


func _init(p_D) -> void:
	D = p_D
	current = named("game")
	image = Image.create(256, 1, false, Image.FORMAT_RGB8)
	texture = ImageTexture.create_from_image(image)
	_upload()


func named(n: String) -> PackedByteArray:
	match n:
		"black":
			var p := PackedByteArray()
			p.resize(768)
			return p
		"white":
			var p := PackedByteArray()
			p.resize(768)
			p.fill(255)
			return p
		"red":
			var g: PackedByteArray = D.palettes["game"]
			var p := PackedByteArray()
			p.resize(768)
			for i in 256:
				p[i * 3] = g[i * 3]
			return p
		"current":
			return named(target_name)
	return D.palettes.get(n, D.palettes["game"]).duplicate()


func set_now(n: String) -> void:
	if n != "black" and n != "white":
		target_name = n
	current = named(n)
	_t = 1.0
	dirty = true


func fade(from_name: String, to_name: String, seconds := 0.65) -> void:
	"""Start a fade; await `faded` for the end."""
	_from = named(from_name) if from_name != "" else current.duplicate()
	_to = named(to_name)
	if to_name != "black" and to_name != "white":
		target_name = to_name
	_t = 0.0
	_duration = maxf(seconds, 0.001)
	current = _from.duplicate()
	dirty = true


func busy() -> bool:
	return _t < 1.0


func update(delta: float) -> void:
	if _t < 1.0:
		_t = minf(1.0, _t + delta / _duration)
		var step := int(_t * 64.0)                       # the original's 65 discrete steps
		for i in 768:
			current[i] = _from[i] + ((int(_to[i]) - int(_from[i])) * step) / 64
		dirty = true
		if _t >= 1.0:
			current = _to.duplicate()
			faded.emit()
	if dirty:
		_upload()


func _upload() -> void:
	dirty = false
	image.set_data(256, 1, false, Image.FORMAT_RGB8, current)
	texture.update(image)


func colour(i: int) -> Color:
	return Color8(current[i * 3], current[i * 3 + 1], current[i * 3 + 2])
