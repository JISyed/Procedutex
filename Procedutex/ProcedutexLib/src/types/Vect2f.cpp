#include "procedutex\types\Vect2f.h"

namespace procedutex
{
	// Default Ctor
	Vect2f::Vect2f() :
		x(0.0f),
		y(0.0f)
	{
	}

	// Specialized Ctor
	Vect2f::Vect2f(const float newX, const float newY) :
		x(newX),
		y(newY)
	{
	}

	// Copy Ctor
	Vect2f::Vect2f(const Vect2f& other) :
		x(other.x),
		y(other.y)
	{
	}

	// Copy Assignment
	Vect2f& Vect2f::operator=(const Vect2f& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->x = other.x;
		this->y = other.y;

		return *this;
	}

	// Dtor
	Vect2f::~Vect2f()
	{
	}


	// Set both coordinates manually
	void Vect2f::Set(const float newX, const float newY)
	{
		this->x = newX;
		this->y = newY;
	}

	// Set with another Vect2f
	void Vect2f::Set(const Vect2f& other)
	{
		this->x = other.x;
		this->y = other.y;
	}


	// Get a uniform scaled vector. Equivalient to (V * s)
	const Vect2f Vect2f::GetScaled(const float uniformScale)
	{
		return Vect2f(this->x * uniformScale, this->y * uniformScale);
	}

	// V + V
	const Vect2f Vect2f::operator+(const Vect2f& other)
	{
		return Vect2f(this->x + other.x, this->y + other.y);
	}

	// V *= s
	Vect2f& Vect2f::operator*=(const float uniformScale)
	{
		this->x *= uniformScale;
		this->y *= uniformScale;

		return *this;
	}

	// V * s
	const Vect2f Vect2f::operator*(const float uniformScale)
	{
		return Vect2f(this->x * uniformScale, this->y * uniformScale);
	}

	// V += V
	Vect2f& Vect2f::operator+=(const Vect2f& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}

}