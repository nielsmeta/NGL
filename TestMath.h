#pragma once
#include"Base/matrix.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtx/string_cast.hpp>
#include<glm/ext.hpp>

ostream& operator<<(ostream& o, glm::mat4 mat)
{
	o << endl;
	o <<"glm:: matrix"<< endl;
	o << mat[0][0] << " " << mat[1][0] << " " << mat[2][0] << " " << mat[3][0] << endl
		<< mat[0][1] << " " << mat[1][1] << " " << mat[2][1] << " " << mat[3][1] << endl
		<< mat[0][2] << " " << mat[1][2] << " " << mat[2][2] << " " << mat[3][2] << endl
		<< mat[0][3] << " " << mat[1][3] << " " << mat[2][3] << " " << mat[3][3] << endl;
	return o;
}

ostream& operator<<(ostream& o, glm::vec4 v)
{
	o << "glm:: vector:" << endl;
	o << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	return o;
}

struct TestMath
{
	void StartTest()
	{
		//glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		//glm::mat4 view = glm::mat4(1.0f);
		//glm::mat4 projection = glm::mat4(1.0f);
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		//projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		//std::cout << model;
		//std::cout << view;
		//std::cout << projection;
		//matrix4x4 mat = xRotation(-55);
		//std::cout << mat;

		//matrix4x4 mat1 = translate(0, 0, -3.0f);
		//std::cout << mat1;

		//matrix4x4 mat2 = glPerspective(45, (float)800 / (float)600, 0.1f, 100.0f);
		//std::cout << mat2;


		/*matrix4x4 mat;
		glm::mat4 m(1.0f);
		std::cout << mat;
		std::cout << m;

		matrix4x4 mat1;
		mat1._34 = -22;
		glm::mat4 m1(1.0f);
		m1[2][3] = -22;
		std::cout << mat1;
		std::cout << m1;*/

		/*matrix4x4 mat2;
		std::cout << translate(-1.0f, 2.0f, 3.0f);

		glm::mat4 m2(1.0f);
		std::cout<<glm::translate(m2, glm::vec3(-1.0f, 2.0f, 3.0f));*/

		/*std::cout << yRotation(45);

		glm::mat4 m3(1.0f);
		std::cout << glm::rotate(m3,glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));*/
		
		/*matrix4x4 m4;
		m4._32 = 10;
		std::cout << mulVector(m4, vector3(2, 3, 4));

		glm::mat4 mat4(1.0f);
		mat4[2][1] = 10;
		std::cout << mat4 * glm::uvec4(2.0f, 3.0f, 4.0f, 0.0f);*/

		/*matrix4x4 m1;
		m1._23 = -1;
		m1._34 = 23;

		matrix4x4 m2;
		m2._32 = 1;
		m2._13 = -7;

		matrix4x4 m3;
		m3._14 = -10;
		m3._33 = 3;

		std::cout << mul(m3,mul(m2, m1));

		glm::mat4 mat(1.0f);
		mat[1][2] = -1;
		mat[2][3] = 23;
		glm::mat4 m(1.0f);
		m[2][1] = 1.0f;
		m[0][2] = -7;

		glm::mat4 m4(1.0f);
		m4[0][3] = -10;
		m4[2][2] = 3;
		
		std::cout << mat * m * m4;;*/

		//matrix4x4 rot = rotation(60,30,0);
		//std::cout << rot;

		//glm::mat4 m(1.0f);
		//auto mz = glm::rotate(m, glm::radians(60.0f), glm::vec3(0.0f, 0.0f, 1.0f));//z
		////auto my = glm::rotate(mz, glm::radians(10.0f), glm::vec3(0.0f, 1.0f, 0.0f));//y
		//auto mx = glm::rotate(mz, glm::radians(30.0f), glm::vec3(1.0f, 0.0f, 0.0f));//x
		//
		//std::cout << mx ;

		/*matrix4x4 m1;
		m1._23 = -1;
		m1._34 = 23;

		matrix4x4 m2;
		m2._32 = 1;
		m2._13 = -7;

		matrix4x4 m3;
		m3._14 = -10;
		m3._33 = 3;

		std::cout <<  mul(m2, m1);*/

		/*auto	projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		matrix4x4 p = glPerspective(45, (float)800 / (float)600, 0.1f, 100.0f);
		std::cout << projection;
		std::cout << p;*/
	
		matrix4x4 mat1;
		mat1._33 = 1;
		mat1._34 = 5;
		mat1._43 = 4;
		matrix4x4 mat2;
		mat2._44 = -1;
		std::cout << mat2;
		std::cout << mat1;
		
		std::cout<<mul(mat1,mat2);
	}
};