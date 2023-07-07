#include "jnsExpBar.h"
#include "CommonUIInclude.h"

namespace jns
{
	ExpBar::ExpBar()
	{
	}
	ExpBar::~ExpBar()
	{
	}
	void ExpBar::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ExpBarUIMaterial");
		
		SetPosition(Vector3(0.0f, -2.2f, 4.5f));
		SetScale(Vector3(7.95f, 0.05f, 1.0f));

		UIBase::Initialize();
	}
	void ExpBar::Update()
	{
		UIBase::Update();
	}
	void ExpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ExpBar::Render()
	{
		UIBase::Render();
	}
}