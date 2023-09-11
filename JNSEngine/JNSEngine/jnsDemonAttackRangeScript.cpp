#include "jnsDemonAttackRangeScript.h"
#include "CommonSceneInclude.h"
#include "jnsMonsterCommonInfo.h"

namespace jns
{
	void DemonAttackRangeScript::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(3);
		this->SetColNum(3);
		mDMScript = GetOwner()->GetComponent<DemonMonsterScript>();
		cd->SetSize(Vector2(1.0f, 1.0f));
	}
	void DemonAttackRangeScript::Update()
	{
	}
	void DemonAttackRangeScript::LateUpdate()
	{
	}
	void DemonAttackRangeScript::Render()
	{
	}
	void DemonAttackRangeScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mDemonInfo = mDMScript->GetMonsterCommonInfo();
			if (mDemonInfo.isChasing == true)
			{
				DemonMonsterScript::eDemonState mDMState = DemonMonsterScript::eDemonState::Attack;
				mDMScript->SetDemonState(mDMState);
			}
		}
	}
	void DemonAttackRangeScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo mDemonInfo = mDMScript->GetMonsterCommonInfo();
			if (mDemonInfo.isChasing == true)
			{
				DemonMonsterScript::eDemonState mDMState = DemonMonsterScript::eDemonState::Attack;
				mDMScript->SetDemonState(mDMState);
			}
		}
	}
	void DemonAttackRangeScript::OnCollisionExit(Collider2D* other)
	{
	}
}
