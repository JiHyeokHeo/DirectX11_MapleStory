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
		SetMesh(L"RectMesh");
		SetMaterial(L"HpBarMaterial");
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Opaque);
		SetPosition(Vector3(0.05f, 0.0, 0.1f));
		tr->SetScale(Vector3(0.85f, 0.1f, 1.0f));
		//SetScaleWhenParentOn(Vector3(100.0f, 100.0f, 1.0f));
		//SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		
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