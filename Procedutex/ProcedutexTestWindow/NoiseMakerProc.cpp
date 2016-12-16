#include "NoiseMakerProc.h"
#include <cassert>
#include <iostream>

#include "procedutex\random\RandomNumberEngines.h"
#include "procedutex\random\ColorUtil.h"
#include "procedutex\math\IntegerOperations.h"
#include "procedutex\math\FloatOperations.h"
#include "procedutex\math\Consts.h"

#include "procedutex\elements\ConstantGenerator.h"
#include "procedutex\elements\PerlinNoise.h"
#include "procedutex\elements\FractalGenerator.h"
#include "procedutex\elements\CompositeGenerator.h"

#include "procedutex\utilities\GrayscaleConverter.h"
#include "procedutex\utilities\GradientConverter.h"

#include "procedutex\elements\DomainDistortionInMod.h"
#include "procedutex\elements\AbsOutMod.h"
#include "procedutex\elements\CustomFunctionOutMod.h"
#include "procedutex\elements\GainOutMod.h"
#include "procedutex\elements\BinarizeOutMod.h"
#include "procedutex\elements\InvertOutMod.h"

#include "procedutex\elements\AddCombiner.h"
#include "procedutex\elements\MultiplyCombiner.h"
#include "procedutex\elements\MinCombiner.h"
#include "procedutex\elements\MaxCombiner.h"


// Random number generator for the whole file
static const unsigned int theSeed = 69786u;
static std::random_device seedMaker;
static procedutex::random::ComplexUniform randGen(theSeed);



//////////////////// MAIN ROUTINE CONTROL
// All texture generation routines are routed in this method
void NoiseMakerProc::operator()()
{
	this->AllocateTexture1(512, TextureFilterType::Bilinear);
	this->AllocateTexture2(128, TextureFilterType::Bilinear);
	this->AllocateTexture3(128, TextureFilterType::Bilinear);
	this->AllocateTexture4(128, TextureFilterType::Bilinear);
}



///////////////////// 1
// Procedure to generate texture 1 (this can always change)
void NoiseMakerProc::GenerateTexture1ColorMap(procedutex::util::TextureBuffer2d& imageData)
{
	procedutex::PerlinNoise perlin(randGen.GetInt(23, 12355));

	procedutex::FractalGenerator fBm(perlin, 2.0f, 8u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f));
	fBm.SetSamplingOrigin({34.65f, 239.35f});

	fBm.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
		new procedutex::FractalGenerator(perlin, 2.0f, 8u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f)),
		10.5f,
		0.4f)
		);

	//fBm.AddOutputModifier(new procedutex::outmods::AbsOutMod());
	//fBm.AddOutputModifier(new procedutex::outmods::GainOutMod(0.5f));
	//fBm.AddOutputModifier(new procedutex::outmods::BinarizeOutMod(0.0f));
	fBm.AddOutputModifier(new procedutex::outmods::InvertOutMod());
	/*
	fBm.AddOutputModifier(new procedutex::outmods::CustomFunctionOutMod(
	[] (float n)->float
	{
	//const float n2 = 2.0f * n;
	//return n2 - procedutex::math::FloatOps::Floorf(n2);
	return -1.0f * procedutex::math::FloatOps::Abs(n);
	}
	));
	//*/

	procedutex::Gradient theColorGradient;
	theColorGradient.Insert(procedutex::Color4f::Black, procedutex::NormalizedValue(-1.0f));
	//theColorGradient.Insert(procedutex::Color4f::Black, procedutex::NormalizedValue(0.0f));
	theColorGradient.Insert(procedutex::Color4f::White, procedutex::NormalizedValue(1.0f));
	procedutex::util::GradientConverter conv(theColorGradient);

	imageData.Generate(fBm, conv);
}


///////////////////// 2
// Procedure to generate texture 2 (this can always change)
void NoiseMakerProc::GenerateTexture2ColorMap(procedutex::util::TextureBuffer2d& imageData)
{
	procedutex::PerlinNoise perlin(randGen.GetInt(23, 12355));

	procedutex::FractalGenerator fBm(perlin, procedutex::util::SampleSpace({0, 0}, 3.0f, 3.0f), 7u, 2.2f, 0.55f, procedutex::Vect2f(1.0f, 1.0f));
	fBm.SetSamplingOrigin({34.65f, 239.35f});

	fBm.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
		new procedutex::FractalGenerator(perlin, 2.0f, 7u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f)),
		10.5f,
		0.4f)
		);

	fBm.AddOutputModifier(new procedutex::outmods::InvertOutMod());

	// Earth gradient
	procedutex::Gradient theColorGradient;
	theColorGradient.Insert(procedutex::Color4f(5.0f / 255.0f, 28.0f / 255.0f, 75.0f / 255.0f), procedutex::NormalizedValue(-1.0f));			// Distant Waters
	theColorGradient.Insert(procedutex::Color4f(6.0f / 255.0f, 81.0f / 255.0f, 106.0f / 255.0f), procedutex::NormalizedValue(-0.1f));			// Nearby Waters
	theColorGradient.Insert(procedutex::Color4f(7.0f / 255.0f, 172.0f / 255.0f, 217.0f / 255.0f), procedutex::NormalizedValue(-0.005f));		// Coast Waters
	theColorGradient.Insert(procedutex::Color4f(239.0f / 255.0f, 210.0f / 255.0f, 143.0f / 255.0f), procedutex::NormalizedValue(0.1f));		// Beach
	theColorGradient.Insert(procedutex::Color4f(98.0f / 255.0f, 132.0f / 255.0f, 66.0f / 255.0f), procedutex::NormalizedValue(0.25f));		// Savanna
	theColorGradient.Insert(procedutex::Color4f(80.0f / 255.0f, 129.0f / 255.0f, 55.0f / 255.0f), procedutex::NormalizedValue(0.4f));			// Grasslands
	theColorGradient.Insert(procedutex::Color4f(44.0f / 255.0f, 80.0f / 255.0f, 47.0f / 255.0f), procedutex::NormalizedValue(0.6f));			// Forest
	theColorGradient.Insert(procedutex::Color4f(97.0f / 255.0f, 76.0f / 255.0f, 65.0f / 255.0f), procedutex::NormalizedValue(0.8f));			// Mountain
	theColorGradient.Insert(procedutex::Color4f(1.0f, 1.0f, 1.0f), procedutex::NormalizedValue(1.0f));									// Snow
	procedutex::util::GradientConverter conv(theColorGradient);

	imageData.Generate(fBm, conv);
}


///////////////////// 3
// Procedure to generate texture 3 (this can always change)
void NoiseMakerProc::GenerateTexture3ColorMap(procedutex::util::TextureBuffer2d& imageData)
{
	procedutex::PerlinNoise perlin(randGen.GetInt(23, 12355));

	procedutex::FractalGenerator fBm(perlin, procedutex::util::SampleSpace({0, 0}, 2.0f, 2.0f), 8u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f));
	fBm.SetSamplingOrigin({34.65f, 239.35f});

	fBm.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
		new procedutex::FractalGenerator(perlin, 2.0f, 8u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f)),
		10.5f,
		0.4f)
		);

	fBm.AddOutputModifier(new procedutex::outmods::InvertOutMod());

	// Venus gradient
	procedutex::Gradient theColorGradient;
	theColorGradient.Insert(procedutex::Color4f(0.1f, 0.01f, 0.005f), procedutex::NormalizedValue(-1.0f));
	theColorGradient.Insert(procedutex::Color4f(1.0f, 0.9f, 0.001f), procedutex::NormalizedValue(0.7f));
	theColorGradient.Insert(procedutex::Color4f(1.0f, 1.0f, 1.0f), procedutex::NormalizedValue(1.0f));
	procedutex::util::GradientConverter conv(theColorGradient);

	imageData.Generate(fBm, conv);
}


///////////////////// 4
// Procedure to generate texture 4 (this can always change)
void NoiseMakerProc::GenerateTexture4ColorMap(procedutex::util::TextureBuffer2d& imageData)
{
	// Make long clouds
	procedutex::PerlinNoise cloudGen(randGen.GetInt(23, 12355));
	cloudGen.SetSamplingSpace(procedutex::util::SampleSpace(procedutex::Vect2f(32.5f, 45.4f), 4.0f, 24.0f));
	cloudGen.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
		new procedutex::PerlinNoise(randGen.GetInt(23, 12355)),
		11.5f,
		3.2f)
		);
	cloudGen.AddOutputModifier(new procedutex::outmods::CustomFunctionOutMod(
		[] (float n)->float
	{
		const float n2 = 1.0f * n;
		return n2 - procedutex::math::FloatOps::Floorf(n2);
	}
	));
	cloudGen.AddOutputModifier(new procedutex::outmods::InvertOutMod());


	// Use perlin noise to make a few jupiter-like spots
	procedutex::PerlinNoise spotGen(randGen.GetInt(234, 123545));
	spotGen.SetSamplingSpace(procedutex::util::SampleSpace(procedutex::Vect2f(22.2f, 0.1f), 4.0f, 9.5f));
	spotGen.AddOutputModifier(new procedutex::outmods::CustomFunctionOutMod(
		[] (float n)->float
	{
		const float upperThreshold = 0.5f;
		if (n > upperThreshold)
		{
			const float newLow = 0.01f;	// Must be less than upperThreshold
			return procedutex::math::FloatOps::Remap(n, upperThreshold, 1.0f, newLow, 1.0f);
		}

		return -1.0f;
	}
	));


	// The spots should have a higher noise value than the clouds to show up
	procedutex::CompositeGenerator jupiter(&cloudGen, &spotGen, new procedutex::combiners::MaxCombiner());


	// Jupiter gradient
	procedutex::Gradient theColorGradient;
	theColorGradient.Insert(procedutex::Color4f(95.0f / 255.0f, 76.0f / 255.0f, 69.0f / 255.0f), procedutex::NormalizedValue(-1.0f)); // Deep brownish-red clouds
	theColorGradient.Insert(procedutex::Color4f(192.0f / 255.0f, 132.0f / 255.0f, 76.0f / 255.0f), procedutex::NormalizedValue(-0.6f)); // Lower orange clouds
	theColorGradient.Insert(procedutex::Color4f(222.0f / 255.0f, 213.0f / 255.0f, 190.0f / 255.0f), procedutex::NormalizedValue(-0.01f)); // Higher tan clouds
	theColorGradient.Insert(procedutex::Color4f(1.0f, 1.0f, 1.0f), procedutex::NormalizedValue(-0.005f));							// border region
	theColorGradient.Insert(procedutex::Color4f(95.0f / 255.0f, 76.0f / 255.0f, 69.0f / 255.0f), procedutex::NormalizedValue(0.0f)); // Outer spot outer rim
	theColorGradient.Insert(procedutex::Color4f(229.0f / 255.0f, 202.0f / 255.0f, 189.0f / 255.0f), procedutex::NormalizedValue(0.2f)); // Outer spot inner rim
	theColorGradient.Insert(procedutex::Color4f(240.0f / 255.0f, 101.0f / 255.0f, 46.0f / 255.0f), procedutex::NormalizedValue(0.3f)); // Spot cyclone paremeter
	theColorGradient.Insert(procedutex::Color4f(192.0f / 255.0f, 52.0f / 255.0f, 36.0f / 255.0f), procedutex::NormalizedValue(0.4f)); // Spot cyclone middle
	theColorGradient.Insert(procedutex::Color4f(53.0f / 255.0f, 27.0f / 255.0f, 27.0f / 255.0f), procedutex::NormalizedValue(4.0f)); // Inner spot
	theColorGradient.Insert(procedutex::Color4f(114.0f / 255.0f, 57.0f / 255.0f, 48.0f / 255.0f), procedutex::NormalizedValue(1.0f)); // Spot Center
	procedutex::util::GradientConverter conv(theColorGradient);

	imageData.Generate(jupiter, conv);
}




















//
// Stuff that probably shouldn't change
//

////////////////////////////////
////////////////////////////////
// Texture allocation methods

void NoiseMakerProc::AllocateTexture1(const size_t imgSize, TextureFilterType filter)
{
	std::cout << "Generating Texture 1...\n";
	if (!procedutex::math::IntOps::IsPowerOf2(imgSize))
	{
		std::cout << "     Bad size:    " << imgSize << "x" << imgSize << std::endl;
		int newSize = procedutex::math::IntOps::GetNextPowerOf2((int)imgSize);
		std::cout << "     Changing to: " << newSize << "x" << newSize << std::endl;
	}
	procedutex::util::TextureBuffer2d imageData(imgSize, imgSize);
	this->GenerateTexture1ColorMap(imageData);
	this->textureSetter.SetupTexture1(imageData, filter);
}

void NoiseMakerProc::AllocateTexture2(const size_t imgSize, TextureFilterType filter)
{
	std::cout << "Generating Texture 2...\n";
	if (!procedutex::math::IntOps::IsPowerOf2(imgSize))
	{
		std::cout << "     Bad size:    " << imgSize << "x" << imgSize << std::endl;
		int newSize = procedutex::math::IntOps::GetNextPowerOf2((int)imgSize);
		std::cout << "     Changing to: " << newSize << "x" << newSize << std::endl;
	}
	procedutex::util::TextureBuffer2d imageData(imgSize, imgSize);
	this->GenerateTexture2ColorMap(imageData);
	this->textureSetter.SetupTexture2(imageData, filter);
}

void NoiseMakerProc::AllocateTexture3(const size_t imgSize, TextureFilterType filter)
{
	std::cout << "Generating Texture 3...\n";
	if (!procedutex::math::IntOps::IsPowerOf2(imgSize))
	{
		std::cout << "     Bad size:    " << imgSize << "x" << imgSize << std::endl;
		int newSize = procedutex::math::IntOps::GetNextPowerOf2((int)imgSize);
		std::cout << "     Changing to: " << newSize << "x" << newSize << std::endl;
	}
	procedutex::util::TextureBuffer2d imageData(imgSize, imgSize);
	this->GenerateTexture3ColorMap(imageData);
	this->textureSetter.SetupTexture3(imageData, filter);
}

void NoiseMakerProc::AllocateTexture4(const size_t imgSize, TextureFilterType filter)
{
	std::cout << "Generating Texture 4...\n";
	if (!procedutex::math::IntOps::IsPowerOf2(imgSize))
	{
		std::cout << "     Bad size:    " << imgSize << "x" << imgSize << std::endl;
		int newSize = procedutex::math::IntOps::GetNextPowerOf2((int)imgSize);
		std::cout << "     Changing to: " << newSize << "x" << newSize << std::endl;
	}
	procedutex::util::TextureBuffer2d imageData(imgSize, imgSize);
	this->GenerateTexture4ColorMap(imageData);
	this->textureSetter.SetupTexture4(imageData, filter);
}


// Ctor
NoiseMakerProc::NoiseMakerProc(AppTexturesSetter& textureCollectionSetter) :
	textureSetter(textureCollectionSetter)
{
}
