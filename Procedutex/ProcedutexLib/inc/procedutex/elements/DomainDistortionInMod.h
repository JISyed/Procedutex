#pragma once
#include "procedutex\elements\InputModifier.h"
#include "procedutex\elements\Generator.h"


// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Input Modifier Elements
	namespace inmods
	{
		// An Input Modifier that translates the input
		class DomainDistortionInMod : public abstract::InputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			DomainDistortionInMod(procedutex::abstract::Generator* const newDistortGenerator, const float shift, const float strength);
			virtual ~DomainDistortionInMod();


			//
			// Contracts
			//

			// Take in the original input and modify it
			virtual const Vect2f Modify(const Vect2f& originalInput) override;



		private:

			//
			// Data
			//

			procedutex::abstract::Generator* distortionGenerator;
			float distortShift;
			float distortStrength;



			//
			// Deleted Methods
			//

			// No Default Ctor
			DomainDistortionInMod() = delete;

		};
	}
}