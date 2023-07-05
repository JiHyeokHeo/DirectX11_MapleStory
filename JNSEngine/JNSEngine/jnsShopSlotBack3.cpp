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
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ShopBackGround2Material"));
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, -0.1f));
		tr->SetScale(Vector3(mTextureRatio.x, mTextureRatio.y, 1.0f));

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