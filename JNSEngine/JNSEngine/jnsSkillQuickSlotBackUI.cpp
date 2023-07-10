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

		SetPosition(Vector3(2.3f, -1.95f, 4.3f));
		SetScaleWithOrginalImageScale(Vector2(3.4f,3.4f));
		
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