#include "jnsCenterStatus.h"
#include "CommonUIInclude.h"

namespace jns
{
	CenterStatus::CenterStatus()
	{
	}
	CenterStatus::~CenterStatus()
	{
	}
	void CenterStatus::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"StatusMainBarMaterial");
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);
		SetPosition(Vector3(0.0f, -339.0f, 4.1f));
		SetScaleWithOriginalImageScale(Vector2(1.00f,1.00f));
		
		UIBase::Initialize();
	}
	void CenterStatus::Update()
	{
		UIBase::Update();
	}
	void CenterStatus::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void CenterStatus::Render()
	{
		UIBase::Render();
	}
}