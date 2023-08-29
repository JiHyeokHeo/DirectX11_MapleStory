#include "jnsSkillUIBTN.h"
#include "CommonSceneInclude.h"

namespace jns
{
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
		
		animationName += able;
		at->PlayAnimation(animationName, false);
	}
	void SkillUIBTN::Update()
	{
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

		GameObject::Update();
	}
	void SkillUIBTN::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillUIBTN::Render()
	{
		GameObject::Render();
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