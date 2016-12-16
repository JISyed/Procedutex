#pragma once
#include <set>
#include "procedutex\types\GradientPoint.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a range of position-dependent colors, facilitating ombre (color blending)
	class Gradient
	{
	public:

		// Default Ctor (Black-to-White)
		Gradient();

		// Dtor
		~Gradient();

		// Copy Ctor
		Gradient(const Gradient& other);

		// Copy Assignment
		Gradient& operator=(const Gradient& other);




		// Insert new gradient point (should replace color at existing position)
		void Insert(const Color4f& newColor, const NormalizedValue newPosition);

		// Insert new gradient point (should replace color at existing position)
		void Insert(const GradientPoint& newGradientPoint);




		// Get the color at a given position in the gradient space using gradient interpolation
		const Color4f GetAt(const NormalizedValue gradientSpacePosition) const;


	private:


		//
		// Data
		//

		// A collection of gradient points, ordered by their position in gradient space
		std::set<GradientPoint> gradientPoints;

	};
}