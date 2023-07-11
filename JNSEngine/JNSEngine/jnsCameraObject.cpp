#include "jnsCameraObject.h"
#include "CommonSceneInclude.h"

namespace jns
{
	CameraObject::CameraObject()
	{
		Initialize();
	}
	CameraObject::CameraObject(eCameraType type)
		: mCameraType(type)
		, mCameraPos(Vector3::Zero)
	{
		Initialize();
	}
	CameraObject::~CameraObject()
	{
	}
	void CameraObject::Initialize()
	{		
		//GameObject* uicamera = object::InstantiateNOmove<GameObject>(eLayerType::Camera);
		//uicamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		//Camera* uicameraComp = uicamera->AddComponent<Camera>();
		//uicameraComp->SetCameraType(jns::Camera::eCameraType::UICamera);
		//uicameraComp->TurnLayerMask(eLayerType::Player, false);
		//uicameraComp->TurnLayerMask(eLayerType::BG, false);
		//uicameraComp->TurnLayerMask(eLayerType::MapEffect, false);
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