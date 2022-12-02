#include"App.h"
#include"Log.h"
using namespace NGL;

int main()
{
	Log::Debug<const char*>("Welcome to NGL.");
	App::Launch();
	App::Close();
	Log::Debug<const char*>("Exit Main.");
	return 0;
}
