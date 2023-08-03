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
		tr->SetScale(Vector3(700.0f, 700.0f, 1.0f));
		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		Vector3 mPos = mPlayerScript->GetOwner()->GetComponent<Transform>()->GetPosition();
		int direction = (int)mPlayerScript->GetPlayerDirection();
		if (isSetPos == false)
		{
			mPos.x -= direction * 100.0f;
			mPos.z = 0.0f;
			SetPosition(mPos);
		}

		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		if (isSetPos == false)
		{
			SkillBase::SetDirection();
			isSetPos = true;
			at->PlayAnimation(L"Rogue_SkillflashJump", true);
		}
		SkillBase::LateUpdate();
	}
	void JumpSkill::Render()
	{
		SkillBase::Render();
	}
	void JumpSkill::CompleteSkillAnimation()
	{
		isRenderOn = false;
		isSetPos = false;
	}
	void JumpSkill::StartSkillAnimation()
	{
	}

}