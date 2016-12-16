# include "procedutex\utilities\SampleSpace.h"

namespace procedutex
{
	namespace util
	{
		// Default Ctor
		SampleSpace::SampleSpace() :
			dimensions(Vect2f(0.0f, 0.0f), 1.0f, 1.0f)
		{
		}

		// Specialized Ctor using origin, width, and height
		SampleSpace::SampleSpace(const Vect2f& origin, const float width, const float height) :
			dimensions(origin, width, height)
		{
		}

		// Specialized Ctor
		SampleSpace::SampleSpace(const Rectf& newDimensions) :
			dimensions(newDimensions)
		{

		}

		// Copy Ctor
		SampleSpace::SampleSpace(const SampleSpace& other) :
			dimensions(other.dimensions)
		{
		}

		// Copy Assignment
		SampleSpace& SampleSpace::operator=(const SampleSpace& other)
		{
			if (this == &other)
			{
				return *this;
			}

			this->dimensions.Set(other.dimensions);

			return *this;
		}

		// Dtor
		SampleSpace::~SampleSpace()
		{
		}





		// Get the rectangular dimensions of this sample space
		const Rectf SampleSpace::GetDimensions() const
		{
			return this->dimensions;
		}

		// Get the upper-left origin of this sample space
		const Vect2f SampleSpace::GetOrigin() const
		{
			return this->dimensions.origin;
		}

		// Get the width of this sample space
		const float SampleSpace::GetWidth() const
		{
			return this->dimensions.width;
		}

		// Get the height of this sample space
		const float SampleSpace::GetHeight() const
		{
			return this->dimensions.height;
		}




		// Set the rectangular dimensions of this sample space
		void SampleSpace::SetDimensions(const Rectf& newDimensions)
		{
			this->dimensions.Set(newDimensions);
		}

		// Set the upper-left origin of this sample space
		void SampleSpace::SetOrigin(const Vect2f& newOrigin)
		{
			this->dimensions.origin.Set(newOrigin);
		}

		// Set the width of this sample space
		void SampleSpace::SetWidth(const float newWidth)
		{
			this->dimensions.width = newWidth;
		}

		// Set the height of this sample space
		void SampleSpace::SetHeight(const float newHeight)
		{
			this->dimensions.height = newHeight;
		}





		// Transform a texel (i,j) coordinate into a floating (x,y) coordinate in this sample space, given the texture space dimensions
		const Vect2f SampleSpace::FromTextureToSampleSpace(const Vect2ui& texelCoordinate, const TextureDimensions& textureSpace) const
		{
			// Calculate the X cooridnate of the sample space
			const float X = (this->dimensions.width / (float)textureSpace.GetWidth()) * (float)texelCoordinate.x + this->dimensions.origin.x;

			// Calculate the Y cooridnate of the sample space
			const float Y = (this->dimensions.height / (float)textureSpace.GetHeight()) * (float)texelCoordinate.y + this->dimensions.origin.y;

			return Vect2f(X, Y);
		}

	}
}