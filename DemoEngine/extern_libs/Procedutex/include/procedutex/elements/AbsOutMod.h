#pragma once
#include "procedutex\elements\OutputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// An Output Mod that takes the absolute value of the generator's output
		class AbsOutMod : public abstract::OutputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			AbsOutMod();
			virtual ~AbsOutMod();



			//
			// Contracts
			//

			// Take in the original output and modify it
			virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) override;

		};
	}
}