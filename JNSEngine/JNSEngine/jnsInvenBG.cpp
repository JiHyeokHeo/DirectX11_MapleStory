#include "jnsInvenBG.h"
#include "jnsInventoryScript.h"

namespace jns
{
	InventoryBG::InventoryBG()
	{
	}
	InventoryBG::~InventoryBG()
	{
	}
	void InventoryBG::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryBGMaterial");

		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);
		SetPosition(Vector3(0.0f, 0.01f, -0.1f));
		tr->SetScale(Vector3(0.92f, 0.77f, 1.0f));
		AddComponent<InventoryScript>();
		//AddComponent<Collider2D>();
		//mInventoryIn->SetPosition(Vector3(0.0f, 200.0f, 4.5f));
		UIBase::Initialize();
	}
	void InventoryBG::Update()
	{
		UIBase::Update();
	}
	void InventoryBG::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void InventoryBG::Render()
	{
		UIBase::Render();
	}
}