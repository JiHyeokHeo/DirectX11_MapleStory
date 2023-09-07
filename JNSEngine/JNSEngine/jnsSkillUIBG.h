#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillUIBG : public UIBase
	{
	public:
		SkillUIBG();
		~SkillUIBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	private:
		bool isRender = false;
	};		
}
