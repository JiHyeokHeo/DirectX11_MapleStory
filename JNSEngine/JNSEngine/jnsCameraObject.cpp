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
			renderer::mainCamera = mCameraComp;
			break;
		case eCameraType::UICamera:
			renderer::cameras.push_back(mCameraComp);
			renderer::UICamera = mCameraComp;
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

	void CameraObject::TurnOffLayer(eLayerType type)
	{
		mCameraComp->TurnOFFLayerMask(type);
	}

	void CameraObject::TurnOnLayer(eLayerType type)
	{
		mCameraComp->TurnLayerMask(type);
	}

	void CameraObject::TurnOnAllLayer()
	{
		mCameraComp->EnableLayerMasks();
	}

	void CameraObject::TurnOffAllLayer()
	{
		mCameraComp->DisableLayerMasks();
	}

}