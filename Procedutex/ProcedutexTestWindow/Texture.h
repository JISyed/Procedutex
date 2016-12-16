#pragma once
#include "openglHeaders.h"
#include <string>

class Shader;

// Determines how to handle texel wrapping outside the texture's coordinate range
enum class TextureWrapType : unsigned short
{
	Repeat = GL_REPEAT,
	MirroredRepeat = GL_MIRRORED_REPEAT,
	EdgeClamp = GL_CLAMP_TO_EDGE,
	BorderClamp = GL_CLAMP_TO_BORDER
};

// Indicates how texels should be blended up-close or far-away
enum class TextureFilterType : unsigned short
{
	Point,
	PointDistanceBlend,
	Bilinear,
	Trilinear
};

// RGB color map on the GPU
class Texture
{
public:
	Texture(const char* const nameInShader);
	Texture(const char* const nameInShader, const unsigned char* const texelData, unsigned int newWidth, unsigned int newHeight, const TextureWrapType wrapping, const TextureFilterType filter);
	~Texture();

	// This can only be called if the texture was not already initialized. 
	// If this texture was already initialized in the constructor, or 
	// this method was already called, the method will do nothing.
	void Setup(const unsigned char* const texelData, unsigned int newWidth, unsigned int newHeight, const TextureWrapType wrapping, const TextureFilterType filter);

	const char* const GetNameInShader() const;
	const bool IsInitialized() const;

	void Use(Shader& shader);


	static const char* const DEFAULT_NAME;

private:

	GLuint textureId;	// Assigned from OpenGL
	std::string name;
	bool initialized;
};

