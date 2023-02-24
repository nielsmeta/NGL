#include"App.h"
#include"Log.h"
#include"head.h"

using namespace NGL;

const std::string vertexShaderSource = "";

App* App::Application;
void App::InitApp(int w, int h)
{
	Vector3 t = Vector3(2, 10,20);
	t.Info();
	width = w;
	height = h;
	if (!glfwInit())
	{
		return;
	}
	window = glfwCreateWindow(width, height, "NGL GameEngine", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwShowWindow(window);

	unsigned int glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		Log::Debug<const char*>("Error");
	}

	float positions[6] = { -0.5, -0.5 ,
							0.5, -0.5,
							0.0f, 0.5 };

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
	glEnableVertexAttribArray(0);
	//glShaderSource(GL_VERTEX_SHADER,);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		this->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void App::Draw()
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
