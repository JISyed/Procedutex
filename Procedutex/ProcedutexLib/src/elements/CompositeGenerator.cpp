#include "procedutex\elements\CompositeGenerator.h"
#include <cassert>

namespace procedutex
{
	CompositeGenerator::CompositeGenerator(abstract::Generator* const firstGen, abstract::Generator* const secondGen, combiners::abstract::Combiner* const newCombiner) :
		Generator(0u),
		firstGenerator(firstGen),
		secondGenerator(secondGen),
		outputCombiner(newCombiner)
	{
		assert(firstGen != nullptr);
		assert(secondGen != nullptr);
		assert(newCombiner != nullptr);
	}

	// VIRTUAL
	CompositeGenerator::~CompositeGenerator()
	{
		delete this->outputCombiner;
	}


	// VIRTUAL OVERRIDE
	// Generate a procedural value at a given position in texture space.
	const NormalizedValue CompositeGenerator::GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions)
	{
		// Transform the texel position from texture space to the generators' sampling space,
		// Then generate their respective outputs
		const NormalizedValue firstOutput = this->firstGenerator->GetAtTexel(texturePosition, textureDimensions);
		const NormalizedValue secondOutput = this->secondGenerator->GetAtTexel(texturePosition, textureDimensions);

		// Combine the two outputs as defined by the Combiner
		return this->outputCombiner->Combine(firstOutput, secondOutput);
	}


	// VIRTUAL OVERRIDE
	// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
	const NormalizedValue CompositeGenerator::CustomGetAt(const Vect2f& sampleSpacePosition)
	{
		// Calculate the outputs of both generators
		const NormalizedValue firstOutput = this->firstGenerator->GetAt(sampleSpacePosition);
		const NormalizedValue secondOutput = this->secondGenerator->GetAt(sampleSpacePosition);

		// Combine the two outputs as defined by the Combiner
		return this->outputCombiner->Combine(firstOutput, secondOutput);
	}


	// VIRTUAL OVERRIDE
	// Custom logic for determine how a generator should handle the changing of its random seed
	void CompositeGenerator::OnSeedChange(const unsigned int newSeed)
	{
		// Intentionally does nothing
		newSeed;
	}


}