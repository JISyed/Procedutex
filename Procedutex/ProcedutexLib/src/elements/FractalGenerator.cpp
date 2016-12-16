#include "procedutex\elements\FractalGenerator.h"
#include "procedutex\math\FloatOperations.h"

#define DEFAULT_OCTAVES 8u
#define DEFAULT_FREQ_MULT 2.0f
#define DEFAULT_AMP_MULT 0.5f

namespace procedutex
{
	// Initialize a new Fractial Generator given a starting frequency
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency) :
		Generator(0u, util::SampleSpace(Vect2f(), initialFrequency, initialFrequency)),
		basisGenerator(baseGenerator),
		octaves(DEFAULT_OCTAVES),
		frequencyMultiplier(DEFAULT_FREQ_MULT),
		amplitudeMultiplier(DEFAULT_AMP_MULT),
		deltaOrigin()
	{
	}

	// Initialize a new Fractial Generator given the initial sampling space
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace) :
		Generator(0u, newSampleSpace),
		basisGenerator(baseGenerator),
		octaves(DEFAULT_OCTAVES),
		frequencyMultiplier(DEFAULT_FREQ_MULT),
		amplitudeMultiplier(DEFAULT_AMP_MULT),
		deltaOrigin()
	{
	}

	// Initialize a new Fractial Generator given a starting frequency, number of octaves, frequency change, and amplitude change
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency, const unsigned int numOctaves, const float deltaFreq, const float deltaAmp) :
		Generator(0u, util::SampleSpace(Vect2f(), initialFrequency, initialFrequency)),
		basisGenerator(baseGenerator),
		octaves(numOctaves),
		frequencyMultiplier(math::FloatOps::Max(0.1f, deltaFreq)),
		amplitudeMultiplier(math::FloatOps::Clamp(deltaAmp, 0.001f, 1.0f)),
		deltaOrigin()
	{
	}

	// Initialize a new Fractial Generator given the initial sampling space, number of octaves, frequency change, and amplitude change
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace, const unsigned int numOctaves, const float deltaFreq, const float deltaAmp) :
		Generator(0u, newSampleSpace),
		basisGenerator(baseGenerator),
		octaves(numOctaves),
		frequencyMultiplier(math::FloatOps::Max(0.1f, deltaFreq)),
		amplitudeMultiplier(math::FloatOps::Clamp(deltaAmp, 0.001f, 1.0f)),
		deltaOrigin()
	{
	}

	// Initialize a new Fractial Generator given a starting frequency, number of octaves, frequency change, amplitude change, and ss-origin change
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const float initialFrequency, const unsigned int numOctaves, const float deltaFreq, const float deltaAmp, const Vect2f& deltaSampleOrigin) :
		Generator(0u, util::SampleSpace(Vect2f(), initialFrequency, initialFrequency)),
		basisGenerator(baseGenerator),
		octaves(numOctaves),
		frequencyMultiplier(math::FloatOps::Max(0.1f, deltaFreq)),
		amplitudeMultiplier(math::FloatOps::Clamp(deltaAmp, 0.001f, 1.0f)),
		deltaOrigin(deltaSampleOrigin)
	{
	}
	
	// Initialize a new Fractial Generator given the initial sampling space, number of octaves, frequency change, amplitude change, and ss-origin change
	FractalGenerator::FractalGenerator(abstract::Generator& baseGenerator, const util::SampleSpace& newSampleSpace, const unsigned int numOctaves, const float deltaFreq, const float deltaAmp, const Vect2f& deltaSampleOrigin) :
		Generator(0u, newSampleSpace),
		basisGenerator(baseGenerator),
		octaves(numOctaves),
		frequencyMultiplier(math::FloatOps::Max(0.1f, deltaFreq)),
		amplitudeMultiplier(math::FloatOps::Clamp(deltaAmp, 0.001f, 1.0f)),
		deltaOrigin(deltaSampleOrigin)
	{
	}



	// VIRTUAL
	// Dtor
	FractalGenerator::~FractalGenerator()
	{
	}




	// VIRTUAL OVERRIDE
	// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
	const NormalizedValue FractalGenerator::CustomGetAt(const Vect2f& sampleSpacePosition)
	{
		Vect2f currPosition = sampleSpacePosition;		// Before offsetting
		Vect2f currPositionOffsetted = currPosition;	// After offsetting
		NormalizedValue totalOutput;
		NormalizedValue currOutput;
		float currAmplitude = 1.0f;

		// Call the base generator for the defined amount of octaves
		for (unsigned int i = 1; i <= this->octaves; i++)
		{
			// Sample current octave
			currOutput = this->basisGenerator.GetAt(currPositionOffsetted);
			
			// Apply amplitude and add to total
			currOutput *= currAmplitude;
			totalOutput += currOutput;

			// Change the frequency, amplitude and sample space offset for the next octave
			currPosition *= this->frequencyMultiplier;
			currAmplitude *= this->amplitudeMultiplier;
			currPositionOffsetted = currPosition + this->deltaOrigin.GetScaled((float)i);
		}

		return totalOutput;
	}



	// VIRTUAL OVERRIDE
	// Compute a sum of octaves of prodecural values given the texture space
	const NormalizedValue FractalGenerator::GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions)
	{
		// Transform the texel position from texture space to this generator's sampling space
		const Vect2f samplePosition = this->GetSamplingSpaceReference().FromTextureToSampleSpace(texturePosition, textureDimensions);

		// Sample the generator function at that sample-space position
		return this->GetAt(samplePosition);
	}

	

	// VIRTUAL OVERRIDE
	// Does not do anything for FractalGenerator
	void FractalGenerator::OnSeedChange(const unsigned int newSeed)
	{
		// Intentionaly does nothing
		newSeed;
	}







}