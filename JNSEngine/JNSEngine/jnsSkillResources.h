#pragma once
#include "jnsUIBase.h"
#include "jnsAnimator.h"
#include "jnsMeshRenderer.h"
#include "jnsSkillUIBG.h"
#include "jnsQuickSlotBackUI.h"

namespace jns
{
	class SkillResources : public UIBase
	{
	public:
		enum class eSkillType
		{
			Assain,
			End,
		};

		SkillResources(eSkillType type);
		~SkillResources();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void MouseBTNClick() override;
		virtual void MouseBTNClickOff() override;

		void ClickOnQuickSlot();
		void ClickOffQuickSlot();

		void SetAssainSkill();
		void SetThisIsIcon(bool isicon) { isItIcon = isicon; }
		void SetQuickSlotUI(QuickSlotUI* skillquickslot) { skillQuickSlot = skillquickslot; }
		void SetSkillUIBG(SkillUIBG* skillbgui) { skillBGUI = skillbgui; }
		void SetIsMoveAble(bool ismove) { isMovePossible = ismove; }
		void SetIsPicked(bool ispick) { isPicked = ispick; }

	private:
		SkillUIBG* skillBGUI;
		QuickSlotUI* skillQuickSlot;
		eSkillType mSkillType;
	
		Animator* at;
		static bool isPicked;
		bool isMovePossible;
		bool isItIcon;
		bool isRender;
	};

}
