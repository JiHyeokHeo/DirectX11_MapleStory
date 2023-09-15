#pragma once
#include "jnsScript.h"
#include "jnsMonsterBase.h"
#include "DamageDisplay.h"
#include "jnsMonsterCommonInfo.h"	

namespace jns
{

	class PierreScript : public Script
	{
	public:
		enum class ePierreType
		{
			Normal,
			Blue,
			Red,
		};

		struct PierreInfo
		{
			ePierreType mBossPrevType;
			ePierreType mBossType;
		};

		enum class ePierreState
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
		void InitData();
		void MakeRandDir();
		void CheckChaseTime();
		void CheckBossHp();
		void UpdateBossHp();
		void SetAniDir();


		void Idle();
		void Move();
		void Attack();
		void Change();
		void Die();
		void SpecialAttack();

		void MonsterControl();
		void AnimatorControl();

	public:
		void ResetData();
		MonsterCommonInfo GetMonsterCommonInfo() { return monsterCommonInfo; }
		PierreInfo GetBloodyQueenTypeInfo() { return pierreInfo; }
		ePierreState GetBloodyQueenState() { return mMonsterState; }
		void SetBloodyQueenState(ePierreState state) { mMonsterState = state; }
		std::wstring GetUsingSkillName() { return mUsingSkillName; }

	private:
		class PierreBoss* mPierre;
		MonsterCommonInfo monsterCommonInfo;
		PierreInfo pierreInfo;
		class Transform* tr;
		class Animator* at;
		class Collider2D* cd;

		ePierreState mMonsterState;
		ePierreState mPrevMonsterState = ePierreState::End;

		int mRandDir = -1;
		float mChangeType;
		float mRandMakeTime;

		bool isChanging;
		float mChangeTime;

		float mChasingTime;
		std::wstring mUsingSkillName;
	};

}
