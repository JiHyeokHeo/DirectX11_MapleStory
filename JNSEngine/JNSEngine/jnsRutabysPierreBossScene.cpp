#include "jnsRutabysPierreBossScene.h"
#include "CommonSceneInclude.h"
#include "jnsBossHp.h"
#include "jnsBossHpBar.h"
#include "jnsPierreBoss.h"
#include "jnsPierreScript.h"
#include "jnsPierreHat.h"

namespace jns
{
	RutabysPierreBossScene::RutabysPierreBossScene()
		:mPrscript(nullptr)
	{
	}
	RutabysPierreBossScene::~RutabysPierreBossScene()
	{
	}
	void RutabysPierreBossScene::Initialize()
	{
		// 보스
		GameObject* obj = object::Instantiate<PierreBoss>(eLayerType::Monster, Vector3(150.0f, -160.0f, 3.0f));
		mPrscript = obj->GetComponent<PierreScript>();

		// 땅바닥 배경
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysPierreBoss);
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -550.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1260.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1260.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		//object::Instantiate<PierreHat>(eLayerType::Monster, Vector3(0.0f, -300.0f, 3.0f));

		// 보스 체력바 연동
		object::Instantiate<BossHp>(eLayerType::UI, Vector3::Zero);
		BossHpBar* bossHpBar = object::Instantiate<BossHpBar>(eLayerType::UI, Vector3::Zero);
		// 피에르랑 연결 시켜야함
		bossHpBar->SetBossTarget(obj);

		// 배경 애니메이션
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality1, Vector3(-950.0f, -20.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality2, Vector3(-380.0f, -220.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality3, Vector3(350.0f, -220.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality4, Vector3(970.0f, -20.0f, 3.0f));

		// 미니맵 카메라

		PlayScene::Initialize();
		// 미니맵 카메라
		CameraObject* minimapCameraObj = new CameraObject(CameraObject::eCameraType::MapCamera);
		minimapCameraObj->Initialize();
		//minimapCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::Camera, minimapCameraObj);
		minimapCameraObj->TurnOffAllLayer();
		minimapCameraObj->TurnOnLayer(eLayerType::BG);
		minimapCameraObj->TurnOnLayer(eLayerType::Player);
		minimapCameraObj->TurnOnLayer(eLayerType::Monster);
		minimapCameraObj->GetComponent<Camera>()->SetSize(10000.0f);
		minimapCameraObj->GetComponent<Transform>()->SetPosition(5000.0f, -2500.0f, 5.0f);
	}
	void RutabysPierreBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysPierreBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void RutabysPierreBossScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysPierreBossScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysPierreBossScene::OnExit()
	{
		mPrscript->ResetData();
		PlayScene::OnExit();
	}
}