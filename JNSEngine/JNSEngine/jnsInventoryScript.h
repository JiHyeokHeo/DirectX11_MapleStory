#pragma once
#include "jnsScript.h"
#include "jnsGameObject.h"
#include "jnsItemResources.h"

namespace jns
{
	struct ItemInfo
	{
		Vector2 idx;
		Vector3 mItemFinalPos;
		int mItemCnt;
		int itemnum;
	};

	class ItemResources;
	class InventoryScript : public Script
	{
	public:
		InventoryScript();
		~InventoryScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
		
		void CheckItems(ItemResources::eItemType type);
		Vector2 SearchALLItemsToFindIndex(ItemResources::eItemType type);

		bool GetIsDrag() { return isDragging; }

		static std::map<ItemResources::eItemType, ItemInfo>& GetInvenInfo() { return mInventory; }
		static std::vector<std::vector<bool>>& GetInvenIndx() { return indexOn; }
	private:
		static std::map<ItemResources::eItemType, ItemInfo> mInventory;
		static std::vector<std::vector<bool>> indexOn;

		

		bool isDragging = false;
		Vector3 initialMousePos;
		Vector3 initialObjectPos;
	};
}
