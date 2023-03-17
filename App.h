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
		static App* GetApp();
		int GetScreenWidth();
		int GetScreenHeight();
		void Render();
		void OnResize(GLFWwindow* window, int width, int height);

	private:
		GLFWwindow* window;
		int width;
		int height;
		unsigned int vbo;
		unsigned int shaderProgram;
		static App* Application;
		void InitApp(int w, int h);
		
		~App();
	};
}

