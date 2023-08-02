#include "jnsJumpSkill.h"
#include "jnsSkillManager.h"
#include "jnsSceneManager.h"
#include "jnsPlayerScript.h"
#include "ObjectTemplate.h"

namespace jns
{
	JumpSkill::JumpSkill()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	JumpSkill::~JumpSkill()
	{
	}
	void JumpSkill::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");

		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\flashJump", 500, 0.1f);
		at->CompleteEvent(L"Rogue_SkillflashJump") = std::bind(&JumpSkill::CompleteSkillAnimation, this);
		at->PlayAnimation(L"Rogue_SkillflashJump", true);
		tr->SetScale(Vector3(700.0f, 700.0f, 1.0f));
		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		SkillBase::SetDirection();
		SkillBase::LateUpdate();
	}
	void JumpSkill::Render()
	{
		SkillBase::Render();
	}
	void JumpSkill::CompleteSkillAnimation()
	{
		this->SetState(eState::Paused);
	}
	void JumpSkill::StartSkillAnimation()
	{
	}

}