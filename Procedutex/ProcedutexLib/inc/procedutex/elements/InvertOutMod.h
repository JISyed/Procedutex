#pragma once
#include "procedutex\elements\OutputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// An OutputModifier that inverts the output value (flips negative sign)
		class InvertOutMod : public abstract::OutputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			InvertOutMod();
			virtual ~InvertOutMod();

			
			//
			// Contracts
			//

			// Take in the original output and modify it
			virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) override;

		};

		
	}
}