#include "jnsSkillLock.h"
#include "CommonSceneInclude.h"
#include "jnsPlayerScript.h"

namespace jns
{
	SkillLock::SkillLock()
	{
	}
	SkillLock::~SkillLock()
	{
	}
	void SkillLock::Initialize()
	{
		SetName(L"AttackReflecton");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Effect\\SkillLockDebuff", 100, 0.1f);
		at->PlayAnimation(L"EffectSkillLockDebuff", true);
		skillLockOnTime = 0.0f;
		GameObject::Initialize();
	}
	void SkillLock::Update()
	{
		if (GetState() == GameObject::eState::Active)
		{
			skillLockOnTime += Time::DeltaTime();
		}

		if (chaseObject != nullptr)
		{
			if (skillLockOnTime >= 5.0f)
			{
				ResetTime();
			}
			Vector3 chaseObjPos = chaseObject->GetComponent<Transform>()->GetPosition();
			Vector3 offSetPos = {};

			offSetPos = Offeset;
			chaseObjPos += offSetPos;
			tr->SetPosition(chaseObjPos);
		}

		if (isEffectOn == true)
			GameObject::Update();
	}
	void SkillLock::LateUpdate()
	{
		if (isEffectOn == true)
			GameObject::LateUpdate();
	}
	void SkillLock::Render()
	{
		if (isEffectOn == true)
			GameObject::Render();
	}
	void SkillLock::ResetTime()
	{

		chaseObject->GetComponent<PlayerScript>()->SetIsSkillLock(false);
		SetState(GameObject::eState::Paused);
		isEffectOn = false;
		skillLockOnTime = 0.0f;

	}
	void SkillLock::ActivateToPlayer(Vector3 effectoffset, GameObject* chaseobj)
	{
		SetState(GameObject::eState::Active);
		chaseObject = chaseobj;
		isEffectOn = true;
		Offeset = effectoffset;
		chaseObject->GetComponent<PlayerScript>()->SetIsSkillLock(true);
	}
}