#include "procedutex\random\SimpleGaussian.h"
#include <cassert>

namespace procedutex
{
	namespace random
	{
		SimpleGaussian::SimpleGaussian(const unsigned int newSeed) :
			randomEngine(newSeed),
			seed(newSeed)
		{
		}

		// VIRTUAL
		SimpleGaussian::~SimpleGaussian()
		{
		}



		// VIRTUAL
		// Get a random integer between "min" and "max"
		const int SimpleGaussian::GetInt(const int min, const int max)
		{
			// Min must be less than Max!
			assert(min < max);
			return std::binomial_distribution<int, float>{max - min, 0.5f}(this->randomEngine) + min;
		}

		// VIRTUAL
		// Get a random unsigned char between "min" and "max"
		const unsigned char SimpleGaussian::GetByte(const unsigned char min, const unsigned char max)
		{
			// Min must be less than Max!
			assert(min < max);
			return (unsigned char)std::binomial_distribution<unsigned short, float>{(unsigned short)(max - min), 0.5f}(this->randomEngine) + min;
		}

		// VIRTUAL
		// Get a random floating point number between "min" and "max"
		const float SimpleGaussian::GetFloat(const float min, const float max)
		{
			// Min must be less than Max!
			assert(min < max);
			const float n = std::normal_distribution<float>{(max + min) / 2.0f, 2.5f}(this->randomEngine);
			if (n < min)
			{
				return min;
			}
			else if (n > max)
			{
				return max;
			}
			return n;
		}

		// VIRTUAL
		// Get a random normalized value between 0.0 and 1.0
		const float SimpleGaussian::GetNormalized()
		{
			return this->GetFloat(0.0f, 1.0f);
		}




		// VIRTUAL
		// Get the current seed of this generator
		const unsigned int SimpleGaussian::GetSeed() const
		{
			return this->seed;
		}

		// VIRTUAL
		// Set a new seed for this generator. NOTICE: reinitializes the generator's internal state
		void SimpleGaussian::SetSeed(const unsigned int newSeed)
		{
			this->seed = newSeed;
			this->randomEngine.seed(newSeed);
		}

		// VIRTUAL
		// Skip a given amount of random generation iterations. Equivalent to generating but discarding numbers.
		void SimpleGaussian::SkipIterations(const unsigned int itersToSkip)
		{
			this->randomEngine.discard(itersToSkip);
		}
	}
}