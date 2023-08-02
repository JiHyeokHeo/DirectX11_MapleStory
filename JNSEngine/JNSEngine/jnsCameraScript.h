#pragma once
#include "jnsScript.h"
#include "jnsScene.h"

namespace jns
{
	class CameraScript : public Script
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		
		Transform* GetCameraTransform() { return cameratr; }
	private:
		bool FollowTarget();
		class Camera* comp;
		class Transform* cameratr;
		Vector3 pos;
		float setYCord;

		Vector3 playerPrevPos;
		Vector3 cameraPrevPos;
		Scene* mActiveScene;
		Scene* mPrevScene;

		Vector3 mCameraRightMaxMove;
		Vector3 mCameraLeftMaxMove;
	};
}
