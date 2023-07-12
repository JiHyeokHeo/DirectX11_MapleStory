#include "jnsShopSlotBack.h"
#include "CommonUIInclude.h"

namespace jns
{
	ShopSlotBack::ShopSlotBack()
	{
	}
	ShopSlotBack::~ShopSlotBack()
	{
	}
	void ShopSlotBack::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ShopBackGroundMaterial");

		SetPosition(Vector3(0.0f, 0.0f, 4.0f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		

		UIBase::Initialize();
	}
	void ShopSlotBack::Update()
	{
		UIBase::Update();
	}
	void ShopSlotBack::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ShopSlotBack::Render()
	{
		UIBase::Render();
	}
}