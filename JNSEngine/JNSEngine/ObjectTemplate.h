#pragma once
#include "jnsEnums.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"

namespace jns::object
{

	//MpBar* centerStatusMpUI = new MpBar();
	//AddGameObject(eLayerType::UI, centerStatusMpUI);
	//centerStatusMpUI->Initialize();

	template<typename T>
	T* InstantiateUIandBG(jns::enums::eLayerType type)
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();

		return gameobj;
	}


}