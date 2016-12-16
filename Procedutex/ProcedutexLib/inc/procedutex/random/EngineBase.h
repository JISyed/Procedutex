#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// Collection of classes to aid in generating random numbers
	namespace random
	{
		// Collection of classes that must be inherited to be usable
		namespace abstract
		{
			// Abstract class to random number engines
			class RandomEngine
			{
			public:
				RandomEngine();
				virtual ~RandomEngine();

				// Get a random integer between "min" and "max"
				virtual const int GetInt(const int min, const int max) = 0;
				// Get a random unsigned char between "min" and "max"
				virtual const unsigned char GetByte(const unsigned char min, const unsigned char max) = 0;
				// Get a random floating point number between "min" and "max"
				virtual const float GetFloat(const float min, const float max) = 0;
				// Get a random normalized value between 0.0 and 1.0
				virtual const float GetNormalized() = 0;

				// Get the current seed of this generator
				virtual const unsigned int GetSeed() const = 0;
				// Set a new seed for this generator. NOTICE: reinitializes the generator's internal state
				virtual void SetSeed(const unsigned int newSeed) = 0;
				// Skip a given amount of random generation iterations. Equivalent to generating but discarding numbers.
				virtual void SkipIterations(const unsigned int itersToSkip) = 0;


			private:

				// No Copy
				RandomEngine(const RandomEngine& other) = delete;
				// No Copy
				RandomEngine& operator=(const RandomEngine& other) = delete;

				// No Move
				RandomEngine(RandomEngine&& other) = delete;
				// No Move
				RandomEngine& operator=(RandomEngine&& other) = delete;

			};
		}
	}
}