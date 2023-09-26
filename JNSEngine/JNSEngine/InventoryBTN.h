#pragma once
#include "jnsUIBase.h"


namespace jns
{
	class InventoryBG;
	class InventoryBTN : public UIBase
	{
	public:
		enum class eInvenUIBTN
		{
			Weapon,
			Potion,
			Etc,
			None,
		};

		InventoryBTN();
		InventoryBTN(eInvenUIBTN type);
		~InventoryBTN();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void MouseBTNClick() override;
		virtual void MouseBTNClickOff() override;


		void SetInvenUIBG(InventoryBG* invenbgui) { InvenBGUI = invenbgui; }

		std::wstring eInvenUIBTNToString(eInvenUIBTN value) {
			enumToString = {
				{eInvenUIBTN::Weapon, L"Weapon"},
				{eInvenUIBTN::Potion, L"Potion"},
				{eInvenUIBTN::Etc, L"Etc"},
				{eInvenUIBTN::None, L"None"}
			};
			return enumToString[value];
		}

		void MakeWeapon();
		void MakePotion();
		void MakeEtc();

		static int GetPushedInvenNumber() { return pushedInvenBtnNumber; }

	private:
		eInvenUIBTN mInvenBTNType;
		InventoryBG* InvenBGUI;
		class Animator* at;
		std::map<eInvenUIBTN, std::wstring> enumToString;
		std::wstring disable = L"Off";
		std::wstring able = L"On";
		static int pushedInvenBtnNumber;

		int invenBtnNumber;

		bool isChanged = false;
		bool isRender = false;
	};
}
