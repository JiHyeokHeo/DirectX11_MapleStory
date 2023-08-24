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

		GameObject::Initialize();
	}
	void AttackReflection::Update()
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


			tr->SetPosition(chaseObjPos);
		}


		GameObject::Update();
	}
	void AttackReflection::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void AttackReflection::Render()
	{
		GameObject::Render();
	}
}