#include "InventoryBTN.h"
#include "CommonSceneInclude.h"

constexpr auto INVENBTN_XSIZE = 25.0f;
constexpr auto INVENBTN_YSIZE = 15.0f;

namespace jns
{
	int InventoryBTN::pushedInvenBtnNumber = -99;
	InventoryBTN::InventoryBTN()
	{
	}
	InventoryBTN::InventoryBTN(eInvenUIBTN type)
		:mInvenBTNType(type)
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	InventoryBTN::~InventoryBTN()
	{
	}
	void InventoryBTN::Initialize()
	{
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionAlphaMaterial"));
		at = AddComponent<Animator>();

		switch (mInvenBTNType)
		{
		case jns::InventoryBTN::eInvenUIBTN::Weapon:
			MakeWeapon();
			break;
		case jns::InventoryBTN::eInvenUIBTN::Potion:
			MakePotion();
			break;
		case jns::InventoryBTN::eInvenUIBTN::Etc:
			MakeEtc();
			break;
		case jns::InventoryBTN::eInvenUIBTN::None:
			break;
		default:
			break;
		}
		std::wstring animationName = eInvenUIBTNToString(mInvenBTNType);
		invenBtnNumber = (int)mInvenBTNType + 1;

		animationName += disable;
		at->PlayAnimation(animationName, false);
	}
	void InventoryBTN::Update()
	{
		if (Input::GetKeyDown(eKeyCode::I))
		{
			if (isRender == false)
			{
				isRender = true;
			}
			else
			{
				isRender = false;
			}
		}

		Vector3 parentPos = InvenBGUI->GetComponent<Transform>()->GetParent()->GetPosition();
		float mYstartCor = parentPos.y + 160.0f;
		float mXstartCor = parentPos.x - 105.0f;
		// 추후에 여기는 
		if (true)
		{
			Vector3 btnPos = tr->GetPosition();
			btnPos.x = mXstartCor;
			btnPos.x += 36.0f * invenBtnNumber;
			btnPos.y = mYstartCor;
			btnPos.z = 1.0f;
			tr->SetPosition(btnPos);
		}

		Vector3 mSkillBtnPos = tr->GetPosition();
		Vector2 mLeftTop = Vector2(mSkillBtnPos.x - (INVENBTN_XSIZE / 2), mSkillBtnPos.y + (INVENBTN_YSIZE / 2));
		Vector2 mRightBottom = Vector2(mSkillBtnPos.x + (INVENBTN_XSIZE / 2), mSkillBtnPos.y - (INVENBTN_YSIZE / 2));
		Vector3 mousePos = Input::GetUIMousePos();

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x
			&& mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				std::wstring animationName = eInvenUIBTNToString(mInvenBTNType);
				invenBtnNumber = (int)mInvenBTNType + 1	;
				pushedInvenBtnNumber = invenBtnNumber;
				animationName += able;
				at->PlayAnimation(animationName, false);
				isChanged = true;
			}
		}

		// 숫자가 바뀌면 disable 애니메이션 작동 

		if (invenBtnNumber != pushedInvenBtnNumber)
		{
			if (isChanged)
			{
				std::wstring animationName = eInvenUIBTNToString(mInvenBTNType);
				invenBtnNumber = (int)mInvenBTNType + 1;
				animationName += disable;
				at->PlayAnimation(animationName, false);
				isChanged = false;
			}
		}



		GameObject::Update();
	}
	void InventoryBTN::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void InventoryBTN::Render()
	{
		if (isRender == true)
		GameObject::Render();
	}
	void InventoryBTN::MouseBTNClick()
	{
	}
	void InventoryBTN::MouseBTNClickOff()
	{
	}

	void InventoryBTN::MakeWeapon()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Weapon\\On", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Weapon\\Off", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void InventoryBTN::MakePotion()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Potion\\On", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Potion\\Off", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void InventoryBTN::MakeEtc()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Etc\\On", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\Inventory\\Etc\\Off", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
}