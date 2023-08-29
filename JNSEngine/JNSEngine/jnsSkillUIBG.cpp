#include "jnsSkillUIBG.h"

namespace jns
{
	SkillUIBG::SkillUIBG()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	SkillUIBG::~SkillUIBG()
	{
	}
	void SkillUIBG::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillSlotBGMaterial");
		SetPosition(Vector3(250.0f, 100.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f, 1.0f));

		UIBase::Initialize();
	}
	void SkillUIBG::Update()
	{
		UIBase::Update();
	}
	void SkillUIBG::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillUIBG::Render()
	{
		UIBase::Render();
	}
}