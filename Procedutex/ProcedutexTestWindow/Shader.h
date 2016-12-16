#pragma once
#include "openglHeaders.h"

// Handle for programmable GPU rendering routine
class Shader
{
public:
	// Constructor generates the shader on the fly
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();


	// Uses the current shader
	void Use();

	void SetTexture(const char* const textureNameInShader);


private:

	GLuint Program;
};

