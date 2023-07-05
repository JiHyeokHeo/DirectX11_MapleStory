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
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ShopBackGroundMaterial"));
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 4.0f));
		tr->SetScale(Vector3(mTextureRatio.x * 2.8f, mTextureRatio.y * 2.8f, 1.0f));

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