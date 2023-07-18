#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class ItemResourcesScript : public GameObject
	{
	public:
		enum class eItemType
		{
			PowerPotion,
			End,
		};

		ItemResourcesScript(eItemType type);
		~ItemResourcesScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPowerPotion();
	private:
		eItemType mItemType;
	};
}
