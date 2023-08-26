#include "jnsHeartScript.h"
#include "CommonSceneInclude.h"
#include "jnsHeart.h"
#include <Random>

std::mt19937_64 rng5(3245);
std::uniform_int_distribution<long long> dist5(0, 100);
namespace jns
{
	void HeartScript::Initialize()
	{
		heartState = eHeartState::Summon;
		hp = 80;
		at = GetOwner()->GetComponent<Animator>();
		at->CompleteEvent(L"HeartHeartSummon") = std::bind(&HeartScript::CompleteSummon, this);
		at->CompleteEvent(L"HeartHeartAttack") = std::bind(&HeartScript::CompleteBomb, this);
		tr = GetOwner()->GetComponent<Transform>();
	}
	void HeartScript::Update()
	{
		int RandSummonPercentage = dist5(rng5);
		if (RandSummonPercentage <= 30.0f && isSummon == false)
		{
			this->GetOwner()->SetState(GameObject::eState::Paused);
			isSummon = true;
			return;
		}

		Fsm();
		PlayAnimation();
		prevheartState = heartState;
	}
	void HeartScript::LateUpdate()
	{
	}
	void HeartScript::Render()
	{
	}
	void HeartScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			GameObject* mPlayer = SceneManager::GetPlayer();
			PlayerScript* playerScript = mPlayer->GetComponent<PlayerScript>();
			int mPlayerHp = playerScript->GetPlayerInfo().hp;
			float mPlayerInvTime = mPlayer->GetComponent<PlayerScript>()->GetPlayerInfo().invisibilityTime;

			if (mPlayerInvTime <= 0.0f && playerScript->GetPlayerState() != jns::PlayerScript::ePlayerState::Die)
			{
				mPlayerHp -= 30.0f;
				mPlayer->GetComponent<PlayerScript>()->SetPlayerHp(mPlayerHp);
				heartState = eHeartState::Bomb;
			}
		}

		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			if (other->GetOwner()->GetName() == L"AssainHit01")
			{
				int mSkillDmg = SkillManager::FindSkillDamage(L"Normal_Assain_First_Attack");
				hp -= mSkillDmg;
			}
			else if (other->GetOwner()->GetName() == L"AssainHit02")
			{
				int mSkillDmg = SkillManager::FindSkillDamage(L"Normal_Assain_Second_Attack");
				hp -= mSkillDmg;
			}
		}
	}
	void HeartScript::OnCollisionStay(Collider2D* other)
	{
	}
	void HeartScript::OnCollisionExit(Collider2D* other)
	{
	}
	void HeartScript::Fsm()
	{
		if (hp <= 0)
			heartState = eHeartState::Bomb;
		


		isSummon = true;
		switch (heartState)
		{
		case jns::HeartScript::eHeartState::Move:
			GoUp();
			break;
		case jns::HeartScript::eHeartState::Summon:
			break;
		case jns::HeartScript::eHeartState::Bomb:
			break;
		case jns::HeartScript::eHeartState::End:
			break;
		default:
			break;
		}
	}
	void HeartScript::PlayAnimation()
	{
		if (prevheartState != heartState)
		{
			switch (heartState)
			{
			case jns::HeartScript::eHeartState::Move:
				at->PlayAnimation(L"HeartHeartNormal", false);
				break;
			case jns::HeartScript::eHeartState::Summon:
				at->PlayAnimation(L"HeartHeartSummon", true);
				break;
			case jns::HeartScript::eHeartState::Bomb:
				at->PlayAnimation(L"HeartHeartAttack", true);
				break;
			case jns::HeartScript::eHeartState::End:
				break;
			default:
				break;
			}
		}

	}
	void HeartScript::GoUp()
	{
		Vector3 heartPos = tr->GetPosition();
		
		heartPos.y += heartMoveSpeed * Time::DeltaTime();
		tr->SetPosition(heartPos);

		if (heartPos.y >= destinationYcor)
		{
			heartState = eHeartState::Bomb;
		}
	}
	void HeartScript::CompleteSummon()
	{
		heartState = HeartScript::eHeartState::Move;
	}
	void HeartScript::CompleteBomb()
	{
		Vector3 heartPos = tr->GetPosition();
		tr->SetPosition(heartPos.x, heartStartPos, heartPos.z);
		heartState = eHeartState::Summon;
		isSummon = false;
		this->GetOwner()->SetState(GameObject::eState::Paused);
	}
}