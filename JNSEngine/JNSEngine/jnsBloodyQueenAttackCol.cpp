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
	}
	void BloodyQueenAttackCol::Update()
	{
	}
	void BloodyQueenAttackCol::LateUpdate()
	{
		BloodyQueenScript::eBloodyQueenState mBQState = mBQScript->GetBloodyQueenState();
		BloodyQueenScript::BloodyQueenInfo mBQInfo = mBQScript->GetBloodyQueenInfo();

		if (mBQState == BloodyQueenScript::eBloodyQueenState::Attack)
		{
			mColMakeTime += Time::DeltaTime();
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			if (mColMakeTime >= 0.8f && mBQScript->GetUsingSkillName() == L"NormalAttack")
			{
				cd->SetColliderOn(true);

				if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
				{
					cd->SetSize(Vector2(0.3f, 0.5f));
					cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
				{
					cd->SetSize(Vector2(0.3f, 0.5f));
					cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
				{
					cd->SetSize(Vector2(0.3f, 0.5f));
					cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
				{
					cd->SetSize(Vector2(0.3f, 0.5f));
					cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
			}

			if (mColMakeTime >= 1.6f && mBQScript->GetUsingSkillName() == L"NormalAttack")
			{
				mColMakeTime = 0.0f;
				cd->SetSize(Vector2::Zero);
				cd->SetColliderOn(false);
			}
		}
		else if (mBQState == BloodyQueenScript::eBloodyQueenState::SpecialAttack)
		{
			mColMakeTime += Time::DeltaTime();
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			if (mColMakeTime >= 0.8f)
			{
				cd->SetColliderOn(true);
				if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
				{
					cd->SetColliderOn(false);
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
				{
					if (mColMakeTime >= 1.8f)
					{
						if (mBQScript->GetUsingSkillName() == L"NormalBloodyQueenNBQBress1")
						{
							cd->SetSize(Vector2(0.5f, 0.20f));
							cd->SetCenter(Vector2(300.0f * (int)mBQInfo.mDir, -100.0f));

						}
						else
						{
							cd->SetColliderOn(false);
						}
					}
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
				{
						//cd->SetSize(Vector2(0.3f, 0.5f));
						//cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
				{
					if (mBQScript->GetUsingSkillName() == L"SmileBloodyQueenSMBQSwallow1")
					{
						cd->SetSize(Vector2(0.2f, 0.5f));
						cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));

					}
				}

				if (mColMakeTime >= 2.5f && mBQScript->GetUsingSkillName() == L"NormalBloodyQueenNBQBress1")
				{
					mColMakeTime = 0.0f;
					cd->SetSize(Vector2::Zero);
					cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));
					cd->SetColliderOn(false);
				}
			}
		}
		else
		{
			mColMakeTime = 0.0f;
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
	}
	void BloodyQueenAttackCol::Render()
	{
	}
	void BloodyQueenAttackCol::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player" )
		{
			GameObject* mPlayer = SceneManager::GetPlayer();
			PlayerScript* playerScript = mPlayer->GetComponent<PlayerScript>();
			int mPlayerHp = playerScript->GetPlayerInfo().hp;
			float mPlayerInvTime = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().invisibilityTime;
			int dmg = -99;
			if (mPlayerInvTime <= 0.0f && playerScript->GetPlayerState() != jns::PlayerScript::ePlayerState::Die)
			{
				if (mBQScript->GetUsingSkillName() == L"NormalAttack")
				{
					dmg = mBQSkillDamage.normalAttack;
					SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsNormalHit(true);
				}

				if (mBQScript->GetUsingSkillName() == L"SmileBloodyQueenSMBQSwallow1")
				{
					dmg = mBQSkillDamage.swallowAttack;
				}

				if (mBQScript->GetUsingSkillName() == L"NormalBloodyQueenNBQBress1")
				{
					dmg = mBQSkillDamage.bressAttack;
				}

				mPlayer->GetComponent<PlayerScript>()->PlayerDamaged(dmg);
				mPlayer->GetComponent<PlayerScript>()->SetPlayerState(jns::PlayerScript::ePlayerState::Hitted);
				Vector3 playerPos = mPlayer->GetComponent<Transform>()->GetPosition();
				damageDisplay.DisplayDamage(dmg, playerPos, Vector2(0.0f, 50.0f));
			}
		}
	}
	void BloodyQueenAttackCol::OnCollisionStay(Collider2D* other)
	{
	}
	void BloodyQueenAttackCol::OnCollisionExit(Collider2D* other)
	{
	}
}
