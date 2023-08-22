#include "jnsMirror.h"
#include "CommonSceneInclude.h"
#include "jnsMirrorScript.h"
#include <random>

std::mt19937_64 rng4(3244);
std::uniform_int_distribution<__int64> dist4(-800, 800);

namespace jns
{
	void Mirror::Initialize()
	{
		SetState(eState::Paused);
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
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorIdle", 500, 0.15f, Vector2(-0.01f, 0.01f));
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\Mirror\\MirrorSummon", 500, 0.15f);
		at->PlayAnimation(L"MirrorMirrorSummon", true);
		AddComponent<MirrorScript>();
	}
	void Mirror::Update()
	{
		
		if (GetState() == GameObject::eState::Paused)
		{
			if (mPrevState != GetState())
				isNotSetting = true;

			if (isNotSetting)
				PositionAndReSetting();
		}
		mPrevState = GetState();
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
	void Mirror::PositionAndReSetting()
	{
		float xCorRanCor = dist4(rng4);

		Transform* mirrorTr = GetComponent<Transform>();
		Vector3 mirrorPos = mirrorTr->GetPosition();

		mirrorPos.x = xCorRanCor;
		mirrorTr->SetPosition(mirrorPos);

		isNotSetting = false;
	}
}