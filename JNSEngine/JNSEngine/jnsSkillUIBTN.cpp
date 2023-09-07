#include "jnsSkillUIBTN.h"
#include "CommonSceneInclude.h"

constexpr auto SKILLBTN_XSIZE = 25.0f;
constexpr auto SKILLBTN_YSIZE = 15.0f;

namespace jns
{
	int SkillUIBTN::pushedBtnNumber = -99;
	SkillUIBTN::SkillUIBTN()
	{
	}
	SkillUIBTN::SkillUIBTN(eSkillUIBTN type)
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
		mSkillBTNType = type;

	
	}
	SkillUIBTN::~SkillUIBTN()
	{
	}
	void SkillUIBTN::Initialize()
	{

		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionAlphaMaterial"));
		at = AddComponent<Animator>();

		switch (mSkillBTNType)
		{
		case jns::SkillUIBTN::eSkillUIBTN::One:
			MakeOne();
			break;
		case jns::SkillUIBTN::eSkillUIBTN::Two:
			MakeTwo();
			break;
		case jns::SkillUIBTN::eSkillUIBTN::Three:
			MakeThree();
			break;
		case jns::SkillUIBTN::eSkillUIBTN::Four:
			MakeFour();
			break;
		case jns::SkillUIBTN::eSkillUIBTN::Five:
			MakeFive();
			break;
		case jns::SkillUIBTN::eSkillUIBTN::None:
			break;
		default:
			break;
		}
		std::wstring animationName = eSkillUIBTNToString(mSkillBTNType);
		skillBtnNumber = (int)mSkillBTNType + 1;
		
		animationName += disable;
		at->PlayAnimation(animationName, false);
	}
	void SkillUIBTN::Update()
	{
		if (Input::GetKeyDown(eKeyCode::K))
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
		Vector3 parentPos = skillBGUI->GetComponent<Transform>()->GetPosition();
		float mYstartCor = parentPos.y + 145.0f;
		float mXstartCor = parentPos.x - 140.0f;
		// 추후에 여기는 
		if (true)
		{
			Vector3 btnPos = tr->GetPosition();
			btnPos.x = mXstartCor;
			btnPos.x += 28.0f * skillBtnNumber;
			btnPos.y = mYstartCor;
			btnPos.z = 1.0f;
			tr->SetPosition(btnPos);
		}

		Vector3 mSkillBtnPos = tr->GetPosition();
		Vector2 mLeftTop = Vector2(mSkillBtnPos.x - (SKILLBTN_XSIZE / 2), mSkillBtnPos.y + (SKILLBTN_YSIZE / 2));
		Vector2 mRightBottom = Vector2(mSkillBtnPos.x + (SKILLBTN_XSIZE / 2), mSkillBtnPos.y - (SKILLBTN_YSIZE / 2));
		Vector3 mousePos = Input::GetUIMousePos();

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x
			&& mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y)
		{
			if (Input::GetKeyDown(eKeyCode::LBUTTON))
			{
				std::wstring animationName = eSkillUIBTNToString(mSkillBTNType);
				skillBtnNumber = (int)mSkillBTNType + 1;
				pushedBtnNumber = skillBtnNumber;
				animationName += able;
				at->PlayAnimation(animationName, false);
				isChanged = true;
			}
		}
		
		// 숫자가 바뀌면 disable 애니메이션 작동 

		if (skillBtnNumber != pushedBtnNumber)
		{
			if (isChanged)
			{
				std::wstring animationName = eSkillUIBTNToString(mSkillBTNType);
				skillBtnNumber = (int)mSkillBTNType + 1;
				animationName += disable;
				at->PlayAnimation(animationName, false);
				isChanged = false;
			}
		}

		GameObject::Update();
	}
	void SkillUIBTN::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillUIBTN::Render()
	{
		if(isRender == true)
		GameObject::Render();
	}
	void SkillUIBTN::MouseBTNClick()
	{
	}
	void SkillUIBTN::MouseBTNClickOff()
	{
	}
	void SkillUIBTN::MakeOne()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\One\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\One\\_disable", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void SkillUIBTN::MakeTwo()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Two\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Two\\_disable", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void SkillUIBTN::MakeThree()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Three\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Three\\_disable", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void SkillUIBTN::MakeFour()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Four\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Four\\_disable", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void SkillUIBTN::MakeFive()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Five\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Five\\_disable", 100, 0.1f);
		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
}