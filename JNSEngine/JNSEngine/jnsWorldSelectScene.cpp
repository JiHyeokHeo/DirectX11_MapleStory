#include "jnsWorldSelectScene.h"
#include "jnsTransform.h"
#include "jnsMeshRenderer.h"
#include "jnsResources.h"
#include "jnsMesh.h"
#include "jnsCameraScript.h"
#include "jnsCamera.h"
#include "jnsWorldSelectBG.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"

namespace jns
{
	WorldSelectScene::WorldSelectScene()
	{
	}
	WorldSelectScene::~WorldSelectScene()
	{
	}
	void WorldSelectScene::Initialize()
	{
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();

		WorldSelectBG* wBG = new WorldSelectBG();
		AddGameObject(eLayerType::BG, wBG);
		wBG->Initialize();
	}
	void WorldSelectScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		Scene::Update();
	}
	void WorldSelectScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void WorldSelectScene::Render()
	{
		Scene::Render();
	}
}