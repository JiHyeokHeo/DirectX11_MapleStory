#pragma once
#include "..\\Engine_SOURCE\jnsGameObject.h"


enum class SceneType
{
	RutaMain,
	RutaQueenMob,
	RutaQueen,
};

namespace jns
{
	class CameraObject : public GameObject
	{
	public:
		enum class eCameraType
		{
			MainCamera,
			UICamera,
			MapCamera,
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

		Vector3 GetCameraPos() { return mCameraPos; }
	public:
		void TurnOffLayer(eLayerType type);
		void TurnOnLayer(eLayerType type);
		void TurnOnAllLayer();
		void TurnOffAllLayer();
		eCameraType GetCameraType() { return mCameraType; }

	private:
		Vector3 mCameraPos;
		eCameraType mCameraType;
		class Camera* mCameraComp;
		GameObject* mFollowTarget;

	};
}

