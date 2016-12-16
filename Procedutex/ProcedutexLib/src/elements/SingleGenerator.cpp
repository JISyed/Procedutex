#include "procedutex\elements\SingleGenerator.h"

namespace procedutex
{
	namespace abstract
	{
		// Initialize the Single Generator with a new seed
		SingleGenerator::SingleGenerator(const unsigned int newSeed) :
			Generator(newSeed)
		{
		}

		// Initialize the Single Generator with a new seed and sample space
		SingleGenerator::SingleGenerator(const unsigned int newSeed, const util::SampleSpace& newSampleSpace) :
			Generator(newSeed, newSampleSpace)
		{
		}

		// VIRTUAL
		// Dtor
		SingleGenerator::~SingleGenerator()
		{
		}



		// VIRTUAL OVERRIDE
		// Generate a procedural value at a given position in texture space
		const NormalizedValue SingleGenerator::GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions)
		{
			// Transform the texel position from texture space to this generator's sampling space
			const Vect2f samplePosition = this->GetSamplingSpaceReference().FromTextureToSampleSpace(texturePosition, textureDimensions);

			// Sample the generator function at that sample-space position
			return this->GetAt(samplePosition);
		}
	}
}