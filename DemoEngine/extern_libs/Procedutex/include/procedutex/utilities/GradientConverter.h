#pragma once
#include "procedutex\utilities\OutputConverter.h"
#include "procedutex\types\Gradient.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in texture generation
	namespace util
	{
		// An Output Converter that turns a procedural value into a color interpolated on a Gradient
		class GradientConverter : public abstract::OutputConverter
		{
		public:

			// Default Ctor
			GradientConverter();

			// Gradient Ctor
			GradientConverter(const Gradient& newGradient);

			// Copy Ctor
			GradientConverter(const GradientConverter& other);

			// Dtor
			virtual ~GradientConverter();

			// Copy Assignment
			GradientConverter& operator=(const GradientConverter& other);





			// Convert a procedurally generated value into a color using gradient interpolation
			virtual const Color4f ConvertValue(const NormalizedValue v) const override;



		private:


			//
			// Data
			//

			Gradient colorGradient;		// The color gradient used to interpolate the output color
			
		};
	}
}