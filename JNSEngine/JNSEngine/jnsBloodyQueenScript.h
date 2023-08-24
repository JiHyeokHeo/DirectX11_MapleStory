#pragma once
#include "jnsScript.h"
#include "jnsMonsterBase.h"

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
			int hp;
			bool isRight;
			float mHittedTime;
			float mMoveSpeed;
			eBloodyQueenType mBossPrevType;
			eBloodyQueenType mBossType;
			MonsterBase::MonsterDir mDir;
			MonsterBase::MonsterDir mPrevDir;
			bool isChasing;
			float mSkillCoolDown;
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
		void SetHeart(class Heart* heart) { mHearts.push_back(heart); }


		void InitData();
		void MakeRandDir();
		void ChangeBossTypeRandom();
		void CheckChaseTime();
		void CheckSkillCoolDown();
		void CheckBossHp();


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

		void ResetData();
	public:
		void Idle();
		void Move();
		void Attack();
		void Change();
		void Die();
		void SpecialAttack();
		void UpdatePatternPercentage();
		void PlaySpecialAttackAnimation(std::wstring animationname);

		void PlayerControl();
		void AnimatorControl();

		MonsterBase::MonsterDir GetMonsterDirection() { return mBloodyQueenInfo.mDir; }
		BloodyQueenScript::BloodyQueenInfo GetBloodyQueenInfo() { return mBloodyQueenInfo; }
		eBloodyQueenState GetBloodyQueenState() { return mMonsterState; }
		void SetBloodyQueenisChasing(bool isChase) { mBloodyQueenInfo.isChasing = isChase; }
		void SetBloodyQueenState(eBloodyQueenState state) { mMonsterState = state; }

		std::wstring GetUsingSkillName() { return mUsingSkillName; }
	private:
		class BloodyQueen* mBloodyQueen;

		BloodyQueenInfo mBloodyQueenInfo;
		class Transform* tr;
		class Animator* at;
		class Collider2D* cd;
		
		eBloodyQueenState mMonsterState;
		eBloodyQueenState mPrevMonsterState = eBloodyQueenState::End;

		int mRandDir;
		float mChangeType;
		float mRandMakeTime;

		bool isChanging;
		float mChangeTime;

		float mChasingTime;
		float mPatternPercentage;

		bool mAnimatorPlaying = false;

		float mBossMaxSkillCollDown = 10.0f;

		float mBressMaxXCor = 800.0f;
		std::wstring mUsingSkillName;

		class Mirror* mMirror;
		std::vector<Heart*> mHearts;
	};


}