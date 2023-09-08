#include "jnsDemonMonster.h"
#include "CommonSceneInclude.h"
#include "jnsDemonMonsterScript.h"
#include "jnsDemonAttackRangeScript.h"
#include "jnsDemonAttackCol.h"

namespace jns
{
	DemonMonster::DemonMonster()
	{
	}
	DemonMonster::~DemonMonster()
	{
	}
	void DemonMonster::Initialize()
	{
		SetName(L"DemonMonster");

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.25f, 0.4f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		at->CreateAnimations(L"..\\Resources\\Monster\\Demon\\dm_attack", 250, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Monster\\Demon\\dm_die", 250, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Monster\\Demon\\dm_hit", 250, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Monster\\Demon\\dm_move", 250, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Monster\\Demon\\dm_Idle", 250, 0.15f);

		at->PlayAnimation(L"Demondm_Idle", true);
		GetComponent<Transform>()->SetScale(Vector3(250.0f, 250.0f, 1.0f));

		AddComponent<DemonMonsterScript>();
		AddComponent<DemonAttackRangeScript>();
		AddComponent<DemonAttackCol>();
	}
	void DemonMonster::Update()
	{
		MonsterBase::Update();
	}
	void DemonMonster::LateUpdate()
	{
		MonsterBase::LateUpdate();
		DemonMonster::SetDirection();
	}
	void DemonMonster::Render()
	{
		MonsterBase::Render();
	}
	void DemonMonster::SetDirection()
	{
		MonsterBase::MonsterDir mMonsterDir = GetComponent<DemonMonsterScript>()->GetMonsterDirection();
		if ((int)mMonsterDir == -1)
		{
			at->GetActiveAnimation()->SetAniDirection(false);
		}
		else if ((int)mMonsterDir == 1)
		{
			at->GetActiveAnimation()->SetAniDirection(true);
		}
	}
}