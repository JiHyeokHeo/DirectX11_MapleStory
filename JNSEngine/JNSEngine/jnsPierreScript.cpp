#include "jnsPierreScript.h"
#include "CommonSceneInclude.h"
#include "jnsPierreBoss.h"
#include "ObjectTemplate.h"
#include "jnsPierreHat.h"
#include "jnsPierreHatScript.h"
// 블러디퀸 좌우 움직임 
extern std::mt19937_64 rng1;
extern std::uniform_int_distribution<__int64> dist1;

// 알기론 이 친구는 몸박데미지 있는거로 아는데..

namespace jns
{
	void PierreScript::Initialize()
	{
		
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\attack1", 1000, 0.15f, Vector2(-0.013f, 0.115f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\attack2", 1000, 0.15f, Vector2(-0.015f, 0.050f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\move", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\transform", 1000, 0.15f, Vector2(0.0125f, -0.02f));

		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\attack1", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\transform", 1000, 0.15f, Vector2(-0.0035f, -0.019f));

		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\attack1", 1000, 0.15f, Vector2(-0.013f, 0.115f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\attack2", 1000, 0.15f, Vector2(-0.015f, 0.050f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\move", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\transform", 1000, 0.15f, Vector2(-0.0035f, -0.019f));

		for (int i = -4; i <= 4 ; i++)
		{
			mHats.push_back(object::Instantiate<PierreHat>(eLayerType::Monster, Vector3(300.0f * i, -430.0f, 3.0f)));
		}

		at = GetOwner()->GetComponent<Animator>();
		cd = GetOwner()->GetComponent<Collider2D>();
		tr = GetOwner()->GetComponent<Transform>();
		cd->SetColNum(1);
		this->SetColNum(1);

		at->CompleteEvent(L"NormalPierreattack1") = std::bind(&PierreScript::CompleteAttack, this);
		at->CompleteEvent(L"NormalPierreattack2") = std::bind(&PierreScript::CompleteAttack, this);
		at->CompleteEvent(L"NormalPierredie1") = std::bind(&PierreScript::CompleteDie, this);
		at->CompleteEvent(L"NormalPierretransform") = std::bind(&PierreScript::CompleteChange, this);
		at->CompleteEvent(L"NormalPierretransform2") = std::bind(&PierreScript::CompleteChange2, this);
		//at->StartEvent(L"NormalPierretransform2") = std::bind(&PierreScript::StartTransform, this);

		at->CompleteEvent(L"RedPierreattack1") = std::bind(&PierreScript::CompleteAttack, this);
		at->CompleteEvent(L"RedPierredie1") = std::bind(&PierreScript::CompleteDie, this);
		at->CompleteEvent(L"RedPierretransform") = std::bind(&PierreScript::CompleteChange, this);
		at->CompleteEvent(L"RedPierretransform2") = std::bind(&PierreScript::CompleteChange2, this);
		at->CompleteEvent(L"RedPierreskill1") = std::bind(&PierreScript::CompleteSkill1, this);
		at->CompleteEvent(L"RedPierreskillAfter1") = std::bind(&PierreScript::CompleteskillAfter1, this);
		at->CompleteEvent(L"RedPierreattack2") = std::bind(&PierreScript::CompleteAttack, this);

		//at->CompleteEvent(L"BluePierretransform") = std::bind(&PierreScript::CompleteAttack, this);
		at->CompleteEvent(L"BluePierredie1") = std::bind(&PierreScript::CompleteDie, this);
		at->CompleteEvent(L"BluePierretransform") = std::bind(&PierreScript::CompleteChange, this);
		at->CompleteEvent(L"BluePierretransform2") = std::bind(&PierreScript::CompleteChange2, this);
		//at->StartEvent(L"BluePierretransform2") = std::bind(&PierreScript::StartTransform, this);
			

		mMonsterState = ePierreState::Idle;
		pierreInfo.mBossType = ePierreType::Normal;
		monsterCommonInfo.maxhp = 100;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
		
		//mPierre = dynamic_cast<PierreBoss*>(GetOwner());
	}
	void PierreScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		CheckChaseTime();
		CheckSkillCoolDown();
		UseTransformSkill();
		CheckBossHp();
		CheckBossType();
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
	
		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			PlayerScript* player = other->GetOwner()->GetComponent<PlayerScript>();
			int maxhp = player->GetPlayerInfo().maxhp;
			monsterCommonInfo.dmg = maxhp / 10;
			DamageDisplay::DamageToPlayer(monsterCommonInfo, other);
		}
	}
	void PierreScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			PlayerScript* player = other->GetOwner()->GetComponent<PlayerScript>();
			int maxhp = player->GetPlayerInfo().maxhp;
			monsterCommonInfo.dmg = maxhp / 10;
			DamageDisplay::DamageToPlayer(monsterCommonInfo, other);
		}
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
	}
	void PierreScript::CheckBossType()
	{	
		// 보스체력을 보면서 체인지 타입
		float hpratio = {};
		hpratio = (float)monsterCommonInfo.hp / monsterCommonInfo.maxhp;

		// 첫변경
		if (hpratio <= 0.7 && mMonsterState != ePierreState::Die && isChanged == false)
		{
			isChanging = true;
			isFirstChange = true;
			isChanged = true;
			mMonsterState = ePierreState::Change;
		}

		// 변경 된 후에 시간 측정
		if (isChanged)
		{
			mChangeType += Time::DeltaTime();
			if (mChangeType >= 15.0f)
			{
				isChanging = true;
				mMonsterState = ePierreState::Change;
				mChangeType = 0.0f;
			}
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
	void PierreScript::CompleteAttack()
	{
		mMonsterState = ePierreState::Idle;
	}
	void PierreScript::CompleteDie()
	{
		GetOwner()->SetState(GameObject::eState::Paused);
	}
	void PierreScript::CompleteChange()
	{
		std::wstring ani = L"transform2";
		name += ani;
		at->PlayAnimation(name, true);
	}
	void PierreScript::CompleteChange2()
	{
		mMonsterState = ePierreState::Idle;
		isChanging = false;
	}
	void PierreScript::CompleteSkill1()
	{
		Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();
		mMonsterPos.x = mPlayerPos.x;
		tr->SetPosition(mMonsterPos);
		at->PlayAnimation(L"RedPierreskillAfter1", true);
	}
	void PierreScript::CompleteskillAfter1()
	{
		at->PlayAnimation(L"RedPierreattack2", true);
	}
	void PierreScript::UseTransformSkill()
	{
		Vector3 mMonsterPos = tr->GetOwner()->GetComponent<Transform>()->GetPosition();
		PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
		Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
		
		if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown && mMonsterState != ePierreState::Change && mMonsterState != ePierreState::SpecialAttack && mMonsterState != ePierreState::Attack)
		{
			if (mPlayerPos.x - 250.0f < mMonsterPos.x)
			{
				mMonsterState = ePierreState::SpecialAttack;
			}
			else if(mPlayerPos.x + 250.0f > mMonsterPos.x)
			{
				mMonsterState = ePierreState::SpecialAttack;
			}
		}
	}
	void PierreScript::StartTransform()
	{
		Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();
		mMonsterPos.x = mPlayerPos.x;
		tr->SetPosition(mMonsterPos);
	}
	void PierreScript::Idle()
	{
		if (mPrevMonsterState == ePierreState::Change)
		{
			checkStandTime = true;
		}

		if (checkStandTime)
		{
			mStandTime += Time::DeltaTime();
			if (mStandTime <= 1.0f)
			{
				return;
			}
			else
			{
				checkStandTime = false;
				mStandTime = 0.0f;
			}
		}

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

		//if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
		//{
		//	mMonsterState = ePierreState::SpecialAttack;
		//}
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

		if (pierreInfo.mBossType == ePierreType::Blue)
		{
			PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
			Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
			if (mPlayerPos.x - 50.0f > mMonsterPos.x)
			{
				mMonsterPos.x += 100.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else if (mPlayerPos.x + 50.0f <= mMonsterPos.x)
			{
				mMonsterPos.x -= 100.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
		}
		else
		{
			if (monsterCommonInfo.isChasing == false)
			{
				if (mRandDir == -1)
				{
					mMonsterPos.x -= 100.0f * Time::DeltaTime();
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
				}
				else if (mRandDir == 1)
				{
					mMonsterPos.x += 100.0f * Time::DeltaTime();
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
				if (mPlayerPos.x - 50.0f > mMonsterPos.x)
				{
					mMonsterPos.x += 100.0f * Time::DeltaTime();
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
				}
				else if (mPlayerPos.x + 50.0f <= mMonsterPos.x)
				{
					mMonsterPos.x -= 100.0f * Time::DeltaTime();
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
				}
			}
		}

	/*	if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
		{
			mMonsterState = ePierreState::SpecialAttack;
		}*/

		tr->SetPosition(mMonsterPos);
	}
	void PierreScript::Attack()
	{
	}
	void PierreScript::Change()
	{
		mChangeTime += Time::DeltaTime();

		if (isChanging == true)
		{
			isChanging = false;

			float hpratio = {};
			hpratio = (float)monsterCommonInfo.hp / monsterCommonInfo.maxhp;
			if (hpratio <= 0.7)
			{
				mChangeTime = 0;
				int typeNum = rand();
				if (isFirstChange == false)
				{
					typeNum %= 3;
				}

				if (pierreInfo.mBossType == ePierreType::Normal)
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
					pierreInfo.mBossType = (ePierreType)typeNum;
				}
				else if (pierreInfo.mBossType == ePierreType::Blue)
				{
					pierreInfo.mBossType = ePierreType::Normal;
				}
				else if (pierreInfo.mBossType == ePierreType::Red)
				{
					pierreInfo.mBossType = ePierreType::Normal;
				}

				// 내가 만약에 처음으로 70퍼 이하를 깠다. 
				if (typeNum == 0 && isFirstChange)
				{
					isFirstChange = false;
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
			}
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
		std::wstring animationNameATT2 = L"attack2";
		std::wstring animationNameCHANGE = L"transform";
		std::wstring animationNameDIE = L"die1";

		
		if (mMonsterState != mPrevMonsterState || monsterCommonInfo.mDir != monsterCommonInfo.mPrevDir)
		{
			mAnimatorPlaying = true;
			switch (mMonsterState)
			{
			case ePierreState::Idle:
				name += animationNameIDLE;
				at->PlayAnimation(name, true);
				break;
			case ePierreState::Move:
				if (pierreInfo.mBossType == ePierreType::Blue)
				{
					name += animationNameATT;
				}
				else
				{
					name += animationNameWALK;
				}
				at->PlayAnimation(name, true);
				break;
			case ePierreState::Attack:
				if (pierreInfo.mBossType == ePierreType::Normal)
				{
					if (usednormalAttackCnt <= 1)
					{
						usednormalAttackCnt++;
						name += animationNameATT;
						mUsingSkillName = animationNameATT;
					}
					else
					{
						usednormalAttackCnt = 0;
						name += animationNameATT2;
						mUsingSkillName = animationNameATT2;
					}
				}
				else
				{
					name += animationNameATT;
					mUsingSkillName = animationNameATT;
				}
				at->PlayAnimation(name, true);
				break;
			case ePierreState::Die:
				name += animationNameDIE;
				at->PlayAnimation(name, true);
				break;
			case ePierreState::SpecialAttack:
				PlaySpecialAttackAnimation(name);
				break;
			case ePierreState::Change:
				name += animationNameCHANGE;
				at->PlayAnimation(name, true);
				break;
			default:
				break;
			}
		}
		

		//if (mMonsterState != mPrevMonsterState)
		//{
		//	switch (mMonsterState)
		//	{
		//	case ePierreState::Change:
		//		name += animationNameCHANGE;
		//		at->PlayAnimation(name, true);
		//		break;
		//	default:
		//		break;
		//	}
		//}
	}
	void PierreScript::CheckSkillCoolDown()
	{
		monsterCommonInfo.skillCoolDown += Time::DeltaTime();

		if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
		{
			for (PierreHat* hat : mHats)
			{
				hat->GetComponent<PierreHatScript>()->Activate();
			}
		}
	}
	void PierreScript::PlaySpecialAttackAnimation(std::wstring animationname)
	{
		Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();
		
		std::wstring animationNameTransform = L"transform";
		std::wstring animationNameSkill1 = L"skill1";

		//mPatternPercentage = dist2(rng2);

		mAnimatorPlaying = true;

		if (pierreInfo.mBossType == ePierreType::Normal)
		{
			mMonsterState = ePierreState::Idle;
		}
		else if (pierreInfo.mBossType == ePierreType::Blue)
		{
			mMonsterState = ePierreState::Idle;
		}
		else if (pierreInfo.mBossType == ePierreType::Red)
		{
			animationname += animationNameSkill1;
			at->PlayAnimation(animationname, true);
		}

		// 플레이 되면 무조건 쿨 줄이기
		mUsingSkillName = animationname;
		monsterCommonInfo.skillCoolDown = 0.0f;
		mAnimatorPlaying = true;
	}
	void PierreScript::ResetData()
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
		{
			GetOwner()->SetState(GameObject::eState::Active);
		}
		tr->SetPosition(Vector3(0.0f, -370.0f, 3.0f));
		mMonsterState = ePierreState::Idle;
		pierreInfo.mBossType = ePierreType::Normal;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
		mChangeType = 0.0f;
		mRandMakeTime = 0.0f;
		mStandTime = 0.0f;
		checkStandTime = false;
		usednormalAttackCnt = 0;
		isFirstChange = false;
		mChangeTime = 0.0f;
		isChanging = false;
		isChanged = false;
		mAnimatorPlaying = false;
	}
}