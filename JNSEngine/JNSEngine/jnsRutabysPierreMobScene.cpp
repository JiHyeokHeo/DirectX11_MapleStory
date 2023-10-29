#include "jnsRutabysPierreMobScene.h"
#include "CommonSceneInclude.h"
#include "jnsYellowPortal.h"
#include "jnsSpawner.h"

namespace jns
{
	RutabysPierreMobScene::RutabysPierreMobScene()
	{
	}
	RutabysPierreMobScene::~RutabysPierreMobScene()
	{
	}
	void RutabysPierreMobScene::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysPierreMob1);
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysPierreMob2);

		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -280.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"DownJumpGround", Vector3(1800.0f, -200.0f, 4.0f), Vector3(350.0f, 30.0f, 1.0f));

		object::InstantiatePortal<Portal>(jns::enums::eSceneType::RutabysMain, Vector3(-00.0f, -200.0f, 1.0f), Vector3(-1850.0f, -180.0f, 0.0f));
		object::InstantiateDirPortal<YellowPortal>(jns::enums::eSceneType::RutabysPierreBoss, Vector3(-00.0f, -300.0f, 1.0f), Vector3(1800.0f, -24.0f, 0.0f), -1);
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::westGardenArtifect1, Vector3(1500, -70.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::westGardenArtifect2, Vector3(-1300, -50.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::westGardenArtifect3, Vector3(1000, 10.0f, 3.0f));

		spawn = new Spawner();
		spawn->Initialize();

		PlayScene::Initialize();
	
		CameraObject* minimapCameraObj = new CameraObject(CameraObject::eCameraType::MapCamera);
		minimapCameraObj->Initialize();
		//minimapCameraObj->SetFollowTarget(followtarget);
		AddGameObject(eLayerType::Camera, minimapCameraObj);
		minimapCameraObj->TurnOffAllLayer();
		minimapCameraObj->TurnOnLayer(eLayerType::BG);
		minimapCameraObj->TurnOnLayer(eLayerType::Player);
		minimapCameraObj->TurnOnLayer(eLayerType::Monster);
		minimapCameraObj->GetComponent<Camera>()->SetSize(10000.0f);
		minimapCameraObj->GetComponent<Transform>()->SetPosition(4000.0f, -2500.0f, 2.0f);
	}
	void RutabysPierreMobScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysPierreMobScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(jns::enums::eSceneType::RutabysPierreBoss);
		}
	}
	void RutabysPierreMobScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysPierreMobScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysPierreMobScene::OnExit()
	{
		PlayScene::OnExit();
	}
}