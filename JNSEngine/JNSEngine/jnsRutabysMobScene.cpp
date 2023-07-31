#include "jnsRutabysMobScene.h"
#include "CommonSceneInclude.h"

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