#pragma once
#include "..\Engine_Source\jnsSceneManager.h"
#include "jnsPlayScene.h"
#include "jnsLoginScene.h"
#include "jnsWorldSelectScene.h"
#include "jnsRutabysScene.h"
#include "jnsRutabysBossScene.h"
#include "jnsSelectScene.h"
#include "jnsCharactorMakeScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\JNSEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\JNSEngine.lib")
#endif

namespace jns
{
	void IntializeScenes()
	{
		SceneManager::CreateScene<SelectScene>(L"Select");
		SceneManager::CreateScene<CharactorMakeScene>(L"CharactorMake");
		SceneManager::CreateScene<RutabysBossScene>(L"RutabysBoss");
		SceneManager::CreateScene<WorldSelectScene>(L"WorldSelect");
		SceneManager::CreateScene<RutabysScene>(L"Rutabys");
		SceneManager::CreateScene<LoginScene>(L"Login");

		//SceneManager::LoadScene(L"Login");
	}
}