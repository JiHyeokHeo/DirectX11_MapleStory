#include "jnsSkillResources.h"
#include "CommonSceneInclude.h"

namespace jns
{
	SkillResources::SkillResources()
	{
	}
	SkillResources::~SkillResources()
	{
	}
	void SkillResources::Initialize()
	{
		mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		at = AddComponent<Animator>();
		switch (mSkillType)
		{
		case eSkillType::Assain:
			SetAssainSkill();
			break;
		}
	}
	void SkillResources::Update()
	{
		GameObject::Update();
	}
	void SkillResources::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillResources::Render()
	{
		GameObject::Render();
	}
	void SkillResources::SetAssainSkill()
	{
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Asain\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Asain\\_disable", 100, 0.1f);

		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
}