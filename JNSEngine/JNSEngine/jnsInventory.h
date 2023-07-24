#pragma once
#include "jnsUIBase.h"
#include "jnsItemResources.h"

namespace jns
{
	class Inventory : public UIBase
	{
	public:
		Inventory();
		virtual ~Inventory();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Collider2D* mInventoryIn;
		Collider2D* mInventoryBar;

		std::vector<ItemResources*> mResources;

	};
	
}

