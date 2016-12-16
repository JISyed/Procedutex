#pragma once
#include "procedutex\elements\Generator.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Generator that uses another Generator to compute a sum of multiple octaves of procedural calculations
	class FractalGenerator final : public abstract::Generator
	{
	public:
		
		//
		// Methods
		//
		
		// Initialize a new Fractial Generator given a starting frequency
		FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency);
		
		// Initialize a new Fractial Generator given the initial sampling space
		FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace);

		// Initialize a new Fractial Generator given a starting frequency, number of octaves, frequency change, and amplitude change
		FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency, const unsigned int numOctaves, const float frequencyMultiplier, const float amplitudeMultiplier);
		
		// Initialize a new Fractial Generator given the initial sampling space, number of octaves, frequency change, and amplitude change
		FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace, const unsigned int numOctaves, const float frequencyMultiplier, const float amplitudeMultiplier);
		
		// Initialize a new Fractial Generator given a starting frequency, number of octaves, frequency change, amplitude change, and ss-origin change
		FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency, const unsigned int numOctaves, const float frequencyMultiplier, const float amplitudeMultiplier, const Vect2f& deltaOrigin);
		
		// Initialize a new Fractial Generator given the initial sampling space, number of octaves, frequency change, amplitude change, and ss-origin change
		FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace, const unsigned int numOctaves, const float frequencyMultiplier, const float amplitudeMultiplier, const Vect2f& deltaOrigin);

		// Dtor
		virtual ~FractalGenerator();


		
		// Compute a sum of octaves of prodecural values given the texture space
		virtual const NormalizedValue GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions) override;



	protected:

		// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
		virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) override;

		// Does not do anything for FractalGenerator
		virtual void OnSeedChange(const unsigned int newSeed) override;




	private:

		//
		// Data
		//

		abstract::Generator& basisGenerator;	// The generator that is processed in different octaves
		unsigned int octaves;					// The number of different iterations (aka octaves) to generate value with
		float frequencyMultiplier;				// The multiplier applied onto the frequency from one octave to the next
		float amplitudeMultiplier;				// The multiplier applied onto the amplitude from one octave to the next
		Vect2f deltaOrigin;						// The change in sample space origin from one octave to the next



		//
		// Deleted Methods
		//

		// No default Ctor
		FractalGenerator() = delete;

		// No copy assignment
		FractalGenerator& operator=(const FractalGenerator& other) = delete;

		// No move assignment
		FractalGenerator& operator=(FractalGenerator&& other) = delete;
	};

	
}