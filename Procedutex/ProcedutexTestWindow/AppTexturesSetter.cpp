#include "AppTexturesSetter.h"


AppTexturesSetter::AppTexturesSetter(Texture& t1, Texture& t2, Texture& t3, Texture& t4, bool& t1Ready, bool& t2Ready, bool& t3Ready, bool& t4Ready) :
	texture1TopLeft(t1),
	texture2TopRight(t2),
	texture3BottomLeft(t3),
	texture4BottomRight(t4),
	isTexture1Ready(t1Ready),
	isTexture2Ready(t2Ready),
	isTexture3Ready(t3Ready),
	isTexture4Ready(t4Ready)
{
}


AppTexturesSetter::~AppTexturesSetter()
{
}





void AppTexturesSetter::SetupTexture1(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter)
{
	this->texture1TopLeft.Setup(
		imageData.GetReadOnlyRawData(),
		imageData.GetWidth(),
		imageData.GetHeight(),
		TextureWrapType::Repeat,
		filter
	);
	this->isTexture1Ready = true;
}

void AppTexturesSetter::SetupTexture2(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter)
{
	this->texture2TopRight.Setup(
		imageData.GetReadOnlyRawData(),
		imageData.GetWidth(),
		imageData.GetHeight(),
		TextureWrapType::Repeat,
		filter
	);
	this->isTexture2Ready = true;
}

void AppTexturesSetter::SetupTexture3(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter)
{
	this->texture3BottomLeft.Setup(
		imageData.GetReadOnlyRawData(),
		imageData.GetWidth(),
		imageData.GetHeight(),
		TextureWrapType::Repeat,
		filter
	);
	this->isTexture3Ready = true;
}

void AppTexturesSetter::SetupTexture4(procedutex::util::TextureBuffer2d& imageData, TextureFilterType filter)
{
	this->texture4BottomRight.Setup(
		imageData.GetReadOnlyRawData(),
		imageData.GetWidth(),
		imageData.GetHeight(),
		TextureWrapType::Repeat,
		filter
	);
	this->isTexture4Ready = true;
}
