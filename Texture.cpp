#include"Texture.h"
#include"FileHelper.h"

void Texture::LoadTexture(const char* texturePath)
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	auto data = FileHelper::LoadImageFile(texturePath, width, height, channel);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed Load Image: " << *texturePath << std::endl;
	}
	FileHelper::FreeImageData(data);

}

int Texture::GetWidth()
{
	return width;
}

int Texture::GetHeight()
{
	return height;
}

unsigned int Texture::GetTextureID()
{
	return textureId;
}