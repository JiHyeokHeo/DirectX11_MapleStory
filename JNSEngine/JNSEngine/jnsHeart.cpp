#include "jnsHeart.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Heart::Heart()
	{
	}
	Heart::~Heart()
	{
	}
	void Heart::Initialize()
	{
		//SetState(eState::Paused);
		SetName(L"BloodyQueenHeart");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		Animator* at = AddComponent<Animator>();
		Collider2D* cd = AddComponent<Collider2D>();
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(600.0f, 600.0f, 1.0f));
		tr->SetPosition(Vector3(-150.0f, -320.0f, -0.5f));
		cd->SetSize(Vector2(0.25f, 0.25f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionOpaqueMaterial"));

		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Heart\\HeartAttack", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Heart\\HeartNormal", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Heart\\HeartSummon", 500, 0.15f);
		at->PlayAnimation(L"HeartHeartSummon", true);
	}
	void Heart::Update()
	{
		GameObject::Update();
	}
	void Heart::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Heart::Render()
	{
		GameObject::Render();
	}
}