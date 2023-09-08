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
		
		mDirectionalLight = new GameObject();
		mDirectionalLight->SetName(L"Smile");
		AddGameObject(eLayerType::Light, mDirectionalLight);
		Light* lightComp = mDirectionalLight->AddComponent<Light>();
		lightComp->SetType(eLightType::Directional);
		lightComp->SetColor(Vector4(0.8f, 0.8f, 0.8f, 1.0f));
		mDirectionalLight->AddComponent<LightScript>();
		
		CreateMainCamera();
		CreateUICamera();
		//CreateEffectCamera();
		//CreateGridCamera();
		
		CreateCursor();
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

	void PlayScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		//CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		//CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
		//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Player, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Skill, true);
		CollisionManager::SetLayer(eLayerType::Ground, eLayerType::Tomb, true);
	}

	void PlayScene::OnExit()
	{
		if(mBGInstance != nullptr)
			mBGInstance->GetComponent<AudioSource>()->Stop();

		mDirectionalLight->GetComponent<LightScript>()->SetDarkTime(0.0f);
	}

	void PlayScene::CreateMainCamera()
	{
		mainCameraObj = new CameraObject(CameraObject::eCameraType::MainCamera);
		mainCameraObj->Initialize();
		mainCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::Camera, mainCameraObj);
		mainCameraObj->TurnOffLayer(eLayerType::UI);
		mainCameraObj->TurnOffLayer(eLayerType::Cursor);
		mainCameraObj->TurnOffLayer(eLayerType::Item);
		mainCameraObj->AddComponent<CameraScript>();
	}

	void PlayScene::CreateUICamera()
	{
		uiCameraObj = new CameraObject(CameraObject::eCameraType::UICamera);
		uiCameraObj->Initialize();
		AddGameObject(eLayerType::Camera, uiCameraObj);
		uiCameraObj->TurnOffAllLayer();
		uiCameraObj->TurnOnLayer(eLayerType::UI);
		uiCameraObj->TurnOnLayer(eLayerType::Cursor);
		uiCameraObj->TurnOnLayer(eLayerType::Item);
	
	}

	//void PlayScene::CreateGridCamera()
	//{
	//	GameObject* grid = new GameObject();
	//	grid->SetName(L"Grid");
	//	AddGameObject(eLayerType::Grid, grid);
	//	MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
	//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
	//	mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
	//	GridScript* gridSc = grid->AddComponent<GridScript>();
	//	gridSc->SetCamera(maincameraComp);
	//}

	void PlayScene::CreatePlayerUI()
	{
		// 1600 x 900 Display Resolution
		object::InstantiateNOmove<ExpBar>(eLayerType::UI);
		object::InstantiateNOmove<ExpMaxBar>(eLayerType::UI);

		//// Slot
		//GameObject* mSkillSlotBack= object::InstantiateNOmove<QuickSlotUI>(eLayerType::UI);
		//GameObject* mSkillSlotFront = object::InstantiateNOmove<QuickSlotFront>(eLayerType::UI);
		//GameObject* mSkillExtensionSlot = object::InstantiateNOmove<QuickExtentionSlot>(eLayerType::UI);
		//mSkillSlotFront->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());
		//mSkillExtensionSlot->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());

		// Status
		GameObject* mStatus = object::InstantiateNOmove<CenterStatus>(eLayerType::UI);
		GameObject* mHpBar= object::InstantiateNOmove<HpBar>(eLayerType::UI);
		GameObject* mMpBar = object::InstantiateNOmove<MpBar>(eLayerType::UI);
		mHpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
		mMpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
	}

	void PlayScene::CreateCursor()
	{
		Cursor* mCursor = object::InstantiateNOmove<Cursor>(eLayerType::Cursor);
		//Collider2D * mCol = mCursor->AddComponent<Collider2D>();
		mCursor->SetUICameraToCursor(uiCameraObj);
		//mCol->Initialize();
		//mCol->SetSize(Vector2(1.0f, 1.0f));
		
	}


	void PlayScene::CreateInventory()
	{
		GameObject* mShopSlotBack01 = object::InstantiateNOmove<ShopSlotBack2>(eLayerType::UI);

	}



}