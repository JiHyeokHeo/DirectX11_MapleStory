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
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"SkillQuickSlotFrontMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		tr->SetScale(Vector3(1.0f , 1.0f, 1.0f));
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