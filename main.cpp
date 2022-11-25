#include<iostream>
#include "GLFW/glfw3.h"
int main()
{
	std::cout << "Welcome to NGL." << std::endl;
	if (!glfwInit())
	{
		return -1;
	}
	auto window = glfwCreateWindow(680, 540,"NGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glfwShowWindow(window);
	while (!glfwWindowShouldClose(window)){
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
	window = nullptr;
	return 0;
}