#include "jnsMirrorScript.h"
#include "CommonSceneInclude.h"
#include "jnsMirror.h"

namespace jns
{
	void MirrorScript::Initialize()
	{
		mHp = 100.0f;
		isNotPlayed = true;
		isDead = false;
		mSummonMaxTime = 5.0f;


		at = GetOwner()->GetComponent<Animator>();
		at->CompleteEvent(L"MirrorMirrorHit") = std::bind(&MirrorScript::CompleteSunmmon, this);
		at->CompleteEvent(L"MirrorMirrorBomb") = std::bind(&MirrorScript::CompleteAni, this);
		at->CompleteEvent(L"MirrorMirrorSummon") = std::bind(&MirrorScript::CompleteSunmmon, this);
		
	}
	void MirrorScript::Update()
	{
		if (mSummonTime >= mSummonMaxTime + 20.0f)
		{
			mMirrorState = eMirrorState::Bombed;
		}

		CheckSummonTime();
		CheckMirrorHp();
		Activate();
		PlayAnimation();

		// 상태 갱신
		mMirrorPrevState = mMirrorState;
	}
	void MirrorScript::LateUpdate()
	{
		// 체력 갱신
		mPrevHp = mHp;
	}
	void MirrorScript::Render()
	{
	}
	void MirrorScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			PlayerScript * playerscript = other->GetOwner()->GetComponent<PlayerScript>();
			
			if (playerscript->GetPlayerState() == jns::PlayerScript::ePlayerState::Attracted)
			{
				playerscript->SetPlayerHp(0);
				mMirrorState = eMirrorState::Bombed;
			}
		}

		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			if (other->GetOwner()->GetName() == L"AssainHit01")
			{
				int mSkillDmg = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamage();;
				mHp -= mSkillDmg;
			}
			else if (other->GetOwner()->GetName() == L"AssainHit02")
			{
				int mSkillDmg = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamage();;
				mHp -= mSkillDmg;
			}
		}
	}
	void MirrorScript::OnCollisionStay(Collider2D* other)
	{
	}
	void MirrorScript::OnCollisionExit(Collider2D* other)
	{
	}
	void MirrorScript::CheckSummonTime()
	{
		if (GetOwner()->GetState() == GameObject::eState::Active && isNotPlayed == true)
		{
			at->PlayAnimation(L"MirrorMirrorSummon", true);
			isNotPlayed = false;
		}

		if (GetOwner()->GetState() == GameObject::eState::Active)
		{
			mSummonTime += Time::DeltaTime();
		}
	}
	void MirrorScript::CheckMirrorHp()
	{
		if (mHp <= 0.0f)
		{
			mMirrorState = eMirrorState::Bombed;
		}

	}
	void MirrorScript::Activate()
	{
		switch (mMirrorState)
		{
		case eMirrorState::Summon:
			Summon();
			break;
		case eMirrorState::Idle:
			Idle();
			break;
		case eMirrorState::Bombed:
			Bombed();
			break;
		case eMirrorState::Hit:
			Hitted();
			break;
		case eMirrorState::Attract:
			Attracted();
			break;


		}
	}
	void MirrorScript::PlayAnimation()
	{
		if (mMirrorState != mMirrorPrevState)
		{
			switch (mMirrorState)
			{
			case eMirrorState::Summon:
				at->PlayAnimation(L"MirrorMirrorAttractSuccess", true);
				break;
			case eMirrorState::Idle:
				at->PlayAnimation(L"MirrorMirrorIdle", true);
				break;
			case eMirrorState::Bombed:
				at->PlayAnimation(L"MirrorMirrorBomb", true);
				break;
			case eMirrorState::Hit:
				at->PlayAnimation(L"MirrorMirrorHit", true);
				break;
			case eMirrorState::Attract:
				at->PlayAnimation(L"MirrorMirrorAttractSuccess", false);
				break;
			}
		}
	}
	void MirrorScript::CompleteAni()
	{
		isNotPlayed = true;
		mMirrorState = eMirrorState::Summon;
		mHp = 100;
		mSummonTime = 0.0f;
		GetOwner()->SetState(GameObject::eState::Paused);
	}

	void MirrorScript::CompleteSunmmon()
	{
		mMirrorState = eMirrorState::Idle;
	}

	void MirrorScript::Summon()
	{
	}

	void MirrorScript::Idle()
	{
		if (isDead)
		{
			mMirrorState = eMirrorState::Bombed;
			return;
		}

		if (mSummonTime >= mSummonMaxTime)
		{
			mMirrorState = eMirrorState::Attract;
			return;
		}

		if (mHp <= 50.0f)
		{
			mMirrorState = eMirrorState::Hit;
			return;
		}
		else
		{
			mMirrorState = eMirrorState::Idle;
		}

	}

	void MirrorScript::Bombed()
	{
	}

	void MirrorScript::Hitted()
	{
	}

	void MirrorScript::Attracted()
	{
		GameObject* player = SceneManager::GetPlayer();
		PlayerScript* playerscript = player->GetComponent<PlayerScript>();

		if (playerscript->GetPlayerState() == jns::PlayerScript::ePlayerState::Die)
			return;



		Transform* mirrorTr = this->GetOwner()->GetComponent<Transform>();
		playerscript->SetPlayerState(jns::PlayerScript::ePlayerState::Attracted);
		Transform* playertr = player->GetComponent<Transform>();

		Vector3 playerPos = playertr->GetPosition();
		Vector3 mirrorPos = mirrorTr->GetPosition();
		
		float moveSpeed = 100.0f;
		
		if (playerPos.x >= mirrorPos.x - 10.0f)
		{
			playerPos.x -= moveSpeed * Time::DeltaTime();
			playertr->SetPosition(playerPos);
			playerscript->SetPlayerDirection(jns::PlayerScript::PlayerDir::Left);
		}
		else if(playerPos.x <= mirrorPos.x + 10.0f)
		{
			playerPos.x += moveSpeed * Time::DeltaTime();
			playertr->SetPosition(playerPos);
			playerscript->SetPlayerDirection(jns::PlayerScript::PlayerDir::Right);
		}

	}

}