#pragma once
#include"Model.h"
#include"Shader.h"
#include"Texture.h"
#include<vector>
using namespace std;
class Triangle :public Model
{

	float vertices[32] = {
	-0.5f, -0.5f, 0.0f,     1.0,1.0,0,     0,0,
	 0.5f, -0.5f, 0.0f,     1.0,0,0,	   1,0,
	 0.5f,  0.5f, 0.0f,     0,1,0,			1,1,
	 -0.5f,  0.5f, 0.0f,    0,0,1,			0,1
	};

	int indices[6] = {
		0,1,2,
		2,3,0
	};

	Shader _shader;

	vector<Texture*> _textures;

public:

	Triangle();

	virtual void Init();

	virtual void OnRender();

};