#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillExtentionSlot : public UIBase
	{
	public:
		SkillExtentionSlot();
		virtual ~SkillExtentionSlot();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


