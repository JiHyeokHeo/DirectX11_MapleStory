#pragma once
#include "jnsScript.h"

namespace jns
{
	class CameraScript : public Script
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		
	private:
		bool FollowTarget();
		class Camera* comp;
		class Transform* cameratr;
		Vector3 pos;
		float setYCord;

		Vector3 playerPrevPos;
		Vector3 cameraPrevPos;
	};
}
