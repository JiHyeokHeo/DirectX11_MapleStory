#include "jnsBloodyQueenScript.h"
#include "CommonSceneInclude.h"
#include <random>
#include "jnsMirror.h"
#include "jnsHeart.h"
#include "jnsHeartScript.h"
#include "jnsSwallowEffect.h"
#include "jnsFireEffect.h"
std::mt19937_64 rng1(3244);
std::uniform_int_distribution<__int64> dist1(-1, 1);

std::mt19937_64 rng2(3245);
std::uniform_real_distribution<float> dist2(0.0, 1.0);

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
		cd->SetColNum(1);
		this->SetColNum(1);
		mMonsterState = eBloodyQueenState::Idle;
		bloodyQueenInfo.mBossType = eBloodyQueenType::Normal;
		monsterCommonInfo.maxhp = 1000;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
		mBloodyQueen = dynamic_cast<BloodyQueen*>(GetOwner());

		at->CompleteEvent(L"AttractionBloodyQueenATBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni1, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni2, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQChangeType") = std::bind(&BloodyQueenScript::CompleteChangeTypeAni3, this);
		at->CompleteEvent(L"AttractionBloodyQueenATBQAttract") = std::bind(&BloodyQueenScript::CompleteAttack, this);

		at->CompleteEvent(L"ReflectBloodyQueenRFBQDebuff1") = std::bind(&BloodyQueenScript::CompleteDebuffAni, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQDebuff2") = std::bind(&BloodyQueenScript::CompleteDebuffAni1, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQDebuff3") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQReflect1") = std::bind(&BloodyQueenScript::CompleteReflect, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQReflect2") = std::bind(&BloodyQueenScript::CompleteReflect1, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQReflect3") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"ReflectBloodyQueenRFBQNormalAttack") = std::bind(&BloodyQueenScript::CompleteAttack, this);

		at->CompleteEvent(L"AttractionBloodyQueenATBQNormalAttack") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQDebuff1") = std::bind(&BloodyQueenScript::CompleteNormalDebuffAni, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQDebuff2") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQBress1") = std::bind(&BloodyQueenScript::CompleteBressAni, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQBress2") = std::bind(&BloodyQueenScript::CompleteBressAni1, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQBress3") = std::bind(&BloodyQueenScript::CompleteBressAni2, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQBress4") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQNormalAttack") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"NormalBloodyQueenNBQNormalAttack") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		at->CompleteEvent(L"BloodyQueenDieDie1") = std::bind(&BloodyQueenScript::CompleteDieAni1, this);
		at->CompleteEvent(L"BloodyQueenDieDie2") = std::bind(&BloodyQueenScript::CompleteDieAni2, this);
		at->CompleteEvent(L"BloodyQueenDieDie3") = std::bind(&BloodyQueenScript::CompleteDieAni3, this);

		at->CompleteEvent(L"SmileBloodyQueenSMBQSummon1") = std::bind(&BloodyQueenScript::CompleteSummon, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQSummon2") = std::bind(&BloodyQueenScript::CompleteSmileSummon, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQSwallow1") = std::bind(&BloodyQueenScript::CompleteSwallow, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQSwallow2") = std::bind(&BloodyQueenScript::CompleteSwallow1, this);
		at->CompleteEvent(L"SmileBloodyQueenSMBQSwallow3") = std::bind(&BloodyQueenScript::CompleteAttack, this);
		
	}
	void BloodyQueenScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		ChangeBossTypeRandom();
		CheckChaseTime();
		CheckSkillCoolDown();
		CheckBossHp();
		MonsterControl();
		UpdatePatternPercentage();
		AnimatorControl();

		// 위치 갱신
		mPrevMonsterState = mMonsterState;
		monsterCommonInfo.mPrevDir = monsterCommonInfo.mDir;
	}
	void BloodyQueenScript::LateUpdate()
	{
		UpdateSpecialSkillCoolTime();
		UpdateBossHp();
		SetAniDir();
	}
	void BloodyQueenScript::Render()
	{

	}
	void BloodyQueenScript::OnCollisionEnter(Collider2D* other)
	{
		if(other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			if (mBloodyQueen->GetIsEffectOn()== false)
			{
				DamageDisplay::DamageToMonsterWithSkill(monsterCommonInfo, other, tr, Vector2(-25.0f, 250.0f));
			}
			else
			{
				Transform* playertr = SceneManager::GetPlayer()->GetComponent<Transform>();
				DamageDisplay::DamageToMonsterWithSkill(monsterCommonInfo, other, playertr, Vector2(0.0f,50.0f), true);
			}
		}
	}
	void BloodyQueenScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
		
		}
	}
	void BloodyQueenScript::OnCollisionExit(Collider2D* other)
	{
		int a = 0;
	}
	
	void BloodyQueenScript::InitData()
	{
		monsterCommonInfo.isChasing = false;
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
		if (mChangeType >= changeLimitTime && (mMonsterState == eBloodyQueenState::Idle || mMonsterState == eBloodyQueenState::Move))
		{
			mMonsterState = eBloodyQueenState::Change;
			mChangeType = 0.0f;
		}
	}
	void BloodyQueenScript::CheckChaseTime()
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
	void BloodyQueenScript::CheckSkillCoolDown()
	{
		monsterCommonInfo.skillCoolDown += Time::DeltaTime();
	}
	void BloodyQueenScript::CheckBossHp()
	{
		if (monsterCommonInfo.hp <= 0)
		{
			mMonsterState = eBloodyQueenState::Die;
		}
	}
	void BloodyQueenScript::UpdateBossHp()
	{
		// 상시로 몬스터 베이스로 체력 정보를 넘겨준다.
		MonsterBase* monsterbase = dynamic_cast<MonsterBase*>(GetOwner());
		monsterbase->SetMonsterStatusHp(monsterCommonInfo.hp);
		monsterbase->SetMonsterStatusMaxHp(monsterCommonInfo.maxhp);
	}
	void BloodyQueenScript::SetAniDir()
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
	void BloodyQueenScript::UpdateSpecialSkillCoolTime()
	{
		if (mMonsterState == eBloodyQueenState::SpecialAttack)
		{
			monsterCommonInfo.skillCoolDown = 0.0f;
		}
	}
	void BloodyQueenScript::CompleteBressAni()
	{
		at->PlayAnimation(L"NormalBloodyQueenNBQBress2", true);
	}
	void BloodyQueenScript::CompleteBressAni1()
	{
		at->PlayAnimation(L"NormalBloodyQueenNBQBress3", true);
	}
	void BloodyQueenScript::CompleteBressAni2()
	{
		at->PlayAnimation(L"NormalBloodyQueenNBQBress4", true);
	}
	void BloodyQueenScript::CompleteDebuffAni()
	{
		at->PlayAnimation(L"ReflectBloodyQueenRFBQDebuff2", true);
	}
	void BloodyQueenScript::CompleteDebuffAni1()
	{
		at->PlayAnimation(L"ReflectBloodyQueenRFBQDebuff3", true);
	}

	void BloodyQueenScript::CompleteNormalDebuffAni()
	{
		at->PlayAnimation(L"NormalBloodyQueenNBQDebuff2", true);
	}
	

	void BloodyQueenScript::CompleteDieAni1()
	{
		at->PlayAnimation(L"BloodyQueenDieDie2", true);
	}

	void BloodyQueenScript::CompleteDieAni2()
	{
		at->PlayAnimation(L"BloodyQueenDieDie3", true);
	}

	void BloodyQueenScript::CompleteDieAni3()
	{
		GetOwner()->SetState(GameObject::eState::Paused);
	}

	void BloodyQueenScript::CompleteChangeTypeAni()
	{
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni1()
	{
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni2()
	{
		isChanging = false;
	}
	void BloodyQueenScript::CompleteChangeTypeAni3()
	{
		isChanging = false;
	}
	void BloodyQueenScript::CompleteSummon()
	{
		at->PlayAnimation(L"SmileBloodyQueenSMBQSummon2", true);
	}
	void BloodyQueenScript::CompleteSummon1()
	{
		at->PlayAnimation(L"SmileBloodyQueenSMBQSwallow1", true);
	}
	void BloodyQueenScript::CompleteReflect()
	{
		at->PlayAnimation(L"ReflectBloodyQueenRFBQReflect2", true);
	}
	void BloodyQueenScript::CompleteReflect1()
	{
		at->PlayAnimation(L"ReflectBloodyQueenRFBQReflect3", true);
	}
	void BloodyQueenScript::CompleteSwallow()
	{
		at->PlayAnimation(L"SmileBloodyQueenSMBQSwallow2", true);
	}
	void BloodyQueenScript::CompleteSwallow1()
	{
		at->PlayAnimation(L"SmileBloodyQueenSMBQSwallow3", true);
	}
	void BloodyQueenScript::CompleteAttack()	
	{
		mAnimatorPlaying = false;
		mMonsterState = eBloodyQueenState::Idle;
	}
	void BloodyQueenScript::CompleteSmileSummon()
	{
		at->PlayAnimation(L"SmileBloodyQueenSMBQSwallow1", true);
		mUsingSkillName = L"SmileBloodyQueenSMBQSwallow1";
	}
	void BloodyQueenScript::ResetData()
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
		{
			GetOwner()->SetState(GameObject::eState::Active);
		}
		tr->SetPosition(Vector3(150.0f, -160.0f, 3.0f));
		mMonsterState = eBloodyQueenState::Idle;
		bloodyQueenInfo.mBossType = eBloodyQueenType::Normal;
		monsterCommonInfo.hp = monsterCommonInfo.maxhp;
		monsterCommonInfo.skillCoolDown = 0.0f;
	}
	void BloodyQueenScript::Idle()
	{
		if (mRandDir != 0 && mPrevMonsterState != eBloodyQueenState::Change && monsterCommonInfo.isChasing == false)
		{
			mMonsterState = eBloodyQueenState::Move;
		}

		if (monsterCommonInfo.isChasing == true)
		{
			mMonsterState = eBloodyQueenState::Move;
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
			mMonsterState = eBloodyQueenState::SpecialAttack;
		}
	}
	void BloodyQueenScript::Move()
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
				mMonsterPos.x -= 25.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
			else if (mRandDir == 1)
			{
				mMonsterPos.x += 25.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else
			{
				mMonsterState = eBloodyQueenState::Idle;
			}
		}
		else
		{
			PlayerScript* player = SceneManager::GetPlayer()->GetComponent<PlayerScript>();
			Vector3 mPlayerPos = player->GetOwner()->GetComponent<Transform>()->GetPosition();
			if (mPlayerPos.x >= mMonsterPos.x)
			{
				mMonsterPos.x += 25.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
			}
			else if (mPlayerPos.x <= mMonsterPos.x)
			{
				mMonsterPos.x -= 25.0f * Time::DeltaTime();
				monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
			}
		}

		Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		if (monsterCommonInfo.isChasing == true)
		{
			if (abs(mMonsterPos.x - mPlayerPos.x) >= mBressMaxXCor && monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown && bloodyQueenInfo.mBossType == eBloodyQueenType::Normal)
			{
				if (mPlayerPos.x >= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
				}
				else if (mPlayerPos.x <= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
				}
				mMonsterState = eBloodyQueenState::SpecialAttack;
			}

			if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown)
			{
				mMonsterState = eBloodyQueenState::SpecialAttack;
			}
		}
		else
		{
			if (monsterCommonInfo.skillCoolDown >= mBossMaxSkillCollDown && bloodyQueenInfo.mBossType == eBloodyQueenType::Reflect)
			{
				if (mPlayerPos.x >= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
				}
				else if (mPlayerPos.x <= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
				}
				mMonsterState = eBloodyQueenState::SpecialAttack;
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

		if (mChangeTime >= 0.5f)
		{
			mMonsterState = eBloodyQueenState::Idle;
			mChangeTime = 0.0f;
			isChanging = false;
		}

		if (isChanging == false)
			return;

		mChangeTime = 0;
		int typeNum = rand();
		typeNum %= 4;
		//bloodyQueenInfo.mBossType = (eBloodyQueenType)typeNum;
		bloodyQueenInfo.mBossType = eBloodyQueenType::Normal;
	}
	void BloodyQueenScript::Die()
	{
		
	}
	void BloodyQueenScript::SpecialAttack()
	{ 
	/*	{
			if (mAnimatorPlaying == false)
			{
				mMonsterState = eBloodyQueenState::Attack;
				return;
			}
		}*/
		if (bloodyQueenInfo.mBossType == eBloodyQueenType::Smile)
		{
			Vector3 mMonsterPos = tr->GetPosition();
			Vector3 swallowOffSetPos = {};
			swallowOffSetPos.x = 100.0f * (int)monsterCommonInfo.mDir;
			Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
			int swallowDir = -99;
			if (mPlayerPos.x >= mMonsterPos.x + swallowOffSetPos.x)
			{
				swallowDir = -1;
			}
			else if (mPlayerPos.x <= mMonsterPos.x + swallowOffSetPos.x)
			{
				swallowDir = 1;
			}

			if (mUsingSkillName == L"SmileBloodyQueenSMBQSwallow1")
			{
				float registPower = 150.0f;
				mPlayerPos.x += registPower * swallowDir * Time::DeltaTime();
				SceneManager::GetPlayer()->GetComponent<Transform>()->SetPosition(mPlayerPos);
			}
		}
	}
	void BloodyQueenScript::UpdatePatternPercentage()
	{
		mPatternPercentage = dist2(rng2);
	}
	void BloodyQueenScript::PlaySpecialAttackAnimation(std::wstring animationname)
	{
		Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		Vector3 mMonsterPos = tr->GetPosition();

		std::wstring animationNameNormalBress = L"Bress1";
		std::wstring animationNameNormalDebuff = L"Debuff1";
		std::wstring animationNameAttract = L"Attract";
		std::wstring animationNameReflectDebuff = L"Debuff1";
		std::wstring animationNameReflect= L"Reflect1";
		std::wstring animationNameSmile = L"Swallow1";
		std::wstring animationNameSmileSummon = L"Summon1";
		
		//mPatternPercentage = dist2(rng2);
		
		mAnimatorPlaying = true;

		if (bloodyQueenInfo.mBossType == eBloodyQueenType::Normal)
		{
			if (mPatternPercentage <= 0.3f)
			{
				mFireEffect->SetState(GameObject::eState::Active);
				animationname += animationNameNormalDebuff;
				at->PlayAnimation(animationname, true);
			}
			else if(abs(mMonsterPos.x - mPlayerPos.x) >= mBressMaxXCor)
			{
				if (mPlayerPos.x >= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Right;
				}
				else if (mPlayerPos.x <= mMonsterPos.x)
				{
					monsterCommonInfo.mDir = MonsterBase::MonsterDir::Left;
				}
				animationname += animationNameNormalBress;
				at->PlayAnimation(animationname, true);
			}
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Attract)
		{
			if (mPatternPercentage <= 0.3f)
			{
				mMirror->SetState(GameObject::eState::Active);
			}
			else
			{
				for (int i =0; i< mHearts.size(); i++)
				{
					mHearts[i]->SetState(GameObject::eState::Active);
				}
			}
			animationname += animationNameAttract;
			at->PlayAnimation(animationname, true);
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Reflect)
		{
			{
				animationname += animationNameReflect;
				mBloodyQueen->SetEffectType(MonsterBase::EffectType::Reflect);
				mBloodyQueen->SetIsEffectOn(true);
				
			}
			at->PlayAnimation(animationname, true);
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Smile)
		{
			if (mPatternPercentage <= 1.0f)
			{
				animationname += animationNameSmileSummon;
				mSwallowEffect->SetState(GameObject::eState::Active);
			}
		
			at->PlayAnimation(animationname, true);
		}

		// 플레이 되면 무조건 쿨 줄이기
		mUsingSkillName = animationname;
		monsterCommonInfo.skillCoolDown = 0.0f;
		mAnimatorPlaying = true;
	}
	void BloodyQueenScript::MonsterControl()
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
		case eBloodyQueenState::SpecialAttack:
			SpecialAttack();
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
	{	
		std::wstring name = {};

		if (bloodyQueenInfo.mBossType == eBloodyQueenType::Normal)
		{
			name = L"NormalBloodyQueenNBQ";
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Attract)
		{
			name = L"AttractionBloodyQueenATBQ";
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Reflect)
		{
			name = L"ReflectBloodyQueenRFBQ";
		}
		else if (bloodyQueenInfo.mBossType == eBloodyQueenType::Smile)
		{
			name = L"\SmileBloodyQueenSMBQ";
		}

		// 상시 갱신
		bloodyQueenInfo.mBossPrevType = bloodyQueenInfo.mBossType;

		std::wstring animationNameIDLE = L"Idle";
		std::wstring animationNameWALK = L"Walk";
		std::wstring animationNameATT = L"NormalAttack";
		std::wstring animationNameCHANGE = L"ChangeType";

		
		if (mMonsterState != mPrevMonsterState || monsterCommonInfo.mDir != monsterCommonInfo.mPrevDir)
		{
			mAnimatorPlaying = true;
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
				mUsingSkillName = animationNameATT;
				break;
			case eBloodyQueenState::Die:
				at->PlayAnimation(L"BloodyQueenDieDie1", true);
				break;
			case eBloodyQueenState::SpecialAttack:
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