#pragma once
#include "procedutex\types\NormalizedValue.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// Collection of classes that must be inherited to be usable
		namespace abstract
		{
			// Interface for modifying generator output (usually a NormalizedValue)
			class OutputModifier
			{
			public:

				//
				// Ctor + Dtor
				//

				// Ctor
				OutputModifier();
				
				// Dtor
				virtual ~OutputModifier();


				//
				// Contracts
				//

				// Take in the original output and modify it
				virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) = 0;

			};
		}
	}
}