#pragma once
#include "procedutex\types\Color4f.h"
#include "procedutex\types\NormalizedValue.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a color-position pair for Gradients
	struct GradientPoint
	{
		//
		// Big 4 + Other Ctors
		//

		// Default Ctor (Black, at 0.0)
		GradientPoint();

		// Specialized Ctor
		GradientPoint(const Color4f& newColor, const NormalizedValue newPosition);

		// Copy Ctor
		GradientPoint(const GradientPoint& other);

		// Dtor
		~GradientPoint();

		// Copy Assignment
		GradientPoint& operator=(const GradientPoint& other);




		//
		// Operators
		//

		// GP < GP. For STL insert
		const bool operator<(const GradientPoint& other) const;

		// GP == GP. For STL find
		const bool operator==(const GradientPoint& other) const;





		//
		// Data
		//

		Color4f color;
		NormalizedValue position;
	};
}