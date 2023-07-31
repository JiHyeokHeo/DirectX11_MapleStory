#include "jnsRutabysScene.h"
#include "CommonSceneInclude.h"
#include "jnsComputeShader.h"

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
		//ComputeShader* cs = new ComputeShader();
		//cs->Create(L"PaintCS.hlsl", "main");
		//Test for VSBinding ( uv 좌표 변경을 통해 이미지 출력 사이즈 조절)
		
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);

#pragma region Ground
		
		// 땅바닥
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -300.0f, 4.0f), Vector3(2500.0f, 100.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"Ladder", Vector3(446.0f, 0.0f, 4.0f), Vector3(20.0f, 430.0f, 1.0f));
		
#pragma endregion


		Inventory* minven = object::InstantiateNOmove<Inventory>(eLayerType::UI);
		InventoryScript* invenScript = minven->GetComponent<InventoryScript>();
		

		// 플레이어 생성
		GameObject* player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 200.0f, 1.0f));
		player->GetComponent<PlayerScript>()->SetInventoryScript(invenScript);
		SceneManager::SetPlayer(player);


		// 플레이어 싹다 생성 후 스킬들 사전 생성



		// 테스트 스킬
		object::InstantiateSkill<AssainHit01>(Vector3::Zero);
		object::InstantiateSkill<JumpSkill>(Vector3::Zero);
		
		
		// 테스트 보스
		object::Instantiate<BloodyQueen>(eLayerType::Monster, Vector3(150.0f, -50.0f, 1.0f));



		// 포탈
		object::InstantiatePortal<Portal>(L"RutaMob", Vector3(-1800.0f, 200.0f, 1.0f), Vector3(-763.0f, -190.0f, 0.0f));


		////object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,   -141.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-200.5f,-170.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-450.0f,-190.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-600.5f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-850.0f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1000.0f,-130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1200.0f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1450.5f,-150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1600.0f,-130.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1850.5f,-250.0f, 4.9f));
																		 
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -201.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(250.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(400.0f, -140.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(600.5f, -200.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(850.5f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1000.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1200.0f, -160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1450.5f, -130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1600.0f, -120.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1850.5f, -140.0f, 4.9f));
	
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
		PlayScene::OnEnter();
	}
	void RutabysScene::OnExit()
	{
		PlayScene::OnExit();
	}
}