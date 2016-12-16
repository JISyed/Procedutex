#include "procedutex\random\EngineBase.h"
#include <random>

// Algorithm x Distribution x Data Type
// MT          Gaussian       Int
// MT          Gaussian       Float

// MT          Uniform        Int
// MT          Uniform        Float

// LGC          Gaussian       Int
// LGC          Gaussian       Float

// LGC          Uniform        Int
// LGC          Uniform        Float

namespace procedutex
{
	namespace random
	{
		namespace abstract
		{
			RandomEngine::RandomEngine()
			{
			}


			// VIRTUAL
			RandomEngine::~RandomEngine()
			{
			}
		}
	}
}