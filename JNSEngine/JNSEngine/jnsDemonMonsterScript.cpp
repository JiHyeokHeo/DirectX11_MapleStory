#include "jnsDemonMonsterScript.h"
#include "CommonSceneInclude.h"
#include <random>

std::mt19937_64 rng3(3244);
std::uniform_int_distribution<__int64> dist3(-1, 1);

namespace jns
{
	void DemonMonsterScript::Initialize()
	{
		InitData();
		at = GetOwner()->GetComponent<Animator>();
		cd = GetOwner()->GetComponent<Collider2D>();
		tr = GetOwner()->GetComponent<Transform>();
		cd->SetColNum(1);
		this->SetColNum(1);
	}
	void DemonMonsterScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		CheckChaseTime();
		CheckMonsterHp();
		MonsterControl();
		AnimatorControl();
		mPrevMonsterState = mMonsterState;
		mDemonInfo.mPrevDir = mDemonInfo.mDir;

		at->CompleteEvent(L"Demondm_attack") = std::bind(&DemonMonsterScript::CompleteAttack, this);
		at->CompleteEvent(L"Demondm_die") = std::bind(&DemonMonsterScript::CompleteDead, this);
	}
	void DemonMonsterScript::LateUpdate()
	{
	}
	void DemonMonsterScript::Render()
	{
	}
	void DemonMonsterScript::OnCollisionEnter(Collider2D* other)
	{
		if (mMonsterState == eDemonState::Die)
			return;

		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			GameObject* mPlayer = SceneManager::GetPlayer();
			int mPlayerHp = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().hp;
			float mPlayerInvTime = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().invisibilityTime;

			if (mPlayerInvTime <= 0.0f)
			{
				mPlayerHp -= 20.0f;
				mPlayer->GetComponent<PlayerScript>()->SetPlayerHp(mPlayerHp);
				mPlayer->GetComponent<PlayerScript>()->SetPlayerState(PlayerScript::ePlayerState::Hitted);
			}
		}

		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			mChangeTime = 0.0f;
			if (other->GetOwner()->GetName() == L"AssainHit01")
			{
				int mSkillDmg = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamage();
				mDemonInfo.hp -= mSkillDmg;
				mDemonInfo.isChasing = true;
			}
			else if (other->GetOwner()->GetName() == L"AssainHit02")
			{
				int mSkillDmg = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamage();
				mDemonInfo.hp -= mSkillDmg;
				mDemonInfo.isChasing = true;
			}
		}
	}
	void DemonMonsterScript::OnCollisionStay(Collider2D* other)
	{
		if (mMonsterState == eDemonState::Die)
			return;
		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			GameObject* mPlayer = SceneManager::GetPlayer();
			int mPlayerHp = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().hp;
			float mPlayerInvTime = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().invisibilityTime;

			if (mPlayerInvTime <= 0.0f)
			{
				mPlayerHp -= 20.0f;
				mPlayer->GetComponent<PlayerScript>()->SetPlayerHp(mPlayerHp);
				mPlayer->GetComponent<PlayerScript>()->SetPlayerState(PlayerScript::ePlayerState::Hitted);
			}
		}
	}
	void DemonMonsterScript::OnCollisionExit(Collider2D* other)
	{
	}
	void DemonMonsterScript::MakeRandDir()
	{
		mRandMakeTime += Time::DeltaTime();
		if (mRandMakeTime >= 3.0f)
		{
			mRandDir = dist3(rng3);
			mRandMakeTime = 0.0f;
		}
	}
	void DemonMonsterScript::ChangeBossTypeRandom()
	{
	}
	void DemonMonsterScript::CheckChaseTime()
	{
		if (mChasingTime >= 8.0f)
		{
			mDemonInfo.isChasing = false;
			mChasingTime = 0.0f;
		}

		if (mDemonInfo.isChasing)
		{
			mChasingTime += Time::DeltaTime();
		}
	}
	void DemonMonsterScript::CheckSkillCoolDown()
	{
	}
	void DemonMonsterScript::CheckMonsterHp()
	{
		if (mDemonInfo.hp <= 0)
		{
			mMonsterState = eDemonState::Die;
		}
	}
	void DemonMonsterScript::MonsterControl()
	{
		switch (mMonsterState)
		{
		case eDemonState::Idle:
			Idle();
			break;
		case eDemonState::Move:
			Move();
			break;
		case eDemonState::Attack:
			Attack();
			break;
		case eDemonState::Hit:
			Hit();
			break;
		case eDemonState::Die:
			Die();
			break;
		default:
			break;
		}
	}
	void DemonMonsterScript::AnimatorControl()
	{
		if (mMonsterState != mPrevMonsterState || mDemonInfo.mDir != mDemonInfo.mPrevDir)
		{
			mAnimatorPlaying = true;
			switch (mMonsterState)
			{
			case eDemonState::Idle:
				at->PlayAnimation(L"Demondm_Idle", true);
				break;
			case eDemonState::Move:
				at->PlayAnimation(L"Demondm_move", true);
				break;
			case eDemonState::Attack:
				at->PlayAnimation(L"Demondm_attack", true);
				break;
			case eDemonState::Hit:
				at->PlayAnimation(L"Demondm_hit", true);
				break;
			case eDemonState::Die:
				at->PlayAnimation(L"Demondm_die", true);
				break;
			default:
				break;
			}
		}
	}
	void DemonMonsterScript::Idle()
	{
		if (mRandDir != 0 && mDemonInfo.isChasing == false)
		{
			mMonsterState = eDemonState::Move;
		}

		if (mDemonInfo.isChasing == true)
		{
			mMonsterState = eDemonState::Move;
		}

		PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
		Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();
		if (mPlayerPos.x >= mMonsterPos.x)
		{
			mDemonInfo.mDir = MonsterBase::MonsterDir::Right;
		}
		else if (mPlayerPos.x <= mMonsterPos.x)
		{
			mDemonInfo.mDir = MonsterBase::MonsterDir::Left;
		}
	}
	void DemonMonsterScript::Move()
	{
		Vector3 mMonsterPos = tr->GetPosition();
		if (mMonsterPos.x >= 2000)
		{
			mRandDir = -1;
		}
		else if (mMonsterPos.x <= -2000)
		{
			mRandDir = 1;
		}

		if (mDemonInfo.isChasing == false)
		{
			if (mRandDir == -1)
			{
				mMonsterPos.x -= 50.0f * Time::DeltaTime();
				mDemonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
			else if (mRandDir == 1)
			{
				mMonsterPos.x += 50.0f * Time::DeltaTime();
				mDemonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else
			{
				mMonsterState = eDemonState::Idle;
			}
		}
		else
		{
			PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
			Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
			if (mPlayerPos.x >= mMonsterPos.x)
			{
				mMonsterPos.x += 50.0f * Time::DeltaTime();
				mDemonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else if (mPlayerPos.x <= mMonsterPos.x)
			{
				mMonsterPos.x -= 50.0f * Time::DeltaTime();
				mDemonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
		}

		tr->SetPosition(mMonsterPos);
	}
	void DemonMonsterScript::Attack()
	{
		mAttackColChangeTime += Time::DeltaTime();

		if (mAttackColChangeTime >= 0.5f)
		{
			cd->SetSize(Vector2(0.6f, 0.5f));
		}
	}
	void DemonMonsterScript::Hit()
	{
	}
	void DemonMonsterScript::Die()
	{
	}
	void DemonMonsterScript::InitData()
	{
		mDemonInfo.hp = 100;
		mDemonInfo.isChasing = false;
	}
	void DemonMonsterScript::CompleteAttack()
	{
		cd->SetSize(Vector2(0.25f, 0.4f));
		mMonsterState = eDemonState::Idle;
		mAttackColChangeTime = 0.0f;
	}
	void DemonMonsterScript::CompleteDead()
	{
		GetOwner()->SetState(GameObject::eState::Paused);
	}
}