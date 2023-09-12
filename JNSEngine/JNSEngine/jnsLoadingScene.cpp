#include "jnsLoadingScene.h"
#include "ObjectTemplate.h"


namespace jns
{
	LoadingScene::LoadingScene()
	{
	}
	LoadingScene::~LoadingScene()
	{
	}
	void LoadingScene::Initialize()
	{

		//GameObject* obj = new GameObject();
		//obj->GetComponent<Transform>()->SetPosition(Vector3::Zero);
		//obj->GetComponent<Transform>()->SetScale(Vector3(1400.0f,1000.0f,1.0f));
		//MeshRenderer* mr = obj->AddComponent<MeshRenderer>();
		//std::shared_ptr<Texture> texture = Resources::Load<Texture>(L"loadingtest", L"..\\Resources\\loadingtext.png");
		//std::shared_ptr<Material> sprtiteMaterial = std::make_shared<Material>(); 
		//sprtiteMaterial->SetShader(Resources::Find<Shader>(L"SpriteShader"));
		//sprtiteMaterial->SetTexture(texture);
		//mr->SetMaterial(sprtiteMaterial);
		//mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//Scene* scene = SceneManager::GetActiveScene();
		//scene->AddGameObject(eLayerType::BG, obj);
		
		PlayScene::Initialize();
	}
	void LoadingScene::Update()
	{
		PlayScene::Update();
	}
	void LoadingScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void LoadingScene::Render()
	{
		PlayScene::Render();
	}
	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
	}
}