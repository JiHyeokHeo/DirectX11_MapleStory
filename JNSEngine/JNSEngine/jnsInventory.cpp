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
		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryMaterial");

		SetPosition(Vector3(-1.0f, 0.0f, 4.5f));
		SetScaleWithOrginalImageScale(Vector2(2.3f,2.3f));
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