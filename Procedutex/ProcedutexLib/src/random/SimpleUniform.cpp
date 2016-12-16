#include "procedutex\random\SimpleUniform.h"
#include <cassert>

namespace procedutex
{
	namespace random
	{
		SimpleUniform::SimpleUniform(const unsigned int newSeed) :
			randomEngine(newSeed),
			seed(newSeed)
		{
		}

		// VIRTUAL
		SimpleUniform::~SimpleUniform()
		{
		}



		// VIRTUAL
		// Get a random integer between "min" and "max"
		const int SimpleUniform::GetInt(const int min, const int max)
		{
			// Min must be less than Max!
			assert(min < max);
			return std::uniform_int_distribution<int>{min, max}(this->randomEngine);
		}

		// VIRTUAL
		// Get a random unsigned char between "min" and "max"
		const unsigned char SimpleUniform::GetByte(const unsigned char min, const unsigned char max)
		{
			// Min must be less than Max!
			assert(min < max);
			return (unsigned char)std::uniform_int_distribution<unsigned short>{(unsigned short)min, (unsigned short)max}(this->randomEngine);
		}

		// VIRTUAL
		// Get a random floating point number between "min" and "max"
		const float SimpleUniform::GetFloat(const float min, const float max)
		{
			// Min must be less than Max!
			assert(min < max);
			return std::uniform_real_distribution<float>{min, max}(this->randomEngine);
		}

		// VIRTUAL
		// Get a random normalized value between 0.0 and 1.0
		const float SimpleUniform::GetNormalized()
		{
			return this->GetFloat(0.0f, 1.0f);
		}




		// VIRTUAL
		// Get the current seed of this generator
		const unsigned int SimpleUniform::GetSeed() const
		{
			return this->seed;
		}

		// VIRTUAL
		// Set a new seed for this generator. NOTICE: reinitializes the generator's internal state
		void SimpleUniform::SetSeed(const unsigned int newSeed)
		{
			this->seed = newSeed;
			this->randomEngine.seed(newSeed);
		}

		// VIRTUAL
		// Skip a given amount of random generation iterations. Equivalent to generating but discarding numbers.
		void SimpleUniform::SkipIterations(const unsigned int itersToSkip)
		{
			this->randomEngine.discard(itersToSkip);
		}
	}
}