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
	private:
		eItemType mItemType;
		bool isitItem = false;
		float mAirTime = 0.0f;
		float airMaxTime = 0.5f;
	};
}
