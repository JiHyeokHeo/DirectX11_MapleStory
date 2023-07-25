#include "jnsInventoryManager.h"

namespace jns
{
	InventoryManager& InventoryManager::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new InventoryManager();
		}
		return *instance;
	}
	void InventoryManager::Initialize()
	{
	}
	void InventoryManager::Update()
	{
	}
	void InventoryManager::LateUpdate()
	{
	}
	void InventoryManager::Render()
	{
	}
	void InventoryManager::AddItemToInventory(ItemResourcesScript* item)
	{
	}
	void InventoryManager::RemoveItemFromInventory(ItemResourcesScript* item)
	{
	}
	void InventoryManager::ArrangeItemsInInventory()
	{
	}
	InventoryManager::InventoryManager()
	{
		mInventoryPosition = Vector3(0.0f, 0.0f, 0.0f);
	}
	InventoryManager::~InventoryManager()
	{
	}
}