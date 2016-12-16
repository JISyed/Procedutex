#include "procedutex\elements\AbsOutMod.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	namespace outmods
	{
		AbsOutMod::AbsOutMod()
		{
		}

		// VIRTUAL
		AbsOutMod::~AbsOutMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original output and modify it
		const NormalizedValue AbsOutMod::Modify(const NormalizedValue& originalOutput)
		{
			return NormalizedValue(math::FloatOps::Abs(originalOutput.GetRawValue()));
		}
	}
}