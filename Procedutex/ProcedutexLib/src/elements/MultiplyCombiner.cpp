#include "procedutex\elements\MultiplyCombiner.h"

namespace procedutex
{
	namespace combiners
	{
		MultiplyCombiner::MultiplyCombiner()
		{
		}

		// VIRTUAL
		MultiplyCombiner::~MultiplyCombiner()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in two generator outputs and somehow combine them into one
		const NormalizedValue MultiplyCombiner::Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput)
		{
			return NormalizedValue(firstOutput * secondOutput);
		}

	}
}