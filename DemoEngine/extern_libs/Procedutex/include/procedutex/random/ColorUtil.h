#pragma once
#include "procedutex\types\Color4f.h"
#include "procedutex\random\EngineBase.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in generating random numbers
	namespace random
	{
		// Utility class to aid in generating random colors
		class ColorUtil
		{
		public:

			// Get a random color
			static const Color4f GetRandomColor(abstract::RandomEngine& rnd);

			// Get a random color with a random alpha
			static const Color4f GetRandomColorWithAlpha(abstract::RandomEngine& rnd);

			// Get a random color, where each of the color channels has a custom range
			static const Color4f GetRandomColor(abstract::RandomEngine& rnd, const float rMin, const float rMax, const float gMin, const float gMax, const float bMin, const float bMax);
			
			// Get a random color with a random alpha, where each of the color channels has a custom range
			static const Color4f GetRandomColorWithAlpha(abstract::RandomEngine& rnd, const float rMin, const float rMax, const float gMin, const float gMax, const float bMin, const float bMax, const float aMin, const float aMax);
			
			// Get a random color, where every color channel has the same custom range
			static const Color4f GetRandomColor(abstract::RandomEngine& rnd, const float everyMin, const float everyMax);

			// Get a random color with a random alpha, where every color channel has the same custom range
			static const Color4f GetRandomColorWithAlpha(abstract::RandomEngine& rnd, const float everyMin, const float everyMax);

			
			
			// Get a random grayscale shade
			static const Color4f GetRandomGrayscale(abstract::RandomEngine& rnd);

			// Get a random grayscale shade with a random alpha
			static const Color4f GetRandomGrayscaleWithAlpha(abstract::RandomEngine& rnd);

			// Get a random grayscale shade, with a custom grayscale range
			static const Color4f GetRandomGrayscale(abstract::RandomEngine& rnd, const float grayMin, const float grayMax);

			// Get a random grayscale shade with a random alpha, where they both have a custom range
			static const Color4f GetRandomGrayscaleWithAlpha(abstract::RandomEngine& rnd, const float grayMin, const float grayMax, const float alphaMin, const float alphaMax);
		};
	}
}