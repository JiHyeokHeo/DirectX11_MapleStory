#include "jnsShopSlotBack3.h"
#include "CommonUIInclude.h"


namespace jns
{
	ShopSlotBack3::ShopSlotBack3()
	{
	}
	ShopSlotBack3::~ShopSlotBack3()
	{
	}
	void ShopSlotBack3::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ShopBackGround3Material");

		SetPosition(Vector3(0.0f, -0.1f, -0.1f));
		SetScaleWhenParentOn(Vector3(1.0f, 0.9f, 1.0f));

		UIBase::Initialize();
	}
	void ShopSlotBack3::Update()
	{
		UIBase::Update();
	}
	void ShopSlotBack3::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ShopSlotBack3::Render()
	{
		UIBase::Render();
	}
}