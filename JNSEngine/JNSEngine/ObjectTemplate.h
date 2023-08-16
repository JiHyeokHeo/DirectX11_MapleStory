#pragma once
#include "jnsEnums.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"
#include "jnsItemResources.h"
#include "jnsBGInstance.h"

namespace jns::object
{

	//MpBar* centerStatusMpUI = new MpBar();
	//AddGameObject(eLayerType::UI, centerStatusMpUI);
	//centerStatusMpUI->Initialize();

	template<typename T>
	T* InstantiateParticle(jns::enums::eLayerType type)
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiateNOmove(jns::enums::eLayerType type)
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiateBG(jns::enums::eLayerType type, BGInstance::eBGType type2)
	{
		T* gameobj = new T(type2);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiateItem(jns::enums::eLayerType type, ItemResources::eItemType type2, Vector3 mPos)
	{
		T* gameobj = new T(type2);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiatePortal(std::wstring portalName, Vector3 setPos, Vector3 mPos, jns::enums::eLayerType type = eLayerType::Portal)
	{
		T* gameobj = new T(portalName, setPos);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->Initialize();

		return gameobj;
	}
	template<typename T>
	T* InstantiateGroundCollider(std::wstring groundName, Vector3 mPos, Vector3 mScale = (Vector3::One),jns::enums::eLayerType type = eLayerType::Ground)
	{
		T* gameobj = new T(groundName);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->GetComponent<Transform>()->SetScale(mScale);
		gameobj->Initialize();

		return gameobj;
	}
	template<typename T>
	T* InstantiateSkill(Vector3 mPos, Vector3 mScale = (Vector3::One), jns::enums::eLayerType type = eLayerType::Skill)
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->GetComponent<Transform>()->SetScale(mScale);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* Instantiate(jns::enums::eLayerType type, Vector3 mPos, Vector3 mScale = (Vector3::One), Vector3 mRotation = (Vector3::Zero))
	{
		T* gameobj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetScale(mScale);
		gameobj->GetComponent<Transform>()->SetRotation(mRotation);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->Initialize();

		return gameobj;
	}

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(jns::GameObject::eState::Dead);
	}

}