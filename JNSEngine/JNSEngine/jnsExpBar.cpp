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
		
		SetPosition(Vector3(0.0f, -379.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(0.71f, 1.0f));

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