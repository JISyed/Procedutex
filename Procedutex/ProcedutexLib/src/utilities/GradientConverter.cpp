#include "procedutex\utilities\GradientConverter.h"

namespace procedutex
{
	namespace util
	{
		// Default Ctor
		GradientConverter::GradientConverter() :
			colorGradient()
		{
		}

		// Gradient Ctor
		GradientConverter::GradientConverter(const Gradient& newGradient) :
			colorGradient(newGradient)
		{
		}

		// Copy Ctor
		GradientConverter::GradientConverter(const GradientConverter& other) :
			colorGradient(other.colorGradient)
		{
		}

		// VIRTUAL
		// Dtor
		GradientConverter::~GradientConverter()
		{
		}

		// Copy Assignment
		GradientConverter& GradientConverter::operator=(const GradientConverter& other)
		{
			if (this == &other)
			{
				return *this;
			}

			this->colorGradient = other.colorGradient;

			return *this;
		}



		// VIRTUAL OVERRIDE
		// Convert a procedurally generated value into a color using gradient interpolation
		const Color4f GradientConverter::ConvertValue(const NormalizedValue v) const
		{
			return this->colorGradient.GetAt(v);
		}

	}
}