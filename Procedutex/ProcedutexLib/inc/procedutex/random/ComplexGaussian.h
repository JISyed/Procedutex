#pragma once
#include "EngineBase.h"
#include <random>

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in generating random numbers
	namespace random
	{
		// A random number generator that uses sophisticated Mersenne Twister algorithm with Gaussian (bell-curve) distribution
		class ComplexGaussian : public abstract::RandomEngine
		{
		public:
			// Ctor: Make a new generator with a pre-assigned seed
			ComplexGaussian(const unsigned int newSeed);
			virtual ~ComplexGaussian();

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
			ComplexGaussian() = delete;

			// No Copy
			ComplexGaussian(const ComplexGaussian& other) = delete;
			// No Copy
			ComplexGaussian& operator=(const ComplexGaussian& other) = delete;

			// No Move
			ComplexGaussian(ComplexGaussian&& other) = delete;
			// No Move
			ComplexGaussian& operator=(ComplexGaussian&& other) = delete;
		};
	}
}