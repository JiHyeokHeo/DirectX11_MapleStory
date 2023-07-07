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

		SetPosition(Vector3(0.0f, -1.95f, 4.3f));
		SetScaleWithOrginalImageScale();
		
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