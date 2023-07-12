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
		

		Player* player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 0.0f, 1.0001f));
		SetTarget(player);
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

		//object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,   -241.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-200.5f,-270.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-450.0f,-290.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-600.5f,-260.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-850.0f, -280.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1000.0f,-230.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1200.0f,-260.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1450.5f,-250.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1600.0f,-230.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1850.5f,-250.0f, 4.9f));
																		 
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -201.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(250.5f, -250.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(400.0f, -240.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(600.5f, -300.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(850.5f, -280.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1000.5f, -250.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1200.0f, -260.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1450.5f, -230.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1600.0f, -220.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1850.5f, -240.0f, 4.9f));
	
		object::InstantiateNOmove<Inventory>(eLayerType::UI);
		// NoMove BackGround
		object::InstantiateNOmove<RutabysMain>(eLayerType::BG);

		//CreateInventory();
		CreatePlayerUI();
		CreateCursor();

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
			SceneManager::LoadScene(L"RutabysBoss");
		}
	}
	void RutabysScene::Render()
	{
		PlayScene::Render();
	}
}