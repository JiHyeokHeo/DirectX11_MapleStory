#include "jnsCameraObject.h"
#include "CommonSceneInclude.h"

namespace jns
{
	CameraObject::CameraObject()
	{
	}
	CameraObject::CameraObject(eCameraType type)
		: mCameraType(type)
		, mCameraPos(Vector3::Zero)
		, mFollowTarget(nullptr)
	{
	}
	CameraObject::~CameraObject()
	{
	}
	void CameraObject::Initialize()
	{		
		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		mCameraComp = AddComponent<Camera>();
		
		switch (mCameraType)
		{
		case eCameraType::MainCamera:
			renderer::cameras.push_back(mCameraComp);
			break;
		case eCameraType::UICamera:
			renderer::cameras.push_back(mCameraComp);
			break;
		default:
			break;
		}
	}
	void CameraObject::Update()
	{
		GameObject::Update();
	}
	void CameraObject::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void CameraObject::Render()
	{
		GameObject::Render();
	}

	void CameraObject::TurnOffMainCameraMask(eLayerType type)
	{
		mCameraComp->TurnLayerMask(type, false);
	}
	
	void CameraObject::TurnOffUICameraMask(eLayerType type)
	{
		mCameraComp->TurnLayerMask(type, false);
	}
}