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
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		SkillBase::Initialize();
	}
	void JumpSkill::Update()
	{
		if (isPosSet == true)
		{
			Vector3 mPos = mPlayerScript->GetOwner()->GetComponent<Transform>()->GetPosition();
			int direction = (int)mPlayerScript->GetPlayerDirection();
			mPos.x -= direction * 100.0f;
			mPos.z = 0.0f;
			SetPosition(mPos);
		}
		

		SkillBase::Update();
	}
	void JumpSkill::LateUpdate()
	{
		if (isPosSet == true)
		{
			SkillBase::SetDirection();
			isPosSet = false;
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
	}
	void JumpSkill::StartSkillAnimation()
	{
	}

}