#include "jnsSceneManager.h"
#include "jnsPlayScene.h"
#include "jnsLoginScene.h"
#include "jnsWorldSelectScene.h"

namespace jns
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*>  SceneManager::mScenes;
	void SceneManager::Initialize()
	{
		//PlayScene* test = new PlayScene();
		
		Scene* mLogin = new LoginScene();
		Scene* mWorld = new WorldSelectScene();
		Scene* mPlay= new PlayScene();

		mScenes.insert(std::make_pair(L"Login", mLogin));
		mScenes.insert(std::make_pair(L"WorldSelect", mWorld));
		mScenes.insert(std::make_pair(L"PlayScene", mPlay));

		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.begin();
		
		for (iter; iter != mScenes.end(); iter++)
		{
			iter->second->Initialize();
		}

		LoadScene(L"PlayScene");
		//mActiveScene->Initialize();
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

	void SceneManager::Release()
	{
		for (auto iter : mScenes)
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
		
		mActiveScene->OnExit();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		
		return iter->second;
	}
}