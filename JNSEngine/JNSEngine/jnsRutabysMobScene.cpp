#include "jnsRutabysMobScene.h"
#include "CommonSceneInclude.h"
#include "jnsDemonMonster.h"
#include "jnsSpawner.h"

namespace jns
{
	RutabysMobScene::RutabysMobScene()
	{
	}
	RutabysMobScene::~RutabysMobScene()
	{
	}
	void RutabysMobScene::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob1);
		GameObject* rutaMovingBG = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob2);
		
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -290.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(2100.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		

		// 이름 // 캐릭터 놓일 위치 // 생성 위치
		object::InstantiatePortal<Portal>(jns::enums::eSceneType::RutabysMain, Vector3(-00.0f, -200.0f, 1.0f), Vector3(-1800.0f, -190.0f, 0.0f));
		object::InstantiatePortal<Portal>(jns::enums::eSceneType::RutabysBoss, Vector3(00.0f, -200.0f, 1.0f), Vector3(1300.0f, -190.0f, 0.0f));

		spawn = new Spawner();
		spawn->Initialize();

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
	void RutabysMobScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysMobScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(jns::enums::eSceneType::RutabysBoss);
		}
	}
	void RutabysMobScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysMobScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysMobScene::OnExit()
	{
		spawn->Activate();

		std::vector<GameObject*> objs = SceneManager::GetActiveScene()->FindObjects<GameObject>(eLayerType::Item);
		std::vector<GameObject*> objs2 = SceneManager::GetActiveScene()->FindObjects<GameObject>(eLayerType::Skill);
		std::vector<GameObject*>::iterator iter
			= objs.begin();

		if (iter != objs.end())
		{
			int cnt = 0;
			for (iter; iter != objs.end(); iter++)
			{
				objs[cnt]->SetState(GameObject::eState::Dead);
				cnt++;
			}
		}

		iter = objs2.begin();

		
		if (iter != objs2.end())
		{
			int cnt = 0;
			for (iter; iter != objs2.end(); iter++)
			{
				if (objs2[cnt]->GetIsOnlyOne() == false)
				{
					objs2[cnt]->SetState(GameObject::eState::Dead);
				}
				cnt++;
			}
		}

		PlayScene::OnExit();
	}
}