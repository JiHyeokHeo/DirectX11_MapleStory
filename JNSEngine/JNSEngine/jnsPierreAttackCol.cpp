#include "jnsPierreAttackCol.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void PierreAttackColScirpt::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
		cd->SetColNum(2);
		cd->SetSize(Vector2::Zero);
		cd->SetColliderOn(false);
		this->SetColNum(2);
		mPrScript = GetOwner()->GetComponent<PierreScript>();
		at = mPrScript->GetOwner()->GetComponent<Animator>();
	}
	void PierreAttackColScirpt::LateUpdate()
	{
		PierreScript::ePierreState mPrState = mPrScript->GetPierreState();
		PierreScript::PierreInfo mPrTypeInfo = mPrScript->GetPierreTypeInfo();
		MonsterCommonInfo mPrInfo = mPrScript->GetMonsterCommonInfo();

		if (mPrState == PierreScript::ePierreState::Attack)
		{
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			if (mPrScript->GetUsingSkillName() == L"attack1")
			{
				if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Blue)
				{
					// 콜라이더 사이즈 변경 해줘야함
					AttackNormal(Vector2(1.0f, 1.0f), Vector2(60.0f * (int)mPrInfo.mDir, 100.0f), 0, 2);
				}
				else if(mPrTypeInfo.mBossType == PierreScript::ePierreType::Normal)
				{
					AttackNormal(Vector2(0.3f, 0.5f), Vector2(60.0f * (int)mPrInfo.mDir, 100.0f), 5, 8);	
				}
				else if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Red)
				{
					AttackNormal(Vector2(0.3f, 0.5f), Vector2(60.0f * (int)mPrInfo.mDir, 100.0f), 3, 5);
				}
			}
			else
			{
				AttackNormal(Vector2(0.3f, 0.5f), Vector2(60.0f * (int)mPrInfo.mDir, 100.0f), 6, 9);
			}

		}
		else if (mPrState == PierreScript::ePierreState::SpecialAttack)
		{
			if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Red)
			{
				if (at->GetActiveAnimation()->GetAnimationName() == L"RedPierreattack2")
				{
					AttackNormal(Vector2(0.3f, 0.5f), Vector2(60.0f * (int)mPrInfo.mDir, 100.0f), 4, 13);
				}
			}
			// 특별 공격 할때 콜라이더 추가 

			//Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();

			//if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
			//{
			//	cd->SetColliderOn(false);
			//}
			//else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
			//{
			//	if (at->GetActiveAnimation()->GetAnimationName() == L"NormalBloodyQueenNBQBress3")
			//	{
			//		cd->SetColliderOn(true);
			//		cd->SetSize(Vector2(0.4f, 0.20f));
			//		cd->SetCenter(Vector2(400.0f * (int)mBQInfo.mDir, -100.0f));

			//	}
			//	else
			//	{
			//		cd->SetSize(Vector2::Zero);
			//		cd->SetColliderOn(false);
			//	}

			//}
			//else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
			//{
			//	//cd->SetSize(Vector2(0.3f, 0.5f));
			//	//cd->SetCenter(Vector2(60.0f * (int)mBQInfo.mDir, 100.0f));
			//}
			//else if (mBQTypeInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
			//{
			//	if (at->GetActiveAnimation()->GetAnimationName() == L"SmileBloodyQueenSMBQSwallow2")
			//	{
			//		cd->SetColliderOn(true);
			//		cd->SetSize(Vector2(0.2f, 0.5f));
			//		cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));
			//	}
			//	else if (at->GetActiveAnimation()->GetAnimationName() == L"SmileBloodyQueenSMBQSwallow3")
			//	{
			//		int idx = at->GetActiveAnimation()->GetAnimationIndex();
			//		if (idx >= 0 && idx <= 3)
			//		{
			//			cd->SetSize(Vector2(0.2f, 0.5f));
			//			cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, -100.0f));
			//		}
			//		else
			//		{
			//			cd->SetColliderOn(false);
			//			cd->SetSize(Vector2::Zero);
			//		}
			//	}
			//}
		}
		else
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
	}
	void PierreAttackColScirpt::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			MonsterCommonInfo monsterinfo = mPrScript->GetMonsterCommonInfo();
			PlayerScript* player = other->GetOwner()->GetComponent<PlayerScript>();
			PierreScript::PierreInfo mPrTypeInfo = mPrScript->GetPierreTypeInfo();
			int maxhp = player->GetPlayerInfo().maxhp;
			if (mPrScript->GetUsingSkillName() == L"attack1")
			{
				monsterinfo.skilldmg = maxhp / 30;
				DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true);
			}
			else if (mPrScript->GetUsingSkillName() == L"attack2")
			{
				if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Normal)
				{
					monsterinfo.skilldmg = maxhp / 30;
					SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsPushedHit(true);
					DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true);
				}

				if (GetOwner()->GetComponent<Transform>()->GetPosition().x > player->GetOwner()->GetComponent<Transform>()->GetPosition().x)
				{
					SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetBossIsLeft(false);
				}
				else
				{
					SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetBossIsLeft(true);
				}

			}
			else if (mPrScript->GetUsingSkillName() == L"RedPierreskill1")
			{
				if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Red)
				{
					monsterinfo.skilldmg = maxhp * 3;
					DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true, 3);
				}
			}
		}
	}
	void PierreAttackColScirpt::OnCollisionStay(Collider2D* other)
	{
		//if (other->GetOwner()->GetName() == L"Player")
		//{
		//	MonsterCommonInfo monsterinfo = mPrScript->GetMonsterCommonInfo();
		//	PlayerScript* player = other->GetOwner()->GetComponent<PlayerScript>();
		//	PierreScript::PierreInfo mPrTypeInfo = mPrScript->GetPierreTypeInfo();
		//	int maxhp = player->GetPlayerInfo().maxhp;
		//	if (mPrScript->GetUsingSkillName() == L"attack1")
		//	{
		//		monsterinfo.skilldmg = maxhp / 30;
		//		DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true);
		//	}
		//	else if (mPrScript->GetUsingSkillName() == L"attack2")
		//	{
		//		if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Normal)
		//		{
		//			monsterinfo.skilldmg = maxhp / 30;
		//			SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetIsPushedHit(true);
		//			DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true);
		//		}
		//		
		//		if (GetOwner()->GetComponent<Transform>()->GetPosition().x > player->GetOwner()->GetComponent<Transform>()->GetPosition().x)
		//		{
		//			SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetBossIsLeft(false);
		//		}
		//		else
		//		{
		//			SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetBossIsLeft(true);
		//		}

		//	}
		//	else if (mPrScript->GetUsingSkillName() == L"RedPierreskill1")
		//	{
		//		if (mPrTypeInfo.mBossType == PierreScript::ePierreType::Red)
		//		{
		//			monsterinfo.skilldmg = maxhp * 3;
		//			DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f, 50.0f), true, 3);
		//		}
		//	}
		//}
	}
	void PierreAttackColScirpt::OnCollisionExit(Collider2D* other)
	{
	}
	void PierreAttackColScirpt::AttackNormal(Vector2 collidersize, Vector2 collidercenter,int anistartIdx, int aniendIdx)
	{
		int idx = at->GetActiveAnimation()->GetAnimationIndex();
		MonsterCommonInfo mPrInfo = mPrScript->GetMonsterCommonInfo();
		if (idx >= anistartIdx && idx <= aniendIdx)
		{
			cd->SetColliderOn(true);
			cd->SetSize(collidersize);
			cd->SetCenter(collidercenter);
		}
		else
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
	}
}