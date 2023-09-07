#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillUIBG;
	class SkillBox : public UIBase
	{
	public:
		SkillBox();
		~SkillBox();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetSkillUIBG(SkillUIBG* skillbgui) { skillBGUI = skillbgui; }
	private:
		static int GlobalIdx;
		SkillUIBG* skillBGUI;
		int mIdx;
		bool isRender = false;
	};
}

