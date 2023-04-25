#pragma once
#include"Base/head.h"

class Texture
{
private:
	int width, height, channel;
	unsigned int textureId;
public :

	void LoadTexture(const char* texturePath);

	int GetWidth();

	int GetHeight();

	unsigned int GetTextureID();

};