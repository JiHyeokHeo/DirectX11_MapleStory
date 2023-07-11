#pragma once
#include "jnsGameObject.h"
#include "jnsCamera.h"

namespace jns
{
	class CameraObject : public GameObject
	{
	public:
		enum class eCameraType
		{
			MainCamera,
			UICamera,
			None,
		};
		CameraObject();
		CameraObject(eCameraType type);
		~CameraObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	public:
		void TurnOffMainCameraMask(eLayerType type);
		void TurnOffUICameraMask(eLayerType type);

		eCameraType GetCameraType() { return mCameraType; }

	private:
		Vector3 mCameraPos;
		eCameraType mCameraType;
		Camera* mCameraComp;
		eLayerType mTurnOffLayer;
	};
}

