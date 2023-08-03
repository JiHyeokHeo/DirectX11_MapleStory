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
		SetMesh(L"RectMesh");
		SetMaterial(L"MpBarMaterial");
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Opaque);
		SetPosition(Vector3(0.05f, -0.2f, 0.1f));
		tr->SetScale(Vector3(0.85f, 0.2f, 1.0f));
	
		
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