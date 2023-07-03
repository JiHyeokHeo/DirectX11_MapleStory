#include "jnsPlayScene.h"
#include "jnsTransform.h"
#include "jnsMeshRenderer.h"
#include "jnsResources.h"
#include "jnsMesh.h"
#include "jnsCameraScript.h"
#include "jnsCamera.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"

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
		//camera->AddComponent<CameraScript>();
	}
}