#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class ItemResources : public GameObject
	{
	public:
		enum class eItemType
		{
			PowerPotion,
			End,
		};


		ItemResources(eItemType type, bool isItem);
		~ItemResources();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	
		void SetPowerPotion();
		int GetItemType() { return itemType; }
		eItemType GetMyItemType() { return mItemType; }
	private:
		eItemType mItemType;
		bool isitItem = false;
		bool isClick = false;
		float mAirTime = 0.0f;
		float airMaxTime = 0.5f;
		bool isRender = true;
		// 1번 장비, 2번 소비, 3번 etc
		int itemType;
		bool isInitDrag = false;
		Vector3 initialMousePos;
		Vector3 initialObjectPos;
		bool isIconRender = false;
	};
}
