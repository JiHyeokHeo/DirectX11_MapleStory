#include "jnsSkillEffect.h"
#include "jnsResources.h"
#include "jnsAnimator.h"

namespace jns
{
	SkillEffect::SkillEffect(SkillBase::eSkillType skilltype)
		:skillType(skilltype)
	{
	}
	SkillEffect::~SkillEffect()
	{
	}
	void SkillEffect::Initialize()
	{
		SetState(GameObject::eState::Active);
		SetName(L"SkillHitEffect");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		Animator* at = AddComponent<Animator>();

		std::wstring animationname = {};
		
		switch (skillType)
		{
		case jns::SkillBase::eSkillType::AssainHit01:
			at->CreateAnimations(L"..\\Resources\\\Rogue_Skill\\\Assaination\\Normal_Assaination_Hit", 500, 0.1f);
			break;
		case jns::SkillBase::eSkillType::AssainHit02:
			at->CreateAnimations(L"..\\Resources\\\Rogue_Skill\\\Assaination\\Normal_Assaination_Hit", 500, 0.1f);
			break;
		default:
			break;
		}

		animationname = at->GetAnimationKey();

		at->CompleteEvent(animationname) = std::bind(&SkillEffect::CompleteHitEffect, this);
		at->PlayAnimation(animationname, true);


		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
	}
	void SkillEffect::Update()
	{
		if (GetState() == eState::Paused)
			SetState(eState::Dead);

		GameObject::Update();
	}
	void SkillEffect::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillEffect::Render()
	{
		GameObject::Render();
	}
	void SkillEffect::CompleteHitEffect()
	{
		SetState(eState::Paused);
	}
}