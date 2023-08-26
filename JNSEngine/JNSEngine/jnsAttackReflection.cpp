#include "jnsAttackReflection.h"
#include "CommonSceneInclude.h"

namespace jns
{
	AttackReflection::AttackReflection()
	{
	}
	AttackReflection::~AttackReflection()
	{
	}
	void AttackReflection::Initialize()
	{
		SetName(L"AttackReflecton");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Effect\\AttackReflection", 100, 0.1f);
		at->PlayAnimation(L"EffectAttackReflection", false);
		reflectionOnTime = 0.0f;
		GameObject::Initialize();
	}
	void AttackReflection::Update()
	{
		isEffectOn = effect::tem::GetMonsterEffectIsOn(chaseObject);

		if (isEffectOn == true)
		{
			if (chaseObject != nullptr)
			{
				Vector3 chaseObjPos = chaseObject->GetComponent<Transform>()->GetPosition();
				Vector3 offSetPos = {};
				if (chaseObject->GetName() == L"BloodyQueen")
				{
					offSetPos = Vector3(-15.0f, 280.0f, 0.0f);
					chaseObjPos += offSetPos;
				}

				MonsterBase::EffectType type = effect::tem::GetMonsterEffectState(chaseObject);

				tr->SetPosition(chaseObjPos);

				if (GetState() == GameObject::eState::Active)
				{
					reflectionOnTime += Time::DeltaTime();
				}
				if (reflectionOnTime >= 5.0f)
				{
					reflectionOnTime = 0.0f;	
					effect::tem::SetMonsterEffectIsOn(chaseObject, false);
				}
			}
		}


		
		if (isEffectOn == true)
			GameObject::Update();
	}
	void AttackReflection::LateUpdate()
	{
		if (isEffectOn == true)
			GameObject::LateUpdate();
	}
	void AttackReflection::Render()
	{
		if(isEffectOn == true)
			GameObject::Render();
	}
	void AttackReflection::ResetTime()
	{
		int a = 0;
		reflectionOnTime = 0.0f;
	}
}