#include "jnsYellowPortal.h"
#include "CommonSceneInclude.h"

namespace jns
{
	YellowPortal::YellowPortal(jns::enums::eSceneType type, Vector3 setpos, int dir)
	{
		if (type != jns::enums::eSceneType::RutabysPierreBoss)
		{
			isBossPortal = false;
		}
		else
		{
			isBossPortal = true;
		}
		destinationSceneType = type;
		setPlayerPos = setpos;
		mDir = dir;
	}
	YellowPortal::~YellowPortal()
	{
	}
	void YellowPortal::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionAlphaMaterial");
		at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Map\\YellowPortal", 200, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Map\\GardenPortal", 200, 0.1f);	
		//at->CompleteEvent(L"CharactorCharWalk") = std::bind(&PlayerScript::Complete, this);


		if (isBossPortal)
		{
			at->PlayAnimation(L"MapGardenPortal", true);
		}
		else
		{
			at->PlayAnimation(L"MapYellowPortal", true);
		}
		tr->SetScale(Vector3(180.0f, 180.0f, 100.0f));
		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.4f, 0.6f));

		AddComponent<PortalScript>();
		PortalBase::Initialize();
	}
	void YellowPortal::Update()
	{
		if (isSetDir == false)
		{
			if (mDir == 1)
			{
				at->GetActiveAnimation()->SetAniDirection(true);
			}
			else
			{
				at->GetActiveAnimation()->SetAniDirection(false);
			}
			isSetDir = true;
		}

	
		GameObject::Update();
	}
	void YellowPortal::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void YellowPortal::Render()
	{
		GameObject::Render();
	}
}