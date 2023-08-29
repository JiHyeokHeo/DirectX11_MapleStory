#include "jnsQuickSlotFront.h"
#include "CommonUIInclude.h"

namespace jns
{
	QuickSlotFront::QuickSlotFront()
	{
	}
	QuickSlotFront::~QuickSlotFront()
	{
	}
	void QuickSlotFront::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillQuickSlotFrontMaterial");

		SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		//SetScaleWithOriginalImageScale(Vector2(1.0f, 1.0f));
	
		UIBase::Initialize();
	}
	void QuickSlotFront::Update()
	{
		UIBase::Update();
	}
	void QuickSlotFront::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void QuickSlotFront::Render()
	{
		UIBase::Render();
	}
}