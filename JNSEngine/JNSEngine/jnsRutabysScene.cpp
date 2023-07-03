#include "jnsRutabysScene.h"
#include "jnsTransform.h"
#include "jnsCamera.h"
#include "jnsCameraScript.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsRutabysMain.h"
#include "jnsResources.h"
#include "jnstestScript.h"

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
		//// Test
		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Zelda");
		//	AddGameObject(eLayerType::Player, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		//	//player->AddComponent<CameraScript>();

		//	GameObject* player2 = new GameObject();
		//	player2->SetName(L"ZeldaChild");
		//	AddGameObject(eLayerType::Player, player2);
		//	MeshRenderer* mr2 = player2->AddComponent<MeshRenderer>();
		//	mr2->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr2->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
		//	player2->GetComponent<Transform>()->SetPosition(Vector3(1.0f, 0.0f, 1.0001f));

		//	player2->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());
		//	//player->AddComponent<CameraScript>();

		//	const float pi = 3.141592f;
		//	float degree = pi / 2.0f;

		//	player->GetComponent<Transform>()->SetPosition(Vector3(-3.0f, 0.0f, 1.0001f));
		//	player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, degree));
		//}

		{
			GameObject* player = new GameObject();
			player->SetName(L"Smile");
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			player->AddComponent<testScript>();
			//player->AddComponent<CameraScript>();
		}

		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Smile");
		//	AddGameObject(eLayerType::Player, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.2f, 0.0f, 0.0f));
		//	//player->AddComponent<CameraScript>();
		//}

		//RutabysMain* rutabysMainBG = new RutabysMain();
		//AddGameObject(eLayerType::BG, rutabysMainBG);
		//rutabysMainBG->Initialize();

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