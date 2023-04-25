#pragma once
#include"Model.h"
#include"Shader.h"

struct Triangle :public Model
{

	float vertices[24] = {
	-0.5f, -0.5f, 0.0f, 1.0,1.0,0,
	 0.5f, -0.5f, 0.0f, 1.0,0,0,
	 0.5f,  0.5f, 0.0f, 0,1,0,
	 -0.5f,  0.5f, 0.0f,0,0,1
	};

	int indices[6] = {
		0,1,2,
		2,3,0
	};

	Shader _shader;

	Triangle()
	{
		_shader.InitShader("./Shaders/testVert.shader", "./Shaders/testFrag.shader");
	}

	virtual void Init()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1,&VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	virtual void OnRender()
	{
		_shader.Use();
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		/*float time = glfwGetTime();
		float v = sin(time) / 2 + 0.5f;
		float t = cos(time) / 2 + 0.5f;
		_shader.SetUniform4f("myColor", t, v, 0.0f, 1.0f);*/
		glBindVertexArray(0);
	}

};