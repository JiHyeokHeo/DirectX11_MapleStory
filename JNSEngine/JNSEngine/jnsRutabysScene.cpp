#include "jnsRutabysScene.h"
#include "CommonSceneInclude.h"
#include "jnsComputeShader.h"
#include "jnsPaintShader.h"
#include "jnsParticleSystem.h"
#include "jnsDamageControl.h"
#include "jnsAssainSkillParticle.h"
#include "jnsTomb.h"
#include "jnsYellowPortal.h"
#include "jnsSwallowEffect.h"
#include "jnsWeaponObject.h"
#include "jnsGenesisWeapon.h"
#include "jnsWeaponManager.h"
#include "jnsBloodyMeso.h"
#include "jnsMesoObjectPooling.h"

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

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Tomb, eLayerType::Ground, true);

		object::Instantiate<Tomb>(jns::enums::eLayerType::Tomb, Vector3::Zero);
		
		//연습용 파티클
		//object::InstantiateParticle<AssainSkillParticle>(jns::enums::eLayerType::Particle);

	

#pragma region Ground
		
		// 땅바닥
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -300.0f, 4.0f), Vector3(2500.0f, 100.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"DownJumpGround", Vector3(0.0f, -210.0f, 4.0f), Vector3(100.0f, 30.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"DownJumpGround", Vector3(440.0f, 200.0f, 4.0f), Vector3(450.0f, 30.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"Ladder", Vector3(446.0f, 0.0f, 4.0f), Vector3(20.0f, 430.0f, 1.0f));
		
#pragma endregion

		// 임시로 잠궈둠
		// //인벤토리
		//Inventory* minven = object::InstantiateNOmove<Inventory>(eLayerType::UI);
		//InventoryBG* minvenBG = object::InstantiateNOmove<InventoryBG>(eLayerType::UI);
		//minvenBG->GetComponent<Transform>()->SetParent(minven->GetComponent<Transform>());

		// 퀵슬롯
		QuickSlotUI* mSkillSlotBack = object::InstantiateNOmove<QuickSlotUI>(eLayerType::UI);
		QuickSlotFront* mSkillSlotFront = object::InstantiateNOmove<QuickSlotFront>(eLayerType::UI);
		QuickExtentionSlot* mSkillExtensionSlot = object::InstantiateNOmove<QuickExtentionSlot>(eLayerType::UI);
		mSkillSlotFront->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());
		mSkillExtensionSlot->GetComponent<Transform>()->SetParent(mSkillSlotBack->GetComponent<Transform>());

		// 스킬창
		SkillUIBG* skillUIBG = object::InstantiateNOmove<SkillUIBG>(eLayerType::UI);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);

		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::One)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Two)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Three)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Four)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Five)->SetSkillUIBG(skillUIBG);

		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::Assain, mSkillSlotBack, skillUIBG, Vector3::Zero, true);
		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::Assain, mSkillSlotBack, skillUIBG, Vector3::Zero, false);
		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::MesoExplosionRed, mSkillSlotBack, skillUIBG, Vector3::Zero, true);
		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::MesoExplosionRed, mSkillSlotBack, skillUIBG, Vector3::Zero, false);
		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::JumpSkill, mSkillSlotBack, skillUIBG, Vector3::Zero, true);
		object::InstantiateSkillUIType<SkillResources>(SkillResources::eSkillType::JumpSkill, mSkillSlotBack, skillUIBG, Vector3::Zero, false);
		//wchar_t szFloat[50] = L"BIN";
		//FontWrapper::DrawFont(szFloat, 10.f, 30.f, 20, FONT_RGBA(255, 0, 255, 255));

		// 플레이어 생성
		GameObject* player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 200.0f, 0.0f));
		PlayerScript* playerScript = player->GetComponent<PlayerScript>();
		//playerScript->SetInventoryScript(minvenBG->GetComponent<InventoryScript>());
		SceneManager::SetPlayer(player);
		WeaponObject* weapon = object::Instantiate<WeaponObject>(eLayerType::MapEffect, Vector3::Zero);
		WeaponManager::AddWeapon(L"Genesis_Thief_Weapon", object::Instantiate<GenesisWeapon>(eLayerType::MapEffect, Vector3::Zero));
		weapon->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());
		//weapon->SetPlayerScript(playerScript);
		// 플레이어 싹다 생성 후 스킬들 사전 생성


		// 테스트 스킬 
		JumpSkill* jump1 = object::InstantiateSkill<JumpSkill>(Vector3::Zero);
		jump1->SetName(L"Rogue_SkillflashJump_01");
		JumpSkill* jump2 =  object::InstantiateSkill<JumpSkill>(Vector3::Zero);
		jump2->SetName(L"Rogue_SkillflashJump_02");
		GameObject* obj1 = object::InstantiateSkill<AssainHit01>(Vector3::Zero);
		GameObject* obj2 = object::InstantiateSkill<AssainHit02>(Vector3::Zero);
		//object::InstantiateSkill<BloodyMeso> (Vector3::Zero);

		std::unique_ptr<jns::MesoPooling::MesoObjectPooling> mesoPooling = std::make_unique<jns::MesoPooling::MesoObjectPooling>();
		MesoPooling::MesoObjectPooling::GetInstance() = mesoPooling.get();
		MesoPooling::MesoObjectPooling::GetInstance()->CreateMesoObject();
		// 테스트 보스
		//object::Instantiate<BloodyQueen>(eLayerType::Monster, Vector3(150.0f, -50.0f, 1.0f));



		// 포탈
		object::InstantiatePortal<Portal>(jns::enums::eSceneType::RutabysMob, Vector3(-1800.0f, 200.0f, 1.0f), Vector3(-735.0f, -190.0f, 0.0f));
		object::InstantiatePortal<Portal>(jns::enums::eSceneType::RutabysPierreMob, Vector3(-1800.0f, 200.0f, 1.0f), Vector3(-260.0f, -190.0f, 0.0f));
		//object::InstantiateDirPortal<YellowPortal>(L"RutaMob", Vector3(-2400.0f, 200.0f, 1.0f), Vector3(-1000.0f, -190.0f, 0.0f), 1);
		//object::InstantiateDirPortal<YellowPortal>(L"RutaMob", Vector3(2400.0f, 200.0f, 1.0f), Vector3(1000.0f, -190.0f, 0.0f), -1);

		////object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,   -141.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-200.5f,-170.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-450.0f,-190.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-600.5f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-850.0f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1000.0f,-130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1200.0f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1450.5f,-150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1600.0f,-130.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1850.5f,-250.0f, 4.9f));
																		 
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -201.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(250.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(400.0f, -140.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(600.5f, -200.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(850.5f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1000.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1200.0f, -160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1450.5f, -130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1600.0f, -120.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1850.5f, -140.0f, 4.9f));
	

		// NoMove BackGround
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysMain);
		

		// 미니맵 카메라
		CameraObject* minimapCameraObj= new CameraObject(CameraObject::eCameraType::MapCamera);
		minimapCameraObj->Initialize();
		//minimapCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::UI, minimapCameraObj);
		minimapCameraObj->TurnOffAllLayer();
		minimapCameraObj->TurnOnLayer(eLayerType::BG);
		minimapCameraObj->TurnOnLayer(eLayerType::Player);
		minimapCameraObj->TurnOnLayer(eLayerType::Monster);
		minimapCameraObj->GetComponent<Camera>()->SetSize(10000.0f);
		minimapCameraObj->GetComponent<Transform>()->SetPosition(5000.0f, -2500.0f, 5.0f);

		//minimapCameraObj->
		
		//CreateInventory();
		CreatePlayerUI();
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
			SceneManager::LoadScene(jns::enums::eSceneType::RutabysMob);
		}
	}
	void RutabysScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysScene::OnExit()
	{
		PlayScene::OnExit();
	}
}