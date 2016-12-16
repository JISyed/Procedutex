#version 400 core

// Uniforms
uniform sampler2D color_map;

// Varying
in VS_OUT
{
	vec4 vFragColor;
	vec2 vTex;
} fs_in;


// Fragment output
out vec4 color;


void main(void) 
{ 
	color = fs_in.vFragColor * texture(color_map, fs_in.vTex, -4);
}
