#include "jnsInventory.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"
#include "InventoryBTN.h"

namespace jns
{
	Inventory::Inventory()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	Inventory::~Inventory()
	{
	}
	void Inventory::Initialize()
	{
		// 인벤토리 배경
		InventoryBG* minvenBG = object::InstantiateNOmove<InventoryBG>(eLayerType::UI);
		minvenBG->GetComponent<Transform>()->SetParent(GetComponent<Transform>());

		for (int i = 0; i < 3; i++)
		{
			// 알아서 0 1 2 weapon potion etc 순으로 생성
			InventoryBTN* btn = new InventoryBTN((InventoryBTN::eInvenUIBTN)i);
			btn->Initialize();
			btn->SetInvenUIBG(minvenBG);
			Scene* scene = SceneManager::GetActiveScene();
			scene->AddGameObject(eLayerType::UI, btn);
		}


		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryMaterial");

		SetPosition(Vector3(-250.0f, 100.0f, 2.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));

		AddComponent<InventoryScript>();
		UIBase::Initialize();
	}
	void Inventory::Update()
	{
		if (Input::GetKeyDown(eKeyCode::I))
		{
			if (isRender == false)
			{
				isRender = true;
			}
			else
			{
				isRender = false;
			}
		}



		UIBase::Update();
	}
	void Inventory::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void Inventory::Render()
	{
		if(isRender)
		UIBase::Render();
	}
}