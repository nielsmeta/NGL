#include"primitive_model.h"
#include "App.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace NGL;

ostream& operator<<(ostream& o, glm::mat4 mat);
Triangle::Triangle()
{
	_shader.InitShader("./Shaders/testVert.shader", "./Shaders/testFrag.shader");

	Texture* tex1 = new Texture();
	tex1->LoadTexture("./Textures/container.jpg",GL_RGB);

	Texture* tex2 = new Texture();
	tex2->LoadTexture("./Textures/awesomeface.png", GL_RGBA,true);

	_textures.push_back(tex1);
	_textures.push_back(tex2);

	_shader.Use();
	_shader.SetInt("container", 0);
	_shader.SetInt("smileTexture", 1);
}

void Triangle::Init()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, false, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	/*glVertexAttribPointer(2, 2, GL_FLOAT, false, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);*/

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
}


void Triangle::OnRender()
{
	_shader.Use();
	int texCount = _textures.size();
	for (int i = 0; i < texCount; i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, _textures[i]->GetTextureID());
	}
	
	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	for (int i = 0; i < 10; i++)
	{
		float angle = 20.0f * i;
		matrix4x4 model = translate(cubePositions[i]);

		model = rotation(angle * 0.5, angle * 1.0f, angle * 0.3) * model;

		_shader.SetUniformMatrix4fv("model", model.toArray);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	/*float time = glfwGetTime();
	float v = sin(time) / 2 + 0.5f;
	float t = cos(time) / 2 + 0.5f;
	_shader.SetUniform4f("myColor", t, v, 0.0f, 1.0f);*/

	/*matrix4x4 model = xRotation(-55);
	_shader.SetUniformMatrix4fv("model", model.toArray);*/

	//matrix4x4 mat = xRotation(50 *glfwGetTime());
	matrix4x4 view = translate(0, 0, -3.0f);
	matrix4x4 projection = glPerspective(45, (float)800 / (float)600, 0.1f, 100.0f);

	_shader.SetUniformMatrix4fv("projection",  projection.toArray);


	float radius = 10.0f;

	float x = sinf(glfwGetTime()) * radius;
	float z = cosf(glfwGetTime()) * radius;

	view = lookAt(vector3(0, 1, 10), vector3(0, 0, 0), vector3(0, 1, 0));

	glm::mat4 t = glm::lookAt(glm::vec3(0, 1, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	
	_shader.SetUniformMatrix4fv("view", glm::value_ptr(t));
	//_shader.SetUniformMatrix4fv("projection",mat2.toArray);

	glBindVertexArray(0);
}

