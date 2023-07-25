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
        static InventoryManager& GetInstance()
        {
            static InventoryManager instance;
            return instance;
        }

        void AddItem(const std::string& itemName, int quantity);
        void RemoveItem(const std::string& itemName, int quantity);
        void ClearInventory();
        bool HasItem(const std::string& itemName, int quantity);
        bool CanAddItem(const std::string& itemName, int quantity);
        bool FindSlotForItem(const std::string& itemName, int quantity, Vector3& position);


    private:
        std::map<std::string, ItemResources*> mInventory;

        InventoryManager() {}
        ~InventoryManager() {}
    };

}
