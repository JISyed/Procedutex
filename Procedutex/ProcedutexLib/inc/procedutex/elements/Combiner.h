#pragma once
#include "procedutex\types\NormalizedValue.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Combiners
	namespace combiners
	{
		// Collection of classes that must be inherited to be usable
		namespace abstract
		{
			// Interface for combining more than 1 generator output inside a CompositeGenerator
			class Combiner
			{
			public:

				//
				// Ctor + Dtor
				//

				Combiner();
				virtual ~Combiner();



				//
				// Contracts
				//

				// Take in two generator outputs and somehow combine them into one
				virtual const NormalizedValue Combine(const NormalizedValue& firstOutput, const NormalizedValue& secondOutput) = 0;


			};
		}
	}
}