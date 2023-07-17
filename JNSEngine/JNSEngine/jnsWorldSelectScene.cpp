#include "jnsWorldSelectScene.h"
#include "CommonSceneInclude.h"
#include "jnsWorldSelectBG.h"

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
		//GameObject* camera = new GameObject();
		//AddGameObject(eLayerType::Player, camera);
		//camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<CameraScript>();
		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"WorldSelectButtonMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(450.0f, 100.0f, 4.8f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}
		WorldSelectBG* wBG = new WorldSelectBG();
		AddGameObject(eLayerType::BG, wBG);
		wBG->Initialize();


		CreateCursor();
		PlayScene::Initialize();
	}
	void WorldSelectScene::Update()
	{
		PlayScene::Update();
	}
	void WorldSelectScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"Select");
		}
	}
	void WorldSelectScene::Render()
	{
		PlayScene::Render();
	}
}