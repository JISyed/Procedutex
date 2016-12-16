#include "procedutex\types\Color4f.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	// math::FloatOps are used very often here
	using namespace math;




	//
	// Static Predefined Colors
	//

	const Color4f Color4f::Black(0.0f, 0.0f, 0.0f, 1.0f);
	const Color4f Color4f::White(1.0f, 1.0f, 1.0f, 1.0f);
	const Color4f Color4f::Red(1.0f, 0.0f, 0.0f, 1.0f);
	const Color4f Color4f::Green(0.0f, 1.0f, 0.0f, 1.0f);
	const Color4f Color4f::Blue(0.0f, 0.0f, 1.0f, 1.0f);





	//
	// Methods
	//

	// Default Ctor
	Color4f::Color4f() :
		red(0.0f),
		green(0.0f),
		blue(0.0f),
		alpha(1.0f)
	{
		
	}

	// New Grayscale Ctor
	Color4f::Color4f(const float grayscaleValue, const float alphaValue) :
		red(FloatOps::Clamp01(grayscaleValue)),
		green(FloatOps::Clamp01(grayscaleValue)),
		blue(FloatOps::Clamp01(grayscaleValue)),
		alpha(FloatOps::Clamp01(alphaValue))
	{
	}

	// New Color Ctor
	Color4f::Color4f(const float r, const float g, const float b, const float a) :
		red(FloatOps::Clamp01(r)),
		green(FloatOps::Clamp01(g)),
		blue(FloatOps::Clamp01(b)),
		alpha(FloatOps::Clamp01(a))
	{
	}

	// Copy Ctor
	Color4f::Color4f(const Color4f& other) :
		red(other.red),
		green(other.green),
		blue(other.blue),
		alpha(other.alpha)
	{
	}

	// Copy Assignment
	Color4f& Color4f::operator=(const Color4f& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->red = other.red;
		this->green = other.green;
		this->blue = other.blue;
		this->alpha = other.alpha;

		return *this;
	}

	// Destructor
	Color4f::~Color4f()
	{
	}




	// Convert a Color4f into a Color4b
	const Color4b Color4f::ConvertToByteRepresentation() const
	{
		return Color4b(math::FloatOps::FloatToUByte(this->red),
					   math::FloatOps::FloatToUByte(this->green),
					   math::FloatOps::FloatToUByte(this->blue),
					   math::FloatOps::FloatToUByte(this->alpha)
		);
	}


	// Retrieve the red channel
	const float Color4f::GetRed() const
	{
		return this->red;
	}

	// Retrieve the green channel
	const float Color4f::GetGreen() const
	{
		return this->green;
	}

	// Retrieve the blue channel
	const float Color4f::GetBlue() const
	{
		return this->blue;
	}

	// Retrieve the alpha channel
	const float Color4f::GetAlpha() const
	{
		return this->alpha;
	}


	// Set the red channel (will clamp between 0.0 and 1.0)
	void Color4f::SetRed(const float r)
	{
		this->red = FloatOps::Clamp01(r);
	}

	// Set the green channel (will clamp between 0.0 and 1.0)
	void Color4f::SetGreen(const float g)
	{
		this->green = FloatOps::Clamp01(g);
	}

	// Set the blue channel (will clamp between 0.0 and 1.0)
	void Color4f::SetBlue(const float b)
	{
		this->blue = FloatOps::Clamp01(b);
	}

	// Set the alpha channel (will clamp between 0.0 and 1.0)
	void Color4f::SetAlpha(const float a)
	{
		this->alpha = FloatOps::Clamp01(a);
	}


	// Set all the channels at once
	void Color4f::Set(const float r, const float g, const float b, const float a)
	{
		this->red = FloatOps::Clamp01(r);
		this->green = FloatOps::Clamp01(g);
		this->blue = FloatOps::Clamp01(b);
		this->alpha = FloatOps::Clamp01(a);
	}



	// STATIC
	// Linear interpolation between the first color to the second color
	const Color4f Color4f::Lerp(const Color4f& first, const Color4f& second, const float t)
	{
		const float tVal = math::FloatOps::Clamp01(t);
		// (a*(1 - t)) + (b*t)

		return Color4f(math::FloatOps::Lerp(first.GetRed(), second.GetRed(), tVal),
					   math::FloatOps::Lerp(first.GetGreen(), second.GetGreen(), tVal),
					   math::FloatOps::Lerp(first.GetBlue(), second.GetBlue(), tVal),
					   math::FloatOps::Lerp(first.GetAlpha(), second.GetAlpha(), tVal));
	}

}
