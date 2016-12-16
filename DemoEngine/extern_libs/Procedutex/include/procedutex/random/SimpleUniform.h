#pragma once
#include "EngineBase.h"
#include <random>

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in generating random numbers
	namespace random
	{
		// A random number generator that uses simple LGC algorithms with uniform distribution
		class SimpleUniform : public abstract::RandomEngine
		{
		public:
			// Ctor: Make a new generator with a pre-assigned seed
			SimpleUniform(const unsigned int newSeed);
			virtual ~SimpleUniform();

			// Get a random integer between "min" and "max"
			virtual const int GetInt(const int min, const int max) override;

			// Get a random unsigned char between "min" and "max"
			virtual const unsigned char GetByte(const unsigned char min, const unsigned char max);

			// Get a random floating point number between "min" and "max"
			virtual const float GetFloat(const float min, const float max) override;

			// Get a random normalized value between 0.0 and 1.0
			virtual const float GetNormalized() override;



			// Get the current seed of this generator
			virtual const unsigned int GetSeed() const override;

			// Set a new seed for this generator. NOTICE: reinitializes the generator's internal state
			virtual void SetSeed(const unsigned int newSeed) override;

			// Skip a given amount of random generation iterations. Equivalent to generating but discarding numbers.
			virtual void SkipIterations(const unsigned int itersToSkip) override;



		private:

			std::minstd_rand randomEngine;	// The "minimum standard" LCG number generator
			unsigned int seed;				// The current seed


			// No default Ctor
			SimpleUniform() = delete;

			// No Copy
			SimpleUniform(const SimpleUniform& other) = delete;
			// No Copy
			SimpleUniform& operator=(const SimpleUniform& other) = delete;

			// No Move
			SimpleUniform(SimpleUniform&& other) = delete;
			// No Move
			SimpleUniform& operator=(SimpleUniform&& other) = delete;
		};
	}
}