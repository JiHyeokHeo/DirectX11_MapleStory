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

		SetPosition(Vector3(0.0f, 0.0, 0.1f));
		SetScaleWithOrginalImageScale(Vector2(0.9f,1.25f));
		
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