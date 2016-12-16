#pragma once
#include "procedutex\elements\SingleGenerator.h"
//#include <vector>


// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Generator that procedurally generates Perlin Noise
	class PerlinNoise final : public abstract::SingleGenerator
	{
	public:

		// Initialize this Perlin Noise Generator with a new seed
		PerlinNoise(const unsigned int newSeed);

		// Initialize this Perlin Noise Generator with a new seed and sample space
		PerlinNoise(const unsigned int newSeed, const util::SampleSpace& newSampleSpace);
		
		// Dtor
		virtual ~PerlinNoise();


	protected:

		// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
		virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) override;

		// Custom logic for determine how a generator should handle the changing of its random seed
		virtual void OnSeedChange(const unsigned int newSeed) override;



	private:

		//
		// Data
		//

		// The permutation array lookup for gradient calculations
		int* p;


		
		//
		// Private Routines
		//

		// Convert the given sample point into one of the 12 gradient directions
		const float GetGradientDirection(const int hash, const float x, const float y, const float z);

		


		//
		// Deleted Methods
		//

		// No default Ctor
		PerlinNoise() = delete;

	};
}