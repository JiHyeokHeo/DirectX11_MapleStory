#include "jnsPierreBoss.h"
#include "CommonSceneInclude.h"

namespace jns
{
	PierreBoss::PierreBoss()
	{
	}
	PierreBoss::~PierreBoss()
	{
	}
	void PierreBoss::Initialize()
	{	
		SetName(L"PierreBoss");
		
		Collider2D* cd =  AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.21f, 0.24f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		// x 마이너스는 왼쪽으로 y 양수가 밑으로
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\attack1", 1000, 0.15f, Vector2(-0.013f, 0.115f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\attack2", 1000, 0.15f, Vector2(-0.015f, 0.050f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\move", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\NormalPierre\\transform", 1000, 0.15f, Vector2(0.0125f, -0.02f));
		
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\move", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\BluePierre\\transform", 1000, 0.15f, Vector2(-0.0035f, -0.019f));

		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\attack1", 1000, 0.15f, Vector2(-0.013f, 0.115f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\attack2", 1000, 0.15f, Vector2(-0.015f, 0.050f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\move", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\die1", 1000, 0.15f, Vector2(0.027f, 0.040f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\stand", 1000, 0.15f, Vector2(0.009f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\RedPierre\\transform", 1000, 0.15f, Vector2(-0.0035f, -0.019f));

		at->PlayAnimation(L"NormalPierredie1", true);
		//GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2000.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(1000.0f, 1000.0f, 1.0f));
		GetComponent<Transform>()->SetPosition(Vector3(0.0f, -370.0f, 3.0f));
		GameObject::Initialize();
	}
	void PierreBoss::Update()
	{
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			at->PlayAnimation(L"RedPierreattack1", true);
		}
		else if (Input::GetKeyDown(eKeyCode::X))
		{
			at->PlayAnimation(L"NormalPierreattack1", true);
		}
		GameObject::Update();
	}
	void PierreBoss::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void PierreBoss::Render()
	{
		GameObject::Render();
	}
}