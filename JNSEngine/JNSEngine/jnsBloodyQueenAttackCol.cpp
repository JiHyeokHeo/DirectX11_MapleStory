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
		//BloodyQueenScript::eBloodyQueenState mBQState = mBQScript->GetBloodyQueenState();
		//BloodyQueenScript::BloodyQueenInfo mBQInfo = mBQScript->GetBloodyQueenInfo();
		//
		//if (mBQState == BloodyQueenScript::eBloodyQueenState::Attack)
		//{
		//	Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		//	cd->SetColliderOn(true);
		//	if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
		//	{
		//		mMonsterPos.x += (int)mBQInfo.mDir * 100.0f;
		//	}
		//	else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
		//	{
		//		mMonsterPos.x += (int)mBQInfo.mDir * 100.0f;
		//	}
		//	else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
		//	{
		//		mMonsterPos.x += (int)mBQInfo.mDir * 100.0f;
		//	}
		//	else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
		//	{
		//		mMonsterPos.x += (int)mBQInfo.mDir * 100.0f;
		//	}
		//	cd->SetPosition(mMonsterPos);
		//}
		//else
		//{
		//	cd->SetColliderOn(false);
		//}


	}
	void BloodyQueenAttackCol::LateUpdate()
	{
		BloodyQueenScript::eBloodyQueenState mBQState = mBQScript->GetBloodyQueenState();
		BloodyQueenScript::BloodyQueenInfo mBQInfo = mBQScript->GetBloodyQueenInfo();
		if (isNomralAttackHit)
		{
			mBlackOutReturnTime += Time::DeltaTime();
		}

		if (mBlackOutReturnTime >= 1.0f)
		{
			SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsNormalHit(isNomralAttackHit = false);
			mBlackOutReturnTime = 0.0f;
		}

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
					cd->SetSize(Vector2(0.3f, 0.5f));
					cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
				}
				else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
				{
					if (mColMakeTime >= 1.5f)
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
					mPlayerHp -= mBQSkillDamage.normalAttack;
					dmg = mBQSkillDamage.normalAttack;
					SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsNormalHit(isNomralAttackHit = true);
				}

				if (mBQScript->GetUsingSkillName() == L"SmileBloodyQueenSMBQSwallow1")
				{
					mPlayerHp -= mBQSkillDamage.swallowAttack;
					dmg = mBQSkillDamage.swallowAttack;
				}
				mPlayer->GetComponent<PlayerScript>()->SetPlayerHp(mPlayerHp);
				mPlayer->GetComponent<PlayerScript>()->SetPlayerState(jns::PlayerScript::ePlayerState::Hitted);
				Vector3 playerPos = mPlayer->GetComponent<Transform>()->GetPosition();
				damageDisplay.DisplayDamage(dmg, playerPos);
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
