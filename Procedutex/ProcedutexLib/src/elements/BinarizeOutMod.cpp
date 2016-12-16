#include "procedutex\elements\BinarizeOutMod.h"
#include "procedutex\math\FloatOperations.h"
#include <cassert>

namespace procedutex
{
	namespace outmods
	{
		BinarizeOutMod::BinarizeOutMod(const float threshold) :
			abstract::OutputModifier(),
			binaryThreshold(threshold)
		{
		}

		// VIRTUAL
		BinarizeOutMod::~BinarizeOutMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original output and modify it
		const NormalizedValue BinarizeOutMod::Modify(const NormalizedValue& originalOutput)
		{
			if (originalOutput.GetRawValue() < this->binaryThreshold)
			{
				return NormalizedValue(NormalizedValue::BEGINNING);
			}

			return NormalizedValue(NormalizedValue::END);
		}


	}
}