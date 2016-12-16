#pragma once
#include "procedutex\elements\OutputModifier.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// Turns the output to one of the normalized extremes
		class BinarizeOutMod : public abstract::OutputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			BinarizeOutMod(const float threshold);
			virtual ~BinarizeOutMod();



			//
			// Contracts
			//

			// Take in the original output and modify it
			virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) override;
		
		
		
		private:

			//
			// Data
			//

			float binaryThreshold;


			//
			// Deleted Methods
			//

			BinarizeOutMod() = delete;

		};

		
	}
}