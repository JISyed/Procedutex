#version 330 core

// Vertex attributes
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;


// Varying variables
out vec2 uv;


// Vertex Shader
void main()
{
	// Write final position of vertex
	gl_Position = vec4(position, 1.0f);

	// Hack to render the texture right-side up without flipping the mesh verts
	uv = vec2(texCoord.x, 1.0 - texCoord.y);
}