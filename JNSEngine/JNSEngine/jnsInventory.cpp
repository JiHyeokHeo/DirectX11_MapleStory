#include "jnsInventory.h"
#include "CommonUIInclude.h"

namespace jns
{
	Inventory::Inventory()
	{
	}
	Inventory::~Inventory()
	{
	}
	void Inventory::Initialize()
	{
		
		mInventoryBar = AddComponent<Collider2D>();
		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryMaterial");

		SetPosition(Vector3(-250.0f, 100.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));

		mInventoryIn = AddComponent<Collider2D>();
		mInventoryIn->SetPosition(Vector3(0.0f, 200.0f, 4.5f));
		UIBase::Initialize();
	}
	void Inventory::Update()
	{
		this;
		UIBase::Update();
	}
	void Inventory::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void Inventory::Render()
	{
		UIBase::Render();
	}
}