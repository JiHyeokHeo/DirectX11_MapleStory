#pragma once
#include "..\Engine_Source\jnsSceneManager.h"
#include "jnsPlayScene.h"
#include "jnsLoginScene.h"
#include "jnsWorldSelectScene.h"
#include "jnsRutabysScene.h"
#include "jnsRutabysBossScene.h"
#include "jnsSelectScene.h"
#include "jnsCharactorMakeScene.h"
#include "jnsRutabysMobScene.h"
#include "jnsStartScene1.h"
#include "jnsStartScene2.h"
#include "jnsStartScene3.h"
#include "jnsStartScene4.h"
#include "jnsStartScene5.h"

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
		SceneManager::CreateScene<StartScene1>(L"StartScene1");
		SceneManager::CreateScene<StartScene2>(L"StartScene2");
		SceneManager::CreateScene<StartScene3>(L"StartScene3");
		SceneManager::CreateScene<StartScene4>(L"StartScene4");
		SceneManager::CreateScene<StartScene5>(L"StartScene5");
		SceneManager::CreateScene<WorldSelectScene>(L"WorldSelect");
		SceneManager::CreateScene<RutabysMobScene>(L"RutabysMob");
		SceneManager::CreateScene<LoginScene>(L"Login");
		SceneManager::CreateScene<RutabysScene>(L"Rutabys");

		//SceneManager::LoadScene(L"Login");
	}
	

}