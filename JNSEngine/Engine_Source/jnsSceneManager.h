#pragma once
#include "jnsScene.h"

namespace jns
{
	class Player;
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Destroy();
		static void Release();

		template<typename T>
		static bool CreateScene(std::wstring name)
		{
			T* scene = new T();

			std::map < std::wstring, Scene*>::iterator iter
				= mScenes.find(name);

			if (iter != mScenes.end())
				return false;

			mScenes.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			mActiveScene->SetName(name);
			scene->Initialize();
			return true;
		}

		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* GetPrevScene() { return mPrevScene; }
		static Scene* LoadScene(std::wstring name);
		static GameObject* GetPlayer() { return mPlayer; }
		static void SetPlayer(GameObject* obj) { mPlayer = obj; }
	private:
		static Scene* mActiveScene;
		static Scene* mPrevScene;
		static std::map<std::wstring, Scene*> mScenes;
		static GameObject* mPlayer;
	};
}