#include "procedutex\types\GradientPoint.h"

namespace procedutex
{
	// Default Ctor (Black, at 0.0)
	GradientPoint::GradientPoint() :
		color(),
		position()
	{
	}

	// Specialized Ctor
	GradientPoint::GradientPoint(const Color4f& newColor, const NormalizedValue newPosition) :
		color(newColor),
		position(newPosition)
	{
	}

	// Copy Ctor
	GradientPoint::GradientPoint(const GradientPoint& other) :
		color(other.color),
		position(other.position)
	{
	}

	// Dtor
	GradientPoint::~GradientPoint()
	{
	}

	// Copy Assignment
	GradientPoint& GradientPoint::operator=(const GradientPoint& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->color = other.color;
		this->position = other.position;

		return *this;
	}


	// GP < GP. For STL insert
	const bool GradientPoint::operator<(const GradientPoint& other) const
	{
		return this->position < other.position;
	}

	// GP == GP. For STL find
	const bool GradientPoint::operator==(const GradientPoint& other) const
	{
		return this->position.GetRawValue() == other.position.GetRawValue();
	}

}