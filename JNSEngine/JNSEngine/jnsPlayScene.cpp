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
		CreateGridCamera();
	}

	void PlayScene::Update()
	{		
		//Vector3 pos(600, 450, 0.0f);
		//Vector3 pos2(600, 450, 1000.0f);
		//Viewport viewport;
		//viewport.width = 1600.0f;
		//viewport.height = 900.0f;
		//viewport.x = 0;
		//viewport.y = 0;
		//viewport.minDepth = 0.0f;
		//viewport.maxDepth = 1.0f;

		//pos = viewport.Unproject(pos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		//pos2 = viewport.Unproject(pos2, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);

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
		GameObject* maincamera = object::InstantiateUIandBG<GameObject>(eLayerType::Camera);
		maincamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		maincameraComp = maincamera->AddComponent<Camera>();
		maincameraComp->SetCameraType(jns::Camera::eCameraType::MainCamera);
		maincameraComp->SetTarget(followtarget);
		maincameraComp->TurnLayerMask(eLayerType::UI, false);
		maincamera->AddComponent<CameraScript>();
	}

	void PlayScene::CreateUICamera()
	{
		GameObject* uicamera = object::InstantiateUIandBG<GameObject>(eLayerType::Camera);
		uicamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* uicameraComp = uicamera->AddComponent<Camera>();
		uicameraComp->SetCameraType(jns::Camera::eCameraType::UICamera);
		uicameraComp->TurnLayerMask(eLayerType::Player, false);
		uicameraComp->TurnLayerMask(eLayerType::BG, false);
		uicameraComp->TurnLayerMask(eLayerType::MapEffect, false);
	}

	void PlayScene::CreateGridCamera()
	{
		GameObject* grid = new GameObject();
		grid->SetName(L"Grid");
		AddGameObject(eLayerType::Grid, grid);
		MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		GridScript* gridSc = grid->AddComponent<GridScript>();
		gridSc->SetCamera(maincameraComp);
	}

	void PlayScene::CreatePlayerUI()
	{
		// 1600 x 900 Display Resolution
		object::InstantiateUIandBG<ExpBar>(eLayerType::UI);
		object::InstantiateUIandBG<ExpMaxBar>(eLayerType::UI);

		// Slot
		GameObject* mSkillSlotBack= object::InstantiateUIandBG<SkillQuickSlotBackUI>(eLayerType::UI);
		GameObject* mSkillSlotFront = object::InstantiateUIandBG<SkillQuickSlotFront>(eLayerType::UI);
		GameObject* mSkillExtensionSlot = object::InstantiateUIandBG<SkillExtentionSlot>(eLayerType::UI);
		mSkillSlotFront->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());
		mSkillExtensionSlot->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());

		// Status
		GameObject* mStatus = object::InstantiateUIandBG<CenterStatus>(eLayerType::UI);
		GameObject* mHpBar= object::InstantiateUIandBG<HpBar>(eLayerType::UI);
		GameObject* mMpBar = object::InstantiateUIandBG<MpBar>(eLayerType::UI);
		mHpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
		mMpBar->GetComponent<Transform>()->SetParent(mStatus->GetComponent<Transform>());
	}

	void PlayScene::CreateCursor()
	{
		object::InstantiateUIandBG<Cursor>(eLayerType::UI);
	}

	void PlayScene::CreateInventory()
	{
		GameObject* mShopSlotBackBase = object::InstantiateUIandBG<ShopSlotBack>(eLayerType::UI);
		GameObject* mShopSlotBack02 = object::InstantiateUIandBG<ShopSlotBack2>(eLayerType::UI);
		GameObject* mShopSlotBack03 = object::InstantiateUIandBG<ShopSlotBack3>(eLayerType::UI);


		mShopSlotBack02->GetComponent<Transform>()->SetParent(mShopSlotBackBase->GetComponent<Transform>());
		mShopSlotBack03->GetComponent<Transform>()->SetParent(mShopSlotBack02->GetComponent<Transform>());
	}
	//void PlayScene::CreateEffectCamera()
	//{
	//	GameObject* uicamera = object::InstantiateUIandBG<GameObject>(eLayerType::Camera);
	//	uicamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
	//	Camera* uicameraComp = uicamera->AddComponent<Camera>();
	//	uicameraComp->TurnLayerMask(eLayerType::Player, false);
	//	uicameraComp->TurnLayerMask(eLayerType::BG, false);
	//}




}