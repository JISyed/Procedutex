#pragma once
#include "procedutex\elements\OutputModifier.h"
#include <functional>

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of all Output Modifier Elements
	namespace outmods
	{
		// Typedef for float custom modification function (takes in a float, returns a float)
		typedef std::function<float(float)> CustomFunction;

		// An Output Mod that takes a custom functor [](float)->float{} to modify the generator output
		class CustomFunctionOutMod : public abstract::OutputModifier
		{
		public:

			//
			// Ctor + Dtor
			//

			CustomFunctionOutMod(const CustomFunction customModificationFunction);
			virtual ~CustomFunctionOutMod();



			//
			// Contracts
			//

			// Take in the original output and modify it
			virtual const NormalizedValue Modify(const NormalizedValue& originalOutput) override;


		private:

			//
			// Data
			//

			CustomFunction customLambda;	// The float(float) lambda to modify the output value



			//
			// Deleted
			//

			// No default ctor
			CustomFunctionOutMod() = delete;



		};
	}
}