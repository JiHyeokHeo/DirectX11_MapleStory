#include "jnsPierreAttackRangeScript.h"
#include "CommonSceneInclude.h"


namespace jns
{
	// 공격범위 스크립트는 3번으로
	void PierreAttackRangeScript::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(3);
		this->SetColNum(3);
		mPrScript = GetOwner()->GetComponent<PierreScript>();
		cd->SetSize(Vector2(0.40f, 0.5f));
	}
	void PierreAttackRangeScript::Update()
	{
		Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		cd->SetPosition(mMonsterPos);
	}
	void PierreAttackRangeScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mMonsterCommonInfo = mPrScript->GetMonsterCommonInfo();
			PierreScript::ePierreState state = mPrScript->GetPierreState();
			PierreScript::PierreInfo info = mPrScript->GetPierreTypeInfo();
			if (mMonsterCommonInfo.isChasing == true && state != PierreScript::ePierreState::SpecialAttack
				&& state != PierreScript::ePierreState::Attack && state != PierreScript::ePierreState::Change)
			{
				PierreScript::ePierreState mPrState = {};
				if (info.mBossType == PierreScript::ePierreType::Blue)
				{
					mPrState = PierreScript::ePierreState::Move;
				}
				else
				{
					mPrState = PierreScript::ePierreState::Attack;
				}
				mPrScript->SetPierreState(mPrState);
			}
		}
	}
	void PierreAttackRangeScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mMonsterCommonInfo = mPrScript->GetMonsterCommonInfo();
			PierreScript::ePierreState state = mPrScript->GetPierreState();
			PierreScript::PierreInfo info = mPrScript->GetPierreTypeInfo();
			if (mMonsterCommonInfo.isChasing == true && state != PierreScript::ePierreState::SpecialAttack
				&& state != PierreScript::ePierreState::Attack && state != PierreScript::ePierreState::Change)
			{
				PierreScript::ePierreState mPrState = {};
				if (info.mBossType == PierreScript::ePierreType::Blue)
				{
					mPrState = PierreScript::ePierreState::Move;
				}
				else
				{
					mPrState = PierreScript::ePierreState::Attack;
				}
				mPrScript->SetPierreState(mPrState);
			}
		}
	}
	void PierreAttackRangeScript::OnCollisionExit(Collider2D* other)
	{
	}
}