#include "jnsInventoryManager.h"

namespace jns
{
	void InventoryManager::AddItem(const std::string& itemName, int quantity)
	{
		if (quantity < 0)
			return;

		//auto iter = mInventory.find(itemName);
		//if (iter != mInventory.end())
		//{
		//	iter->second.quantity += quantity;
		//}

	}
	void InventoryManager::RemoveItem(const std::string& itemName, int quantity)
	{
	}
	void InventoryManager::ClearInventory()
	{
	}
	bool InventoryManager::HasItem(const std::string& itemName, int quantity)
	{
		return false;
	}
	bool InventoryManager::CanAddItem(const std::string& itemName, int quantity)
	{
		return false;
	}
	bool InventoryManager::FindSlotForItem(const std::string& itemName, int quantity, Vector3& position)
	{
		return false;
	}
}