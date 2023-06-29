#pragma once
#include "..\Engine_Source\jnsSceneManager.h"
#include "jnsPlayScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\JNSEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\JNSEngine.lib")
#endif

namespace jns
{
	void IntializeScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

	}
}