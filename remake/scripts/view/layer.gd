extends Node2D
## A canvas layer whose drawing is done by a callback (painter.call(self)).

var painter: Callable


func _draw() -> void:
	if painter.is_valid():
		painter.call(self)
