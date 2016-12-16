#pragma once
#include "procedutex\elements\InputModifier.h"
#include "procedutex\types\Vect2f.h"

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Input Modifier Elements
	namespace inmods
	{
		// An Input Modifier that translates the input
		class TranslateInMod : public abstract::InputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			TranslateInMod(const Vect2f& newTranslation);
			virtual ~TranslateInMod();


			//
			// Contracts
			//

			// Take in the original input and modify it
			virtual const Vect2f Modify(const Vect2f& originalInput) override;



		private:

			//
			// Data
			//

			Vect2f translation;




			//
			// Deleted Methods
			//

			// No Default Ctor
			TranslateInMod() = delete;

		};
	}
}