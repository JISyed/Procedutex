#include "procedutex\elements\ConstantGenerator.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	// Float Ctor. The "constantOutput" will be clamped to the defined range of NormalizedValue
	ConstantGenerator::ConstantGenerator(const float constantOutput) :
		SingleGenerator(0u),
		constantValue(constantOutput)
	{
	}

	// NormalizedValue Ctor
	ConstantGenerator::ConstantGenerator(const NormalizedValue constantOutput) :
		SingleGenerator(0u),
		constantValue(constantOutput)
	{
	}

	// VIRTUAL
	// Dtor
	ConstantGenerator::~ConstantGenerator()
	{
	}


	// VIRTUAL OVERRIDE
	// Generate the same constant value defined to this generator (position doesn't matter)
	const NormalizedValue ConstantGenerator::CustomGetAt(const Vect2f& sampleSpacePosition)
	{
		sampleSpacePosition;
		return this->constantValue;
	}

	// VIRTUAL OVERRIDE
	// Generate the same constant value defined to this generator (position doesn't matter)
	const NormalizedValue ConstantGenerator::GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions)
	{
		texturePosition; textureDimensions;
		return this->constantValue;
	}

	// VIRTUAL OVERRIDE
	// Doesn't do anything for the ConstantGenerator
	void ConstantGenerator::OnSeedChange(const unsigned int newSeed)
	{
		newSeed; // Intentionally does nothing in a ConstantGenerator
	}


	// Get the constant value always returned by this generator
	const float ConstantGenerator::GetConstantValue() const
	{
		return this->constantValue.GetRawValue();
	}

	// Set a new constant value for this generator to return
	void ConstantGenerator::SetConstantValue(const float newConstantValue)
	{
		this->constantValue.SetRawValueManually(newConstantValue);
	}


}