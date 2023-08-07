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

		enum class eBossStatus
		{

		};

		enum class eBloodyQueenState
		{
			Idle,
			Move,
			Attack,
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
	
		void InitData();
		void MakeRandDir();
		void ChangeBossTypeRandom();
		void CheckChaseTime();


		void CompleteChangeTypeAni();
		void CompleteChangeTypeAni1();
		void CompleteChangeTypeAni2();
		void CompleteChangeTypeAni3();
	public:
		void Idle();
		void Move();
		void Attack();
		void Change();
		void Die();

		void PlayerControl();
		void AnimatorControl();

		MonsterBase::MonsterDir GetMonsterDirection() { return mBloodyQueenInfo.mDir; }
	private:
		struct BloodyQueenInfo
		{
			int hp;
			
			bool isRight;
			float mHittedTime;
			float mMoveSpeed;
			eBloodyQueenType mBossPrevType;
			eBloodyQueenType mBossType;
			eBossStatus mBloodyQueenStatus;
			MonsterBase::MonsterDir mDir;
			MonsterBase::MonsterDir mPrevDir;
		};

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

		bool isChasing;
		float mChasingTime;
	};


}