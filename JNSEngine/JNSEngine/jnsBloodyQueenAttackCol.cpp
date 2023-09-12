#include "jnsBloodyQueenAttackCol.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void BloodyQueenAttackCol::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(2);
		cd->SetSize(Vector2::Zero);
		cd->SetColliderOn(false);
		this->SetColNum(2);
		mColMakeTime = 0.0f;
		mBlackOutReturnTime = 0.0f;
		mBQScript = GetOwner()->GetComponent<BloodyQueenScript>();
		at = mBQScript->GetOwner()->GetComponent<Animator>();
	}
	void BloodyQueenAttackCol::Update()
	{
	}
	void BloodyQueenAttackCol::LateUpdate()
	{
		BloodyQueenScript::eBloodyQueenState mBQState = mBQScript->GetBloodyQueenState();
		BloodyQueenScript::BloodyQueenInfo mBQTypeInfo = mBQScript->GetBloodyQueenTypeInfo();
		MonsterCommonInfo mBQInfo = mBQScript->GetMonsterCommonInfo();

		if (mBQState == BloodyQueenScript::eBloodyQueenState::Attack)
		{
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			if (mBQScript->GetUsingSkillName() == L"NormalAttack")
			{
				int idx = at->GetActiveAnimation()->GetAnimationIndex();
				if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
				{
					if (idx >= 4 && idx <= 6)
					{
						cd->SetColliderOn(true);
						cd->SetSize(Vector2(0.3f, 0.5f));
						cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
					}
					else
					{
						cd->SetSize(Vector2::Zero);
						cd->SetColliderOn(false);
					}

				}
				else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
				{
					if (idx >= 5 && idx <= 7)
					{
						cd->SetColliderOn(true);
						cd->SetSize(Vector2(0.3f, 0.5f));
						cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
					}
					else
					{
						cd->SetSize(Vector2::Zero);
						cd->SetColliderOn(false);
					}
				}
				else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
				{
					if (idx >= 4 && idx <= 6)
					{
						cd->SetColliderOn(true);
						cd->SetSize(Vector2(0.3f, 0.5f));
						cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
					}
					else
					{
						cd->SetSize(Vector2::Zero);
						cd->SetColliderOn(false);
					}
				}
				else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
				{
					if (idx >= 4 && idx <= 6)
					{
						cd->SetColliderOn(true);
						cd->SetSize(Vector2(0.3f, 0.5f));
						cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
					}
					else
					{
						cd->SetSize(Vector2::Zero);
						cd->SetColliderOn(false);
					}
				}
			}

		}
		else if (mBQState == BloodyQueenScript::eBloodyQueenState::SpecialAttack)
		{
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
			{
				cd->SetColliderOn(false);
			}
			else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
			{
				if (at->GetActiveAnimation()->GetAnimationName() == L"NormalBloodyQueenNBQBress3")
				{
					cd->SetColliderOn(true);
					cd->SetSize(Vector2(0.5f, 0.20f));
					cd->SetCenter(Vector2(300.0f * (int)mBQInfo.mDir, -100.0f));

				}
				else
				{
					cd->SetColliderOn(false);
				}

			}
			else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
			{
				//cd->SetSize(Vector2(0.3f, 0.5f));
				//cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
			}
			else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
			{
				if (at->GetActiveAnimation()->GetAnimationName() == L"NormalBloodyQueenNBQBress2")
				{
					cd->SetColliderOn(true);
					cd->SetSize(Vector2(0.2f, 0.5f));
					cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));
				}
				else if (at->GetActiveAnimation()->GetAnimationName() == L"NormalBloodyQueenNBQBress3")
				{
					int idx = at->GetActiveAnimation()->GetAnimationIndex();
					if (idx >= 0 && idx <= 3)
					{
						cd->SetSize(Vector2(0.2f, 0.5f));
						cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));
					}
				}
				else
				{
					cd->SetColliderOn(false);
					cd->SetSize(Vector2::Zero);
				}
			}
		}
	}
	void BloodyQueenAttackCol::Render()
	{
	}
	void BloodyQueenAttackCol::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player" )
		{
			MonsterCommonInfo monsterinfo = mBQScript->GetMonsterCommonInfo();
			
			if (mBQScript->GetUsingSkillName() == L"NormalAttack")
			{
				monsterinfo.skilldmg = mBQSkillDamage.normalAttack;
				SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsNormalHit(true);
			}

			if (mBQScript->GetUsingSkillName() == L"SmileBloodyQueenSMBQSwallow1")
			{
				monsterinfo.skilldmg = mBQSkillDamage.swallowAttack;
			}

			if (mBQScript->GetUsingSkillName() == L"NormalBloodyQueenNBQBress1")
			{
				monsterinfo.skilldmg = mBQSkillDamage.bressAttack;
			}

			DamageDisplay::DamageToPlayer(monsterinfo, other, true);
			
		}
	}
	void BloodyQueenAttackCol::OnCollisionStay(Collider2D* other)
	{
	}
	void BloodyQueenAttackCol::OnCollisionExit(Collider2D* other)
	{
	}
}
