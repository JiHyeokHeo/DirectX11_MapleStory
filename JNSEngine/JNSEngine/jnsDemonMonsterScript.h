#pragma once
#include "jnsScript.h"
#include "jnsMonsterBase.h"

namespace jns
{
	class DemonMonsterScript : public Script
	{
	public:
		enum class eDemonState
		{
			Idle,
			Move,
			Attack,
			Hit,
			Die,
			End,
		};

		struct DemonInfo
		{
			int hp;
			bool isRight;
			float mHittedTime;
			float mMoveSpeed;
			eDemonState mBossPrevType;
			eDemonState mBossType;
			MonsterBase::MonsterDir mDir;
			MonsterBase::MonsterDir mPrevDir;
			bool isChasing;
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
	
		void MakeRandDir();
		void ChangeBossTypeRandom();
		void CheckChaseTime();
		void CheckSkillCoolDown();
		void CheckMonsterHp();
		void MonsterControl();
		void AnimatorControl();

		void Idle();
		void Move();
		void Attack();
		void Hit();
		void Die();

		void InitData();


		MonsterBase::MonsterDir GetMonsterDirection() { return mDemonInfo.mDir; }
		DemonInfo GetDemonInfo() { return mDemonInfo; }
		void SetDemonState(eDemonState state) { mMonsterState = state; }


		void CompleteAttack();
		void CompleteDead();

	private:
		class Collider2D* cd;
		class Animator* at;
		class Transform* tr;

		int mRandDir;
		float mChangeType;
		float mRandMakeTime;

		bool isChanging;
		float mChangeTime;
		float mChasingTime;
		float mAttackColChangeTime;

		bool mAnimatorPlaying = false;
		eDemonState mMonsterState;
		eDemonState mPrevMonsterState;

		DemonInfo mDemonInfo;

	};
}



