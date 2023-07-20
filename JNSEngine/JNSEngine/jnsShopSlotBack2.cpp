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
		SetMaterial(L"ShopBackGroundMaterial");

		SetPosition(Vector3(0.0f, 0.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));

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