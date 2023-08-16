#include "jnsMirror.h"
#include "CommonSceneInclude.h"
#include "jnsMirrorScript.h"

namespace jns
{
	void Mirror::Initialize()
	{
		//SetState(eState::Paused);
		SetName(L"BloodyQueenMirror");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		Animator * at = AddComponent<Animator>();
		Collider2D* cd = AddComponent<Collider2D>();
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(600.0f, 600.0f, 1.0f));
		
		cd->SetSize(Vector2(0.25f, 0.25f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorAttractSuccess", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorBomb", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorHit", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorIdle", 500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorSummon", 500, 0.15f);
		at->PlayAnimation(L"MirrorMirrorSummon", true);
		AddComponent<MirrorScript>();
	}
	void Mirror::Update()
	{
		GameObject::Update();
	}
	void Mirror::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Mirror::Render()
	{
		GameObject::Render();
	}
}