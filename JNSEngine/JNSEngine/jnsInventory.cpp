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
		SetMaterial(L"ExpBarUIMaterial");

		SetPosition(Vector3(0.0f, -2.2f, 4.5f));
		SetScale(Vector3(7.95f, 0.05f, 1.0f));
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