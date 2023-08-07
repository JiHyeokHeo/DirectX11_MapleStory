#include "jnsBloodyQueenScript.h"
#include "CommonSceneInclude.h"
#include <random>

std::mt19937_64 rng1(3244);
std::uniform_int_distribution<__int64> dist1(-1, 1);


namespace jns
{
	void BloodyQueenScript::Initialize()
	{
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttack", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 1500, 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenHitMotion", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress1", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress2", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress3", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress4", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff", 1500, 0.15f, Vector2(0.006f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.02f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQChangeType", 1500, 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff1", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff2", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff3", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQNormalAttack", 700, 0.15f, Vector2(-0.01f, -0.02f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQChangeType", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQNormalAttack", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSummon", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallow", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallowEnd", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallowLoop", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->PlayAnimation(L"NormalBloodyQueenNBQWalk", true);
		
		InitData();

		at = GetOwner()->GetComponent<Animator>();
		cd = GetOwner()->GetComponent<Collider2D>();
		tr = GetOwner()->GetComponent<Transform>();

		mMonsterState = eBloodyQueenState::Idle;
		mBloodyQueenInfo.mBossType = eBloodyQueenType::Normal;
		mBloodyQueenInfo.hp = 100;
		
		at->CompleteEvent(L"AttractionBloodyQueenATBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni1, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni2, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni3, this);
	}
	void BloodyQueenScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		ChangeBossTypeRandom();
		CheckChaseTime();
		PlayerControl();
		AnimatorControl();
		mPrevMonsterState = mMonsterState;
		mBloodyQueenInfo.mPrevDir = mBloodyQueenInfo.mDir;
	}
	void BloodyQueenScript::LateUpdate()
	{
	}
	void BloodyQueenScript::Render()
	{

	}
	void BloodyQueenScript::OnCollisionEnter(Collider2D* other)
	{
		if(other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			if (other->GetOwner()->GetName() == L"AssainHit01")
			{
				int mSkillDmg = SkillManager::FindSkillDamage(L"Normal_Assain_First_Attack");
				mBloodyQueenInfo.hp -= mSkillDmg;
				isChasing = true;
			}
			else if(other->GetOwner()->GetName() == L"AssainHit02")
			{
			}
		}
	}
	void BloodyQueenScript::OnCollisionStay(Collider2D* other)
	{
	}
	void BloodyQueenScript::OnCollisionExit(Collider2D* other)
	{
	}
	void BloodyQueenScript::InitData()
	{
		isChasing = false;
		mRandMakeTime = 0.0f;
		mChasingTime = 0.0f;
		mChangeType = 0.0f;
	}
	void BloodyQueenScript::MakeRandDir()
	{
		mRandMakeTime += Time::DeltaTime();
		if (mRandMakeTime >= 3.0f)
		{
			mRandDir = dist1(rng1);
			mRandMakeTime = 0.0f;
		}
	}
	void BloodyQueenScript::ChangeBossTypeRandom()
	{
		mChangeType += Time::DeltaTime();
		if (mChangeType >= 15.0f)
		{
			mMonsterState = eBloodyQueenState::Change;
			mChangeType = 0.0f;
		}
	}
	void BloodyQueenScript::CheckChaseTime()
	{
		if (mChasingTime >= 8.0f)
		{
			isChasing = false;
			mChasingTime = 0.0f;
		}

		if (isChasing)
		{
			mChasingTime += Time::DeltaTime();
		}
	}
	void BloodyQueenScript::CompleteChangeTypeAni()
	{
		mMonsterState = eBloodyQueenState::Idle;
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni1()
	{
		mMonsterState = eBloodyQueenState::Idle;
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni2()
	{
		mMonsterState = eBloodyQueenState::Idle;
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni3()
	{
		mMonsterState = eBloodyQueenState::Idle;
		isChanging = false;
	}
	void BloodyQueenScript::Idle()
	{
		if (mRandDir != 0 && mPrevMonsterState != eBloodyQueenState::Change)
		{
			if(isChasing == false)
				mMonsterState = eBloodyQueenState::Move;
		}

		if (isChasing == true)
		{
			mMonsterState = eBloodyQueenState::Move;
		}
	}
	void BloodyQueenScript::Move()
	{
		Vector3 mMonsterPos = tr->GetPosition();
		
		if (isChasing == false)
		{
			if (mRandDir == -1)
			{
				mMonsterPos.x -= 25.0f * Time::DeltaTime();
				mBloodyQueenInfo.mDir = MonsterBase::MonsterDir::Left;
			}
			else if (mRandDir == 1)
			{
				mMonsterPos.x += 25.0f * Time::DeltaTime();
				mBloodyQueenInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else
			{
				mMonsterState = eBloodyQueenState::Idle;
			}
		}
		else
		{
			PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
			PlayerScript::PlayerDir mPlayerDir = player->GetPlayerDirection();
			if ((int)mPlayerDir == -1)
			{
				mMonsterPos.x += 25.0f * Time::DeltaTime();
				mBloodyQueenInfo.mDir = MonsterBase::MonsterDir::Left;
			}
			else if ((int)mPlayerDir == 1)
			{
				mMonsterPos.x -= 25.0f * Time::DeltaTime();
				mBloodyQueenInfo.mDir = MonsterBase::MonsterDir::Right;
			}
		}
		
		
		tr->SetPosition(mMonsterPos);
	}
	void BloodyQueenScript::Attack()
	{
	}
	void BloodyQueenScript::Change()
	{
		mChangeTime += Time::DeltaTime();
		if (mChangeTime >= 3.0f)
		{
			mMonsterState = eBloodyQueenState::Idle;
			isChanging = false;
		}

		if (isChanging == true)
			return;

		mChangeTime = 0;
		int typeNum = rand();
		typeNum %= 4;
		mBloodyQueenInfo.mBossType = (eBloodyQueenType)typeNum;
	}
	void BloodyQueenScript::Die()
	{
	}
	void BloodyQueenScript::PlayerControl()
	{
		switch (mMonsterState)
		{
		case eBloodyQueenState::Idle:
			Idle();
			break;
		case eBloodyQueenState::Move:
			Move();
			break;
		case eBloodyQueenState::Attack:
			Attack();
			break;
		case eBloodyQueenState::Change:
			Change();
			break;
		case eBloodyQueenState::Die:
			Die();
			break;
		default:
			break;
		}
	}
	void BloodyQueenScript::AnimatorControl()
	{	//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttack", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 1500, 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 1500, 0.15f, Vector2(0.0f, 0.03f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenHitMotion", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress1", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress2", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress3", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress4", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff", 1500, 0.15f, Vector2(0.006f, 0.0f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.02f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQChangeType", 1500, 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff1", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff2", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff3", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQNormalAttack", 700, 0.15f, Vector2(-0.01f, -0.02f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQChangeType", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQIdle", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQNormalAttack", 1500, 0.15f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSummon", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallow", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallowEnd", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallowLoop", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		//at->PlayAnimation(L"NormalBloodyQueenNBQWalk", true);
		std::wstring name = {};
		if (mBloodyQueenInfo.mBossType == eBloodyQueenType::Normal)
		{
			name = L"NormalBloodyQueenNBQ";
		}
		else if (mBloodyQueenInfo.mBossType == eBloodyQueenType::Attract)
		{
			name = L"AttractionBloodyQueenATBQ";
		}
		else if (mBloodyQueenInfo.mBossType == eBloodyQueenType::Reflect)
		{
			name = L"ReflectBloodyQueenRFBQ";
		}
		else if (mBloodyQueenInfo.mBossType == eBloodyQueenType::Smile)
		{
			name = L"AttractionBloodyQueenSMBQ";
		}

		// 상시 갱신
		mBloodyQueenInfo.mBossPrevType = mBloodyQueenInfo.mBossType;

		std::wstring animationNameIDLE = L"Idle";
		std::wstring animationNameWALK = L"Walk";
		std::wstring animationNameATT = L"NormalAttack";
		std::wstring animationNameCHANGE = L"ChangeType";

		if (mMonsterState != mPrevMonsterState || mBloodyQueenInfo.mDir != mBloodyQueenInfo.mPrevDir)
		{
			switch (mMonsterState)
			{
			case eBloodyQueenState::Idle:
				name += animationNameIDLE;
				at->PlayAnimation(name, true);
				break;
			case eBloodyQueenState::Move:
				name += animationNameWALK;
				at->PlayAnimation(name, true);
				break;
			case eBloodyQueenState::Attack:
				name += animationNameATT;
				at->PlayAnimation(name, true);
				break;
			default:
				break;
			}
		}
		if (mMonsterState != mPrevMonsterState)
		{
			switch (mMonsterState)
			{
			case eBloodyQueenState::Change:
				name += animationNameCHANGE;
				at->PlayAnimation(name, true);
				isChanging = true;
				break;
			default:
				break;
			}
		}
	}
}