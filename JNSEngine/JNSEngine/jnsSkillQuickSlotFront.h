#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillQuickSlotFront : public UIBase
	{
	public:
		SkillQuickSlotFront();
		virtual ~SkillQuickSlotFront();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


