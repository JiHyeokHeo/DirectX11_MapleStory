#include "jnsRutabysBossScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	RutabysBossScene::RutabysBossScene()
	{
	}
	RutabysBossScene::~RutabysBossScene()
	{
	}
	void RutabysBossScene::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenBoss);
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -450.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		//player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 0.0f, 1.0001f));
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"Login");
		}
	}
	void RutabysBossScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysBossScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysBossScene::OnExit()
	{
		PlayScene::OnExit();
	}
}