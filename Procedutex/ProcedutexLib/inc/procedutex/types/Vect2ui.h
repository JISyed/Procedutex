#pragma once

namespace procedutex
{
	// Represents a 2D vector in non-negative integer space (used for pixel cooridnates)
	struct Vect2ui
	{
		//
		// Methods
		//

		// Default Ctor
		Vect2ui();

		// Specialized Ctor
		Vect2ui(const unsigned int newX, const unsigned int newY);

		// Copy Ctor
		Vect2ui(const Vect2ui& other);
		
		// Copy Assignment
		Vect2ui& operator=(const Vect2ui& other);
		
		// Dtor
		~Vect2ui();



		// Set both coordinates manually
		void Set(const unsigned int newX, const unsigned int newY);

		// Set with another Vect2ui
		void Set(const Vect2ui& other);





		//
		// Data
		//

		unsigned int x;		// X position (going right)
		unsigned int y;		// Y position (going down)
	};
}