#include "GLFW/glfw3.h"

class App
{
public:
	int width;
	int height;
	static void Launch()
	{
		App *app = new App();
		app->InitApp(680, 540);
	}

private:
	GLFWwindow* window;

	void InitApp(int w, int h)
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
	~App()
	{
		if (window != nullptr)
		{
			delete window;
		}
	}
};