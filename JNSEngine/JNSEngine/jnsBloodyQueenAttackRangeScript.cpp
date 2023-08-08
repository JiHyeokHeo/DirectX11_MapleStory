#include "jnsBloodyQueenAttackRangeScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void BloodyQueenAttackRangeScript::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(1);
		this->SetColNum(1);
		mBQScript = GetOwner()->GetComponent<BloodyQueenScript>();
		cd->SetSize(Vector2(0.5f,0.5f));
	}
	void BloodyQueenAttackRangeScript::Update()
	{
		Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		cd->SetPosition(mMonsterPos);
	}
	void BloodyQueenAttackRangeScript::LateUpdate()
	{
	}
	void BloodyQueenAttackRangeScript::Render()
	{
	}
	void BloodyQueenAttackRangeScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			BloodyQueenScript::BloodyQueenInfo mBloodyQuuenInfo = mBQScript->GetBloodyQueenInfo();
			if (mBloodyQuuenInfo.isChasing == true)
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
			BloodyQueenScript::BloodyQueenInfo mBloodyQuuenInfo = mBQScript->GetBloodyQueenInfo();
			if (mBloodyQuuenInfo.isChasing == true)
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