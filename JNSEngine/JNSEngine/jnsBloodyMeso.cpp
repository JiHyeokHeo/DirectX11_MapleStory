#include "jnsBloodyMeso.h"
#include "CommonSceneInclude.h"

namespace jns
{
	BloodyMeso::BloodyMeso()
		: SkillBase(eSkillType::BloodyMeso)
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
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
		SkillBase::Initialize();
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
}