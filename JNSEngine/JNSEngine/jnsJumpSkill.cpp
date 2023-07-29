#include "jnsJumpSkill.h"
#include "jnsSkillManager.h"
#include "jnsSceneManager.h"

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

		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\flashJump", 500, 0.1f);
		tr->SetScale(Vector3(800.0f, 800.0f, 1.0f));

		at->PlayAnimation(L"Rogue_SkillflashJump", false);

		mSkillDirection = 1;
		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		at->GetActiveAnimation()->SetAniDirection(mSkillDirection);
		SkillBase::LateUpdate();
	}
	void JumpSkill::Render()
	{
		SkillBase::Render();
	}
}