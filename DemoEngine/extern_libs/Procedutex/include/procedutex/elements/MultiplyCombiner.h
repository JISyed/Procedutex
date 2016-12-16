#pragma once
#include "procedutex\elements\Combiner.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Combiners
	namespace combiners
	{
		// Multiply two generator outputs together
		class MultiplyCombiner : public abstract::Combiner
		{
		public:

			//
			// Ctor + Dtor
			//

			MultiplyCombiner();
			virtual ~MultiplyCombiner();


			//
			// Contracts
			//

			// Take in two generator outputs and somehow combine them into one
			virtual const NormalizedValue Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput) override;


		};
	}
}