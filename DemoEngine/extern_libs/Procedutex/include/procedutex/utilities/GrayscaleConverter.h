#pragma once
#include "procedutex\utilities\OutputConverter.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// An Output Converter that turns a procedural value into a grayscale color
		class GrayscaleConverter final : public abstract::OutputConverter
		{
		public:

			// Default Ctor
			GrayscaleConverter();

			// Dtor
			virtual ~GrayscaleConverter();




			// Convert a procedurally generated value into a grayscale shade
			virtual const Color4f ConvertValue(const NormalizedValue v) const override;

		};
	}
}