#include "jnsShopSlotBack2.h"
#include "CommonUIInclude.h"

namespace jns
{
	ShopSlotBack2::ShopSlotBack2()
	{
	}
	ShopSlotBack2::~ShopSlotBack2()
	{
	}
	void ShopSlotBack2::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ShopBackGround2Material");

		SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		SetScaleWithOrginalImageScale(Vector2(0.97f,0.97f));

		UIBase::Initialize();
	}
	void ShopSlotBack2::Update()
	{
		UIBase::Update();
	}
	void ShopSlotBack2::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ShopSlotBack2::Render()
	{
		UIBase::Render();
	}
}