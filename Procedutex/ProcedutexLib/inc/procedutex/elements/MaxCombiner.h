#pragma once
#include "procedutex\elements\Combiner.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Combiners
	namespace combiners
	{
		// Evaluate the max of two generator outputs
		class MaxCombiner : public abstract::Combiner
		{
		public:

			//
			// Ctor + Dtor
			//

			MaxCombiner();
			virtual ~MaxCombiner();


			//
			// Contracts
			//

			// Take in two generator outputs and somehow combine them into one
			virtual const NormalizedValue Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput) override;

		};
	}
}