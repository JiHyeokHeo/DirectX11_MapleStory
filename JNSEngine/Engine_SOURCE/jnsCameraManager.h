#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class CameraManager
	{
	private:
		CameraManager() {};
		~CameraManager() {};
		CameraManager(const CameraManager& ref) {}
		CameraManager& operator=(const CameraManager& ref) {}

	public:
		static CameraManager& GetInstance()
		{
			static CameraManager instance;
			return instance;
		}

		void SetCameraFollowTarget(GameObject* followtarget) { mCameraFollowTarget = followtarget; }
		GameObject* GetFollowTarget() { return mCameraFollowTarget; }


	private:
		GameObject* mCameraFollowTarget;
	};

}
