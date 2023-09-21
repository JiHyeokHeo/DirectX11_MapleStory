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
		//settarget.clear();
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


		if (targetNum < 0)
		{
			srand(time(NULL));
			int t = rand();
			
			if (settarget.size() >= 1)
			{
				targetNum = t % settarget.size();
			}
		}
		else
		{
			Vector3 monsterPos = settarget[targetNum]->GetComponent<Transform>()->GetPosition();

			float v = 100.0f;
			float theta = 30.0f;
			float g = 9.8f;
			float t = 1.0f; // 시작 시간


			float x = v * t * cos(theta) *Time::DeltaTime();
			float y = v * t * sin(theta) - (0.5f * g * t * t) * Time::DeltaTime();

			Vector3 newPos = monsterPos + Vector3(x, y, 0.0f);
			tr->SetPosition(newPos);
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
		AttackColScript* attackColScript = GetComponent<AttackColScript>();
		
		attackColScript->UpdateMonsters();
		monsters = attackColScript->GetMonsterObjects();


		for (GameObject* obj : monsters)
		{
			MonsterBase* base = dynamic_cast<MonsterBase*>(obj);

			if (base == nullptr)
			{
				return;
			}
			else
			{
				settarget.push_back(base);
			}
		}
	}
}