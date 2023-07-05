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
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"SkillSlotExtensionMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(-0.505, 0.0f, -0.2f)); // 이방성 필터링이 맞는지에 관한 질문 + 0.2 와 -0.2 즉 렌더링의 순서의 차이 신기방구
		tr->SetScale(Vector3(0.02f, 1.0f, 1.0f));
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