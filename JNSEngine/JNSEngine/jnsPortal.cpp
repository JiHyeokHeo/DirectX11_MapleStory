#include "jnsPortal.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Portal::Portal(std::wstring name)
	{
		mPortalName = name;
	}
	Portal::~Portal()
	{
	}
	void Portal::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Map\\Portal", 200, 0.1f);
		//at->CompleteEvent(L"CharactorCharWalk") = std::bind(&PlayerScript::Complete, this);
		
		at->PlayAnimation(L"MapPortal", true);
		tr->SetScale(Vector3(130.0f, 130.0f, 100.0f));
		
		PortalBase::Initialize();
	}
	void Portal::Update()
	{
		PortalBase::Update();
	}
	void Portal::LateUpdate()
	{
		PortalBase::LateUpdate();
	}
	void Portal::Render()
	{
		PortalBase::Render();
	}
}