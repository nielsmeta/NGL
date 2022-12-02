#include"App.h"
#include"Log.h"
using namespace NGL;

App* App::Application;
void App::InitApp(int w, int h)
{
	width = w;
	height = h;
	if (!glfwInit())
	{
		return;
	}
	window = glfwCreateWindow(680, 540, "NGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwShowWindow(window);
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(0, 0.5);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int App::GetScreenWidth()
{
	return width;
}

int App::GetScreenHeight()
{
	return height;
}

void App::Launch()
{
	App::Application = new App();
	App::Application->InitApp(680, 540);
}

void App::Close()
{
	if (Application != nullptr)
	{
		delete Application;
		Application = nullptr;
	}
	Log::Debug<const char*>("Close Application.");
}

App::~App()
{
	Log::Debug<const char*>("Exit Application.");
}
