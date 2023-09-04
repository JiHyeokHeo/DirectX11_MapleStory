#include "jnsQuickExtentionSlot.h"
#include "CommonUIInclude.h"

namespace jns
{
	QuickExtentionSlot::QuickExtentionSlot()
	{
		SetIsOnlyOne(true);
		SetState(eState::DontDestroy);
	}
	QuickExtentionSlot::~QuickExtentionSlot()
	{
	}
	void QuickExtentionSlot::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillSlotExtensionMaterial");

		SetPosition(Vector3(-0.505, 0.0f, -0.2f));
		SetScaleWhenParentOn(Vector3(0.1f, 1.0f, 1.0f));

		UIBase::Initialize();
	}
	void QuickExtentionSlot::Update()
	{
		UIBase::Update();
	}
	void QuickExtentionSlot::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void QuickExtentionSlot::Render()
	{
		UIBase::Render();
	}
}