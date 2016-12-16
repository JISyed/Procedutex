#pragma once
#include "Texture.h"
#include "procedutex\utilities\TextureBuffer2d.h"

// Serves as a bridge between noise making procedures and the App
class AppTexturesSetter
{
public:
	AppTexturesSetter(Texture& t1, Texture& t2, Texture& t3, Texture& t4, bool& t1Ready, bool& t2Ready, bool& t3Ready, bool& t4Ready);
	~AppTexturesSetter();


	void SetupTexture1(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter);
	void SetupTexture2(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter);
	void SetupTexture3(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter);
	void SetupTexture4(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter);


private:

	Texture& texture1TopLeft;
	Texture& texture2TopRight;
	Texture& texture3BottomLeft;
	Texture& texture4BottomRight;
	bool& isTexture1Ready;
	bool& isTexture2Ready;
	bool& isTexture3Ready;
	bool& isTexture4Ready;



	// No default ctor
	AppTexturesSetter() = delete;
	// No copy
	AppTexturesSetter(const AppTexturesSetter& o) = delete;
	// No copy
	AppTexturesSetter& operator=(const AppTexturesSetter& o) = delete;
	// No move
	AppTexturesSetter(AppTexturesSetter&& o) = delete;
	// No move
	AppTexturesSetter& operator=(AppTexturesSetter&& o) = delete;
};

