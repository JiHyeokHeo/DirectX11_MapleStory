#include "jnsAssainHit02.h"
#include "CommonSceneInclude.h"

namespace jns
{
	AssainHit02::AssainHit02()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	AssainHit02::~AssainHit02()
	{
	}
	void AssainHit02::Initialize()
	{
		isRenderOn = false;
		cd = AddComponent<Collider2D>();
		SetName(L"AssainHit02");
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\Assaination\\Normal_Assasination_Second_Attack", 500, 0.05f);
		at->CompleteEvent(L"AssainationNormal_Assasination_Second_Attack") = std::bind(&AssainHit02::CompleteSkillAnimation, this);
		at->PlayAnimation(L"AssainationNormal_Assasination_Second_Attack", true);
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		cd->SetSize(Vector2(0.6f, 0.7f));
		cd->SetCenter(Vector2(0.0f, 0.0f));
		SkillBase::Initialize();
	}
	void AssainHit02::Update()
	{
		SkillSetPos();

		if (isRenderOn == false)
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
		else
		{
			cd->SetSize(Vector2(0.6f, 0.7f));
			cd->SetColliderOn(true);
		}

		SkillBase::Update();
	}
	void AssainHit02::LateUpdate()
	{
		SkillBase::SetDirection();
		SkillBase::LateUpdate();

		if (isPlayPossible == true)
		{
			isPlayPossible = false;
			at->PlayAnimation(L"AssainationNormal_Assasination_First_Attack", true);
		}
	}
	void AssainHit02::Render()
	{
		SkillBase::Render();
	}
	void AssainHit02::CompleteSkillAnimation()
	{
		isRenderOn = false;
	}
	void AssainHit02::StartSkillAnimation()
	{
	}
	void AssainHit02::SkillSetPos()
	{
		Vector3 mPos = mPlayerScript->GetOwner()->GetComponent<Transform>()->GetPosition();
		int direction = (int)mPlayerScript->GetPlayerDirection();
		mPos.x += direction * 130.0f;
		mPos.y += 130.0f;
		mPos.z = 0.0f;
		SetPosition(mPos);
	}

}