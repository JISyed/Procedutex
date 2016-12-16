#include "procedutex\types\Rectf.h"

namespace procedutex
{
	// Default Ctor
	Rectf::Rectf() :
		origin(),
		width(0.0f),
		height(0.0f)
	{
	}

	// Specialized Ctor
	Rectf::Rectf(const Vect2f& newOrigin, const float newWidth, const float newHeight) :
		origin(newOrigin),
		width(newWidth),
		height(newHeight)
	{
	}

	// Copy Ctor
	Rectf::Rectf(const Rectf& other) :
		origin(other.origin),
		width(other.width),
		height(other.height)
	{
	}

	// Copy Assignment
	Rectf& Rectf::operator=(const Rectf& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->origin.Set(other.origin);
		this->width = other.width;
		this->height = other.height;

		return *this;
	}

	// Dtor
	Rectf::~Rectf()
	{
	}


	// Set with another Rectf
	void Rectf::Set(const Rectf& newRect)
	{
		this->origin.Set(newRect.origin);
		this->width = newRect.width;
		this->height = newRect.height;
	}

	// Set the origin, width, and height, all at once
	void Rectf::Set(const Vect2f& newOrigin, const float newWidth, const float newHeight)
	{
		this->origin.Set(newOrigin);
		this->width = newWidth;
		this->height = newHeight;
	}

}