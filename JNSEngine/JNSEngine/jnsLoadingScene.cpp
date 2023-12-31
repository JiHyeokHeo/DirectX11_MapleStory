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

		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::CharactorSelect);

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CharacSelectMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(-360.0f, 130.0f, 4.9f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CharacSelectInfoMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(420.0f, -50.0f, 4.9f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CharacSelectInfoMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(420.0f, -50.0f, 4.9f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CharSelectBtSelectMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(420.0f, -130.0f, 4.8f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CharSelectBtNewMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(-100.0f, -350.0f, 4.8f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		{
			GameObject* uiobj = object::InstantiateNOmove<GameObject>(eLayerType::UI);
			MeshRenderer* mr = uiobj->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"CommonBtPreviewMaterial"));
			Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			Transform* tr = uiobj->GetComponent<Transform>();
			tr->SetPosition(Vector3(-480, -370.0f, 4.8f));
			tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		}

		
		PlayScene::Initialize();
	}
	void LoadingScene::Update()
	{
		PlayScene::Update();
	}
	void LoadingScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::LBUTTON) && SceneManager::isComplete == true)
		{
			jns::SceneManager::check = true;
			mBGInstance->GetComponent<AudioSource>()->Stop();
			SceneManager::LoadScene(jns::enums::eSceneType::RutabysMain);
		}
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