#include "jnsPierreScript.h"
#include "CommonSceneInclude.h"

std::mt19937_64 rng4(3244);
std::uniform_int_distribution<__int64> dist4(-1, 1);

namespace jns
{
	void PierreScript::Initialize()
	{
	}
	void PierreScript::Update()
	{
		srand(time(NULL));
		MakeRandDir();
		CheckChaseTime();
		CheckBossHp();
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
	}
	void PierreScript::OnCollisionStay(Collider2D* other)
	{
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
			mRandDir = dist4(rng4);
			mRandMakeTime = 0.0f;
		}
	}
	void PierreScript::CheckChaseTime()
	{
	}
	void PierreScript::CheckBossHp()
	{
	}
	void PierreScript::UpdateBossHp()
	{
	}
	void PierreScript::SetAniDir()
	{
	}
	void PierreScript::Idle()
	{
	}
	void PierreScript::Move()
	{
	}
	void PierreScript::Attack()
	{
	}
	void PierreScript::Change()
	{
	}
	void PierreScript::Die()
	{
	}
	void PierreScript::SpecialAttack()
	{
	}
	void PierreScript::MonsterControl()
	{
	}
	void PierreScript::AnimatorControl()
	{
	}
	void PierreScript::ResetData()
	{
	}
}