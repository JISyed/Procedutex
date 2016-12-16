#include "procedutex\utilities\TextureDimensions.h"

namespace procedutex
{
	namespace util
	{
		// Specialized Ctor
		TextureDimensions::TextureDimensions(const unsigned int newWidth, const unsigned int newHeight, const unsigned int newDepth) :
			width(newWidth),
			height(newHeight),
			depth(newDepth)
		{
		}

		// Copy Ctor
		TextureDimensions::TextureDimensions(const TextureDimensions& other) :
			width(other.width),
			height(other.height),
			depth(other.depth)
		{
		}

		// Dtor
		TextureDimensions::~TextureDimensions()
		{
		}


		// Get the width of the texture that created this info-class
		const unsigned int TextureDimensions::GetWidth() const
		{
			return this->width;
		}

		// Get the height of the texture that created this info-class
		const unsigned int TextureDimensions::GetHeight() const
		{
			return this->height;
		}

		// Get the depth of the texture that created this info-class (for 2D textures, this should be 1)
		const unsigned int TextureDimensions::GetDepth() const
		{
			return this->width;
		}


	}
}