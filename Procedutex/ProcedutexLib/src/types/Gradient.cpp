#include "procedutex\types\Gradient.h"
#include <cassert>
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	// Default Ctor
	Gradient::Gradient() :
		gradientPoints()
	{
		// Need a default gradient across the entire gradient space
		this->gradientPoints.insert(GradientPoint(Color4f::Black, NormalizedValue(NormalizedValue::BEGINNING) ) );
		this->gradientPoints.insert(GradientPoint(Color4f::White, NormalizedValue(NormalizedValue::END)));
	}

	// Dtor
	Gradient::~Gradient()
	{
		gradientPoints.clear();
	}

	// Copy Ctor
	Gradient::Gradient(const Gradient& other) : 
		gradientPoints(other.gradientPoints)
	{
	}

	// Copy Assignment
	Gradient& Gradient::operator=(const Gradient& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->gradientPoints.clear();
		this->gradientPoints = other.gradientPoints;

		return *this;
	}





	// Insert new gradient point (should replace color at existing position)
	void Gradient::Insert(const Color4f& newColor, const NormalizedValue newPosition)
	{
		this->Insert(GradientPoint(newColor, newPosition));
	}


	// Insert new gradient point (should replace color at existing position)
	void Gradient::Insert(const GradientPoint& newGradientPoint)
	{
		// Check if there is already a gradient point at the given position
		auto samePosition = this->gradientPoints.find(newGradientPoint);
		if (samePosition != this->gradientPoints.cend())
		{
			// Remove the old gradient point
			this->gradientPoints.erase(samePosition);
		}

		// Regardless, add the new gradient point
		this->gradientPoints.insert(newGradientPoint);
	}







	// Get the color at a given position in the gradient space using gradient interpolation
	const Color4f Gradient::GetAt(const NormalizedValue gradientSpacePosition) const
	{
		// Iterators
		auto currPoint = this->gradientPoints.begin();
		currPoint++;
		auto prevPoint = this->gradientPoints.begin();
		auto endOfIteration = this->gradientPoints.end();

		// Find the two gradient points that the given position lies between
		while (currPoint != endOfIteration)
		{
			if (currPoint->position >= gradientSpacePosition)
			{
				// Found it!
				break;
			}

			prevPoint++;
			currPoint++;
		}

		// Make sure that the currPoint is still a valid iterator
		assert(currPoint != endOfIteration);

		// Lerp between the two colors given by the two found gradient points
		const float t = math::FloatOps::RemapTo01(gradientSpacePosition.GetRawValue(),
												  prevPoint->position.GetRawValue(),
												  currPoint->position.GetRawValue());
		return Color4f::Lerp(prevPoint->color, currPoint->color, t);
	}







}