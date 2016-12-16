#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Math operations
	namespace math
	{
		// A collection of important numerical constants
		class Constants
		{
		public:

			static const float Pi;				// Ratio of circumferance of circle to its diameter
			static const float Tau;				// Tau == 2 * Pi
			static const float Epsilon;			// Smallest floating point number before zero
			static const float DegToRad;		// Constant to convert degrees to radians
			static const float RadToDeg;		// Constant to convert radians to degrees
			static const float fMin;			// Lowest floating point number
			static const float fMax;			// Largest floating point number
			static const float InvSqrtOf2;		// 1 / sqrt(2)
			static const float e;				// Base of natural logarithm

			static const int iMin;				// Lowest 32-bit integer
			static const int iMax;				// Largetst 32-bit integer
		};
	}
}