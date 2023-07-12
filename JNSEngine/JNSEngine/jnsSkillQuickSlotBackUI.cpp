#include "jnsSkillQuickSlotBackUI.h"
#include "CommonUIInclude.h"

namespace jns
{
	SkillQuickSlotBackUI::SkillQuickSlotBackUI()
	{
	}
	SkillQuickSlotBackUI::~SkillQuickSlotBackUI()
	{
	}
	void SkillQuickSlotBackUI::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillQuickSlotBackMaterial");

		SetPosition(Vector3(400.3f, -400.0f, 4.3f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		
		UIBase::Initialize();
	}
	void SkillQuickSlotBackUI::Update()
	{
		UIBase::Update();
	}
	void SkillQuickSlotBackUI::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillQuickSlotBackUI::Render()
	{
		UIBase::Render();
	}
}