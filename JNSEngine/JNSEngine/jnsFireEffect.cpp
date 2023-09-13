#include "jnsFireEffect.h"
#include "CommonSceneInclude.h"`

namespace jns
{
	FireEffect::FireEffect()
	{
	}
	FireEffect::~FireEffect()
	{
	}
	void FireEffect::Initialize()
	{
		mBurningTime = 0.0f;
		SetState(GameObject::eState::Active);
		SetName(L"FireEffect");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));


		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\FireEffect\\Fire", 500, 0.025f);
		at->PlayAnimation(L"FireEffectFire", true);
		GameObject::Initialize();
	}
	void FireEffect::Update()
	{
		if (GetState() == GameObject::eState::Active)
		{
			mBurningTime += Time::DeltaTime();
			Vector3 playerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
			playerPos.y -= 20.0f;
			tr->SetPosition(playerPos);
		}
		
		if (mBurningTime - mLastBurningTime >= 1.0f)
		{
			GameObject* obj = SceneManager::GetPlayer();
			Player* player = dynamic_cast<Player*>(obj);
			PlayerScript* playerScript = player->GetComponent<PlayerScript>(); 
			Collider2D* cd = playerScript->GetOwner()->GetComponent<Collider2D>();
			mLastBurningTime = mBurningTime;
			MonsterCommonInfo monsterinfo = {};
			int maxhp = playerScript->GetPlayerInfo().maxhp;
			// 최대체력 10프로
			monsterinfo.skilldmg = maxhp / 10;
			DamageDisplay::DamageToPlayer(monsterinfo, cd, Vector2(0.0f, 50.0f), false, true);
		}

		if (mBurningTime >= 6.0f)
		{
			mBurningTime = 0.0f;	
			mLastBurningTime = mBurningTime;
			SetState(GameObject::eState::Paused);
		}

		GameObject::Update();
	}
	void FireEffect::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void FireEffect::Render()
	{
		GameObject::Render();
	}
}