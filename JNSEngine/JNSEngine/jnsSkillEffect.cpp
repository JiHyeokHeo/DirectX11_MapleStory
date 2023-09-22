#include "jnsSkillEffect.h"
#include "jnsResources.h"
#include "jnsAnimator.h"
#include "jnsTime.h"

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
		at = AddComponent<Animator>();

		switch (skillType)
		{
		case jns::SkillBase::eSkillType::AssainHit01:
			isMade = true;
			at->CreateAnimations(L"..\\Resources\\\Rogue_Skill\\\Assaination\\Normal_Assaination_Hit", 500, 0.1f);
			break;
		case jns::SkillBase::eSkillType::AssainHit02:
			isMade = true;
			at->CreateAnimations(L"..\\Resources\\\Rogue_Skill\\\Assaination\\Normal_Assaination_Hit", 500, 0.1f);
			break;
		case jns::SkillBase::eSkillType::BloodyMeso:
			isMade = true;
			at->CreateAnimations(L"..\\Resources\\\Rogue_Skill\\MesoExplostionRed", 500, 0.1f);
			break;
		default:
			break;
		}

		
		if (isMade)
		{
			animationname = at->GetAnimationKey();
			at->PlayAnimation(animationname, true);
		}
		
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
	}
	void SkillEffect::Update()
	{
		renderDelayTime += Time::DeltaTime();
	
		renderTime += Time::DeltaTime();
		transparecny += 1.0f * Time::DeltaTime();;

	/*	if (isMade)
		{
			at->PlayAnimation(animationname, false);
			at->GetActiveAnimation()->SetTransparency(transparecny);
		}*/
		
		if (renderTime >= 0.6f)
		{
			SetState(GameObject::eState::Dead);
		}
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
}