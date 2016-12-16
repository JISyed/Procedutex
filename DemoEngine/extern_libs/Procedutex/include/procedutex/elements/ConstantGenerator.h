#pragma once
#include "procedutex\elements\SingleGenerator.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A Generator that only produces a constant value
	class ConstantGenerator final : public abstract::SingleGenerator
	{
	public:

		// Float Ctor. The "constantOutput" will be clamped to the defined range of NormalizedValue
		explicit ConstantGenerator(const float constantOutput);
		
		// NormalizedValue Ctor
		explicit ConstantGenerator(const NormalizedValue constantOutput);
		
		// Dtor
		virtual ~ConstantGenerator();

		
		// Generate the same constant value defined to this generator (position doesn't matter)
		virtual const NormalizedValue GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions) override;


		// Get the constant value always returned by this generator
		const float GetConstantValue() const;

		// Set a new constant value for this generator to return
		void SetConstantValue(const float newConstantValue);


	protected:

		// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
		virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) override;

		// Doesn't do anything for the ConstantGenerator
		virtual void OnSeedChange(const unsigned int newSeed) override;


	private:

		//
		// Data
		//

		NormalizedValue constantValue;	// The single value the this generator always outputs



		//
		// Deleted Methods
		//

		// No default ctor
		ConstantGenerator() = delete;

	};

	
}