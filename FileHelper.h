#pragma once

#include<iostream>

using namespace std;

class FileHelper
{
public:

	static string ReadFileTxt(const char* filePath);
	

	static unsigned char* LoadImageFile(const char* filePath, int& width, int& height, int& channel, bool needFlipY = false);

	static void FreeImageData(unsigned char* data);

};

