#include "jnsPierreScript.h"
#include "CommonSceneInclude.h"
#include "jnsPierreBoss.h"
// 블러디퀸 좌우 움직임 
extern std::mt19937_64 rng1;
extern std::uniform_int_distribution<__int64> dist1;

namespace jns
{
	void PierreScript::Initialize()
	{
		at = GetOwner()->GetComponent<Animator>();
		cd = GetOwner()->GetComponent<Collider2D>();
		tr = GetOwner()->GetComponent<Transform>();
		mMonsterState = ePierreState::Idle;
		pierreInfo.mBossType = ePierreType::Normal;
		monsterCommonInfo.maxhp = 1000;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
		//mPierre = dynamic_cast<PierreBoss*>(GetOwner());
	}
	void PierreScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		CheckChaseTime();
		CheckBossHp();
		MonsterControl();
		AnimatorControl();

		// 위치 갱신
		mPrevMonsterState = mMonsterState;
		monsterCommonInfo.mPrevDir = monsterCommonInfo.mDir;
	}
	void PierreScript::LateUpdate()
	{
		UpdateBossHp();
		SetAniDir();
	}
	void PierreScript::Render()
	{
	}
	void PierreScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			DamageDisplay::DamageToMonsterWithSkill(monsterCommonInfo, other, tr, Vector2(-25.0f, 120.0f));
		}
	}
	void PierreScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PierreScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PierreScript::InitData()
	{
	}
	void PierreScript::MakeRandDir()
	{
		mRandMakeTime += Time::DeltaTime();
		if (mRandMakeTime >= 3.0f)
		{
			mRandDir = dist1(rng1);
			mRandMakeTime = 0.0f;
		}
	}
	void PierreScript::CheckChaseTime()
	{
		if (mChasingTime >= 8.0f)
		{
			monsterCommonInfo.isChasing = false;
			mChasingTime = 0.0f;
		}

		if (monsterCommonInfo.isChasing)
		{
			mChasingTime += Time::DeltaTime();
		}
	}
	void PierreScript::CheckBossHp()
	{
		if (monsterCommonInfo.hp <= 0)
		{
			mMonsterState = ePierreState::Die;
		}


		// 보스체력을 보면서 체인지 타입
		float hpratio = {};
		hpratio = (float)monsterCommonInfo.hp / monsterCommonInfo.maxhp;

		if (hpratio <= 0.7 && mMonsterState != ePierreState::Die)
		{
			mMonsterState = ePierreState::Change;
		}
	}
	void PierreScript::UpdateBossHp()
	{	
		// 상시로 몬스터 베이스로 체력 정보를 넘겨준다.
		MonsterBase* monsterbase = dynamic_cast<MonsterBase*>(GetOwner());
		monsterbase->SetMonsterStatusHp(monsterCommonInfo.hp);
		monsterbase->SetMonsterStatusMaxHp(monsterCommonInfo.maxhp);
	}
	void PierreScript::SetAniDir()
	{
		if ((int)monsterCommonInfo.mDir == -1)
		{
			at->GetActiveAnimation()->SetAniDirection(false);
		}
		else if ((int)monsterCommonInfo.mDir == 1)
		{
			at->GetActiveAnimation()->SetAniDirection(true);
		}
	}
	void PierreScript::Idle()
	{
		if (mRandDir != 0 && mPrevMonsterState != ePierreState::Change && monsterCommonInfo.isChasing == false)
		{
			mMonsterState = ePierreState::Move;
		}

		if (monsterCommonInfo.isChasing == true)
		{
			mMonsterState = ePierreState::Move;
		}

		PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
		Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();
		if (mPlayerPos.x >= mMonsterPos.x)
		{
			monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
		}
		else if (mPlayerPos.x <= mMonsterPos.x)
		{
			monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
		}

		if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
		{
			mMonsterState = ePierreState::SpecialAttack;
		}
	}
	void PierreScript::Move()
	{
		Vector3 mMonsterPos = tr->GetPosition();
		if (mMonsterPos.x >= 950)
		{
			mRandDir = -1;
		}
		else if (mMonsterPos.x <= -900)
		{
			mRandDir = 1;
		}

		if (monsterCommonInfo.isChasing == false)
		{
			if (mRandDir == -1)
			{
				mMonsterPos.x -= 155.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
			else if (mRandDir == 1)
			{
				mMonsterPos.x += 155.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else
			{
				mMonsterState = ePierreState::Idle;
			}
		}
		else
		{
			PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
			Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
			if (mPlayerPos.x >= mMonsterPos.x)
			{
				mMonsterPos.x += 155.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else if (mPlayerPos.x <= mMonsterPos.x)
			{
				mMonsterPos.x -= 155.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
		}

		//Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		//if (monsterCommonInfo.isChasing == true)
		//{
		//	if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
		//	{
		//		mMonsterState = ePierreState::SpecialAttack;
		//	}
		//}
		//else
		//{
		//	mMonsterState = ePierreState::SpecialAttack;
		//}


		tr->SetPosition(mMonsterPos);
	}
	void PierreScript::Attack()
	{
	}
	void PierreScript::Change()
	{
		// 변신을 완료하면 Idle 상태로 넘어가게
		mChangeTime += Time::DeltaTime();

		if (mChangeTime >= 0.5f)
		{
			mMonsterState = ePierreState::Idle;
			mChangeTime = 0.0f;
			isChanging = false;
			return;
		}

		if (isChanging == false)
			return;

		// 체력에 비례해서 변경되게 해주자
		float hpratio = {};

		hpratio = (float)monsterCommonInfo.hp / monsterCommonInfo.maxhp;
		
		if (hpratio <= 0.7)
		{
			isFirstChange = true;
			mChangeTime = 0;
			int typeNum = rand();
			typeNum %= 3;
			// 내가 만약에 처음으로 70퍼 이하를 깠다. 
			if (typeNum == 0 && isFirstChange)
			{
				int random = rand();
				random %= 2;
				
				if (random == 0)
				{
					typeNum = 1;
				}
				else
				{
					typeNum = 2;
				}
			}
			else if (pierreInfo.mBossType == ePierreType::Blue)
			{
				pierreInfo.mBossType = ePierreType::Red;
			}
			else if (pierreInfo.mBossType == ePierreType::Red)
			{
				pierreInfo.mBossType = ePierreType::Blue;
			}
			pierreInfo.mBossType = (ePierreType)typeNum;
		}
	}
	void PierreScript::Die()
	{
	}
	void PierreScript::SpecialAttack()
	{
		

	}
	void PierreScript::MonsterControl()
	{
		switch (mMonsterState)
		{
		case ePierreState::Idle:
			Idle();
			break;
		case ePierreState::Move:
			Move();
			break;
		case ePierreState::Attack:
			Attack();
			break;
		case ePierreState::SpecialAttack:
			SpecialAttack();
			break;
		case ePierreState::Change:
			Change();
			break;
		case ePierreState::Die:
			Die();
			break;
		default:
			break;
		}
	}
	void PierreScript::AnimatorControl()
	{
		std::wstring name = {};

		if (pierreInfo.mBossType == ePierreType::Normal)
		{
			name = L"NormalPierre";
		}
		else if (pierreInfo.mBossType == ePierreType::Blue)
		{
			name = L"BluePierre";
		}
		else if (pierreInfo.mBossType == ePierreType::Red)
		{
			name = L"RedPierre";
		}
	

		// 상시 갱신
		pierreInfo.mBossPrevType = pierreInfo.mBossType;

		std::wstring animationNameIDLE = L"stand";
		std::wstring animationNameWALK = L"move";
		std::wstring animationNameATT = L"attack1";
		std::wstring animationNameCHANGE = L"transform";
		std::wstring animationNameDIE = L"die1";


		if (mMonsterState != mPrevMonsterState || monsterCommonInfo.mDir != monsterCommonInfo.mPrevDir)
		{
			switch (mMonsterState)
			{
			case ePierreState::Idle:
				name += animationNameIDLE;
				at->PlayAnimation(name, true);
				break;
			case ePierreState::Move:
				name += animationNameWALK;
				at->PlayAnimation(name, true);
				break;
			case ePierreState::Attack:
				name += animationNameATT;
				at->PlayAnimation(name, true);
				mUsingSkillName = animationNameATT;
				break;
			case ePierreState::Die:
				name += animationNameDIE;
				at->PlayAnimation(name, true);
				break;
			case ePierreState::SpecialAttack:
				PlaySpecialAttackAnimation(name);
				break;
			default:
				break;
			}
		}

		if (mMonsterState != mPrevMonsterState)
		{
			switch (mMonsterState)
			{
			case ePierreState::Change:
				name += animationNameCHANGE;
				at->PlayAnimation(name, true);
				isChanging = true;
				break;
			default:
				break;
			}
		}
	}
	void PierreScript::PlaySpecialAttackAnimation(std::wstring animationname)
	{
	}
	void PierreScript::ResetData()
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
		{
			GetOwner()->SetState(GameObject::eState::Active);
		}
		tr->SetPosition(Vector3(150.0f, -160.0f, 3.0f));
		mMonsterState = ePierreState::Idle;
		pierreInfo.mBossType = ePierreType::Normal;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
		isFirstChange = false;
	}
}