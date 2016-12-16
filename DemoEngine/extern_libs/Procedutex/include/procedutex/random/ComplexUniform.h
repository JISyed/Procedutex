# pragma once
#include "EngineBase.h"
#include <random>

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in generating random numbers
	namespace random
	{
		// A random number generator that uses sophisticated Mersenne Twister algorithm with uniform distribution
		class ComplexUniform : public abstract::RandomEngine
		{
		public:
			// Ctor: Make a new generator with a pre-assigned seed
			ComplexUniform(const unsigned int newSeed);
			virtual ~ComplexUniform();

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

			std::mt19937 randomEngine;		// The Mersenne Twister number generator
			unsigned int seed;				// The current seed


			// No default Ctor
			ComplexUniform() = delete;

			// No Copy
			ComplexUniform(const ComplexUniform& other) = delete;
			// No Copy
			ComplexUniform& operator=(const ComplexUniform& other) = delete;

			// No Move
			ComplexUniform(ComplexUniform&& other) = delete;
			// No Move
			ComplexUniform& operator=(ComplexUniform&& other) = delete;
		};
	}
}