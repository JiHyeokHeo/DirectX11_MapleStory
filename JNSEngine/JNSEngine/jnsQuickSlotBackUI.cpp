#include "jnsQuickSlotBackUI.h"
#include "CommonUIInclude.h"
#include "jnsQuickSlotScript.h"

namespace jns
{
	QuickSlotUI::QuickSlotUI()
	{
	}
	QuickSlotUI::~QuickSlotUI()
	{
	}
	void QuickSlotUI::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillQuickSlotBackMaterial");

		SetPosition(Vector3(405.0f, -339.0f, 4.3f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		
		AddComponent<QuickSlotScript>();
		UIBase::Initialize();
	}
	void QuickSlotUI::Update()
	{
		UIBase::Update();
	}
	void QuickSlotUI::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void QuickSlotUI::Render()
	{
		UIBase::Render();
	}
}