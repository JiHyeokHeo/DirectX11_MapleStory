#include "jnsWeaponObject.h"
#include "CommonSceneInclude.h"
#include "jnsWeaponManager.h"


// 이 친구는 정확하게 빈 상자의 WeaponObject이다. WeaponBox라고 명칭하는게 좋음.
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
		Animator* weaponAnimator = weapon->GetComponent<Animator>();
		
		if (equipweapon == nullptr || equipweapon != weapon)
		{
			weaponFrontName.clear();
			for (const wchar_t& i : weaponName)
			{
				if (i == L'_')
				{
					weaponAnimator->PlayAnimation(weaponFrontName + L"stand1", true);
					equipweapon = weapon;
					break;
				}
				weaponFrontName += i;
			}
		}
		playerScript = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
		int mDir = PlayerScript::GetStaticPlayerDir();
		Vector3 parentPos= tr->GetParent()->GetPosition();
		parentPos.x -= mDir * 11.0f;
		parentPos.y -= 33.0f;
		PlayerScript::ePlayerState type = playerScript->GetPlayerState();
		
		if (playerChangeState != type)
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
		else if (type == PlayerScript::ePlayerState::Attack)
		{
			if (playerScript->GetOwner()->GetComponent<Animator>()->GetActiveAnimation()->GetAnimationName() == L"CharactorCharAssain1Hit")
			{
				parentPos.x -= mDir * 10.0f;
				parentPos.y += 32.0f;
			}
			else if (playerScript->GetOwner()->GetComponent<Animator>()->GetActiveAnimation()->GetAnimationName() == L"CharactorCharAssain2Hit")
			{
				parentPos.x += mDir * 15.0f;
				parentPos.y += 25.0f;
			}
		}
		weapon->GetComponent<Transform>()->SetPosition(parentPos);

		playerChangeState = type;
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
		if(playerScript->GetPlayerState() != PlayerScript::ePlayerState::Die)
		GameObject::Render();
	}
}