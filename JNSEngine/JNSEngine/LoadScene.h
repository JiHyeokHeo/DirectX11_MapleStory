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
#include "jnsLoadingScene.h"
#include "jnsRutabysPierreMobScene.h"
#include "jnsRutabysPierreBossScene.h"
//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\JNSEngine.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\JNSEngine.lib")
//#endif

namespace jns
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<SelectScene>(jns::enums::eSceneType::Select);
		SceneManager::CreateScene<CharactorMakeScene>(jns::enums::eSceneType::CharactorMake);
		SceneManager::CreateScene<RutabysBossScene>(jns::enums::eSceneType::RutabysBoss);
		SceneManager::CreateScene<StartScene1>(jns::enums::eSceneType::StartScene1);
		/*SceneManager::CreateScene<StartScene2>(L"StartScene2");
		SceneManager::CreateScene<StartScene3>(L"StartScene3");
		SceneManager::CreateScene<StartScene4>(L"StartScene4");
		SceneManager::CreateScene<StartScene5>(L"StartScene5");*/
		//SceneManager::CreateScene<WorldSelectScene>(L"WorldSelect");
		SceneManager::CreateScene<RutabysMobScene>(jns::enums::eSceneType::RutabysMob);
		//SceneManager::CreateScene<LoginScene>(L"Login");
		SceneManager::CreateScene<RutabysPierreMobScene>(jns::enums::eSceneType::RutabysPierreMob);
		SceneManager::CreateScene<RutabysPierreBossScene>(jns::enums::eSceneType::RutabysPierreBoss);
		SceneManager::CreateScene<RutabysScene>(jns::enums::eSceneType::RutabysMain);

		SceneManager::LoadScene(jns::enums::eSceneType::RutabysMob);
	}
	
	void InitializeLoadingScene()
	{

		SceneManager::CreateScene<LoadingScene>(jns::enums::eSceneType::Loading);

	}

}