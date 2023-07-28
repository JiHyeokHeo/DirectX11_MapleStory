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

		void SetFollowTarget(GameObject* target) { mFollowTarget = target; }
		GameObject* GetFollowTarget() { return mFollowTarget; }

	public:
		void TurnOffLayer(eLayerType type);
		void TurnOnLayer(eLayerType type);
		void TurnOnAllLayer();
		void TurnOffAllLayer();
		eCameraType GetCameraType() { return mCameraType; }

	private:
		Vector3 mCameraPos;
		eCameraType mCameraType;
		Camera* mCameraComp;
		GameObject* mFollowTarget;
	};
}

