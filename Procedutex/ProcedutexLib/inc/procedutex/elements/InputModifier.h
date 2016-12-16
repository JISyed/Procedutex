#pragma once
#include "procedutex\types\Vect2f.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Input Modifier Elements
	namespace inmods
	{
		// Collection of classes that must be inherited to be usable
		namespace abstract
		{
			// Interface for modifying generator input (usually a Vect)
			class InputModifier
			{
			public:

				//
				// Ctor + Dtor
				//

				// Ctor
				InputModifier();

				// Dtor
				virtual ~InputModifier();



				//
				// Contracts
				//

				// Take in the original input and modify it
				virtual const Vect2f Modify(const Vect2f& originalInput) = 0;

			};
		}
	}
}