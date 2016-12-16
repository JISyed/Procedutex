#pragma once
#include "procedutex\elements\Generator.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes that must be inherited to be usable
	namespace abstract
	{
		// Abstract class for a Generator that generates a value by itself, without other Generators composed together
		class SingleGenerator : public Generator
		{
		public:
			// Initialize the Single Generator with a new seed
			SingleGenerator(const unsigned int newSeed);

			// Initialize the Single Generator with a new seed and sample space
			SingleGenerator(const unsigned int newSeed, const util::SampleSpace& newSampleSpace);
			
			// Dtor
			virtual ~SingleGenerator();
			
			// Generate a procedural value at a given position in texture space
			virtual const NormalizedValue GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions) override;
			


		protected:

			// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
			virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) = 0;

			// Custom logic for determine how a generator should handle the changing of its random seed
			virtual void OnSeedChange(const unsigned int newSeed) = 0;


		private:

			// No default ctor
			SingleGenerator() = delete;
		};
	}
}