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

		SetPosition(Vector3(0.0f, -0.2, 0.1f));
		SetScaleWhenParentOn(Vector3(0.8f, 1.1f, 1.0f));
	
		
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