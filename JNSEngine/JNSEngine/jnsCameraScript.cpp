#include "jnsCameraScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsTime.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsCamera.h"
#include "jnsCameraObject.h"

namespace jns
{
	void CameraScript::Update()
	{
		cameratr = GetOwner()->GetComponent<Transform>();
		//comp = GetOwner()->;

		if (FollowTarget())
		{

		}
		else
		{
			pos = cameratr->GetPosition();
		}

		

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.z += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
	}

	bool CameraScript::FollowTarget()
	{
		GameObject* mCamera = this->GetOwner();
		CameraObject* mMainCamera = dynamic_cast<CameraObject*>(mCamera);
		GameObject* checkTarget = mMainCamera->GetFollowTarget();
		
		if (checkTarget == nullptr)
			return false;
		
		Transform* followTR = checkTarget->GetComponent<Transform>();
		pos = followTR->GetPosition();

		cameratr->SetPosition(Vector3(pos.x, pos.y, -10.0f));
		return true;
	}
}