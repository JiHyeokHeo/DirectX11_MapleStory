#include "jnsDamageControl.h"
#include "CommonSceneInclude.h"


namespace jns
{
	DamageControl::DamageControl()
	{
	}
	DamageControl::~DamageControl()
	{
	}
	void DamageControl::Initialize()
	{

		Transform* tr = GetComponent<Transform>();
		ani = AddComponent<Animator>();
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Zero", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\One", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Two", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Three", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Four", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Five", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Six", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Seven", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Eight", 1, 0.1f, Vector2::Zero);
		ani->CreateAnimations(L"..\\Resources\\UI\\NormalDamageSkin\\Nine", 1, 0.1f, Vector2::Zero);
		ani->PlayAnimation(L"NormalDamageSkinZero", false);

		/*	ani->GetCompleteEvent(L"PirateBossDie") = std::bind(&PirateBoss::bubbleCompleteEvent, this);*/
		GameObject::Initialize();
	}
	void DamageControl::Update()
	{
		setSkillDamage = 1250;
		std::string damage = std::to_string(setSkillDamage);
		
		int cnt = 0;
		for (char dmgcnt : damage)
		{
			cnt++;
		}


		if (damage[0] = "9" && mType == DamageType::Thousands)
		{
			ani->PlayAnimation(L"NormalDamageSkinZero", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinEight", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinSeven", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinSix", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinFive", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinFour", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinThree", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinTwo", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinOne", false);
		}
		if (damage[0] = "9" && mType == DamageType::Ones)
		{
			ani->PlayAnimation(L"NormalDamageSkinZero", false);
		}
		//if (== 4 && mType == DamageType::Hundreds)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinFour", false);
		//}
		//if (mMinutes == 3 && mType == DamageType::Hundreds)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinThree", false);
		//}
		//if (mMinutes == 2 && mType == DamageType::Hundreds)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinTwo", false);
		//}
		//if (mMinutes == 1 && mType == DamageType::Hundreds)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinOne", false);
		//}
		//if (mMinutes == 0 && mType == DamageType::Hundreds)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinZero", false);
		//}

		////-----------------------------------------------------
		//if (mTenSeconds == 5 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinFive", false);
		//}
		//if (mTenSeconds == 4 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinFour", false);
		//}
		//if (mTenSeconds == 3 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinThree", false);
		//}
		//if (mTenSeconds == 2 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinTwo", false);
		//}
		//if (mTenSeconds == 1 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinOne", false);
		//}
		//if (mTenSeconds == 0 && mType == DamageType::Tens)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinZero", false);
		//}
		////-----------------------------------------------------
		//if (mSeconds == 9 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinNine", false);
		//}
		//if (mSeconds == 8 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinEight", false);
		//}
		//if (mSeconds == 7 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinSeven", false);
		//}
		//if (mSeconds == 6 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinSix", false);
		//}
		//if (mSeconds == 5 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinFive", false);
		//}
		//if (mSeconds == 4 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinFour", false);
		//}
		//if (mSeconds == 3 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinThree", false);
		//}
		//if (mSeconds == 2 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinTwo", false);
		//}
		//if (mSeconds == 1 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinOne", false);
		//}
		//if (mSeconds == 0 && mType == DamageType::Ones)
		//{
		//	ani->PlayAnimation(L"NormalDamageSkinZero", false);
		//}

		GameObject::Update();
	}
	void DamageControl::LateUpdate()
	{
	}
	void DamageControl::Render()
	{
	}
	
}