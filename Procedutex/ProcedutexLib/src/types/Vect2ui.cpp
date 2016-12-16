#include "procedutex\types\Vect2ui.h"

namespace procedutex
{
	// Default Ctor
	Vect2ui::Vect2ui() :
		x(0),
		y(0)
	{
	}

	// Specialized Ctor
	Vect2ui::Vect2ui(const unsigned int newX, const unsigned int newY) :
		x(newX),
		y(newY)
	{
	}

	// Copy Ctor
	Vect2ui::Vect2ui(const Vect2ui& other) :
		x(other.x),
		y(other.y)
	{
	}

	// Copy Assignment
	Vect2ui& Vect2ui::operator=(const Vect2ui& other)
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
	Vect2ui::~Vect2ui()
	{
	}


	// Set both coordinates manually
	void Vect2ui::Set(const unsigned int newX, const unsigned int newY)
	{
		this->x = newX;
		this->y = newY;
	}

	// Set with another Vect2ui
	void Vect2ui::Set(const Vect2ui& other)
	{
		this->x = other.x;
		this->y = other.y;
	}

}