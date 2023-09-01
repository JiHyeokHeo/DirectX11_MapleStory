#include "jnsSkillResources.h"
#include "CommonSceneInclude.h"

constexpr auto SKILLICON_SIZE = 30.0f;

namespace jns
{
	SkillResources::SkillResources(eSkillType type)
		: at(nullptr)
		, mSkillType(type)
		, isMovePossible(false)
	{
		SetIsOnlyOne(true);
		SetState(GameObject::eState::DontDestroy);
	}
	SkillResources::~SkillResources()
	{
	}
	void SkillResources::Initialize()
	{
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		at = AddComponent<Animator>();
		switch (mSkillType)
		{
		case eSkillType::Assain:
			SetAssainSkill();
			break;
		}

		if (mSkillType == eSkillType::Assain)
		{
			at->PlayAnimation(L"Assain_able", true);
		}

	}
	void SkillResources::Update()
	{
		Vector3 mSkillResourcesPos = tr->GetPosition();
		
		Vector2 mLeftTop = Vector2(mSkillResourcesPos.x - SKILLICON_SIZE, mSkillResourcesPos.y + SKILLICON_SIZE);
		Vector2 mRightBottom = Vector2(mSkillResourcesPos.x + SKILLICON_SIZE, mSkillResourcesPos.y - SKILLICON_SIZE);

		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			MouseBTNClick();
		}
		else if (Input::GetKeyUp(eKeyCode::LBUTTON))
		{

		}

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
	void SkillResources::MouseBTNClick()
	{
		tr->SetPosition(Input::GetUIMousePos());
	}
	void SkillResources::MouseBTNClickOff()
	{
	}
	void SkillResources::SetAssainSkill()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Assain\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Assain\\_disable", 100, 0.1f);

		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
}