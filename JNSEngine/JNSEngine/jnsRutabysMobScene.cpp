#include "jnsRutabysMobScene.h"
#include "CommonSceneInclude.h"
#include "jnsDemonMonster.h"

namespace jns
{
	RutabysMobScene::RutabysMobScene()
	{
	}
	RutabysMobScene::~RutabysMobScene()
	{
	}
	void RutabysMobScene::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob1);
		GameObject* rutaMovingBG = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob2);
		
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -300.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-1600.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-1400.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-1000.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-800.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-600.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-400.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(-200.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(0.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(200.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(400.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(600.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(800.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(1000.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(1400.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(1600.0f, -180.0f, 2.0f));
		//object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(1800.0f, -180.0f, 2.0f));

		// 이름 // 캐릭터 놓일 위치 // 생성 위치
		object::InstantiatePortal<Portal>(L"RutaScene", Vector3(-00.0f, -200.0f, 1.0f), Vector3(-1800.0f, -190.0f, 0.0f));
		object::InstantiatePortal<Portal>(L"RutaBoss", Vector3(00.0f, -200.0f, 1.0f), Vector3(1300.0f, -190.0f, 0.0f));

		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysMobScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysMobScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"RutabysBoss");
		}
	}
	void RutabysMobScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysMobScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysMobScene::OnExit()
	{
		PlayScene::OnExit();
	}
}