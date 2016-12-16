#ifndef ENGINE_MATH_UTIL_H
#define ENGINE_MATH_UTIL_H

#include "Constants.h"

namespace lge
{
	// Utility class to aid floating point comparisons
	class Util
	{
	public:
		static const bool isEqual(const float a, const float b, const float epsilon = MATH_TOLERANCE);
		static const bool isNotEqual(const float a, const float b, const float epsilon = MATH_TOLERANCE);
		static const bool isOne(const float a, const float epsilon = MATH_TOLERANCE);
		static const bool isNonZero(const float a, const float epsilon = MATH_TOLERANCE);
		static const bool isZero(const float a, const float epsilon = MATH_TOLERANCE);
	};
}

#endif