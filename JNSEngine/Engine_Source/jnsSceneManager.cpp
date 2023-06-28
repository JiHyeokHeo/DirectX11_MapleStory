#include "jnsSceneManager.h"

namespace jns
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*>  SceneManager::mScenes;
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
		
		mActiveScene->OnExit();
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		
		return iter->second;
	}
}