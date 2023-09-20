#include "jnsHatObject.h"
#include "CommonSceneInclude.h"

namespace jns
{
	HatObject::HatObject()
	{
		
	}
	HatObject::~HatObject()
	{
	}
	void HatObject::Initialize()
	{
		SetState(GameObject::eState::Paused);
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		
		at = AddComponent<Animator>();

		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Hat\\Blue", 500, 1.0f, Vector2(0.05f,0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Hat\\Red", 500, 1.0f, Vector2(0.05f, 0.0f));

		GetComponent<Transform>()->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		GameObject::Initialize();
	}
	void HatObject::Update()
	{
		Vector3 playerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();

		PlayerScript::ePlayerState state = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerState();
		
		if (state == PlayerScript::ePlayerState::Prone)
		{
			int a = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().isRight;
			playerPos.x += a * 2.0f;
			playerPos.y += 12.0f;
		}
		else if(state == PlayerScript::ePlayerState::Attack)
		{
			bool isAssain1 = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerSkillInfo().isAssainHit1Used;

			if (isAssain1)
			{
				playerPos.y += 35.0f;
			}
			else if (isAssain1 == false)
			{
				playerPos.y += 40.0f;
			}
		}
		else
		{
			playerPos.y += 30.0f;
		}
 		Transform* tr = GetComponent<Transform>();

		if (hattype != prevtype)
		{
			switch (hattype)
			{
			case jns::HatObject::HatType::Blue:
				at->PlayAnimation(L"HatBlue", true);
				break;
			case jns::HatObject::HatType::Red:
				at->PlayAnimation(L"HatRed", true);
				break;
			case jns::HatObject::HatType::None:
				break;
			default:
				break;
			}
		}

		SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo();
		tr->SetPosition(playerPos);
		prevtype = hattype;

		at->GetActiveAnimation()->SetAniDirection((bool)SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().isRight);
		GameObject::Update();
	}
	void HatObject::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void HatObject::Render()
	{
		GameObject::Render();
	}
	void HatObject::Activate()
	{
		SetState(GameObject::eState::Active);
		srand(time(NULL));
		int t = rand() % 2;
		t += 1;
		hattype = (HatObject::HatType)t;
	}
	void HatObject::DeActive()
	{
		SetState(GameObject::eState::Paused);
	}


}