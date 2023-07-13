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
		CreateMainCamera();
		CreateUICamera();
		//CreateEffectCamera();
		//CreateGridCamera();
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
		CameraObject* mainCamera = new CameraObject(CameraObject::eCameraType::MainCamera);
		mainCamera->Initialize();
		mainCamera->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::Camera, mainCamera);
		mainCamera->TurnOffLayer(eLayerType::UI);
		mainCamera->AddComponent<CameraScript>();
		
	}

	void PlayScene::CreateUICamera()
	{
		CameraObject* uiCamera = new CameraObject(CameraObject::eCameraType::UICamera);
		uiCamera->Initialize();
		AddGameObject(eLayerType::Camera, uiCamera);
		uiCamera->TurnOffAllLayer();
		uiCamera->TurnOnLayer(eLayerType::UI);
	
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

		// Slot
		GameObject* mSkillSlotBack= object::InstantiateNOmove<SkillQuickSlotBackUI>(eLayerType::UI);
		GameObject* mSkillSlotFront = object::InstantiateNOmove<SkillQuickSlotFront>(eLayerType::UI);
		GameObject* mSkillExtensionSlot = object::InstantiateNOmove<SkillExtentionSlot>(eLayerType::UI);
		mSkillSlotFront->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());
		mSkillExtensionSlot->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());

		// Status
		GameObject* mStatus = object::InstantiateNOmove<CenterStatus>(eLayerType::UI);
		GameObject* mHpBar= object::InstantiateNOmove<HpBar>(eLayerType::UI);
		GameObject* mMpBar = object::InstantiateNOmove<MpBar>(eLayerType::UI);
		mHpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
		mMpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
	}

	void PlayScene::CreateCursor()
	{
		GameObject* mCursor = object::InstantiateNOmove<Cursor>(eLayerType::Cursor);
		mCursor->AddComponent<Collider2D>();
	}


	void PlayScene::CreateInventory()
	{
		GameObject* mShopSlotBackBase = object::InstantiateNOmove<ShopSlotBack>(eLayerType::UI);
		GameObject* mShopSlotBack02 = object::InstantiateNOmove<ShopSlotBack2>(eLayerType::UI);
		GameObject* mShopSlotBack03 = object::InstantiateNOmove<ShopSlotBack3>(eLayerType::UI);


		mShopSlotBack02->GetComponent<Transform>()->SetParent(mShopSlotBackBase->GetComponent<Transform>());
		mShopSlotBack03->GetComponent<Transform>()->SetParent(mShopSlotBack02->GetComponent<Transform>());
	}
}