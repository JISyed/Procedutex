#pragma once
#include "procedutex\types\Rectf.h"
#include "procedutex\types\Vect2ui.h"
#include "procedutex\utilities\TextureDimensions.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// Represents a rectangular section of infinite real-number space, used to define the positions to sample for procedural algorithms
		class SampleSpace
		{
		public:

			//
			// Big 4 + Other Ctors
			//

			// Default Ctor (0, 0, 1, 1)
			SampleSpace();

			// Specialized Ctor using origin, width, and height
			SampleSpace(const Vect2f& origin, const float width, const float height);

			// Specialized Ctor
			SampleSpace(const Rectf& newDimensions);

			// Copy Ctor
			SampleSpace(const SampleSpace& other);

			// Copy Assignment
			SampleSpace& operator=(const SampleSpace& other);

			// Dtor
			~SampleSpace();



			//
			// Accessors
			//

			// Get the rectangular dimensions of this sample space
			const Rectf GetDimensions() const;

			// Get the upper-left origin of this sample space
			const Vect2f GetOrigin() const;

			// Get the width of this sample space
			const float GetWidth() const;

			// Get the height of this sample space
			const float GetHeight() const;




			// Set the rectangular dimensions of this sample space
			void SetDimensions(const Rectf& newDimensions);

			// Set the upper-left origin of this sample space
			void SetOrigin(const Vect2f& newOrigin);

			// Set the width of this sample space
			void SetWidth(const float newWidth);

			// Set the height of this sample space
			void SetHeight(const float newHeight);





			//
			// Methods
			//

			// Transform a texel (i,j) coordinate into a floating (x,y) coordinate in this sample space, given the texture space dimensions
			const Vect2f FromTextureToSampleSpace(const Vect2ui& texelCoordinate, const TextureDimensions& textureSpace) const;



		private:

			Rectf dimensions;	// The rectangular dimensions of this sample space

		};
	}
}