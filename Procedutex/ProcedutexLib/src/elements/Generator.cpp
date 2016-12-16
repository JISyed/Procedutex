#include "procedutex\elements\Generator.h"
#include <cassert>

namespace procedutex
{
	namespace abstract
	{
		// Initialize the base Generator with a new seed
		Generator::Generator(const unsigned int newSeed) :
			samplingSpace(),
			seed(newSeed),
			inputModifiers(),
			outputModifiers()
		{
		}

		// Initialize the base Generator with a new seed and sample space
		Generator::Generator(const unsigned int newSeed, const util::SampleSpace& newSampleSpace) :
			samplingSpace(newSampleSpace),
			seed(newSeed),
			inputModifiers(),
			outputModifiers()
		{
		}
		
		// VIRTUAL
		// Dtor
		Generator::~Generator()
		{
			// Delete input modifiers
			this->inputModifiers.Clear();

			// Delete output modifiers
			this->outputModifiers.Clear();
		}


		// Generate a procedural value at a given position in sample space. This is completely independent of texture boundaries so it can be used for anything
		const NormalizedValue Generator::GetAt(const Vect2f& sampleSpacePosition)
		{
			// Modify input, if any modifiers exist
			Vect2f modifiedPosition = sampleSpacePosition;
			for (auto inModItr = this->inputModifiers.GetIterator(); !inModItr.IsDone(); inModItr.GoToNext())
			{
				modifiedPosition = inModItr.GetCurrent()->Modify(modifiedPosition);
			}

			// Call actual generator algorithm
			NormalizedValue output = this->CustomGetAt(modifiedPosition);

			// Modify output, if any modifiers exist
			for (auto outModItr = this->outputModifiers.GetIterator(); !outModItr.IsDone(); outModItr.GoToNext())
			{
				output = outModItr.GetCurrent()->Modify(output);
			}

			// Return final output
			return output;
		}


		// Get the sampling space of this generator. Used in texture generation
		const util::SampleSpace Generator::GetSamplingSpace() const
		{
			return this->samplingSpace;
		}

		// Set the sample space dimensions to be used to generate a texture
		void Generator::SetSamplingSpace(const util::SampleSpace& newSamplingSpace)
		{
			this->samplingSpace = newSamplingSpace;
		}

		// Get the seed used to determine the random sequence of this generator
		const unsigned int Generator::GetSeed() const
		{
			return this->seed;
		}

		// Set a new random seed for this generator. Will automatically call Generator::OnSeedChange() afterward
		void Generator::SetSeed(const unsigned int newSeed)
		{
			this->seed = newSeed;
			this->OnSeedChange(newSeed);
		}

		// Set the origin of this generator's sample space. Used in texture generation
		const Vect2f Generator::GetSamplingOrigin() const
		{
			return this->samplingSpace.GetOrigin();
		}

		// Set the sample space origin to be used to generate a texture
		void Generator::SetSamplingOrigin(const Vect2f& newOrigin)
		{
			this->samplingSpace.SetOrigin(newOrigin);
		}

		

		// Add an Input Modifier instance into the internal list of input modifications (now owned by this Generator)
		void Generator::AddInputModifier(inmods::abstract::InputModifier* const newInputModifier)
		{
			assert(newInputModifier != nullptr);

			this->inputModifiers.AddToBack(newInputModifier);
		}

		// Add an Output Modifier instance into the internal list of output modifications (now owned by this Generator)
		void Generator::AddOutputModifier(outmods::abstract::OutputModifier* const newOutputModifier)
		{
			assert(newOutputModifier != nullptr);

			this->outputModifiers.AddToBack(newOutputModifier);
		}





		// Get the sample space as a reference. Used by child classes
		const util::SampleSpace& Generator::GetSamplingSpaceReference() const
		{
			return this->samplingSpace;
		}
	}
}