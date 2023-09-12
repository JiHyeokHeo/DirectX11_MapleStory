#pragma once
#include "jnsEnums.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"
#include "jnsItemResources.h"
#include "jnsBGInstance.h"
#include "jnsSkillUIBTN.h"
#include "jnsSkillManager.h"
#include "jnsSkillResources.h"
#include "jnsQuickSlotFront.h"
#include "jnsBGobject.h"

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
	T* InstantiateAniObjects(jns::enums::eLayerType type, BGobject::eBGObjectType type2, Vector3 setPos)
	{
		T* gameobj = new T();
		gameobj->BGobject::SetBGObjectType(type2);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();
		gameobj->GetComponent<Transform>()->SetPosition(setPos);
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
	T* InstantiatePortal(jns::enums::eSceneType destiationSceneType, Vector3 setPos, Vector3 mPos, jns::enums::eLayerType type = eLayerType::Portal)
	{
		T* gameobj = new T(destiationSceneType, setPos);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->GetComponent<Transform>()->SetPosition(mPos);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiateSkillBTN(jns::enums::eLayerType type, SkillUIBTN::eSkillUIBTN type2)
	{
		T* gameobj = new T(type2);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(type, gameobj);
		gameobj->Initialize();

		return gameobj;
	}

	template<typename T>
	T* InstantiateDirPortal(jns::enums::eSceneType destiationSceneType, Vector3 setPos, Vector3 mPos, int dir = 0, jns::enums::eLayerType type = eLayerType::Portal)
	{
		T* gameobj = new T(destiationSceneType, setPos, dir);
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

		SkillManager::AddSkill(gameobj->GetName(), gameobj);
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

	template<typename T>
	T* InstantiateSkillUIType(SkillResources::eSkillType type, QuickSlotUI* slot, SkillUIBG* bg, Vector3 mPos, bool isItIcon, Vector3 mScale = (Vector3::One), Vector3 mRotation = (Vector3::Zero))
	{
		T* gameobj = new T(type);
		gameobj->SkillResources::SetSkillUIBG(bg);
		gameobj->SkillResources::SetThisIsIcon(isItIcon);
		gameobj->SkillResources::SetQuickSlotUI(slot);
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(eLayerType::UI, gameobj);
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