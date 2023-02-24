#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <string>
namespace NGL
{
	class App
	{
	public:
		
		static void Launch();
		static void Close();
		int GetScreenWidth();
		int GetScreenHeight();
		void Draw();

	private:
		GLFWwindow* window;
		int width;
		int height;
		static App* Application;
		void InitApp(int w, int h);
		~App();
	};
}

