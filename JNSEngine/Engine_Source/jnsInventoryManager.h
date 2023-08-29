#pragma once
#include "JNSEngine.h"
#include "jnsMath.h"

using namespace jns::math;

namespace jns
{
	class ItemResources;
    class InventoryManager
    {
    public:
        static void AddItem(const std::string& itemName, int quantity);
        static void RemoveItem(const std::string& itemName, int quantity);
        static void ClearInventory();
        static bool HasItem(const std::string& itemName, int quantity);
        static bool CanAddItem(const std::string& itemName, int quantity);
        static bool FindSlotForItem(const std::string& itemName, int quantity, Vector3& position);

    private:
        static std::map<std::string, ItemResources*> mInventory;

        InventoryManager() {}
        ~InventoryManager() {}
    };

}
