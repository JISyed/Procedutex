#include "procedutex\elements\TranslateInMod.h"

namespace procedutex
{
	namespace inmods
	{
		TranslateInMod::TranslateInMod(const Vect2f& newTranslation) :
			translation(newTranslation)
		{
		}

		// VIRTUAL
		TranslateInMod::~TranslateInMod()
		{
		}


		// VIRTUAL OVERRIDE
		// Take in the original input and modify it
		const Vect2f TranslateInMod::Modify(const Vect2f& originalInput)
		{
			return this->translation + originalInput;
		}

	}
}