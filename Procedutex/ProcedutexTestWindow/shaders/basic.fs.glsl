#version 330 core

// Texture samplers
uniform sampler2D mainTexture;


// Varying variables
in vec2 uv;


// Pixel color output
out vec4 color;


// Fragment shader
void main()
{
	color = texture(mainTexture, uv);
}