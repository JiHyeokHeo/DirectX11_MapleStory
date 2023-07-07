#include "jnsSkillQuickSlotFront.h"
#include "CommonUIInclude.h"

namespace jns
{
	SkillQuickSlotFront::SkillQuickSlotFront()
	{
	}
	SkillQuickSlotFront::~SkillQuickSlotFront()
	{
	}
	void SkillQuickSlotFront::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillQuickSlotFrontMaterial");

		SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		SetScale(Vector3(1.0f, 1.0f, 1.0f));
	
		UIBase::Initialize();
	}
	void SkillQuickSlotFront::Update()
	{
		UIBase::Update();
	}
	void SkillQuickSlotFront::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillQuickSlotFront::Render()
	{
		UIBase::Render();
	}
}