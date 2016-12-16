#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// Read-only info-class concerning the dimensions of a texture
		class TextureDimensions
		{
		public:
			
			//
			// Methods
			//
			
			// Specialized Ctor
			TextureDimensions(const unsigned int newWidth, const unsigned int newHeight, const unsigned int newDepth = 1u);
			
			// Copy Ctor
			TextureDimensions(const TextureDimensions& other);
			
			// Dtor
			~TextureDimensions();



			// Get the width of the texture that created this info-class
			const unsigned int GetWidth() const;

			// Get the height of the texture that created this info-class
			const unsigned int GetHeight() const;

			// Get the depth of the texture that created this info-class (for 2D textures, this should be 1)
			const unsigned int GetDepth() const;



		private:

			//
			// Data
			//

			const unsigned int width;		// The width of the texture in pixels
			const unsigned int height;		// The height of the texture in pixels
			const unsigned int depth;		// The depth of the texture in pixels (relevant for 3D textures)



			//
			// Deleted Methods
			//

			// No default ctor
			TextureDimensions() = delete;

			// No copy assignment
			TextureDimensions& operator=(const TextureDimensions& other) = delete;

		};
	}
}