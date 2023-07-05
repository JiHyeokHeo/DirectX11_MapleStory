#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class ShopSlotBack2 : public UIBase
	{
	public:
		ShopSlotBack2();
		virtual ~ShopSlotBack2();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}