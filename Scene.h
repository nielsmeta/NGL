#pragma once
#include"Base/head.h"
#include<iostream>
#include<vector>
#include"primitive_model.h"
using namespace std;
struct Scene
{
private:
	vector<Model*> _models;

public:

	Model AddModel(Model* model)
	{
		_models.push_back(model);
		return *model;
	}

	void Init()
	{
		AddModel(new Triangle());
		InitModels();
	}

	void InitModels()
	{
		int count = _models.size();
		for (int i = 0; i < count; i++)
		{
			auto model = _models.at(i);
			model->Init();
		}
	}

	void OnRender()
	{
		int count = _models.size();
		for (int i = 0; i < count; i++)
		{
			auto model = _models.at(i);
			model->OnRender();
		}
	}
};