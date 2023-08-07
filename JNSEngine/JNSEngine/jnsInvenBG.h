#pragma once
#include "jnsUIBase.h"
#include "jnsItemResources.h"

namespace jns
{
	class InventoryBG : public UIBase
	{
	public:
		InventoryBG();
		virtual ~InventoryBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};

}

