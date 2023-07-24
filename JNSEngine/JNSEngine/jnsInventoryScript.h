#pragma once
#include "jnsScript.h"

namespace jns
{
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
		
		static Vector3 GetInventoryItemPos() { return setPos; }
		static bool GetInventoryItemSet() { return isSet; }
		static void SetInventoryItemSet(bool istrue) { isSet = istrue; }
	private:
		static bool isTouched;
		static std::vector<std::vector<int>> mInventory;
		static bool isSet;
		static Vector3 setPos;
	};
}
