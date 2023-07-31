#include "jnsJumpSkill.h"
#include "jnsSkillManager.h"
#include "jnsSceneManager.h"
#include "jnsPlayerScript.h"
#include "ObjectTemplate.h"

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
		at->CompleteEvent(L"Rogue_SkillflashJump") = std::bind(&JumpSkill::CompleteJump, this);
		at->PlayAnimation(L"Rogue_SkillflashJump", true);
		tr->SetScale(Vector3(700.0f, 700.0f, 1.0f));
		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		if (this->GetState() == eState::Paused)
		{
			object::Destroy(this);
		}
		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		int mDir = (int)mPlayerScript->GetPlayerDirection();

		if (at->GetActiveAnimation() != nullptr && isMaked == false)
		{
			if (mDir == -1)
			{
				at->GetActiveAnimation()->SetAniDirection(false);
			}
			else
			{
				at->GetActiveAnimation()->SetAniDirection(true);
			}
			isMaked = true;
		}

		SkillBase::LateUpdate();
	}
	void JumpSkill::Render()
	{
		SkillBase::Render();
	}
	void JumpSkill::CompleteJump()
	{
		this->SetState(eState::Paused);
	}
}