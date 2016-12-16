#include "procedutex\elements\DomainDistortionInMod.h"
#include <cassert>

namespace procedutex
{
	namespace inmods
	{
		DomainDistortionInMod::DomainDistortionInMod(procedutex::abstract::Generator* const newDistortGenerator, const float shift, const float strength) :
			distortionGenerator(newDistortGenerator),
			distortShift(shift),
			distortStrength(strength)
		{
			assert(newDistortGenerator != nullptr);
		}

		// VIRTUAL
		DomainDistortionInMod::~DomainDistortionInMod()
		{
			if (this->distortionGenerator != nullptr)
			{
				delete this->distortionGenerator;
			}
		}


		// VIRTUAL OVERRIDE
		// Take in the original input and modify it
		const Vect2f DomainDistortionInMod::Modify(const Vect2f& originalInput)
		{
			// Distort the input position of the target generator using the distorter generator
			Vect2f distortedPosition = originalInput;
			{
				Vect2f shiftedPosition = originalInput;
				Vect2f distortVector;

				// Shift the position then create a distort vector using the distorter generator
				distortVector.x = this->distortionGenerator->GetAt(shiftedPosition).GetRawValue();
				shiftedPosition.x += this->distortShift;
				distortVector.y = this->distortionGenerator->GetAt(shiftedPosition).GetRawValue();

				// Budge the original position by the distort vector
				distortedPosition += (distortVector * this->distortStrength);
			}

			return distortedPosition;
		}

	}
}