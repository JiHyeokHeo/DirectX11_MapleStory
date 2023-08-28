#include "jnsWeaponObject.h"
#include "CommonSceneInclude.h"
#include "jnsWeaponManager.h"

namespace jns
{
	WeaponObject::WeaponObject()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	WeaponObject::~WeaponObject()
	{
	}
	void WeaponObject::Initialize()
	{
		tr = GetComponent<Transform>();
	}
	void WeaponObject::Update()
	{
		// 여기는 추후에 아이템을 끼고있는 정보를 불러 가져오도록 구조를 바꾸자.
		weapon = WeaponManager::FindWeapon(L"Genesis_Thief_Weapon");
		
		std::wstring weaponName = WeaponManager::FindWeaponData(L"Genesis_Thief_Weapon")->GetWeaponName();
		std::wstring weaponFrontName = {};
		for (const wchar_t& i : weaponName)
		{
			if (i == L'_')
				break;
			weaponFrontName += i;
		}

		//	Idle,
		//	Move,
		//	Ladder,
		//	Jump,
		//	Prone,
		//	Attack,
		//	Hitted,
		//	Die,
		//	Attracted,
		//	End,

		Animator* weaponAnimator = weapon->GetComponent<Animator>();
		int mDir = (int)playerScript->GetPlayerDirection();
		Vector3 parentPos= tr->GetParent()->GetPosition();
		parentPos.x -= mDir * 15.0f;
		parentPos.y -= 30.0f;
		if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Idle)
		{
			weaponAnimator->PlayAnimation(weaponFrontName + L"stand1", true);
		}
		else if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Move)
		{
			weaponAnimator->PlayAnimation(weaponFrontName + L"walk1", true);
		}
		else if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Attack)
		{
			if (playerScript->GetOwner()->GetComponent<Animator>()->GetActiveAnimation()->GetAnimationName() == L"CharactorCharAssain1Hit")
			{
				weaponAnimator->PlayAnimation(weaponFrontName + L"swingO1", false);
			}
			else if (playerScript->GetOwner()->GetComponent<Animator>()->GetActiveAnimation()->GetAnimationName() == L"CharactorCharAssain2Hit")
			{
				weaponAnimator->PlayAnimation(weaponFrontName + L"swingO2", false);
			}
		}
		
		weapon->GetComponent<Transform>()->SetPosition(parentPos);
		GameObject::Update();
	}
	void WeaponObject::LateUpdate()
	{

		// 좌우 조정
		int mDir = (int)playerScript->GetPlayerDirection();
		Animator* weaponAnimator = weapon->GetComponent<Animator>();
		if (weaponAnimator->GetActiveAnimation() != nullptr)
		{
			if (mDir == -1)
			{
				weaponAnimator->GetActiveAnimation()->SetAniDirection(false);
			}
			else
			{
				weaponAnimator->GetActiveAnimation()->SetAniDirection(true);
			}
		}


		GameObject::LateUpdate();
	}
	void WeaponObject::Render()
	{
		GameObject::Render();
	}
}