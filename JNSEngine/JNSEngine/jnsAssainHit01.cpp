#include "jnsAssainHit01.h"
#include "CommonSceneInclude.h"

namespace jns
{
	AssainHit01::AssainHit01()
	{
	}
	AssainHit01::~AssainHit01()
	{
	}
	void AssainHit01::Initialize()
	{
		Collider2D* cd = AddComponent<Collider2D>();

		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\Assaination\\Normal_Assasination_First_Attack",  500, 0.1f);
		at->CompleteEvent(L"AssainationNormal_Assasination_First_Attack") = std::bind(&AssainHit01::CompleteSkillAnimation, this);
		at->PlayAnimation(L"AssainationNormal_Assasination_First_Attack" , true);
		tr->SetScale(Vector3(800.0f, 800.0f, 1.0f));

		cd->SetSize(Vector2(0.5f, 0.3f));
		SkillBase::Initialize();
	}
	void AssainHit01::Update()
	{
		SkillBase::Update();
	}
	void AssainHit01::LateUpdate()
	{
		SkillBase::SetDirection();
		SkillBase::LateUpdate();
	}
	void AssainHit01::Render()
	{
		SkillBase::Render();
	}
	void AssainHit01::CompleteSkillAnimation()
	{
		this->SetState(eState::Paused);
	}
	void AssainHit01::StartSkillAnimation()
	{
	}
}