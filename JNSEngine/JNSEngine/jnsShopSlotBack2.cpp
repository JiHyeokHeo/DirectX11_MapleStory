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
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ShopBackGround2Material"));
		//mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		tr->SetScale(Vector3(0.97f, 0.97f, 1.0f));

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