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
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
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