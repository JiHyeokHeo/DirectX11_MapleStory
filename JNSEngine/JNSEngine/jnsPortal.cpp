#include "jnsPortal.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Portal::Portal(std::wstring name, Vector3 setpos)
	{
		mPortalName = name;
		setPlayerPos = setpos;
	}
	Portal::~Portal()
	{
	}
	void Portal::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionAlphaMaterial");
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Map\\Portal", 200, 0.1f);
		//at->CompleteEvent(L"CharactorCharWalk") = std::bind(&PlayerScript::Complete, this);

		
		at->PlayAnimation(L"MapPortal", true);
		tr->SetScale(Vector3(180.0f, 180.0f, 100.0f));
		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.4f, 0.6f));

		AddComponent<PortalScript>();
		PortalBase::Initialize();
	}
	void Portal::Update()
	{
		GameObject::Update();
	}
	void Portal::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Portal::Render()
	{
		GameObject::Render();
	}
}