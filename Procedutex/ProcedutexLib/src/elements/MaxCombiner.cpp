#include "procedutex\elements\MaxCombiner.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	namespace combiners
	{
		MaxCombiner::MaxCombiner()
		{
		}

		// VIRTUAL
		MaxCombiner::~MaxCombiner()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in two generator outputs and somehow combine them into one
		const NormalizedValue MaxCombiner::Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput)
		{
			return NormalizedValue(math::FloatOps::Max(firstOutput.GetRawValue(), secondOutput.GetRawValue()));
		}


	}
}