#pragma once
#include "procedutex\elements\OutputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// Controls the gain of the noise output value
		class GainOutMod : public abstract::OutputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			GainOutMod(const float gain);
			virtual ~GainOutMod();

		
			//
			// Contracts
			//

			// Take in the original output and modify it
			virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) override;


		private:

			//
			// Data
			//

			float gainValue;



			GainOutMod() = delete;

		};
	}
}