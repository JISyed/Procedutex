#include "Texture.h"
#include <cassert>
#include "Shader.h"


const char* const Texture::DEFAULT_NAME = "mainTexture";


Texture::Texture(const char* const nameInShader) :
	name(nameInShader),
	initialized(false)
{

}

Texture::Texture(const char* const nameInShader, const unsigned char* const texelData, unsigned int newWidth, unsigned int newHeight, const TextureWrapType wrapping, const TextureFilterType filter) :
	name(nameInShader),
	initialized(false)
{
	this->Setup(texelData, newWidth, newHeight, wrapping, filter);
}


Texture::~Texture()
{
	if (this->initialized)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glDeleteTextures(1, &(this->textureId));
	}
}



// This can only be called if the texture was not already initialized. 
// If this texture was already initialized in the constructor, or 
// this method was already called, the method will do nothing.
void Texture::Setup(const unsigned char* const texelData, unsigned int newWidth, unsigned int newHeight, const TextureWrapType wrapping, const TextureFilterType filter)
{
	if (!initialized)
	{
		glGenTextures(1, &(this->textureId));
		glBindTexture(GL_TEXTURE_2D, this->textureId); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object

		// Set our texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (GLint)wrapping);	// Set texture wrapping to GL_REPEAT
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (GLint)wrapping);

		// Set texture filtering
		GLint minFilter = GL_NEAREST;
		GLint magFilter = GL_NEAREST;
		switch (filter)
		{
			case TextureFilterType::Point:
				minFilter = GL_NEAREST_MIPMAP_NEAREST;
				magFilter = GL_NEAREST;
				break;
			case TextureFilterType::PointDistanceBlend:
				minFilter = GL_NEAREST_MIPMAP_LINEAR;
				magFilter = GL_NEAREST;
				break;
			case TextureFilterType::Bilinear:
				minFilter = GL_LINEAR_MIPMAP_NEAREST;
				magFilter = GL_LINEAR;
				break;
			case TextureFilterType::Trilinear:
				minFilter = GL_LINEAR_MIPMAP_LINEAR;
				magFilter = GL_LINEAR;
				break;
			default:
				// Unsupported TextureFilterType!
				assert(false);
				break;
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, newWidth, newHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texelData);
		glGenerateMipmap(GL_TEXTURE_2D);


		glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
		this->initialized = true;
	}
}



const char* const Texture::GetNameInShader() const
{
	return this->name.c_str();
}


const bool Texture::IsInitialized() const
{
	return this->initialized;
}



void Texture::Use(Shader& shader)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->textureId);
	shader.SetTexture(this->name.c_str());
}





