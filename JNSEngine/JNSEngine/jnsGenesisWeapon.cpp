#include "jnsGenesisWeapon.h"
#include "CommonSceneInclude.h"

namespace jns
{
	GenesisWeapon::GenesisWeapon()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	GenesisWeapon::~GenesisWeapon()
	{
	}
	void GenesisWeapon::Initialize()
	{
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\proneStab", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\proneIdle", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\stand1", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\swingO1", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\swingO2", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\swingO3", 100, 0.05f);
		at->CreateAnimations(L"..\\Resources\\Weapons\\Genesis\\walk1", 100, 0.05f);
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void GenesisWeapon::Update()
	{
		WeaponBase::Update();
	}
	void GenesisWeapon::LateUpdate()
	{
		WeaponBase::LateUpdate();
	}
	void GenesisWeapon::Render()
	{
		if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerState() != PlayerScript::ePlayerState::Die)
		WeaponBase::Render();
	}
}