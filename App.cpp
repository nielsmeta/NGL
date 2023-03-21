#include"App.h"
#include"Log.h"
using namespace NGL;

const std::string vertexShaderSource = "";


App* App::Application;

App* App::GetApp()
{
	return App::Application;
}

void  FrameBufferResizeCallback(GLFWwindow* window, int width, int height)
{
	App::GetApp()->OnResize(window, width, height);
}

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GL_TRUE)
	{
		Log::Info("press escape down");
		glfwSetWindowShouldClose(window, 1);
	}
}

void App::InitApp(int w, int h)
{
	width = w;
	height = h;
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	glfwWindowHint(GL_MAJOR_VERSION, 3);
	glfwWindowHint(GL_MINOR_VERSION, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!glfwInit())
	{
		return;
	}
	window = glfwCreateWindow(width, height, "NGL GameEngine", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwShowWindow(window);

	glViewport(0, 0, width, height);

	unsigned int glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		Log::Debug<const char*>("Error");
		glfwTerminate();
		return;
	}

	glfwSetFramebufferSizeCallback(window, FrameBufferResizeCallback);

	while (!glfwWindowShouldClose(window)) {
		ProcessInput(window);
		glClearColor(0, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		this->Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void App::Render()
{

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
	if (App::Application != nullptr)return;
	App::Application = new App();
	App::Application->InitApp(680, 540);
}

void App::OnResize(GLFWwindow* window, int width, int height)
{
	this->width = width;
	this->height = height;
	std::cout << "width: " << width << "	height:" << height << std::endl;
	glViewport(0, 0, width, height);
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
