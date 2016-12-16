#include "procedutex\utilities\TextureBuffer2d.h"
#include "procedutex\math\FloatOperations.h"
#include "procedutex\math\IntegerOperations.h"
#include <cassert>

namespace procedutex
{
	namespace util
	{
		// Ctor
		TextureBuffer2d::TextureBuffer2d(const size_t newWidth, const size_t newHeight) :
			width((size_t)math::IntOps::GetNextPowerOf2(newWidth)),
			height((size_t)math::IntOps::GetNextPowerOf2(newHeight))
		{
			assert(math::IntOps::IsPowerOf2((int)this->width));
			assert(math::IntOps::IsPowerOf2((int)this->height));

			this->colorData = new Color4b[this->width * this->height];
		}

		// Dtor
		TextureBuffer2d::~TextureBuffer2d()
		{
			if (this->colorData != nullptr)
			{
				delete[] this->colorData;
			}
		}

		// Move ctor
		TextureBuffer2d::TextureBuffer2d(TextureBuffer2d&& other) :
			width(other.width),
			height(other.height),
			colorData(other.colorData)
		{
			// Image data is moved, so clear values of old TextureBuffer2d
			other.width = 0u;
			other.height = 0u;
			other.colorData = nullptr;
		}

		// Move assignment
		TextureBuffer2d& TextureBuffer2d::operator=(TextureBuffer2d&& other)
		{
			// Moving to yourself doesn't make sense
			if (this == &other)
			{
				return *this;
			}

			// Move old data into new data
			this->width = other.width;
			this->height = other.height;
			this->colorData = other.colorData;

			// Image data is moved, so clear values of old TextureBuffer2d
			other.width = 0u;
			other.height = 0u;
			other.colorData = nullptr;

			return *this;
		}



		// Get width of image in pixels
		const size_t TextureBuffer2d::GetWidth() const
		{
			return this->width;
		}

		// Get height of image in pixels
		const size_t TextureBuffer2d::GetHeight() const
		{
			return this->height;
		}

		// Get read-only pointer to the raw image buffer
		const unsigned char* const TextureBuffer2d::GetReadOnlyRawData() const
		{
			return (unsigned char*) this->colorData;
		}


		// Get read-only pointer to the color texture buffer (TextureBuffer2d must still exist!)
		const Color4b* const TextureBuffer2d::GetReadOnlyColorData() const
		{
			return this->colorData;
		}

		// Get the pixel dimensions of the texture as a class "package"
		const TextureDimensions TextureBuffer2d::GetDimensions() const
		{
			return TextureDimensions(this->width, this->height);
		}



		// Set the grayscale value of the specified pixel (x right-to-left, y top-to-bottom)
		void TextureBuffer2d::SetPixelGrayscale(const float grayValue, const Vect2ui pixelCoordinate)
		{
			assert(pixelCoordinate.x < this->width);
			assert(pixelCoordinate.y < this->height);

			this->SetPixelGrayscale(math::FloatOps::FloatToUByte(grayValue), pixelCoordinate);
		}

		// Set the grayscale value of the specified pixel (x left-to-right, y top-to-bottom) (both starting at 0)
		void TextureBuffer2d::SetPixelGrayscale(const unsigned char grayValue, const Vect2ui pixelCoordinate)
		{
			assert(pixelCoordinate.x < this->width);
			assert(pixelCoordinate.y < this->height);

			const size_t xIncrement = pixelCoordinate.x;
			const size_t yIncrement = pixelCoordinate.y * this->width;

			this->colorData[xIncrement + yIncrement] = Color4b(grayValue);
		}


		// Set the color value of the specified pixel (x right-to-left, y top-to-bottom)
		void TextureBuffer2d::SetPixelColor(const Color4f& color, const Vect2ui pixelCoordinate)
		{
			assert(pixelCoordinate.x < this->width);
			assert(pixelCoordinate.y < this->height);

			this->SetPixelColor(color.ConvertToByteRepresentation(), pixelCoordinate);
		}

		// Set the color value of the specified pixel (x right-to-left, y top-to-bottom)
		void TextureBuffer2d::SetPixelColor(const Color4b color, const Vect2ui pixelCoordinate)
		{
			assert(pixelCoordinate.x < this->width);
			assert(pixelCoordinate.y < this->height);

			const size_t xIncrement = pixelCoordinate.x;
			const size_t yIncrement = pixelCoordinate.y * this->width;

			this->colorData[xIncrement + yIncrement] = color;
		}




		// Clear the entire image to a given color. NOTICE: Potentially slow for large images
		void TextureBuffer2d::ClearToColor(const Color4f& color)
		{
			this->ClearToColor(color.ConvertToByteRepresentation());
		}

		// Clear the entire image to a given color. NOTICE: Potentially slow for large images
		void TextureBuffer2d::ClearToColor(const Color4b color)
		{
			const size_t bufferSize = this->width * this->height;

			for (size_t i = 0u; i < bufferSize; i++)
			{
				this->colorData[i] = color;
			}
		}




		// Use procedural generation techniques to generate a texture image
		void TextureBuffer2d::Generate(procedutex::abstract::Generator& generator, const abstract::OutputConverter& converter)
		{
			const TextureDimensions dimens = this->GetDimensions();
			Vect2ui texelCoordinate;
			Color4f texelColor;
			for (unsigned int y = 0u; y < dimens.GetHeight(); y++)
			{
				for (unsigned int x = 0u; x < dimens.GetWidth(); x++)
				{
					texelCoordinate.Set(x, y);
					NormalizedValue v = generator.GetAtTexel(texelCoordinate, dimens);
					texelColor = converter.ConvertValue(v);
					this->SetPixelColor(texelColor, texelCoordinate);
				}
			}
		}





	}
}