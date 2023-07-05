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
		GameObject* maincamera = object::InstantiateUIandBG<GameObject>(eLayerType::Camera);
		maincamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* maincameraComp = maincamera->AddComponent<Camera>();
		maincameraComp->TurnLayerMask(eLayerType::UI, false);
		maincamera->AddComponent<CameraScript>();
	}

	void PlayScene::CreateUICamera()
	{
		GameObject* uicamera = object::InstantiateUIandBG<GameObject>(eLayerType::Camera);
		uicamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* uicameraComp = uicamera->AddComponent<Camera>();
		uicameraComp->TurnLayerMask(eLayerType::Player, false);
		uicameraComp->TurnLayerMask(eLayerType::BG, false);
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
		object::InstantiateUIandBG<Cursor>(eLayerType::Cursor);
	}

	void PlayScene::CreateInventory()
	{
		GameObject* mShopSlotBackBase = object::InstantiateUIandBG<ShopSlotBack>(eLayerType::UI);
		GameObject* mShopSlotBack02 = object::InstantiateUIandBG<ShopSlotBack2>(eLayerType::UI);
		GameObject* mShopSlotBack03 = object::InstantiateUIandBG<ShopSlotBack3>(eLayerType::UI);


		mShopSlotBack02->GetComponent<Transform>()->SetParent(mShopSlotBackBase->GetComponent<Transform>());
		mShopSlotBack03->GetComponent<Transform>()->SetParent(mShopSlotBack02->GetComponent<Transform>());
	
	}	



}