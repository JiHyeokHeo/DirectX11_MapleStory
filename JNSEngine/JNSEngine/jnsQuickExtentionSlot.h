#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class QuickExtentionSlot : public UIBase
	{
	public:
		QuickExtentionSlot();
		virtual ~QuickExtentionSlot();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


