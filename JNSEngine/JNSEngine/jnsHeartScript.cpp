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
		cd = GetOwner()->GetComponent<Collider2D>();
		cd->SetColliderOn(false);
		heartState = eHeartState::Summon;
		monsterinfo.hp = 80;
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
				int maxhp = playerScript->GetPlayerInfo().maxhp;
				// 최대체력 10프로
				monsterinfo.skilldmg = maxhp / 10;
				DamageDisplay::DamageToPlayer(monsterinfo, other, Vector2(0.0f,50.0f), true);
				heartState = eHeartState::Bomb;
			}
		}

		if (other->GetOwner()->GetLayerType() == eLayerType::Skill)
		{
			DamageDisplay::DamageToMonsterWithSkill(monsterinfo, other, GetOwner()->GetComponent<Transform>());
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
		if (monsterinfo.hp <= 0)
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
		cd->SetColliderOn(true);
	}
	void HeartScript::CompleteBomb()
	{
		Vector3 heartPos = tr->GetPosition();
		tr->SetPosition(heartPos.x, heartStartPos, heartPos.z);
		heartState = eHeartState::Summon;
		isSummon = false;
		this->GetOwner()->SetState(GameObject::eState::Paused);
		cd->SetColliderOn(false);
	}
}