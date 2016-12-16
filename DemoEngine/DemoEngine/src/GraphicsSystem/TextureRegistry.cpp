#include "TextureRegistry.h"
#include <cassert>

#include "procedutex\random\RandomNumberEngines.h"
#include "procedutex\random\ColorUtil.h"
#include "procedutex\utilities\TextureBuffer2d.h"
#include "procedutex\types\Gradient.h"
#include "procedutex\math\FloatOperations.h"

#include "procedutex\elements\CompositeGenerator.h"
#include "procedutex\elements\PerlinNoise.h"
#include "procedutex\elements\FractalGenerator.h"
#include "procedutex\elements\ConstantGenerator.h"

#include "procedutex\elements\TranslateInMod.h"
#include "procedutex\elements\DomainDistortionInMod.h"

#include "procedutex\elements\InvertOutMod.h"
#include "procedutex\elements\BinarizeOutMod.h"
#include "procedutex\elements\GainOutMod.h"
#include "procedutex\elements\AbsOutMod.h"
#include "procedutex\elements\CustomFunctionOutMod.h"

#include "procedutex\elements\AddCombiner.h"
#include "procedutex\elements\MultiplyCombiner.h"
#include "procedutex\elements\MinCombiner.h"
#include "procedutex\elements\MaxCombiner.h"

#include "procedutex\utilities\GrayscaleConverter.h"
#include "procedutex\utilities\GradientConverter.h"


//////////////////////////////
//
// Procedural Texture Generation
//
//////////////////////////////

void CreateProceduralTextureSimple()
{
	procedutex::random::ComplexUniform rnd(89631);

	procedutex::util::TextureBuffer2d imageData(512, 1024);

	// BEGIN NOISE
	//*
	{
		procedutex::PerlinNoise perlin(rnd.GetInt(23, 12355));

		procedutex::FractalGenerator fBm(perlin, procedutex::util::SampleSpace({0,0}, 6.0f, 3.0f), 7u, 2.2f, 0.55f, procedutex::Vect2f(1.0f, 1.0f));
		fBm.SetSamplingOrigin({34.65f, 239.35f});

		fBm.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
			new procedutex::FractalGenerator(perlin, 2.0f, 7u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f)),
			10.5f,
			0.4f)
		);

		fBm.AddOutputModifier(new procedutex::outmods::InvertOutMod());

		// Earth gradient
		procedutex::Gradient theColorGradient;
		theColorGradient.Insert(procedutex::Color4f(5.0f/255.0f, 28.0f/255.0f, 75.0f/255.0f), procedutex::NormalizedValue(-1.0f));			// Distant Waters
		theColorGradient.Insert(procedutex::Color4f(6.0f/255.0f, 81.0f/255.0f, 106.0f/255.0f), procedutex::NormalizedValue(-0.1f));			// Nearby Waters
		theColorGradient.Insert(procedutex::Color4f(7.0f/255.0f, 172.0f/255.0f, 217.0f/255.0f), procedutex::NormalizedValue(-0.005f));		// Coast Waters
		theColorGradient.Insert(procedutex::Color4f(239.0f/255.0f, 210.0f/255.0f, 143.0f/255.0f), procedutex::NormalizedValue(0.1f));		// Beach
		theColorGradient.Insert(procedutex::Color4f(98.0f/255.0f, 132.0f/255.0f, 66.0f/255.0f), procedutex::NormalizedValue(0.25f));		// Savanna
		theColorGradient.Insert(procedutex::Color4f(80.0f/255.0f, 129.0f/255.0f, 55.0f/255.0f), procedutex::NormalizedValue(0.4f));			// Grasslands
		theColorGradient.Insert(procedutex::Color4f(44.0f/255.0f, 80.0f/255.0f, 47.0f/255.0f), procedutex::NormalizedValue(0.6f));			// Forest
		theColorGradient.Insert(procedutex::Color4f(97.0f/255.0f, 76.0f/255.0f, 65.0f/255.0f), procedutex::NormalizedValue(0.8f));			// Mountain
		theColorGradient.Insert(procedutex::Color4f(1.0f, 1.0f, 1.0f), procedutex::NormalizedValue(1.0f));									// Snow
		procedutex::util::GradientConverter conv(theColorGradient);

		imageData.Generate(fBm, conv);
	}
	//*/
	// END NOISE

	lge::TextureRegistry::Create(lge::TextureName::ProceduralSurfaceSimple,
								 lge::TextureMapType::Color,
								 imageData,
								 lge::TextureFilterType::Bilinear,
								 lge::TextureWrapType::EdgeClamp
	);
}


void CreateProceduralTextureMinimal()
{
	procedutex::random::ComplexUniform rnd(3452);

	procedutex::util::TextureBuffer2d imageData(512, 1024);

	// BEGIN NOISE
	//*
	{
		procedutex::PerlinNoise perlin(rnd.GetInt(23, 12355));

		procedutex::FractalGenerator fBm(perlin, procedutex::util::SampleSpace({0,0}, 4.0f, 2.0f), 8u, 2.2f, 0.65f, procedutex::Vect2f(0.0f, 0.0f));
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
	//*/
	// END NOISE

	lge::TextureRegistry::Create(lge::TextureName::ProceduralSurfaceMinimal,
								 lge::TextureMapType::Color,
								 imageData,
								 lge::TextureFilterType::Bilinear,
								 lge::TextureWrapType::EdgeClamp
	);
}


void CreateProceduralTextureComplex()
{
	procedutex::random::ComplexUniform rnd(888);

	procedutex::util::TextureBuffer2d imageData(1024, 2048);

	// BEGIN NOISE
	//*
	{
		// Make long clouds
		procedutex::PerlinNoise cloudGen(rnd.GetInt(23, 12355));
		cloudGen.SetSamplingSpace(procedutex::util::SampleSpace(procedutex::Vect2f(32.5f, 90.4f), 4.0f, 24.0f));
		cloudGen.AddInputModifier(new procedutex::inmods::DomainDistortionInMod(
			new procedutex::PerlinNoise(rnd.GetInt(23, 12355)),
			11.5f,
			3.2f)
		);
		cloudGen.AddOutputModifier(new procedutex::outmods::CustomFunctionOutMod(
			[] (float n)->float
		{
			const float n2 = 1.5f * n;
			return n2 - procedutex::math::FloatOps::Floorf(n2);
		}
		));
		cloudGen.AddOutputModifier(new procedutex::outmods::InvertOutMod());
		

		// Use perlin noise to make a few jupiter-like spots
		procedutex::PerlinNoise spotGen(rnd.GetInt(234, 123545));
		spotGen.SetSamplingSpace(procedutex::util::SampleSpace(procedutex::Vect2f(22.2f, 0.1f), 16.0f, 19.0f));
		spotGen.AddOutputModifier(new procedutex::outmods::CustomFunctionOutMod(
			[] (float n)->float
			{
				const float upperThreshold = 0.55f;
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
		theColorGradient.Insert(procedutex::Color4f(95.0f/255.0f, 76.0f/255.0f, 69.0f/255.0f), procedutex::NormalizedValue(-1.0f)); // Deep brownish-red clouds
		theColorGradient.Insert(procedutex::Color4f(192.0f/255.0f, 132.0f/255.0f, 76.0f/255.0f), procedutex::NormalizedValue(-0.6f)); // Lower orange clouds
		theColorGradient.Insert(procedutex::Color4f(222.0f/255.0f, 213.0f/255.0f, 190.0f/255.0f), procedutex::NormalizedValue(-0.01f)); // Higher tan clouds
		theColorGradient.Insert(procedutex::Color4f(1.0f, 1.0f, 1.0f), procedutex::NormalizedValue(-0.005f));							// border region
		theColorGradient.Insert(procedutex::Color4f(95.0f/255.0f, 76.0f/255.0f, 69.0f/255.0f), procedutex::NormalizedValue(0.0f)); // Outer spot outer rim
		theColorGradient.Insert(procedutex::Color4f(229.0f/255.0f, 202.0f/255.0f, 189.0f/255.0f), procedutex::NormalizedValue(0.2f)); // Outer spot inner rim
		theColorGradient.Insert(procedutex::Color4f(240.0f/255.0f, 101.0f/255.0f, 46.0f/255.0f), procedutex::NormalizedValue(0.3f)); // Spot cyclone paremeter
		theColorGradient.Insert(procedutex::Color4f(192.0f/255.0f, 52.0f/255.0f, 36.0f/255.0f), procedutex::NormalizedValue(0.4f)); // Spot cyclone middle
		theColorGradient.Insert(procedutex::Color4f(53.0f/255.0f, 27.0f/255.0f, 27.0f/255.0f), procedutex::NormalizedValue(4.0f)); // Inner spot
		theColorGradient.Insert(procedutex::Color4f(114.0f/255.0f, 57.0f/255.0f, 48.0f/255.0f), procedutex::NormalizedValue(1.0f)); // Spot Center
		procedutex::util::GradientConverter conv(theColorGradient);

		imageData.Generate(jupiter, conv);
	}
	//*/
	// END NOISE

	lge::TextureRegistry::Create(lge::TextureName::ProceduralSurfaceComplicated,
								 lge::TextureMapType::Color,
								 imageData,
								 lge::TextureFilterType::Bilinear,
								 lge::TextureWrapType::EdgeClamp
	);
}


//////////////////////////////
//
// Texture Registry
//
//////////////////////////////

namespace lge
{
	//
	// Static Data
	//
	TextureRegistry* TextureRegistry::singletonInstance = nullptr;



	//
	// Methods
	//

	TextureRegistry::TextureRegistry() :
		textureList()
	{
		assert(TextureRegistry::singletonInstance == nullptr);
		TextureRegistry::singletonInstance = this;
	}

	// VIRTUAL
	TextureRegistry::~TextureRegistry()
	{
		// List must be emptied before destroying manager!
		assert(this->textureList.GetNumberOfElements() == 0);

		// Manager must exist in singleton link!
		assert(TextureRegistry::singletonInstance != nullptr);
		TextureRegistry::singletonInstance = this;
	}







	// VIRTUAL
	void TextureRegistry::Load()
	{
		TextureRegistry::Create(TextureName::Duckweed,
								TextureMapType::Color,
								"res/textures/duckweed.tga",
								TextureFilterType::Bilinear,
								TextureWrapType::EdgeClamp);

		TextureRegistry::Create(TextureName::MarioGround,
								TextureMapType::Color,
								"res/textures/marioGround.tga",
								TextureFilterType::PointDistanceBlend,
								TextureWrapType::EdgeClamp);

		TextureRegistry::Create(TextureName::Rocks,
								TextureMapType::Color,
								"res/textures/rocks.tga",
								TextureFilterType::Bilinear,
								TextureWrapType::EdgeClamp);
		
		TextureRegistry::Create(TextureName::ExampleNormalMap,
								TextureMapType::Normal,
								"res/textures/weirdNormalMap.tga",
								TextureFilterType::Bilinear,
								TextureWrapType::EdgeClamp);


		// Procedural Texture Generation Routines
		
		CreateProceduralTextureSimple();

		CreateProceduralTextureMinimal();

		CreateProceduralTextureComplex();

		
	}

	// VIRTUAL
	void TextureRegistry::Unload()
	{
		while (this->textureList.GetNumberOfElements() != 0)
		{
			Texture* oldObject = this->textureList.RemoveFront();
			delete oldObject;
		}
	}

	// VIRTUAL
	void TextureRegistry::Update()
	{
		// Intentionally does nothing
	}





	// STATIC
	// Must be dynamically allocated, for it will be deleted by this manager later
	void TextureRegistry::Add(Texture* newObject)
	{
		assert(newObject != nullptr);
		TextureRegistry::singletonInstance->textureList.AddFront(newObject);
	}

	// STATIC
	// Find any Texture
	Texture& TextureRegistry::Find(TextureName name)
	{
		return *(TextureRegistry::singletonInstance->textureList.FindById(static_cast<unsigned int>(name)));
	}

	// STATIC
	// Factory for Textures. Automatically added
	Texture* const TextureRegistry::Create(TextureName name, TextureMapType mapType, const char * const filePath, TextureFilterType filtering, TextureWrapType wrapping)
	{
		assert(TextureRegistry::singletonInstance != nullptr);

		Texture* newTexture = new Texture(filePath, mapType, name);
		newTexture->SetFiltering(filtering);
		newTexture->SetWrapping(wrapping);

		TextureRegistry::Add(newTexture);

		return newTexture;
	}

	// STATIC
	// Factory for Textures. Automatically added
	Texture* const TextureRegistry::Create(TextureName name, TextureMapType mapType, const ImageBuffer& image, TextureFilterType filtering, TextureWrapType wrapping)
	{
		assert(TextureRegistry::singletonInstance != nullptr);

		Texture* newTexture = new Texture(image, mapType, name);
		newTexture->SetFiltering(filtering);
		newTexture->SetWrapping(wrapping);

		TextureRegistry::Add(newTexture);

		return newTexture;
	}

	// STATIC
	// Factory for Textures. Automatically added
	Texture* const TextureRegistry::Create(TextureName name, TextureMapType mapType, const procedutex::util::TextureBuffer2d& image, TextureFilterType filtering, TextureWrapType wrapping)
	{
		assert(TextureRegistry::singletonInstance != nullptr);

		Texture* newTexture = new Texture(image, mapType, name);
		newTexture->SetFiltering(filtering);
		newTexture->SetWrapping(wrapping);

		TextureRegistry::Add(newTexture);

		return newTexture;
	}

}