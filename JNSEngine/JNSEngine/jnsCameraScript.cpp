#include "jnsCameraScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsTime.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsCamera.h"
#include "jnsCameraObject.h"
#include "jnsCameraManager.h"
#include "jnsPlayerScript.h"

namespace jns
{
	void CameraScript::Initialize()
	{
		mActiveScene = SceneManager::GetActiveScene();
		mPrevScene = nullptr;
		playerPrevPos = Vector3::Zero;
		cameraPrevPos = Vector3::Zero;
		setYCord = 130.0f;
	}
	void CameraScript::Update()
	{
		cameratr = GetOwner()->GetComponent<Transform>();

		if (FollowTarget())
		{

		}
		else
		{
			pos = cameratr->GetPosition();
		}

		

		//if (Input::GetKey(eKeyCode::W))
		//{
		//	pos.y += 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::S))
		//{
		//	pos.y -= 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::A))
		//{
		//	pos.x -= 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::D))
		//{
		//	pos.x += 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::Q))
		//{
		//	pos.z -= 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
		//else if (Input::GetKey(eKeyCode::E))
		//{
		//	pos.z += 255.0f * Time::DeltaTime();
		//	cameratr->SetPosition(pos);
		//}
	}

	bool CameraScript::FollowTarget()
	{
		GameObject* mCamera = this->GetOwner();
		GameObject* checkTarget = SceneManager::GetPlayer();
		
		if (checkTarget == nullptr)
			return false;
		
		// 씬마다 카메라 한계치를 만들어줍시다.

		if (mActiveScene != mPrevScene)
		{
			mActiveScene = SceneManager::GetActiveScene();
			mCameraRightMaxMove.x = 0.0f;
			mCameraRightMaxMove.y = 0.0f;
			mCameraLeftMaxMove.x = 0.0f;
			mCameraLeftMaxMove.y = 0.0f;
			mPrevScene = mActiveScene;
		}

		if (mActiveScene->GetSceneType() == jns::enums::eSceneType::RutabysMain)
		{
			mCameraRightMaxMove.x = 525.0f;
			mCameraRightMaxMove.y = 200.0f;
			mCameraLeftMaxMove.x = -525.0f;
			mCameraLeftMaxMove.y = 200.0f;
			setYCord = 150.0f;
		}

		if (mActiveScene->GetSceneType() == jns::enums::eSceneType::RutabysMob)
		{
			mCameraRightMaxMove.x = 1360.0f;
			mCameraRightMaxMove.y = -10.0f;
			mCameraLeftMaxMove.x = -1360.0f;
			mCameraLeftMaxMove.y = -10.0f;
			setYCord = 200.0f;
		}

		if (mActiveScene->GetSceneType() == jns::enums::eSceneType::RutabysBoss)
		{
			mCameraRightMaxMove.x = 525.0f;
			mCameraRightMaxMove.y = -10.0f;
			mCameraLeftMaxMove.x = -525.0f;
			mCameraLeftMaxMove.y = -10.0f;
			setYCord = 200.0f;
		}

		PlayerScript* playerScript = checkTarget->GetComponent<PlayerScript>();
		//if (playerScript->GetPlayerState() == jns::PlayerScript::ePlayerState::Hitted)
		//	return false;
		if (playerScript->GetPlayerState() == jns::PlayerScript::ePlayerState::Die)
			return false;
		// 플레이어 최신 위치를 불러온다.
		Transform* followTR = checkTarget->GetComponent<Transform>();
		Vector3 playerPos = followTR->GetPosition();
		float followSpeed = 4.0f;
		// 카메라 위치 선형 보간을 시킨다.
		Vector3 targetCameraPos = playerPos + Vector3(0.0f, setYCord, -10.0f);
		Vector3 interpolatedCameraPos = Vector3::Lerp(cameraPrevPos, targetCameraPos, followSpeed * Time::DeltaTime());
		

		// 카메라 z값은 다시 -10으로 바꿔준다. UI카메라와 혼동성을 깨뜨리면 안되기 때문에.
		interpolatedCameraPos.z = -10.0f;

		if (interpolatedCameraPos.x >= mCameraRightMaxMove.x)
		{
			interpolatedCameraPos.x = mCameraRightMaxMove.x;
		}
		if (interpolatedCameraPos.y >= mCameraRightMaxMove.y)
		{
			interpolatedCameraPos.y = mCameraRightMaxMove.y;
		}
		if (interpolatedCameraPos.x <= mCameraLeftMaxMove.x)
		{
			interpolatedCameraPos.x = mCameraLeftMaxMove.x;
		}
		if (interpolatedCameraPos.y >= mCameraLeftMaxMove.y)
		{
			interpolatedCameraPos.y = mCameraLeftMaxMove.y;
		}

		// 카메라를 선형 보간 시킨 위치로 이동 시킨다.
		cameratr->SetPosition(interpolatedCameraPos);
		playerPrevPos = playerPos;
		cameraPrevPos = interpolatedCameraPos;

		return true;
	}
}

