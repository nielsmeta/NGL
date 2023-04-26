#include"FileHelper.h"

#define STB_IMAGE_IMPLEMENTATION
#include"Base/stb_image.h"

string FileHelper::ReadFileTxt(const char* filePath)
{
	auto fs = fopen(filePath, "r");
	char c;
	string buffer;
	while (fscanf(fs, "%c", &c) == 1)
	{
		buffer += c;
	}

	fclose(fs);
	return buffer;
}

unsigned char* FileHelper::LoadImageFile(const char* filePath, int& width, int& height, int& channel,bool needFlipY)
{
	if (needFlipY)
	{
		stbi_set_flip_vertically_on_load(true);
	}
	auto data = stbi_load(filePath, &width, &height, &channel, 0);
	stbi_set_flip_vertically_on_load(false);
	return  data;
}

void FileHelper::FreeImageData(unsigned char* data)
{
	stbi_image_free(data);
}