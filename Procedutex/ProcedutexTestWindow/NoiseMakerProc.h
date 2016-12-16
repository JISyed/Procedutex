#pragma once
#include "AppTexturesSetter.h"

// Functor to test some procedural texture generation
class NoiseMakerProc
{
public:
	// Ctor
	NoiseMakerProc(AppTexturesSetter& textureCollectionSetter);
	~NoiseMakerProc() {}

	// Run the procedural generation routine
	void operator()();

private:

	//
	// Data
	//

	AppTexturesSetter& textureSetter;



	//
	// Private routines
	//

	// This is where actual noise generation is done
	void GenerateTexture1ColorMap(procedutex::util::TextureBuffer2d& imageData);
	void GenerateTexture2ColorMap(procedutex::util::TextureBuffer2d& imageData);
	void GenerateTexture3ColorMap(procedutex::util::TextureBuffer2d& imageData);
	void GenerateTexture4ColorMap(procedutex::util::TextureBuffer2d& imageData);


	// Allocate memory for images. Assuming squared textures
	void AllocateTexture1(const size_t imgSize, TextureFilterType filter);
	void AllocateTexture2(const size_t imgSize, TextureFilterType filter);
	void AllocateTexture3(const size_t imgSize, TextureFilterType filter);
	void AllocateTexture4(const size_t imgSize, TextureFilterType filter);



	//
	// Deleted Methods
	//

	// No default ctor
	NoiseMakerProc() = delete;
	// No copy
	NoiseMakerProc(const NoiseMakerProc& o) = delete;
	// No copy
	NoiseMakerProc& operator=(const NoiseMakerProc& o) = delete;
	// No move
	NoiseMakerProc(NoiseMakerProc&& o) = delete;
	// No move
	NoiseMakerProc& operator=(NoiseMakerProc&& o) = delete;

};

