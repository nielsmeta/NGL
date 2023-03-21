#include "App.h"
#include"Log.h"
#include"Base/vector.h"
using namespace NGL;

int main()
{
	Log::Debug<const char*>("Welcome to NGL.");
	App::Launch();
	App::Close();
	Log::Debug<const char*>("Exit Main.");
	/*vector2i v = vector2i(1, 1);
	vector2i b = vector2i(2, 2);
	vector2i c = v * 2;
	std::cout <<project(b,v) << std::endl;*/
	return 0;
}


