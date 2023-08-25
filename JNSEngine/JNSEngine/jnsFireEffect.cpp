#include "jnsFireEffect.h"
#include "CommonSceneInclude.h"`

namespace jns
{
	FireEffect::FireEffect()
	{
	}
	FireEffect::~FireEffect()
	{
		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"LinkSprite", L"..\\Resources\\Texture\\linkSprites.png");

		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3);
	}
	void FireEffect::Initialize()
	{
		SetName(L"AttackReflecton");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));

		std::shared_ptr<Texture> atlas
			= Resources::Load<Texture>(L"FireAtlas", L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQFire\\fire.png");
		Animator* at = AddComponent<Animator>();
		at->Create(L"Fire", atlas, Vector2::Zero, Vector2(120.0f, 120.0f),19, 100.0f);
		at->PlayAnimation(L"Fire", true);
		GameObject::Initialize();
	}
	void FireEffect::Update()
	{
		EffectBase::Update();
	}
	void FireEffect::LateUpdate()
	{
		EffectBase::LateUpdate();
	}
	void FireEffect::Render()
	{
		EffectBase::Render();
	}
}