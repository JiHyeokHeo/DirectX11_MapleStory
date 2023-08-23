#include "jnsTomb.h"
#include "CommonSceneInclude.h"
#include "jnsTombScript.h"

namespace jns
{
	Tomb::Tomb()
		: isRenderOn(false)
		, tr(nullptr)
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	Tomb::~Tomb()
	{
	}
	void Tomb::Initialize()
	{
		SetName(L"Tomb");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.4f, 0.5f));
		tr = GetComponent<Transform>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Effect\\DieEffect", 100, 0.05f);
		tr->SetPosition(Vector3::Zero);
		tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
		at->PlayAnimation(L"EffectDieEffect", false);
		AddComponent<TombScript>();
	}
	void Tomb::Update()
	{
		if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()
			->GetPlayerState() == PlayerScript::ePlayerState::Die)
		{
			isRenderOn = true;
		}
		else
		{
			isInitPos = true;
			isSetDone = false;
			isRenderOn = false;
		}

		if (isRenderOn == false)
			return;

		Vector3 playerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
		Vector3 tombPos = tr->GetPosition();
		float tombUpperInitPosY = 500.0f;
		if (isInitPos)
		{
			tombPos.y += tombUpperInitPosY;
			isInitPos = false;
		}

		float tombFallingSpeed = 500.0f;
		float setGroundPos = 50.0f;
		tombPos.y -= tombFallingSpeed * Time::DeltaTime();
		tombPos.x = playerPos.x;
		tombPos.z = playerPos.z + 0.01f;

		if (tombPos.y >= playerPos.y - setGroundPos && isSetDone == false)
		{
			tr->SetPosition(tombPos);
		}
		else
		{
			isSetDone = true;
		}
		

		GameObject::Update();
	}
	void Tomb::LateUpdate()
	{
		if (isRenderOn == false)
			return;

		GameObject::LateUpdate();
	}
	void Tomb::Render()
	{
		if (isRenderOn == false)
			return;

		GameObject::Render();
	}
}