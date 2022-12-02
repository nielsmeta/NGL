#pragma once
#include "GLFW/glfw3.h"
namespace NGL
{
	class App
	{
	public:
		
		static void Launch();
		static void Close();
		int GetScreenWidth();
		int GetScreenHeight();

	private:
		GLFWwindow* window;
		int width;
		int height;
		static App* Application;
		void InitApp(int w, int h);
		~App();
	};
}

