#include "jnsDemonAttackCol.h"
#include "CommonSceneInclude.h"
#include "jnsDemonMonsterScript.h"

namespace jns
{
	void DemonAttackCol::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(2);
		cd->SetColliderOn(false);
		this->SetColNum(2);
		mDMScript = GetOwner()->GetComponent<DemonMonsterScript>();
		cd->SetSize(Vector2(0.5f, 0.5f));
	}
	void DemonAttackCol::Update()
	{
		if (mDMScript->GetDemonState() == jns::DemonMonsterScript::eDemonState::Attack)
		{
			int aniIdx = GetOwner()->GetComponent<Animator>()->GetActiveAnimation()->GetAnimationIndex();
			if (aniIdx >= 6 && aniIdx <= 8)
			{
				cd->SetSize(Vector2(0.5f, 0.5f));;
				int dir = (int)mDMScript->GetMonsterCommonInfo().mDir;
				cd->SetColliderOn(true);
				cd->SetCenter(Vector2(10.0f * dir , 0.0f));
			}
			else
			{
				cd->SetColliderOn(false);
				cd->SetSize(Vector2::Zero);
			}
		}
		else
		{
			cd->SetColliderOn(false);
			cd->SetSize(Vector2::Zero);
		}
	}
	void DemonAttackCol::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			MonsterCommonInfo monsterinfo= mDMScript->GetMonsterCommonInfo();
			DamageDisplay::DamageToPlayer(monsterinfo, other);
		}
	}
	void DemonAttackCol::OnCollisionStay(Collider2D* other)
	{
	}
	void DemonAttackCol::OnCollisionExit(Collider2D* other)
	{
	}
}