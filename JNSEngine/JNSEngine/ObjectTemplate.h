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



	template<typename T>
	T* Instantiate(jns::enums::eLayerType type, Vector3 mPos, Vector3 mRotation = (Vector3::Zero), Vector3 mScale = (Vector3::One))
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->GetComponent<Transform>()->SetRotation(mRotation);
		//gameobj->GetComponent<Transform>()->SetScale(mScale);

		return gameobj;
	}

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(jns::GameObject::eState::Dead);
	}

}