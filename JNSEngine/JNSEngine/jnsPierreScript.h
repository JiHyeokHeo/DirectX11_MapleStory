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
		void CheckBossType();
		void UpdateBossHp();
		void SetAniDir();

		void CompleteAttack();
		void CompleteDie();
		void CompleteChange();
		void CompleteChange2();
		void CompleteSkill1();
		void CompleteskillAfter1();
		void UseTransformSkill();


		void Idle();
		void Move();
		void Attack();
		void Change();
		void Die();
		void SpecialAttack();

		void MonsterControl();
		void AnimatorControl();
		void CheckSkillCoolDown();

		void PlaySpecialAttackAnimation(std::wstring animationname);
	public:
		void ResetData();
		MonsterCommonInfo GetMonsterCommonInfo() { return monsterCommonInfo; }
		PierreInfo GetPierreTypeInfo() { return pierreInfo; }
		ePierreState GetPierreState() { return mMonsterState; }
		void SetPierreState(ePierreState state) { mMonsterState = state; }
		std::wstring GetUsingSkillName() { return mUsingSkillName; }

	private:
		//class PierreBoss* mPierre;
		MonsterCommonInfo monsterCommonInfo;
		PierreInfo pierreInfo;
		class Transform* tr;
		class Animator* at;
		class Collider2D* cd;

		ePierreState mMonsterState;
		ePierreState mPrevMonsterState = ePierreState::End;

		int mRandDir = -1;

		// 데이터 관련 부분
		float mChangeType = 0.0f;
		float mRandMakeTime = 0.0f;
		float mStandTime = 0.0f;
		bool checkStandTime = false;
		int usednormalAttackCnt = 0;
		bool isFirstChange = false;
		float mChangeTime = 0.0f;
		bool isChanging = false;
		bool isChanged = false;
		bool mAnimatorPlaying = false;

		float mBossMaxSkillCollDown = 10.0f;

		float mChasingTime;
		std::wstring mUsingSkillName;


		std::wstring name = {};

	};

}
