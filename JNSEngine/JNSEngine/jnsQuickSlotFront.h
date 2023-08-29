#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class QuickSlotFront : public UIBase
	{
	public:
		QuickSlotFront();
		virtual ~QuickSlotFront();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


