#include "procedutex\elements\GainOutMod.h"
#include <cassert>
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	namespace outmods
	{
		GainOutMod::GainOutMod(const float gain) :
			abstract::OutputModifier(),
			gainValue(math::FloatOps::Clamp(gain, -1.0f, 1.0f))
		{
		}

		// VIRTUAL
		GainOutMod::~GainOutMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original output and modify it
		const NormalizedValue GainOutMod::Modify(const NormalizedValue& originalOutput)
		{
			const float originalValue = originalOutput.GetRawValue();

			// If positive
			if (originalValue > 0.0f)
			{
				return NormalizedValue(originalValue + this->gainValue);
			}
			// If negative
			else if (originalValue < 0.0f)
			{
				return NormalizedValue(originalValue - this->gainValue);
			}

			// If zero
			return originalOutput;
		}


	}
}