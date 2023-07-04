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
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"SkillQuickSlotBackMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(2.4f, -1.95f, 4.3f));
		tr->SetScale(Vector3(3.2f, 0.40f, 1.0f));
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