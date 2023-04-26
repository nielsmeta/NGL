#pragma once
#include"Base/head.h"

class Texture
{
private:
	int width, height, channel;
	unsigned int textureId;
public :

	Texture()
	{

	}

	void LoadTexture(const char* texturePath, GLint imageFormat,bool needYFlip = false);

	int GetWidth();

	int GetHeight();

	unsigned int GetTextureID();

};