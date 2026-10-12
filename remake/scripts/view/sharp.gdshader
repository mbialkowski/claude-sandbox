shader_type canvas_item;
// "Sharp bilinear" for colour pictures (intro, game over, credits): crisp, evenly sized pixels at any
// scale.  Needs linear filtering on the node; out_scale = output pixels per texel.

uniform vec2 out_scale = vec2(1.0, 1.0);

void fragment() {
	vec2 size = 1.0 / TEXTURE_PIXEL_SIZE;
	vec2 t = UV * size - 0.5;
	vec2 f0 = floor(t);
	vec2 f = clamp((t - f0 - 0.5) * out_scale + 0.5, 0.0, 1.0);
	COLOR = texture(TEXTURE, (f0 + 0.5 + f) / size);
}
