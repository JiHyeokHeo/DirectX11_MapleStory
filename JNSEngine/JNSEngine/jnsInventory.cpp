#include "jnsInventory.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"

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
		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryMaterial");

		SetPosition(Vector3(-250.0f, 100.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));

		AddComponent<InventoryScript>();
		//AddComponent<Collider2D>();
		//mInventoryIn->SetPosition(Vector3(0.0f, 200.0f, 4.5f));
		UIBase::Initialize();
	}
	void Inventory::Update()
	{
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