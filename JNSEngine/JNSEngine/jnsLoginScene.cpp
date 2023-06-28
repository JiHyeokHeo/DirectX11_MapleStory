#include "jnsLoginScene.h"
#include "jnsTransform.h"
#include "jnsCamera.h"
#include "jnsCameraScript.h"
#include "jnsLoginBG.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"

namespace jns
{
	LoginScene::LoginScene()
	{
	}
	LoginScene::~LoginScene()
	{
	}
	void LoginScene::Initialize()
	{
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();

		LoginBG* loginBG = new LoginBG();
		AddGameObject(eLayerType::BG, loginBG);
		loginBG->Initialize();
	}
	void LoginScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"WorldSelect");
		}
		Scene::Update();
	}
	void LoginScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void LoginScene::Render()
	{
		Scene::Render();
	}
}