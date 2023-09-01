#pragma once
#include "jnsScene.h"


namespace jns
{
	enum class eSceneType
	{
		Login,
		Select,
		CharactorMake,
		StartScene1,
		RutabysMain,
		RutabysMob,
		RutabysBoss,
	};

	class Player;
	class SceneManager
	{
	public:
		static bool isLoading;
		static bool check;

	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Destroy();
		static void Release();

		template<typename T>
		static bool CreateScene(jns::enums::eSceneType type)
		{
			T* scene = new T();

			std::map <jns::enums::eSceneType, Scene*>::iterator iter
				= mScenes.find(type);

			if (iter != mScenes.end())
				return false;

			mScenes.insert(std::make_pair(type, scene));
			
			mActiveScene = scene;
			mActiveScene->SetSceneType(type);
			
			if (mLoadingScene == nullptr)
			{
				mLoadingScene = scene;
			}

			scene->Initialize();
			return true;
		}

		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* GetLoadingScene() { return mLoadingScene; }
		static Scene* GetPrevScene() { return mPrevScene; }
		static Scene* LoadScene(jns::enums::eSceneType type);
		static GameObject* GetPlayer() { return mPlayer; }
		static void SetPlayer(GameObject* obj) { mPlayer = obj; }
	private:
		static Scene* mActiveScene;
		static Scene* mLoadingScene;
		static Scene* mPrevScene;
		static std::map<jns::enums::eSceneType, Scene*> mScenes;
		static GameObject* mPlayer;
		
	};
}