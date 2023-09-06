#include "jnsSceneManager.h"
#include "..\\JNSEngine\jnsPlayer.h"
#include "jnsCollisionManager.h"
#include "..\\JNSEngine\ObjectTemplate.h"
#include "jnsResources.h"


namespace jns
{
	bool SceneManager::isLoading = false;
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mLoadingScene = nullptr;
	Scene* SceneManager::mPrevScene = nullptr;
	std::map<jns::enums::eSceneType, Scene*>  SceneManager::mScenes;
	GameObject* SceneManager::mPlayer;
	void SceneManager::Initialize()
	{

		// 임시로 사운드 이쪽에서 로드
		Resources::Load<AudioClip>(L"RutaBysMain", L"..\\Resources\\Sound\\YggdrasilPrayer.mp3");
		Resources::Load<AudioClip>(L"QueenPalace", L"..\\Resources\\Sound\\QueenPalace.mp3");
	}
	void SceneManager::Update()
	{
		if (isLoading == false)
			mActiveScene->Update();
		else
			mLoadingScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		if (isLoading == false)
		mActiveScene->LateUpdate();
		else
		mLoadingScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		//if (isLoading == false)
		//mActiveScene->Render();
		//else
		mLoadingScene->Render();
	}
	void SceneManager::Destroy()
	{
		if (isLoading == false)
		mActiveScene->Destroy();
		else
		mLoadingScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(jns::enums::eSceneType type)
	{
		mPrevScene = mActiveScene;
		std::map<jns::enums::eSceneType, Scene*>::iterator iter
			= mScenes.find(type);
		
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