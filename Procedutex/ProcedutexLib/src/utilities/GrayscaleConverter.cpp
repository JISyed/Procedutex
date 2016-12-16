#include "procedutex\utilities\GrayscaleConverter.h"

namespace procedutex
{
	namespace util
	{
		// Default Ctor
		GrayscaleConverter::GrayscaleConverter()
		{
		}

		// VIRTUAL
		// Dtor
		GrayscaleConverter::~GrayscaleConverter()
		{
		}



		// VIRTUAL OVERRIDE
		// Convert a procedurally generated value into a grayscale shade
		const Color4f GrayscaleConverter::ConvertValue(const NormalizedValue v) const
		{
			return Color4f(v.GetInNewInterval(0.0f, 1.0f));
		}
	}
}