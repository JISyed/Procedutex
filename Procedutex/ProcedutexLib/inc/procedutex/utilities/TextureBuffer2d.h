#pragma once
#include "procedutex\types\Color4f.h"
#include "procedutex\types\Color4b.h"
#include "procedutex\types\Vect2ui.h"
#include "procedutex\utilities\TextureDimensions.h"
#include "procedutex\elements\Generator.h"
#include "procedutex\utilities\OutputConverter.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// A buffer of texture data that can be altered on the CPU before being passed to OpenGL
		class TextureBuffer2d
		{
		public:
			//
			// Big Four
			//

			// Ctor
			TextureBuffer2d(const size_t newWidth, const size_t newHeight);
			// Dtor
			~TextureBuffer2d();
			// Move ctor
			TextureBuffer2d(TextureBuffer2d&& other);
			// Move assignment
			TextureBuffer2d& operator=(TextureBuffer2d&& other);



			//
			// Getters
			//

			// Get width of image in pixels
			const size_t GetWidth() const;

			// Get height of image in pixels
			const size_t GetHeight() const;

			// Get read-only pointer to the raw texture buffer (TextureBuffer2d must still exist!)
			const unsigned char* const GetReadOnlyRawData() const;

			// Get read-only pointer to the color texture buffer (TextureBuffer2d must still exist!)
			const Color4b* const GetReadOnlyColorData() const;

			// Get the pixel dimensions of the texture as a class "package"
			const TextureDimensions GetDimensions() const;



			//
			// Setters
			//

			// Set the grayscale value of the specified pixel (x right-to-left, y top-to-bottom)
			void SetPixelGrayscale(const float grayValue, const Vect2ui pixelCoordinate);

			// Set the grayscale value of the specified pixel (x right-to-left, y top-to-bottom)
			void SetPixelGrayscale(const unsigned char grayValue, const Vect2ui pixelCoordinate);


			// Set the color value of the specified pixel (x right-to-left, y top-to-bottom)
			void SetPixelColor(const Color4f& color, const Vect2ui pixelCoordinate);

			// Set the color value of the specified pixel (x right-to-left, y top-to-bottom)
			void SetPixelColor(const Color4b color, const Vect2ui pixelCoordinate);



			//
			// Helpers
			// 

			// Clear the entire image to a given color. NOTICE: Potentially slow for large images
			void ClearToColor(const Color4f& color);

			// Clear the entire image to a given color. NOTICE: Potentially slow for large images
			void ClearToColor(const Color4b color);



			//
			// Texture Generation
			//

			// Use procedural generation techniques to generate a texture image
			void Generate(procedutex::abstract::Generator& generator, const abstract::OutputConverter& converter);



		private:

			//
			// Data
			//

			Color4b* colorData;		// The texture buffer
			size_t width;			// The width of the texture in pixels
			size_t height;			// The height of the texture in pixels




			//
			// Deleted Methods
			//

			// No copy assignment
			TextureBuffer2d& operator=(const TextureBuffer2d& other) = delete;

			// No copy ctor
			TextureBuffer2d(const TextureBuffer2d& other) = delete;

			// Default
			TextureBuffer2d() = delete;

		};

	}
}