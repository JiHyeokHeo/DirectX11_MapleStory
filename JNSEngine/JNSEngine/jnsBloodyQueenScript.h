#pragma once
#include "jnsScript.h"
#include "jnsMonsterBase.h"
#include "DamageDisplay.h"
#include "DamageInterface.h"
#include "jnsMonsterCommonInfo.h"	

namespace jns
{
	class BloodyQueenScript : public Script
	{
	public:
		enum class eBloodyQueenType
		{
			Normal,
			Attract,
			Reflect,
			Smile,
		};

		struct BloodyQueenInfo
		{
			eBloodyQueenType mBossPrevType;
			eBloodyQueenType mBossType;
		};

		enum class eBloodyQueenState
		{
			Idle,
			Move,
			Attack,
			SpecialAttack,
			Change,
			Debuff,
			Die,
			End,
		};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
	
		void SetMirror(class Mirror* mirror) { mMirror = mirror; }
		void SetSwallow(class SwallowEffect* swallow) { mSwallowEffect = swallow; }
		void SetHeart(class Heart* heart) { mHearts.push_back(heart); }
		void SetFireEffect(class FireEffect* fire) { mFireEffect = fire; }

	private:
		void InitData();
		void MakeRandDir();
		void ChangeBossTypeRandom();
		void CheckChaseTime();
		void CheckSkillCoolDown();
		void CheckBossHp();
		void UpdateBossHp();
		void SetAniDir();
		void UpdateSpecialSkillCoolTime();

		void CompleteBressAni();
		void CompleteBressAni1();
		void CompleteBressAni2();
		void CompleteDebuffAni();
		void CompleteDebuffAni1();
		void CompleteNormalDebuffAni();
		void CompleteDieAni1();
		void CompleteDieAni2();
		void CompleteDieAni3();
		void CompleteChangeTypeAni();
		void CompleteChangeTypeAni1();
		void CompleteChangeTypeAni2();
		void CompleteChangeTypeAni3();
		void CompleteSummon();
		void CompleteSummon1();
		void CompleteReflect();
		void CompleteReflect1();

		void CompleteSwallow();
		void CompleteSwallow1();

		void CompleteAttack();
		void CompleteSmileSummon();

		void Idle();
		void Move();
		void Attack();
		void Change();
		void Die();
		void SpecialAttack();
		void UpdatePatternPercentage();
		void PlaySpecialAttackAnimation(std::wstring animationname);

		void MonsterControl();
		void AnimatorControl();

	public:
		void ResetData();
		MonsterCommonInfo GetMonsterCommonInfo() { return monsterCommonInfo; }
		BloodyQueenInfo GetBloodyQueenTypeInfo() { return bloodyQueenInfo; }
		eBloodyQueenState GetBloodyQueenState() { return mMonsterState; }
		//void SetBloodyQueenisChasing(bool isChase) { mBloodyQueenInfo.isChasing = isChase; }
		void SetBloodyQueenState(eBloodyQueenState state) { mMonsterState = state; }
		std::wstring GetUsingSkillName() { return mUsingSkillName; }

	private:
		class BloodyQueen* mBloodyQueen;
		MonsterCommonInfo monsterCommonInfo;
		BloodyQueenInfo bloodyQueenInfo;
		class Transform* tr;
		class Animator* at;
		class Collider2D* cd;

		eBloodyQueenState mMonsterState;
		eBloodyQueenState mPrevMonsterState = eBloodyQueenState::End;

		// 데이터 부분
		int mRandDir = -1;
		float mChangeType = 0.0f;
		float mRandMakeTime = 0.0f;
		bool isChanging = false;
		float mChangeTime = 0.0f;
		float mChasingTime = 0.0f;
		float mPatternPercentage = 0.0f;
		bool mAnimatorPlaying = false;


		std::wstring mUsingSkillName;
		class Mirror* mMirror;
		std::vector<Heart*> mHearts;
		class SwallowEffect* mSwallowEffect;
		class FireEffect* mFireEffect;
		DamageDisplay damageDisplay;
		float changeLimitTime = 20.0f;
		float mBossMaxSkillCollDown = 10.0f;
		float mBressMaxXCor = 100.0f;

	};


}