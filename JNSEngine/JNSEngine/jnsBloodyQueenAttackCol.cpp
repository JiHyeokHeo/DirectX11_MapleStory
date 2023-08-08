#include "jnsBloodyQueenAttackCol.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void BloodyQueenAttackCol::Initialize()
	{
		cd = GetOwner()->AddComponent<Collider2D>();
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
		if (mBQState == BloodyQueenScript::eBloodyQueenState::Attack)
		{
			Vector3 mMonsterPos = GetOwner()->GetComponent<Transform>()->GetPosition();
			cd->SetColliderOn(true);
			
			if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Attract)
			{
				cd->SetSize(Vector2(0.4f, 0.5f));
				cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, 100.0f));
			}
			else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Normal)
			{
				cd->SetSize(Vector2(0.4f, 0.5f));
				cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, 100.0f));
			}
			else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Reflect)
			{
				cd->SetSize(Vector2(0.4f, 0.5f));
				cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, 100.0f));
			}
			else if (mBQInfo.mBossType == BloodyQueenScript::eBloodyQueenType::Smile)
			{
				cd->SetSize(Vector2(0.4f, 0.5f));
				cd->SetCenter(Vector2(100.0f * (int)mBQInfo.mDir, 100.0f));
			}

		}
		else
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
	}
	void BloodyQueenAttackCol::Render()
	{
	}
	void BloodyQueenAttackCol::OnCollisionEnter(Collider2D* other)
	{
	}
	void BloodyQueenAttackCol::OnCollisionStay(Collider2D* other)
	{
	}
	void BloodyQueenAttackCol::OnCollisionExit(Collider2D* other)
	{
	}
}