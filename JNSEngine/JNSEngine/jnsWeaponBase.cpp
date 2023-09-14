#include "jnsWeaponBase.h"
#include "jnsTransform.h"
#include "jnsMeshRenderer.h"
#include "jnsResources.h"
#include "jnsAnimation.h"
#include "jnsSceneManager.h"
#include "jnsPlayerScript.h"

namespace jns
{
	WeaponBase::WeaponBase()
	{
		mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr = GetComponent<Transform>();
		at = AddComponent<Animator>();
	}
	WeaponBase::~WeaponBase()
	{
	}
	void WeaponBase::Initialize()
	{
		
	}
	void WeaponBase::Update()
	{
		GameObject::Update();
	}
	void WeaponBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void WeaponBase::Render()
	{
		if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerState() != PlayerScript::ePlayerState::Die)
		GameObject::Render();
	}
}