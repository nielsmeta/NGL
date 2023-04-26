#include"Scene.h"

#include"Base/head.h"
#include"primitive_model.h"

Model Scene::AddModel(Model* model)
{
	_models.push_back(model);
	return *model;
}

void Scene::Init()
{
	AddModel(new Triangle());
	InitModels();
}

void Scene::InitModels()
{
	int count = _models.size();
	for (int i = 0; i < count; i++)
	{
		auto model = _models.at(i);
		model->Init();
	}
}

void Scene::OnRender()
{
	int count = _models.size();
	for (int i = 0; i < count; i++)
	{
		auto model = _models.at(i);
		model->OnRender();
	}
}