#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Represents a color where each channel is stored in an unsigned char
	struct Color4b
	{
		//
		// Methods
		//

		// Default Ctor (Black)
		Color4b();

		// New Grayscale Ctor
		Color4b(const unsigned char grayscaleValue, const unsigned char alphaValue = 0xFF);
		
		// New Color Ctor
		Color4b(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 0xFF);
		
		// Copy Ctor
		Color4b(const Color4b& other);

		// Copy Assignment
		Color4b& operator=(const Color4b& other);

		// Dtor
		~Color4b();


		//
		// Data
		//

		unsigned char red;		// r
		unsigned char green;	// g
		unsigned char blue;		// b
		unsigned char alpha;	// a
	};
}