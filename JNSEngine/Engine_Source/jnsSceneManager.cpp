#include "jnsSceneManager.h"
#include "..\\JNSEngine\jnsPlayer.h"
#include "jnsCollisionManager.h"
#include "..\\JNSEngine\ObjectTemplate.h"

namespace jns
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*>  SceneManager::mScenes;
	GameObject* SceneManager::mPlayer;
	void SceneManager::Initialize()
	{

	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		mActiveScene->Render();
	}
	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);
		
		if (iter == mScenes.end())
			return nullptr;

		if (mActiveScene == nullptr)
			mActiveScene = iter->second;
		
		std::vector<GameObject*> dontDestroyObjects;
		for (Layer& layer : mActiveScene->GetLayers())
		{
			for (GameObject* gameObj : layer.GetGameObjects())
			{
				if (gameObj->GetState() == GameObject::eState::DontDestroy)
				{
					dontDestroyObjects.push_back(gameObj);
					eLayerType layerType = gameObj->GetLayerType();
					mActiveScene->DeleteGameObject(layerType, gameObj);
				}
			}
		}

		mActiveScene->OnExit();
		CollisionManager::Clear();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		for (GameObject* dontDestroyObj : dontDestroyObjects)
		{
			eLayerType layerType = dontDestroyObj->GetLayerType();

			if (dontDestroyObj->GetIsOnlyOne() == true)
			{
				mActiveScene->AddGameObject(layerType, dontDestroyObj);
			}
				
		}

		dontDestroyObjects.clear();
		return iter->second;
	}
}