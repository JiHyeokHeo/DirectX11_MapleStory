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

	void PlayScene::CreateMainCamera()
	{
		mainCameraObj = new CameraObject(CameraObject::eCameraType::MainCamera);
		mainCameraObj->Initialize();
		mainCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::Camera, mainCameraObj);
		mainCameraObj->TurnOffLayer(eLayerType::UI);
		mainCameraObj->TurnOffLayer(eLayerType::Cursor);
		mainCameraObj->AddComponent<CameraScript>();
	}

	void PlayScene::CreateUICamera()
	{
		CameraObject* uiCamera = new CameraObject(CameraObject::eCameraType::UICamera);
		uiCamera->Initialize();
		AddGameObject(eLayerType::Camera, uiCamera);
		uiCamera->TurnOffAllLayer();
		uiCamera->TurnOnLayer(eLayerType::UI);
		uiCamera->TurnOnLayer(eLayerType::Cursor);
	
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
		Collider2D * mCol = mCursor->AddComponent<Collider2D>();
		mCol->Initialize();
		mCol->SetSize(Vector2(1.0f, 1.0f));
		
	}


	void PlayScene::CreateInventory()
	{
		GameObject* mShopSlotBack02 = object::InstantiateNOmove<ShopSlotBack2>(eLayerType::UI);


	}
}