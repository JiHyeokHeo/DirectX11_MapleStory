#include "jnsMpBar.h"
#include "CommonUIInclude.h"

namespace jns
{
	MpBar::MpBar()
	{
	}
	MpBar::~MpBar()
	{
	}
	void MpBar::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"MpBarMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));

		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.065f, -2.06f, 4.2f));
		tr->SetScale(Vector3(mTextureRatio.x * 1.247f, mTextureRatio.y * 1.247f, 1.0f));
		
		UIBase::Initialize();
	}
	void MpBar::Update()
	{
		UIBase::Update();
	}
	void MpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void MpBar::Render()
	{
		UIBase::Render();
	}
}