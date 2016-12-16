#include "procedutex\elements\InvertOutMod.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	namespace outmods
	{
		InvertOutMod::InvertOutMod()
		{
		}

		// VIRTUAL
		InvertOutMod::~InvertOutMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original output and modify it
		const NormalizedValue InvertOutMod::Modify(const NormalizedValue& originalOutput)
		{
			return originalOutput * -1.0f;
		}

	}
}