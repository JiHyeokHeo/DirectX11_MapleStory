#pragma once
#include "jnsScript.h"
#include "jnsGameObject.h"

namespace jns
{
	struct ItemInfo
	{
		Vector3 mItemFinalPos;
		int mItemCnt;
		bool isPicked;
	};

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
		
		//void CheckItem(ItemResources* item);
	private:
		std::map<std::wstring, ItemInfo> mInventory;
		jns::GameObject::eState mPrevState;
		jns::GameObject::eState mNowState;
	};
}
