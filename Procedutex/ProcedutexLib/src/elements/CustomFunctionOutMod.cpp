#include "procedutex\elements\CustomFunctionOutMod.h"

namespace procedutex
{
	namespace outmods
	{
		CustomFunctionOutMod::CustomFunctionOutMod(const CustomFunction customModificationFunction) :
			customLambda(customModificationFunction)
		{
		}

		// VIRTUAL
		CustomFunctionOutMod::~CustomFunctionOutMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original output and modify it
		const NormalizedValue CustomFunctionOutMod::Modify(const NormalizedValue& originalOutput)
		{
			const float finalValue = this->customLambda(originalOutput.GetRawValue());
			return NormalizedValue(finalValue);
		}
	}
}