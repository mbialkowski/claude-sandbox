extends RefCounted
## The dialogue text buffer (Text_Draw 0x1F138 / FUN_0001ECB0): a cursor that persists between messages,
## {x:NNN} {y:NNN} {c:NNN} tags, '\n' back to the line start, proportional glyphs with spacing -1.
## Coordinates are those of the original 320x240 screen (the play-field starts at y = 6).

var D
var glyphs := []              # [x, y, unicode, colour]
var cx := 0
var cy := 0
var line_x := 0
var colour := 12
var outline := 42


func _init(p_D) -> void:
	D = p_D


func clear() -> void:
	glyphs.clear()


func set_cursor(x: int, y: int) -> void:
	cx = x
	line_x = x
	cy = y


func write(s: String, skip_tags := false) -> void:
	var i := 0
	var n := s.length()
	while i < n:
		var ch := s[i]
		if ch == "{" and i + 6 < n and s[i + 2] == ":" and s[i + 6] == "}":
			var v := s.substr(i + 3, 3).to_int()
			if not skip_tags:
				match s[i + 1]:
					"x":
						set_cursor(v, cy)
					"y":
						set_cursor(cx, v)
					"c":
						colour = v
			i += 7
			continue
		_char(ch.unicode_at(0))
		i += 1


func _char(code: int) -> void:
	var f: Dictionary = D.font
	if code == 10:
		cx = line_x
		cy += int(f["line_height"])
		return
	var spacing := int(f["letter_spacing"])
	if code == 32:
		cx += int(f["space_advance"]) + spacing
	var g = D.glyphs.get(code)
	if g == null:
		g = D.glyphs.get(63)                               # '?'
	if g == null:
		return
	if code != 32:
		glyphs.append([cx, cy, code, colour])
	cx += int(g[2]) + spacing


func width_of(s: String) -> int:
	var save := [cx, cy, line_x, glyphs.size()]
	cx = 0
	line_x = 0
	write(s, true)
	var w := cx
	glyphs.resize(save[3])
	cx = save[0]
	cy = save[1]
	line_x = save[2]
	return w
