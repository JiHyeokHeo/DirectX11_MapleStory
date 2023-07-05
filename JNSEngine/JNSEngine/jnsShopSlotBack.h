#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class ShopSlotBack : public UIBase
	{
	public:
		ShopSlotBack();
		virtual ~ShopSlotBack();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}

