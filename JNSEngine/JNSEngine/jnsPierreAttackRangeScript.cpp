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
		cd->SetSize(Vector2(0.37f, 0.5f));
	}
	void PierreAttackRangeScript::Update()
	{
		Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		cd->SetPosition(mMonsterPos);
	}
	void PierreAttackRangeScript::OnCollisionEnter(Collider2D* other)
	{
		//if (other->GetOwner()->GetName() == L"Player")
		//{d
		// 
		//	MonsterCommonInfo mBloodyQuuenInfo = mPrScript->GetMonsterCommonInfo();
		//	BloodyQueenScript::eBloodyQueenState state = mPrScript->GetBloodyQueenState();
		//	if (mBloodyQuuenInfo.isChasing == true && state != BloodyQueenScript::eBloodyQueenState::SpecialAttack
		//		&& state != BloodyQueenScript::eBloodyQueenState::Attack && state != BloodyQueenScript::eBloodyQueenState::Change)
		//	{
		//		BloodyQueenScript::eBloodyQueenState mBQState = BloodyQueenScript::eBloodyQueenState::Attack;
		//		mPrScript->SetBloodyQueenState(mBQState);
		//	}
		//}
	}
	void PierreAttackRangeScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PierreAttackRangeScript::OnCollisionExit(Collider2D* other)
	{
	}
}