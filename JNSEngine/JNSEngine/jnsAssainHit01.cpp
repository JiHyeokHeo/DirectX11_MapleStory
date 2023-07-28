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
		AddComponent<Collider2D>();

		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");

		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\Assaination\\Normal_Assasination_First_Attack",  300, 0.1f);
		
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
		at->PlayAnimation(L"AssainationNormal_Assasination_First_Attack" , true);
		SkillBase::Initialize();
	}
	void AssainHit01::Update()
	{
		SkillBase::Update();
	}
	void AssainHit01::LateUpdate()
	{
		SkillBase::LateUpdate();
	}
	void AssainHit01::Render()
	{
		SkillBase::Render();
	}
}