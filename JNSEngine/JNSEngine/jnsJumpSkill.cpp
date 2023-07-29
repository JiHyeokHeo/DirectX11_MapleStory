#include "jnsJumpSkill.h"
#include "jnsSkillManager.h"
#include "jnsSkillManager.h"

namespace jns
{
	JumpSkill::JumpSkill()
	{
	}
	JumpSkill::~JumpSkill()
	{
	}
	void JumpSkill::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");

		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\flashJump", 400, 0.1f);
		tr->SetScale(Vector3(177.0f, 100.0f, 1.0f));

		at->PlayAnimation(L"Rogue_SkillflashJump", false);



		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		SkillBase::LateUpdate();
	}
	void JumpSkill::Render()
	{
		SkillBase::Render();
	}
}