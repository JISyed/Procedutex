#pragma once
#include "procedutex\types\NormalizedValue.h"
#include "procedutex\types\Vect2f.h"
#include "procedutex\types\Color4f.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// Collection of classes that must be inherited to be usable
		namespace abstract
		{
			// An abstract class to define how a normalized value converts into a color
			class OutputConverter
			{
			public:

				//
				// Ctor + Dtor
				//

				// Default Ctor
				OutputConverter();

				// Dtor
				virtual ~OutputConverter();
				


				//
				// Contracts
				//

				// Convert a procedurally generated value into a color
				virtual const Color4f ConvertValue(const NormalizedValue v) const = 0;

			};
		}
	}
}