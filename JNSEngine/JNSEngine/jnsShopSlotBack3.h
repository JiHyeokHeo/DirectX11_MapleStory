#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class ShopSlotBack3 : public UIBase
	{
	public:
		ShopSlotBack3();
		virtual ~ShopSlotBack3();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}