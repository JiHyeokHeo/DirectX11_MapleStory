#include "jnsPierreHat.h"
#include "CommonSceneInclude.h"
#include "jnsPierreHatScript.h"
namespace jns
{
	PierreHat::PierreHat()
	{
	}
	PierreHat::~PierreHat()
	{
	}
	void PierreHat::Initialize()
	{
		AddComponent<Collider2D>();
		SetState(GameObject::eState::Active);
		SetName(L"PierreHat");
		MeshRenderer* mr =  AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		// x 마이너스는 왼쪽으로 y 양수가 밑으로
		at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapAffected", 500, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapAffectedAfter", 500, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectStart", 500, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning1", 500, 0.1f, Vector2(0.020f, 0.45f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning2", 500, 0.1f, Vector2(0.020f, 0.45f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning3", 500, 0.1f, Vector2(0.020f, 0.45f));
		
		GetComponent<Transform>()->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		at->PlayAnimation(L"CapCapEffectWarning1", true);

		AddComponent<PierreHatScript>();
		GameObject::Initialize();
	}
	void PierreHat::Update()
	{
		GameObject::Update();
	}	
	void PierreHat::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void PierreHat::Render()
	{
		GameObject::Render();
	}
}