#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class SkillBox : public UIBase
	{
	public:
		SkillBox();
		~SkillBox();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetSkillUIBG(class SkillUIBG* skillbgui) { skillBGUI = skillbgui; }
	private:
		static int GlobalIdx;
		class SkillUIBG* skillBGUI;
		int mIdx;
	};
}

