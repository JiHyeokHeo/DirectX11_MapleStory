#pragma once
#include "..\Engine_Source\jnsSceneManager.h"
#include "jnsPlayScene.h"
#include "jnsLoginScene.h"
#include "jnsWorldSelectScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\JNSEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\JNSEngine.lib")
#endif

namespace jns
{
	void IntializeScenes()
	{
		SceneManager::CreateScene<LoginScene>(L"Login");
		SceneManager::CreateScene<WorldSelectScene>(L"WorldSelect");
		SceneManager::CreateScene<PlayScene>(L"Play");
	}
}