#include"procedutex\elements\AddCombiner.h"

namespace procedutex
{
	namespace combiners
	{
		AddCombiner::AddCombiner()
		{
		}

		// VIRTUAL
		AddCombiner::~AddCombiner()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in two generator outputs and somehow combine them into one
		const NormalizedValue AddCombiner::Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput)
		{
			return NormalizedValue(firstOutput + secondOutput);
		}
	}
}