#include "jnsRutabysBossScene.h"
#include "CommonSceneInclude.h"
#include "jnsSwallowEffect.h"
#include "jnsFireEffect.h"
#include "jnsBossHp.h"
#include "jnsBossHpBar.h"

namespace jns
{
	RutabysBossScene::RutabysBossScene()
	{
	}
	RutabysBossScene::~RutabysBossScene()
	{
	}
	void RutabysBossScene::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenBoss);
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -450.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		

		object::Instantiate<DarkPaper>(eLayerType::BG, Vector3::Zero);
		
		// 보스 이펙트 연동
		GameObject* obj = object::Instantiate<BloodyQueen>(eLayerType::Monster, Vector3(150.0f, -160.0f, 3.0f));
		mBQscript = obj->GetComponent<BloodyQueenScript>();
		Mirror* mirror = object::Instantiate<Mirror>(eLayerType::Monster, Vector3(-150.0f, -300.0f, 2.0f));
		atObj = object::Instantiate<AttackReflection>(eLayerType::MapEffect, Vector3::Zero);
		atObj->SetChaseObject(obj);
		FireEffect* fireObj = object::Instantiate<FireEffect>(jns::enums::eLayerType::MapEffect, Vector3::Zero);
		SwallowEffect* swallowObj= object::Instantiate<SwallowEffect>(jns::enums::eLayerType::MapEffect, Vector3(0.0f, -390.0f, 2.0f));
		//
		mBQscript->SetMirror(mirror);
		mBQscript->SetSwallow(swallowObj);
		mBQscript->SetFireEffect(fireObj);
		// 하트 세팅
		for (int i = -7; i <= 7; i++)
		{
			Heart* heart = object::Instantiate<Heart>(eLayerType::Monster, Vector3(100*i, -375.0f, 0.5f));
			mBQscript->SetHeart(heart);
		}

		// UI
		object::Instantiate<BossHp>(eLayerType::UI, Vector3::Zero);
		BossHpBar* bossHpBar = object::Instantiate<BossHpBar>(eLayerType::UI, Vector3::Zero);
		bossHpBar->SetBossTarget(obj);

		// 미니맵 카메라
		CameraObject* minimapCameraObj = new CameraObject(CameraObject::eCameraType::MapCamera);
		minimapCameraObj->Initialize();
		//minimapCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::UI, minimapCameraObj);
		minimapCameraObj->TurnOffAllLayer();
		minimapCameraObj->TurnOnLayer(eLayerType::BG);
		minimapCameraObj->TurnOnLayer(eLayerType::Player);
		minimapCameraObj->TurnOnLayer(eLayerType::Monster);
		minimapCameraObj->GetComponent<Camera>()->SetSize(10000.0f);
		minimapCameraObj->GetComponent<Transform>()->SetPosition(5000.0f, -2500.0f, 5.0f);

		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		//if (Input::GetKeyDown(eKeyCode::P))
		//{
		//	SceneManager::LoadScene(L"Login");
		//}
	}
	void RutabysBossScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysBossScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysBossScene::OnExit()
	{
		mBQscript->ResetData();
		atObj->ResetTime();
		PlayScene::OnExit();
	}
}