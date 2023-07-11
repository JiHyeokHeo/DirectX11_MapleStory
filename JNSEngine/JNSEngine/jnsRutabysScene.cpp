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
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,-1.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1.5f,-0.8f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-2.0f,-0.9f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-3.5f,-0.7f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-4.0f,-0.8f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-5.5f,-1.1f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-6.0f,-0.6f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-7.5f,-0.5f, 4.9f));
																		 
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -0.7f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1.5f, -0.6f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(2.0f, -1.1f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(3.5f, -0.8f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(4.0f, -0.9f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(5.5f, -0.6f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(6.0f, -0.8f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(7.5f, -0.9f, 4.9f));
	

		// NoMove BackGround
		object::InstantiateNOmove<RutabysMain>(eLayerType::BG);

		CreateInventory();
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