#include "procedutex\random\ColorUtil.h"

namespace procedutex
{
	namespace random
	{
		// STATIC
		// Get a random color
		const Color4f ColorUtil::GetRandomColor(abstract::RandomEngine& rnd)
		{
			return Color4f(rnd.GetNormalized(), rnd.GetNormalized(), rnd.GetNormalized());
		}

		// STATIC
		// Get a random color with a random alpha
		const Color4f ColorUtil::GetRandomColorWithAlpha(abstract::RandomEngine& rnd)
		{
			return Color4f(rnd.GetNormalized(), rnd.GetNormalized(), rnd.GetNormalized(), rnd.GetNormalized());
		}

		// STATIC
		// Get a random color, where each of the color channels has a custom range
		const Color4f ColorUtil::GetRandomColor(abstract::RandomEngine& rnd, const float rMin, const float rMax, const float gMin, const float gMax, const float bMin, const float bMax)
		{
			return Color4f(rnd.GetFloat(rMin, rMax), rnd.GetFloat(gMin, gMax), rnd.GetFloat(bMin, bMax));
		}

		// STATIC
		// Get a random color with a random alpha, where each of the color channels has a custom range
		const Color4f ColorUtil::GetRandomColorWithAlpha(abstract::RandomEngine& rnd, const float rMin, const float rMax, const float gMin, const float gMax, const float bMin, const float bMax, const float aMin, const float aMax)
		{
			return Color4f(rnd.GetFloat(rMin, rMax), rnd.GetFloat(gMin, gMax), rnd.GetFloat(bMin, bMax), rnd.GetFloat(aMin, aMax));
		}

		// STATIC
		// Get a random color, where every color channel has the same custom range
		const Color4f ColorUtil::GetRandomColor(abstract::RandomEngine& rnd, const float everyMin, const float everyMax)
		{
			return Color4f(rnd.GetFloat(everyMin, everyMax), rnd.GetFloat(everyMin, everyMax), rnd.GetFloat(everyMin, everyMax));
		}

		// STATIC
		// Get a random color with a random alpha, where every color channel has the same custom range
		const Color4f ColorUtil::GetRandomColorWithAlpha(abstract::RandomEngine& rnd, const float everyMin, const float everyMax)
		{
			return Color4f(rnd.GetFloat(everyMin, everyMax), rnd.GetFloat(everyMin, everyMax), rnd.GetFloat(everyMin, everyMax), rnd.GetFloat(everyMin, everyMax));
		}










		// STATIC
		// Get a random grayscale shade
		const Color4f ColorUtil::GetRandomGrayscale(abstract::RandomEngine& rnd)
		{
			return Color4f(rnd.GetNormalized());
		}

		// STATIC
		// Get a random grayscale shade with a random alpha
		const Color4f ColorUtil::GetRandomGrayscaleWithAlpha(abstract::RandomEngine& rnd)
		{
			return Color4f(rnd.GetNormalized(), rnd.GetNormalized());
		}

		// STATIC
		// Get a random grayscale shade, with a custom grayscale range
		const Color4f ColorUtil::GetRandomGrayscale(abstract::RandomEngine& rnd, const float grayMin, const float grayMax)
		{
			return Color4f(rnd.GetFloat(grayMin, grayMax));
		}

		// STATIC
		// Get a random grayscale shade with a random alpha, where they both have a custom range
		const Color4f ColorUtil::GetRandomGrayscaleWithAlpha(abstract::RandomEngine& rnd, const float grayMin, const float grayMax, const float alphaMin, const float alphaMax)
		{
			return Color4f(rnd.GetFloat(grayMin, grayMax), rnd.GetFloat(alphaMin, alphaMax));
		}

	}
}