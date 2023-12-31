#include "jnsScene.h"

namespace jns
{
	Scene::Scene()
	{
		mLayers.resize((int)jns::enums::eLayerType::End);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{	


	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer& layer : mLayers)
		{
			layer.LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer& layer : mLayers)
		{
			layer.Render();
		}
	}
	void Scene::Destroy()
	{
		for (Layer& layer : mLayers)
		{
			layer.Destroy();
		}
	}
	void Scene::OnEnter()
	{
		for (Layer& layer : mLayers)
		{
			layer.DontDestroySceneEnter();
		}
	}
	void Scene::OnExit()
	{
		for (Layer& layer : mLayers)
		{
			layer.DontDestroySceneExit();
		}
	}
	void Scene::AddGameObject(enums::eLayerType type, GameObject* gameObj)
	{
		gameObj->SetType(type);
		mLayers[(int)type].AddGameObject(gameObj);
	}
	void Scene::DeleteGameObject(enums::eLayerType type, GameObject* gameObj)
	{
		mLayers[(int)type].DeleteGameObject(gameObj);
	}

}