#pragma once
#include "procedutex\types\Vect2f.h"
#include "procedutex\types\Vect2ui.h"
#include "procedutex\types\NormalizedValue.h"
#include "procedutex\utilities\SampleSpace.h"
#include "procedutex\utilities\TextureDimensions.h"
#include "procedutex\utilities\InputModifierList.h"
#include "procedutex\utilities\OutputModifierList.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes that must be inherited to be usable
	namespace abstract
	{
		// Abstract class for procedural value generators
		class Generator
		{
		public:

			//
			// Ctors + Dtor
			//

			// Initialize the base Generator with a new seed
			Generator(const unsigned int newSeed);

			// Initialize the base Generator with a new seed and sample space
			Generator(const unsigned int newSeed, const util::SampleSpace& newSampleSpace);
			
			// Dtor
			virtual ~Generator();



			//
			// Contracts
			//


			// Generate a procedural value at a given position in texture space.
			virtual const NormalizedValue GetAtTexel(const Vect2ui& texturePosition, const util::TextureDimensions& textureDimensions) = 0;



			//
			// Methods
			//

			// Generate a procedural value at a given position in sample space. This is completely independent of texture boundaries so it can be used for anything
			const NormalizedValue GetAt(const Vect2f& sampleSpacePosition);

			// Add an Input Modifier instance into the internal list of input modifications (now owned by this Generator)
			void AddInputModifier(inmods::abstract::InputModifier* const newInputModifier);

			// Add an Output Modifier instance into the internal list of output modifications (now owned by this Generator)
			void AddOutputModifier(outmods::abstract::OutputModifier* const newOutputModifier);



			//
			// Accessors
			//

			// Get the sampling space of this generator. Used in texture generation
			const util::SampleSpace GetSamplingSpace() const;

			// Set the sample space dimensions to be used to generate a texture
			void SetSamplingSpace(const util::SampleSpace& newSamplingSpace);


			// Set the origin of this generator's sample space. Used in texture generation
			const Vect2f GetSamplingOrigin() const;

			// Set the sample space origin to be used to generate a texture
			void SetSamplingOrigin(const Vect2f& newOrigin);


			// Get the seed used to determine the random sequence of this generator
			const unsigned int GetSeed() const;

			// Set a new random seed for this generator. Will automatically call Generator::OnSeedChange() afterward
			void SetSeed(const unsigned int newSeed);




		protected:


			//
			// Protected Contracts
			// 

			// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
			virtual const NormalizedValue CustomGetAt(const Vect2f& sampleSpacePosition) = 0;

			// Custom logic for determine how a generator should handle the changing of its random seed
			virtual void OnSeedChange(const unsigned int newSeed) = 0;




			//
			// Protected Accessors
			//

			// Get the sample space as a reference. Used by child classes
			const util::SampleSpace& GetSamplingSpaceReference() const;




		private:

			//
			// Data
			//

			util::SampleSpace samplingSpace;				// The sample space of the generator (aka "noise" space)
			unsigned int seed;								// The random seed of this generator
			modutil::InputModifierList inputModifiers;		// A list of all input modifiers in this Generator
			//std::list<OutModNode> outputModifiers;		// A list of all output modifiers in this Generator
			modutil::OutputModifierList outputModifiers;	// A list of all output modifiers in this Generator



			//
			// Deleted Methods
			//

			// No default ctor
			Generator() = delete;

		};
	}
}