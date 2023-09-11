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
		int dmg = -99;

		if (other->GetOwner()->GetLayerType() == eLayerType::Player)
		{
			GameObject* mPlayer = SceneManager::GetPlayer();
			PlayerScript* playerScript = mPlayer->GetComponent<PlayerScript>();
			PlayerScript::PlayerInfo playerInfo = playerScript->GetPlayerInfo();

			if (playerInfo.invisibilityTime <= 0.0f && playerScript->GetPlayerState() != jns::PlayerScript::ePlayerState::Die) 
			{
				dmg = 20;
				playerScript->PlayerDamaged(dmg);
				playerScript->SetPlayerState(PlayerScript::ePlayerState::Hitted);
				damageDisplay.DisplayDamage(dmg, playerScript->GetOwner()->GetComponent<Transform>()->GetPosition(), Vector2(0.0f, 50.0f));
			}
		}
	}
	void DemonAttackCol::OnCollisionStay(Collider2D* other)
	{
	}
	void DemonAttackCol::OnCollisionExit(Collider2D* other)
	{
	}
}