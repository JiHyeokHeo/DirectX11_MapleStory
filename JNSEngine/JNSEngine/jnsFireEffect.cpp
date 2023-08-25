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
		SetName(L"FireEffect");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));


		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\FireEffect\\Fire", 500, 0.025f);
		at->PlayAnimation(L"FireEffectFire", true);
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