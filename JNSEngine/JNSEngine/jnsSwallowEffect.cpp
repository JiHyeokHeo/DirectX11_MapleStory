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
		SetState(GameObject::eState::Active);
		SetName(L"SwallowEffect");
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		tr->SetScale(Vector3(1000.0f, 600.0f, 1.0f));


		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SwallowInit\\Swallow", 500, 0.15f);
		at->CompleteEvent(L"SwallowInitSwallow") = std::bind(&SwallowEffect::SwallowComplete, this);
		at->PlayAnimation(L"SwallowInitSwallow", true);
		
		GameObject::Initialize();
	}
	void SwallowEffect::Update()
	{
		if (GetState() == GameObject::eState::Active)
		{
			Vector3 playerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
			Vector3 swallowOriginPos = tr->GetPosition();
			if (isSet == false)
			{
				tr->SetPosition(playerPos.x, swallowOriginPos.y, swallowOriginPos.z);
				isSet = true;
			}
			Vector3 swallowDestinationPos = tr->GetPosition();

			int swallowDir = -99;
			if (playerPos.x >= swallowDestinationPos.x)
			{
				swallowDir = -1;
			}
			else if (playerPos.x <= swallowDestinationPos.x)
			{
				swallowDir = 1;
			}

			float registPower = 150.0f;
			playerPos.x += registPower * swallowDir * Time::DeltaTime();
			SceneManager::GetPlayer()->GetComponent<Transform>()->SetPosition(playerPos);
		}
		

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
	void SwallowEffect::SwallowComplete()
	{
		SetState(GameObject::eState::Paused);
		isSet = false;
	}
}
