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


		ItemResources(eItemType type);
		~ItemResources();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	
		void SetPowerPotion();
	private:
		eItemType mItemType;

	};
}
