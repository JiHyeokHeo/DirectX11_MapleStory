#include "jnsSkillExtentionSlot.h"
#include "CommonUIInclude.h"

namespace jns
{
	SkillExtentionSlot::SkillExtentionSlot()
	{
	}
	SkillExtentionSlot::~SkillExtentionSlot()
	{
	}
	void SkillExtentionSlot::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillSlotExtensionMaterial");

		SetPosition(Vector3(-0.505, 0.0f, -0.2f));
		SetScale(Vector3(0.02f, 1.0f, 1.0f));

		UIBase::Initialize();
	}
	void SkillExtentionSlot::Update()
	{
		UIBase::Update();
	}
	void SkillExtentionSlot::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillExtentionSlot::Render()
	{
		UIBase::Render();
	}
}