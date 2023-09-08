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
		playerScript = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
		Animator* weaponAnimator = weapon->GetComponent<Animator>();
		int mDir = PlayerScript::GetStaticPlayerDir();
		Vector3 parentPos= tr->GetParent()->GetPosition();
		parentPos.x -= mDir * 11.0f;
		parentPos.y -= 33.0f;
		PlayerScript::ePlayerState type = playerScript->GetPlayerState();

		if (playerScript->GetPlayerState() != playerScript->GetPlayerPrevState())
		{
			weapon->GetComponent<Transform>()->SetRotation(Vector3::Zero);
			weapon->GetComponent<Transform>()->SetPosition(parentPos);
			if (type == PlayerScript::ePlayerState::Idle)
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
			else if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Prone)
			{
				weaponAnimator->PlayAnimation(weaponFrontName + L"proneIdle", false);
			}
			else if (type == PlayerScript::ePlayerState::Jump)
			{
				weaponAnimator->PlayAnimation(weaponFrontName + L"stand1", false);
			}
		}
		if (type == PlayerScript::ePlayerState::Prone)
		{
			parentPos.y -= 10.0f;
			parentPos.x += mDir* 30.0f;
		}
		else if (type == PlayerScript::ePlayerState::Jump)
		{
			parentPos.x += mDir * 22.0f;
			parentPos.y += 32.0f;
			float angle = DegreeToRadian(120.0f * mDir);
			weapon->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, angle));
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