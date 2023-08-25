#include "jnsSwallowEffect.h"
#include "CommonSceneInclude.h"

namespace jns
{
	SwallowEffect::SwallowEffect()
	{
	}
	SwallowEffect::~SwallowEffect()
	{
	}
	void SwallowEffect::Initialize()
	{
		SetName(L"SwallowEffect");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(600.0f, 600.0f, 1.0f));


		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SwallowInit\\Swallow", 500, 0.15f);
		at->PlayAnimation(L"SwallowInitSwallow", true);
		GameObject::Initialize();
	}
	void SwallowEffect::Update()
	{
		EffectBase::Update();
	}
	void SwallowEffect::LateUpdate()
	{
		EffectBase::LateUpdate();
	}
	void SwallowEffect::Render()
	{
		EffectBase::Render();
	}
}
