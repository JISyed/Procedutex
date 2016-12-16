#include "procedutex\elements\PerlinNoise.h"
#include "procedutex\math\FloatOperations.h"
#include "procedutex\random\RandomNumberEngines.h"

#define P_1CYCLE (256)
#define P_2CYCLES (512)


//
// C Helper Routines
//
namespace chelp
{
	// Swap the values of a and b
	static void swap(int& a, int& b)
	{
		const int temp = a;
		a = b;
		b = temp;
	}

	// Credit: http://www.geeksforgeeks.org/shuffle-a-given-array/
	static void randomShuffle(int* const intArray, const int size, const unsigned int seed)
	{
		// New random engine with given seed
		std::mt19937 rnd(seed);

		// Start from last element and swap one by one
		for (int i = size - 1, j; i > 0; i--)
		{
			// Get a random index between 0 and i
			j = rnd() % (i + 1);

			// Swap a[i] with a[j]
			chelp::swap(intArray[i], intArray[j]);
		}
	}
}



namespace procedutex
{
	// Initialize this Perlin Noise Generator with a new seed
	PerlinNoise::PerlinNoise(const unsigned int newSeed) :
		SingleGenerator(newSeed, util::SampleSpace()),
		p(new int[P_2CYCLES])
	{
		this->OnSeedChange(newSeed);
	}

	// Initialize this Perlin Noise Generator with a new seed and sample space
	PerlinNoise::PerlinNoise(const unsigned int newSeed, const util::SampleSpace& newSampleSpace) :
		SingleGenerator(newSeed, newSampleSpace),
		p(new int[P_2CYCLES])
	{
		this->OnSeedChange(newSeed);
	}

	// VIRTUAL
	// Dtor
	PerlinNoise::~PerlinNoise()
	{
		if (this->p != nullptr)
		{
			delete[] this->p;
		}
	}


	// VIRTUAL OVERRIDE
	// Custom logic for calculating a procedural value given a position in sample space. A noise algorithm would be implemented here.
	const NormalizedValue PerlinNoise::CustomGetAt(const Vect2f& sampleSpacePosition)
	{
		// The improved Perlin noise taken from: http://cs.nyu.edu/~perlin/noise/

		float x = sampleSpacePosition.x;
		float y = sampleSpacePosition.y;
		float z = 0.0f;

		// Find the unit cube that contains the point (value has to be less than 255)
		int X = math::FloatOps::Floori(x) & 0xFF;
		int Y = math::FloatOps::Floori(y) & 0xFF;
		int Z = math::FloatOps::Floori(z) & 0xFF;

		// Find relative x, y,z of point in cube
		x -= math::FloatOps::Floorf(x);
		y -= math::FloatOps::Floorf(y);
		z -= math::FloatOps::Floorf(z);

		// Compute fade curves for each of x, y, z (for gradient lerping)
		const float u = math::FloatOps::Smoothstep5th(x);
		const float v = math::FloatOps::Smoothstep5th(y);
		const float w = math::FloatOps::Smoothstep5th(z);

		// Hash coordinates of the 8 cube corners
		const int A =  p[X]     + Y;
		const int B =  p[X + 1] + Y;
		const int AA = p[A]     + Z;
		const int AB = p[A + 1] + Z;
		const int BA = p[B]     + Z;
		const int BB = p[B + 1] + Z;

		// Add blended results from 8 corners of cube (w lerps v and v lerps u)
		const float result = math::FloatOps::Lerp(math::FloatOps::Lerp(math::FloatOps::Lerp(GetGradientDirection(p[AA],     x,      y,      z    ),
																							GetGradientDirection(p[BA],     x - 1,  y,      z    ),
																							u) ,
																	   math::FloatOps::Lerp(GetGradientDirection(p[AB],     x,      y - 1,  z    ),
																							GetGradientDirection(p[BB],     x - 1,  y - 1,  z    ),
																							u),
																	   v),
												  math::FloatOps::Lerp(math::FloatOps::Lerp(GetGradientDirection(p[AA + 1], x,      y,      z - 1),
																							GetGradientDirection(p[BA + 1], x - 1,  y,      z - 1),
																							u),
																	   math::FloatOps::Lerp(GetGradientDirection(p[AB + 1], x,      y - 1,  z - 1),
																							GetGradientDirection(p[BB + 1], x - 1,  y - 1,  z - 1),
																							u),
																	   v),
												  w);

		// Result is a value between -1.0f and 1.0f
		return NormalizedValue(result);
	}




	// VIRTUAL OVERRIDE
	// Custom logic for determine how a generator should handle the changing of its random seed
	void PerlinNoise::OnSeedChange(const unsigned int newSeed)
	{
		// Redefine the permutation array when the seed changes
		// Credit to sol-prog: https://github.com/sol-prog/Perlin_Noise/blob/master/PerlinNoise.cpp 

		// Fill p with values 0 to 255 in increasing order (iota is greek letter)
		for (int i = 0; i < P_1CYCLE; i++)
		{
			this->p[i] = i;
		}

		// Shuffle the values in the permutation array
		chelp::randomShuffle(this->p, P_1CYCLE, newSeed);

		// Duplicate the permutation array (from 256 to 512 exclusive)
		for (int i = P_1CYCLE; i < P_2CYCLES; i++)
		{
			this->p[i] = this->p[i - P_1CYCLE];
		}
	}





	// Convert the given sample point into one of the 12 gradient directions (taken from Perlin's improved noise)
	const float PerlinNoise::GetGradientDirection(const int hash, const float x, const float y, const float z)
	{
		// We are actually using a hash based off the lowest 4 bits of our given hash
		const int realHash = hash & 0xF;

		// Compute the gradient based off the sample coordinate
		const float u = (realHash < 0x8) ? (x) : (y);
		const float v = (realHash < 0x4) ? (y) : ((realHash == 0xC || realHash == 0xE) ? (x) : (z));

		// Compute the gradient direction from the hash
		return (((realHash & 0x1) == 0) ? (u) : (-u)) + (((realHash & 0x2) == 0) ? (v) : (-v));
	}




} // end namespace procedutex