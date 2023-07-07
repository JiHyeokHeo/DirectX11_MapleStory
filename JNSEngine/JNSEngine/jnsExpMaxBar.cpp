#include "jnsExpMaxBar.h"
#include "CommonUIInclude.h"

namespace jns
{
	ExpMaxBar::ExpMaxBar()
	{
	}
	ExpMaxBar::~ExpMaxBar()
	{
	}
	void ExpMaxBar::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ExpMaxBarMaterial");
	
		SetPosition(Vector3(0.05f, -2.2f, 4.0f));
		SetScale(Vector3(7.95f, 0.05f, 1.0f));

		UIBase::Initialize();
	}
	void ExpMaxBar::Update()
	{
		UIBase::Update();
	}
	void ExpMaxBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ExpMaxBar::Render()
	{
		UIBase::Render();
	}
}