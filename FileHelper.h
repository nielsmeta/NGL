#pragma once

#include<iostream>
using namespace std;


class FileHelper
{
public:

	static string ReadFileTxt(const char* filePath)
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

private:

};

