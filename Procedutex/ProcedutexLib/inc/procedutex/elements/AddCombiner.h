#pragma once
#include "procedutex\elements\Combiner.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Combiners
	namespace combiners
	{
		// Add two generator outputs together
		class AddCombiner : public abstract::Combiner
		{
		public:

			//
			// Ctor + Dtor
			//

			AddCombiner();
			virtual ~AddCombiner();


			//
			// Contracts
			//

			// Take in two generator outputs and somehow combine them into one
			virtual const NormalizedValue Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput) override;

		};
	}
}