#pragma once
#include "procedutex\types\Vect2f.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a rectangle with an origin, width, and height
	struct Rectf
	{
		//
		// Methods
		//

		// Default Ctor
		Rectf();

		// Specialized Ctor
		Rectf(const Vect2f& newOrigin, const float newWidth, const float newHeight);
		
		// Copy Ctor
		Rectf(const Rectf& other);

		// Copy Assignment
		Rectf& operator=(const Rectf& other);

		// Dtor
		~Rectf();


		// Set with another Rectf
		void Set(const Rectf& newRect);

		// Set the origin, width, and height, all at once
		void Set(const Vect2f& newOrigin, const float newWidth, const float newHeight);




		//
		// Data
		//


		Vect2f origin;	// The origin of the rectangle (conventially the upper left corner)
		float width;	// The width of the rectangle
		float height;	// The height of the rectangle
	};
}