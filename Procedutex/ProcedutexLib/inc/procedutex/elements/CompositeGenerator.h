#pragma once
#include "procedutex\elements\Generator.h"
#include "procedutex\elements\Combiner.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Generator that combines the values of two other Generators using a Combiner
	class CompositeGenerator : public abstract::Generator
	{
	public:
		CompositeGenerator(abstract::Generator* const firstGen, abstract::Generator* const secondGen, combiners::abstract::Combiner* const newCombiner);
		virtual ~CompositeGenerator();


		//
		// Contracts
		//


		// Generate a procedural value at a given position in texture space.
		virtual const NormalizedValue GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions) override;



	protected:

		//
		// Protected Contracts
		// 

		// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
		virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) override;

		// Custom logic for determine how a generator should handle the changing of its random seed
		virtual void OnSeedChange(const unsigned int newSeed) override;


	private:

		//
		// Data
		//

		abstract::Generator* firstGenerator;
		abstract::Generator* secondGenerator;
		combiners::abstract::Combiner* outputCombiner;


		//
		// Deleted Methods
		//

		CompositeGenerator() = delete;
		CompositeGenerator(const CompositeGenerator& other) = delete;
		CompositeGenerator& operator=(const CompositeGenerator& other) = delete;

	};

	
}