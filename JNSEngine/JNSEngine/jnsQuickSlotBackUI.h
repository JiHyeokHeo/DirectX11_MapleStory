#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class QuickSlotUI : public UIBase
	{
	public:
		QuickSlotUI();
		virtual ~QuickSlotUI();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		
	};
}




