#pragma once
#include "jnsScript.h"
#include "jnsMonsterCommonInfo.h"

namespace jns
{
	class PierreBossScript : public Script
	{
	public:
		enum class ePierreType
		{
			Normal,
			Red,
			Blue,
		};

		struct PierreInfo
		{
			ePierreType mBossPrevType;
			ePierreType mBossType;
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

	private:
		class BloodyQueen* mBloodyQueen;
		MonsterCommonInfo monsterCommonInfo;
		PierreInfo pierreInfo;
		class Transform* tr;
		class Animator* at;
		class Collider2D* cd;

		eBloodyQueenState mMonsterState;
		eBloodyQueenState mPrevMonsterState = eBloodyQueenState::End;

		int mRandDir = -1;
		float mChangeType;
		float mRandMakeTime;

		bool isChanging;
		float mChangeTime;

		float mChasingTime;
		float mPatternPercentage;

		bool mAnimatorPlaying = false;


	};

}
