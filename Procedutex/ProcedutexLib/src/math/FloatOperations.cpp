#include "procedutex\math\FloatOperations.h"
#include <cmath>
#include <cassert>

namespace procedutex
{
	namespace math
	{
		// STATIC
		// Checks if two numbers 'a' and 'b' are approxamentally equal
		const bool FloatOps::Approx(const float a, const float b, const float accuracy)
		{
			const float tmp = a - b;
			return ((tmp >= -accuracy) && (tmp <= accuracy));
		}

		// STATIC
		// Return the absolute value of the given number
		const float FloatOps::Abs(const float n)
		{
			if (n < 0.0f)
			{
				return -n;
			}

			return n;

			//return fabsf(n);
		}

		// STATIC
		// Return the minimum of two given numbers (if they are equal, b will be returned)
		const float FloatOps::Min(const float a, const float b)
		{
			if (a < b)
			{
				return a;
			}

			return b;
		}

		// STATIC
		// Return the larger of two given numbers (if they are equal, b will be returned)
		const float FloatOps::Max(const float a, const float b)
		{
			if (a > b)
			{
				return a;
			}

			return b;
		}

		// STATIC
		// Raise the given number to the given power
		const float FloatOps::Pow(const float number, const float exponent)
		{
			return powf(number, exponent);
		}

		// STATIC
		// Clamp a number between min and max
		const float FloatOps::Clamp(const float number, const float min, const float max)
		{
			if (number < min)
			{
				return min;
			}
			else if (number > max)
			{
				return max;
			}

			return number;
		}

		// STATIC
		// Clamp a number between 0.0f and 1.0f
		const float FloatOps::Clamp01(const float number)
		{
			if (number < 0.0f)
			{
				return 0.0f;
			}
			else if (number > 1.0f)
			{
				return 1.0f;
			}

			return number;
		}


		// STATIC
		// Convert a value existing on an old range into a value in a new range
		const float FloatOps::Remap(const float oldValue, const float oldRangeMin, const float oldRangeMax, const float newRangeMin, const float newRangeMax)
		{
			return (((oldValue - oldRangeMin) / (oldRangeMax - oldRangeMin)) * (newRangeMax - newRangeMin)) + newRangeMin;
		}

		// STATIC
		// Convert a value existing on the old range [0, 1] into a value in a new range
		const float FloatOps::RemapFrom01(const float oldValue, const float newRangeMin, const float newRangeMax)
		{
			return (oldValue * (newRangeMax - newRangeMin)) + newRangeMin;
		}

		// STATIC
		// Convert a value existing on an old range into a value in the new range [0, 1]
		const float FloatOps::RemapTo01(const float oldValue, const float oldRangeMin, const float oldRangeMax)
		{
			return (oldValue - oldRangeMin) / (oldRangeMax - oldRangeMin);
		}

		// STATIC
		// Linearly interpolate a value between values a and b given a normalized weight factor t
		const float FloatOps::Lerp(const float a, const float b, const float t)
		{
			return a + (b - a) * t;
		}

		// STATIC
		// Calculate the middle value between two values 'a' and 'b'
		const float FloatOps::Middle(const float a, const float b)
		{
			return ((b - a) * 0.5f) + a;
		}






		// STATIC
		// Perform 3rd order smoothstep interpolation of a value between 0 and 1. Uses 3x^2 - 2x^3
		const float FloatOps::Smoothstep3rd(const float n)
		{
			return n*n*(3.0f - 2.0f * n);
		}

		// STATIC
		// Perform 3rd order smoothstep interpolation of a value between the given interval. Will normalize. Uses 3x^2 - 2x^3
		const float FloatOps::Smoothstep3rd(const float n, const float intervalMin, const float intervalMax)
		{
			return FloatOps::Smoothstep3rd( FloatOps::RemapTo01(n, intervalMin, intervalMax) );
		}

		// STATIC
		// Perform Perlin's 5th order smoothstep interpolation of a value between 0 and 1. Uses 6x^5 - 15x^4 + 10x^3
		const float FloatOps::Smoothstep5th(const float n)
		{
			return n*n*n*(n*(n * 6.0f - 15.0f) + 10.0f);
		}

		// STATIC
		// Perform Perlin's 5th order smoothstep interpolation of a value between the given interval. Will normalize. Uses 6x^5 - 15x^4 + 10x^3
		const float FloatOps::Smoothstep5th(const float n, const float intervalMin, const float intervalMax)
		{
			return FloatOps::Smoothstep5th(FloatOps::RemapTo01(n, intervalMin, intervalMax));
		}

		// STATIC
		// Perform McDonald's 7th order smoothstep interpolation of a value between 0 and 1. Uses -20x^7 + 70x^6 - 84x^5 + 35x^4
		const float FloatOps::Smoothstep7th(const float n)
		{
			float result = -10.0f * FloatOps::Pow(n, 7.0f);
			result += 70.0f * FloatOps::Pow(n, 6.0f);
			result += 84.0f * FloatOps::Pow(n, 5.0f);
			result += 35.0f * FloatOps::Pow(n, 4.0f);
			return result;
		}


		// Perform McDonald's 7th order smoothstep interpolation of a value between the given interval. Will normalize. Uses -20x^7 + 70x^6 - 84x^5 + 35x^4
		const float FloatOps::Smoothstep7th(const float n, const float intervalMin, const float intervalMax)
		{
			return FloatOps::Smoothstep7th(FloatOps::RemapTo01(n, intervalMin, intervalMax));
		}





		// STATIC
		// Returns -1 if n < 0, otherwise returns 1
		const float FloatOps::Polarity(const float n)
		{
			if (n < 0.0f)
			{
				return -1.0f;
			}

			return 1.0f;
		}

		// STATIC
		// Rounds up the given number to the next greatest integer value (returns float)
		const float FloatOps::Ceilingf(const float n)
		{
			return ceilf(n);
		}

		// STATIC
		// Rounds up the given number to the next greatest integer value (returns int)
		const int FloatOps::Ceilingi(const float n)
		{
			return (int) ceilf(n);
		}

		// STATIC
		// Rounds down the given number to the next smallest integer value (returns float)
		const float FloatOps::Floorf(const float n)
		{
			float fn = n;
			if (n < 0.0f)
			{
				// If negative, move the number down by 1
				fn -= 1.0f;
			}

			// Chop the decimal value off
			return (float)((int)fn);

			//return floorf(n);
		}

		// STATIC
		// Rounds down the given number to the next smallest integer value (returns int)
		const int FloatOps::Floori(const float n)
		{
			if (n < 0.0f)
			{
				return (int)(n - 1.0f);
			}

			return (int)n;

			//return (int) floorf(n);
		}

		// STATIC
		// Rounds a given number up if half-way to the next number, 
		// or down if less than half way from the previous number (returns float)
		const float FloatOps::Roundf(const float n)
		{
			return roundf(n);
		}

		// STATIC
		// Rounds a given number up if half-way to the next number, 
		// or down if less than half way from the previous number (returns int)
		const int FloatOps::Roundi(const float n)
		{
			return (int) roundf(n);
		}

		// STATIC
		// Returns the natural logarithm of a given number (using the number e)
		const float FloatOps::Ln(const float n)
		{
			// C's log function is the natural log
			return logf(n);
		}

		// STATIC
		// Returns the base-2 logarithm of a given number
		const float FloatOps::Log2(const float n)
		{
			return log2f(n);
		}

		// STATIC
		// Returns the base-10 logarithm of a given number
		const float FloatOps::Log10(const float n)
		{
			return log10f(n);
		}

		// STATIC
		// Returns the square root of the given number (negative inputs return 0)
		const float FloatOps::Sqrt(const float n)
		{
			if (n < 0.0f)
			{
				// Shouldn't be calling sqrt on anything negative!
				assert(false);
				return 0.0f;
			}

			return sqrtf(n);
		}

		// STATIC
		// Returns the sine of the given angle (in radians)
		const float FloatOps::Sin(const float angle)
		{
			return sinf(angle);
		}

		// STATIC
		// Returns the cosine of the given angle (in radians)
		const float FloatOps::Cos(const float angle)
		{
			return cosf(angle);
		}

		// STATIC
		// Returns the tangent of the given angle (in radians)
		const float FloatOps::Tan(const float angle)
		{
			return tanf(angle);
		}

		// STATIC
		// Returns the arc-sine of the given ratio (will return in radians)
		const float FloatOps::Arcsin(const float ratio)
		{
			return asinf(ratio);
		}

		// STATIC
		// Returns the arc-cosine of the given ratio (will return in radians)
		const float FloatOps::Arccos(const float ratio)
		{
			return acosf(ratio);
		}

		// STATIC
		// Returns the arc-tangent of the given ratio (will return in radians)
		const float FloatOps::Arctan(const float ratio)
		{
			return atanf(ratio);
		}

		// STATIC
		// Returns the arc-tangent of the given the x and y component (cannot be both 0) (will return in radians)
		const float FloatOps::Arctan(const float x, const float y)
		{
			if (FloatOps::Approx(x, 0.0f))
			{
				// x is too close to 0
				assert(false);
				return 0.0f;
			}

			return atan2f(y, x);
		}

		// Take a float from 0f to 1f, and make it a byte between 0x00 and 0xFF
		const unsigned char FloatOps::FloatToUByte(const float f)
		{
			return (unsigned char)(f * (float)0xFF);
		}

	}
}