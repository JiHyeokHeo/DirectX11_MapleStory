#pragma once
#include "jnsUIBase.h"
#include "jnsAnimator.h"

namespace jns
{
	class SkillUIBG;
	class SkillUIBTN : public UIBase
	{
	public:
		enum class eSkillUIBTN
		{
			One,
			Two,
			Three,
			Four,
			Five,
			None,
		};

		SkillUIBTN();
		SkillUIBTN(eSkillUIBTN type);
		~SkillUIBTN();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void MouseBTNClick() override;
		virtual void MouseBTNClickOff() override;


		void SetSkillUIBG(SkillUIBG* skillbgui) { skillBGUI = skillbgui; }

		void MakeOne();
		void MakeTwo();
		void MakeThree();
		void MakeFour();
		void MakeFive();

		std::wstring eSkillUIBTNToString(eSkillUIBTN value) {
			enumToString = {
				{eSkillUIBTN::One, L"One"},
				{eSkillUIBTN::Two, L"Two"},
				{eSkillUIBTN::Three, L"Three"},
				{eSkillUIBTN::Four, L"Four"},
				{eSkillUIBTN::Five, L"Five"},
				{eSkillUIBTN::None, L"None"}
			};
			return enumToString[value];
		}

		static int GetPushedSkillBTNNumber() { return pushedBtnNumber; }
	private:
		eSkillUIBTN mSkillBTNType;
		SkillUIBG* skillBGUI;
		Animator* at;
		std::map<eSkillUIBTN, std::wstring> enumToString;
		std::wstring disable = L"_disable";
		std::wstring able = L"_able";
		int skillBtnNumber;
		static int pushedBtnNumber;

		bool isChanged = false;
	};

}

