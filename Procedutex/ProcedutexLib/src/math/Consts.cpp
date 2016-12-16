#include "procedutex\math\Consts.h"
#include <cmath>
#include <climits>
#include <cfloat>

namespace procedutex
{
	namespace math
	{
		// Not pie
		const float Constants::Pi = 3.1415926535f;

		// Tau == 2 * Pi
		const float Constants::Tau = 6.2831853071f;

		// Smallest floating point number	
		const float Constants::Epsilon = 0.0001f;

		// Constant to convert degrees to radians
		const float Constants::DegToRad = 0.0174532924f;

		// Constant to convert radians to degrees
		const float Constants::RadToDeg = 57.29578f;

		// Lowest floating point number
		const float Constants::fMin = -FLT_MAX;
		
		// Largest floating point number
		const float Constants::fMax = FLT_MAX;

		// 1 / sqrt(2)
		const float InvSqrtOf2 = 0.707106781188f;


		// Lowest 32-bit integer
		const int Constants::iMin = INT_MIN;
		
		// Largetst 32-bit integer
		const int Constants::iMax = INT_MAX;
	}
}