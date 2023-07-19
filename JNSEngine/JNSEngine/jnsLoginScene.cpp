#include "jnsLoginScene.h"
#include "CommonSceneInclude.h"

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
		//GameObject* camera = new GameObject();
		//AddGameObject(eLayerType::Player, camera);
		//camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<CameraScript>();
		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"LoginButtonMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(0.0f, -20.0f, 4.8f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Login);
		PlayScene::Initialize();
	}
	void LoginScene::Update()
	{
		PlayScene::Update();
	}
	void LoginScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"WorldSelect");
		}
	}
	void LoginScene::Render()
	{
		PlayScene::Render();
	}
}