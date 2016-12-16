#include "procedutex\types\Color4b.h"

namespace procedutex
{
	// Default Ctor
	Color4b::Color4b() :
		red(0x00),
		green(0x00),
		blue(0x00),
		alpha(0xFF)
	{
	}

	// New Grayscale Ctor
	Color4b::Color4b(const unsigned char grayscaleValue, const unsigned char alphaValue) :
		red(grayscaleValue),
		green(grayscaleValue),
		blue(grayscaleValue),
		alpha(alphaValue)
	{
	}

	// New Color Ctor
	Color4b::Color4b(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a) :
		red(r),
		green(g),
		blue(b),
		alpha(a)
	{
	}

	// Copy Ctor
	Color4b::Color4b(const Color4b& other) :
		red(other.red),
		green(other.green),
		blue(other.blue),
		alpha(other.alpha)
	{
	}

	// Copy Assignment
	Color4b& Color4b::operator=(const Color4b& other)
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

	// Dtor
	Color4b::~Color4b()
	{
	}
}