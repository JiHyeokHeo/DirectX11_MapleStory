#pragma once
#include "JNSEngine.h"
#include "jnsMath.h"

using namespace jns::math;

namespace jns
{
	class ItemResourcesScript;
	class InventoryManager
	{
	public:
		static InventoryManager& GetInstance();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void AddItemToInventory(ItemResourcesScript* item);
		void RemoveItemFromInventory(ItemResourcesScript* item);
		void ArrangeItemsInInventory();
		void SetInventoryPosition(Vector3 invenPos) { mInventoryPosition = invenPos; }

	private:
		InventoryManager();
		~InventoryManager();

		static InventoryManager* instance; 
		std::vector<ItemResourcesScript*> mInventoryItems;
		Vector3 mInventoryPosition; 
	};

}
