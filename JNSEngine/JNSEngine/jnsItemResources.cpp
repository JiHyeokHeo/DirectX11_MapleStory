#include "jnsItemResources.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ItemResources::ItemResources(eItemType type)
		: mItemType(type)
	{
	}
	ItemResources::~ItemResources()
	{
	}
	void ItemResources::Initialize()
	{
		AddComponent<ItemResourcesScript>();
		switch (mItemType)
		{
		case eItemType::PowerPotion:
			SetPowerPotion();
			break;
		}
	}
	void ItemResources::Update()
	{
		GameObject::Update();
	}
	void ItemResources::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ItemResources::Render()
	{
		GameObject::Render();
	}
	void ItemResources::SetPowerPotion()
	{
		SetName(L"PowerPotion");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		AddComponent<Collider2D>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"HP_MP_PotionMaterial"));
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);


		Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
		GetComponent<Transform>()->SetPosition(Vector3(300.0f, 250.0f, 3.0f));
		GetComponent<Transform>()->SetScale(Vector3(mSize.x *2.0f, mSize.y *2.0f, 1.0f));
	}
}