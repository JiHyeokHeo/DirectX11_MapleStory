#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillQuickSlotBackUI : public UIBase
	{
	public:
		SkillQuickSlotBackUI();
		virtual ~SkillQuickSlotBackUI();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}




