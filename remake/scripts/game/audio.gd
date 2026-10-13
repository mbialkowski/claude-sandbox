extends Node
## Sound effects (up to 16 voices, looping effects stoppable by id - the original stops loops by sound id)
## and the music modules (rendered to Ogg).  Dialogues pause the effects like Dlg_Begin / Dlg_End.
## In-game music is the remake's addition (the original is silent while playing): the two modules in turn.

var D
var voices := []
var music_player: AudioStreamPlayer
var paused := false
var playlist: Array = []                               # in-game music: track names played in turn
var track := 0
var track_start_ms := 0


func setup(p_D) -> void:
	D = p_D
	for i in 16:
		var p := AudioStreamPlayer.new()
		p.bus = "Master"
		add_child(p)
		voices.append(p)
	music_player = AudioStreamPlayer.new()
	add_child(music_player)
	apply_volumes()


func apply_volumes() -> void:
	AudioServer.set_bus_mute(0, not D.settings["sound"])     # Options -> Sound off: everything silent
	var sv := linear_to_db(maxf(float(D.settings["sfx_volume"]), 0.0001))
	for p in voices:
		p.volume_db = sv
	music_player.volume_db = linear_to_db(maxf(float(D.settings["music_volume"]), 0.0001))


func play(id: int) -> void:
	if id < 0 or id >= D.sounds.size() or paused:
		return
	var free_p: AudioStreamPlayer = null
	for p in voices:
		if not p.playing:
			free_p = p
			break
	if free_p == null:                                 # steal the oldest non-looping voice
		for p in voices:
			if not D.is_sound_looping(p.get_meta("id", -1)):
				free_p = p
				break
	if free_p == null:
		return
	free_p.stream = D.sounds[id]
	free_p.set_meta("id", id)
	free_p.play()


func stop(id: int) -> void:
	for p in voices:
		if p.playing and p.get_meta("id", -1) == id:
			p.stop()


func stop_all() -> void:
	for p in voices:
		p.stop()


func pause_all(on: bool) -> void:
	paused = on
	for p in voices:
		p.stream_paused = on


func play_music(name: String) -> void:
	playlist = []
	var s = D.music.get(name)
	if s == null:
		return
	if music_player.stream == s and music_player.playing:
		return
	music_player.stream = s
	music_player.play()


func play_playlist(names: Array) -> void:
	"""Plays the tracks one after another, round and round (the streams loop, so a late switch is seamless)."""
	if playlist == names and music_player.playing:
		return
	playlist = names
	track = 0
	_start_track()


func _start_track() -> void:
	var s = D.music.get(playlist[track])
	if s == null:
		playlist = []
		return
	music_player.stream = s
	music_player.play()
	track_start_ms = Time.get_ticks_msec()


func _process(_delta: float) -> void:
	if playlist.is_empty() or not music_player.playing:
		return
	var len_ms := int(music_player.stream.get_length() * 1000.0)
	if len_ms > 0 and Time.get_ticks_msec() - track_start_ms >= len_ms:
		track = (track + 1) % playlist.size()
		_start_track()


func stop_music() -> void:
	playlist = []
	music_player.stop()
