#pragma once
#include "jnsUIBase.h"
#include "jnsItemResources.h"

namespace jns
{
	class InventoryBG;
	class QuickSlotUI;
	class Inventory : public UIBase
	{
	public:
		Inventory();
		virtual ~Inventory();
		

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetQuickSlotUI(QuickSlotUI* skillquickslot) { skillQuickSlot = skillquickslot; }

	private:
		QuickSlotUI* skillQuickSlot;
		InventoryBG* minvenBG;
		bool isChanged = false;
		bool isRender = false;
	};
	
}

