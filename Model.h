#pragma once

class Model
{
protected:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;

public:

	virtual void Init();
	virtual void OnRender();
};