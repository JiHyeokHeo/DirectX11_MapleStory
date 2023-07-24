#include "jnsRutabysScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	RutabysScene::RutabysScene()
	{
	}
	RutabysScene::~RutabysScene()
	{
	}
	void RutabysScene::Initialize()
	{
		//Test for VSBinding ( uv 좌표 변경을 통해 이미지 출력 사이즈 조절)
		
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);


		Player* player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 0.0f, 1.0001f));
		player->AddComponent<PlayerScript>();
		player->AddComponent<Collider2D>();
		SetTarget(player);

		//Player* player2 = object::Instantiate<Player>(eLayerType::Monster, Vector3(0.0f, 0.0f, 1.0001f));
		//Transform* tr = player2->GetComponent<Transform>();
		//tr->SetPosition(Vector3(300.0f, 0.0f, 1.0001f));
		//player2->AddComponent<Collider2D>();

		//GameObject* obj = object::InstantiateItem<ItemResources>(eLayerType::Item, jns::ItemResources::eItemType::PowerPotion);
		//Transform* tr2 = obj->GetComponent<Transform>();
		//tr2->SetPosition(Vector3(300.0f, 0.0f, 1.0001f));
		
		ItemResources* testitem = new ItemResources(ItemResources::eItemType::PowerPotion);
		testitem->Initialize();
		AddGameObject(eLayerType::Item, testitem);
		
		//Collider2D* cd = player->AddComponent<Collider2D>();
		//cd->SetCenter(Vector2(0.5f, 0.0f));

		//cd = player->AddComponent<Collider2D>();
		////cd->SetCenter(Vector2(0.f, 0.0f));

		//std::vector<Collider2D*> comps 
		//	= player->GetComponents<Collider2D>();

		////Test for PS Binding ( uv 좌표 변경을 통해 이미지 무한 루프 wrap 개념(SamplerState) 
		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Smile");
		//	AddGameObject(eLayerType::Player, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
		//	player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		//	player->GetComponent<Transform>()->SetScale(Vector3(1.0f, 1.0f, 1.0f));
		//	//player->AddComponent<testScript>();
		//	//player->AddComponent<CameraScript>();
		//}

		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Smile");
		//	AddGameObject(eLayerType::Player, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.5f, 0.0f, -1.0f));
		//	player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		//	player->GetComponent<Transform>()->SetScale(Vector3(1.0f, 1.0f, 1.0f));
		//	//player->AddComponent<testScript>();
		//	//player->AddComponent<CameraScript>();
		//}

		//std::shared_ptr<Texture> atlas
		//	= Resources::Load<Texture>(L"LinkSprite", L"..\\Resources\\Texture\\linkSprites.png");

		//Animator* at = player->AddComponent<Animator>();
		//at->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f), 3);

		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharWalk");
		//at->PlayAnimation(L"CharactorCharWalk", true);

		////object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,   -141.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-200.5f,-170.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-450.0f,-190.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-600.5f,-160.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-850.0f, -180.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1000.0f,-130.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1200.0f,-160.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1450.5f,-150.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1600.0f,-130.0f, 4.9f));
		////object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1850.5f,-250.0f, 4.9f));
		//																 
		////object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -201.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(250.5f, -150.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(400.0f, -140.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(600.5f, -200.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(850.5f, -180.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1000.5f, -150.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1200.0f, -160.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1450.5f, -130.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1600.0f, -120.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1850.5f, -140.0f, 4.9f));
	
		object::InstantiateNOmove<Inventory>(eLayerType::UI);
		// NoMove BackGround
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysMain);
		//CreateInventory();
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"RutabysMob");
		}
	}
	void RutabysScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);
	}
	void RutabysScene::OnExit()
	{
	}
}