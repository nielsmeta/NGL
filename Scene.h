#pragma once
#include<iostream>
#include<vector>

#include"Model.h"

using namespace std;

class Scene
{
private:

	vector<Model*> _models;

public:

	Model AddModel(Model* model);

	void Init();

	void InitModels();

	void OnRender();
};