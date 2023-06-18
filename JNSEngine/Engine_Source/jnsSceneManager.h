#pragma once
#include "jnsScene.h"

namespace jns
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();

		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* LoadScene(std::wstring name);

	private:
		static Scene* mActiveScene;
		static std::map<std::wstring, Scene*> mScenes;
	};
}