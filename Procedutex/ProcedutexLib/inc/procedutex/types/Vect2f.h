#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a 2D vector in floating number space
	struct Vect2f
	{
		//
		// Methods
		//

		// Default Ctor
		Vect2f();

		// Specialized Ctor
		Vect2f(const float newX, const float newY);

		// Copy Ctor
		Vect2f(const Vect2f& other);

		// Copy Assignment
		Vect2f& operator=(const Vect2f& other);

		// Dtor
		~Vect2f();

		

		// Set both coordinates manually
		void Set(const float newX, const float newY);

		// Set with another Vect2f
		void Set(const Vect2f& other);



		// Get a uniform scaled vector. Equivalient to (V * s)
		const Vect2f GetScaled(const float uniformScale);

		// V + V
		const Vect2f operator+(const Vect2f& other);

		// V *= s
		Vect2f& operator*=(const float uniformScale);

		// V * s
		const Vect2f operator*(const float uniformScale);

		// V += V
		Vect2f& operator+=(const Vect2f& other);



		//
		// Data
		//

		float x;	// X position
		float y;	// Y position
	};
}