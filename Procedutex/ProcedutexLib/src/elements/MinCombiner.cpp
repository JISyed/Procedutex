#include "procedutex\elements\MinCombiner.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	namespace combiners
	{
		MinCombiner::MinCombiner()
		{
		}

		// VIRTUAL
		MinCombiner::~MinCombiner()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in two generator outputs and somehow combine them into one
		const NormalizedValue MinCombiner::Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput)
		{
			return NormalizedValue(math::FloatOps::Min(firstOutput.GetRawValue(), secondOutput.GetRawValue()));
		}


	}
}