#pragma once
#include "procedutex\types\NormalizedValue.h"
#include "procedutex\types\Color4b.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a color where each channel is stored in a float
	struct Color4f
	{
		//
		// Methods
		//

		// Default Ctor (Black)
		Color4f();

		// New Grayscale Ctor
		Color4f(const float grayscaleValue, const float alphaValue = 1.0f);

		// New Color Ctor
		Color4f(const float r, const float g, const float b, const float a = 1.0f);

		// Copy Ctor
		Color4f(const Color4f& other);

		// Copy Assignment
		Color4f& operator=(const Color4f& other);

		// Destructor
		~Color4f();


		// Convert a Color4f into a Color4b
		const Color4b ConvertToByteRepresentation() const;


		// Retrieve the red channel
		const float GetRed() const;
		// Retrieve the green channel
		const float GetGreen() const;
		// Retrieve the blue channel
		const float GetBlue() const;
		// Retrieve the alpha channel
		const float GetAlpha() const;


		// Set the red channel (will clamp between 0.0 and 1.0)
		void SetRed(const float r);
		// Set the green channel (will clamp between 0.0 and 1.0)
		void SetGreen(const float g);
		// Set the blue channel (will clamp between 0.0 and 1.0)
		void SetBlue(const float b);
		// Set the alpha channel (will clamp between 0.0 and 1.0)
		void SetAlpha(const float a);

		// Set all the channels at once
		void Set(const float r, const float g, const float b, const float a);


		// Linear interpolation between the first color to the second color
		static const Color4f Lerp(const Color4f& first, const Color4f& second, const float t);
		
		
		//
		// Constant Color Values
		//
		
		static const Color4f Black;
		static const Color4f White;
		static const Color4f Red;
		static const Color4f Green;
		static const Color4f Blue;



	private:


		//
		// Data
		//

		float red;		// r
		float green;	// g
		float blue;		// b
		float alpha;	// a
	};
}