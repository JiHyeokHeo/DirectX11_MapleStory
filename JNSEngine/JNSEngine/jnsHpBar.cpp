#include "jnsHpBar.h"
#include "CommonUIInclude.h"

namespace jns
{
	HpBar::HpBar()
	{
	}
	HpBar::~HpBar()
	{
	}
	void HpBar::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"HpBarMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));

		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.065f, -1.94f, 4.2f));
		tr->SetScale(Vector3(mTextureRatio.x * 1.247f, mTextureRatio.y * 1.247f, 1.0f));

		UIBase::Initialize();
	}
	void HpBar::Update()
	{
		UIBase::Update();
	}
	void HpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void HpBar::Render()
	{
		UIBase::Render();
	}
}