#include "jnsBloodyMeso.h"
#include "CommonSceneInclude.h"
#include "jnsAttackColScript.h"

namespace jns
{
	BloodyMeso::BloodyMeso()
		: SkillBase(eSkillType::BloodyMeso)
	{
		//SetState(GameObject::eState::DontDestroy);
		//SetIsOnlyOne(true);
	}
	BloodyMeso::~BloodyMeso()
	{
	}
	void BloodyMeso::Initialize()
	{
		isRenderOn = true;
		cd = AddComponent<Collider2D>();
		SetName(L"BloodyMeso");
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\BloodyParket", 500, 0.1f, Vector2(0.0f,0.05f));
		at->PlayAnimation(L"Rogue_SkillBloodyParket", true);
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		cd->SetSize(Vector2(0.1f, 0.1f));

		AddComponent<AttackColScript>();
	}
	void BloodyMeso::Update()
	{
		// 플레이어 위치정보 가져오기
		//int direction = (int)mPlayerScript->GetPlayerDirection();
		//mPos.x += direction * 130.0f;
		//mPos.z = 0.0f;
		//SetPosition(mPos);

		if (isRenderOn == false)
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
		else
		{
			cd->SetSize(Vector2(0.1f, 0.1f));
			cd->SetColliderOn(true);
		}

		SkillBase::Update();
	}
	void BloodyMeso::LateUpdate()
	{
		SkillBase::LateUpdate();
	}
	void BloodyMeso::Render()
	{
		SkillBase::Render();
	}
	void BloodyMeso::CompleteSkillAnimation()
	{
	}
	void BloodyMeso::StartSkillAnimation()
	{
	}
	void BloodyMeso::Activate()
	{
		if (this->GetState() == eState::Paused)
			return;

		std::vector<GameObject*> monsters = {};
		monsters = GetComponent<AttackColScript>()->GetMonsterObjects();

		for (GameObject* obj : monsters)
		{
			Vector3 monsterPos = obj->GetComponent<Transform>()->GetPosition();
			
			float v = 100.0f;
			float theta = 30.0f;
			float g = 9.8f;
			float t = 1.0f; // 시작 시간

			
			float x = v * t * cos(theta);
			float y = v * t * sin(theta) - (0.5f * g * t * t);

			Vector3 newPos = monsterPos + Vector3(x, y, 0.0f);

			tr->SetPosition(monsterPos);
		}
	}
}