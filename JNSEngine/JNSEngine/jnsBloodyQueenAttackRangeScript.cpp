#include "jnsBloodyQueenAttackRangeScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void BloodyQueenAttackRangeScript::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(3);
		this->SetColNum(3);
		mBQScript = GetOwner()->GetComponent<BloodyQueenScript>();
		cd->SetSize(Vector2(0.37f,0.5f));
	}
	void BloodyQueenAttackRangeScript::Update()
	{
		Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		cd->SetPosition(mMonsterPos);
	
	}
	void BloodyQueenAttackRangeScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mBloodyQuuenInfo = mBQScript->GetMonsterCommonInfo();
			BloodyQueenScript::eBloodyQueenState state = mBQScript->GetBloodyQueenState();
			if (mBloodyQuuenInfo.isChasing == true && state != BloodyQueenScript::eBloodyQueenState::SpecialAttack 
				&& state != BloodyQueenScript::eBloodyQueenState::Attack && state != BloodyQueenScript::eBloodyQueenState::Change)
			{
				BloodyQueenScript::eBloodyQueenState mBQState = BloodyQueenScript::eBloodyQueenState::Attack;
				mBQScript->SetBloodyQueenState(mBQState);
			}
		}
	}
	void BloodyQueenAttackRangeScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mBloodyQuuenInfo = mBQScript->GetMonsterCommonInfo();
			BloodyQueenScript::eBloodyQueenState state = mBQScript->GetBloodyQueenState();
			if (mBloodyQuuenInfo.isChasing == true && state != BloodyQueenScript::eBloodyQueenState::SpecialAttack
				&& state != BloodyQueenScript::eBloodyQueenState::Attack && state != BloodyQueenScript::eBloodyQueenState::Change)
			{
				BloodyQueenScript::eBloodyQueenState mBQState = BloodyQueenScript::eBloodyQueenState::Attack;
				mBQScript->SetBloodyQueenState(mBQState);
			}
		}
	}
	void BloodyQueenAttackRangeScript::OnCollisionExit(Collider2D* other)
	{

	}
}