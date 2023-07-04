#include "jnsPlayScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
	/*	Main Camera*/
		CreateMainCamera();
		CreateUICamera();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::CreateMainCamera()
	{
		GameObject* maincamera = new GameObject();
		AddGameObject(eLayerType::Player, maincamera);
		maincamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* maincameraComp = maincamera->AddComponent<Camera>();
		//maincameraComp->SetCameraSize(2.5f);
		maincameraComp->TurnLayerMask(eLayerType::UI, false);
		maincamera->AddComponent<CameraScript>();
	}
	void PlayScene::CreateUICamera()
	{
		GameObject* uicamera = new GameObject();
		AddGameObject(eLayerType::Player, uicamera);
		uicamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* uicameraComp = uicamera->AddComponent<Camera>();

		uicameraComp->TurnLayerMask(eLayerType::Player, false);
		uicameraComp->TurnLayerMask(eLayerType::BG, false);
		//uicamera->AddComponent<CameraScript>();
	}
	void PlayScene::CreatePlayerUI()
	{
		// NoMove UI
		ExpBar* expBarUI = new ExpBar();
		//expBarUI->AddComponent<testScript>();
		AddGameObject(eLayerType::UI, expBarUI);
		expBarUI->Initialize();

		ExpMaxBar* maxBarUI = new ExpMaxBar();
		maxBarUI->AddComponent<testScript>();
		AddGameObject(eLayerType::UI, maxBarUI);
		maxBarUI->Initialize();
		
		SkillQuickSlotBackUI* skillSlotUI = new SkillQuickSlotBackUI();
		AddGameObject (eLayerType::UI, skillSlotUI);
		skillSlotUI->Initialize();
		
		CenterStatus* centerStatusUI = new CenterStatus();
		AddGameObject(eLayerType::UI, centerStatusUI);
		centerStatusUI->Initialize();

	}
}