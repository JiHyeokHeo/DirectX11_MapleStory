#pragma once
#include "jnsScript.h"
#include "jnsScene.h"

namespace jns
{
	class PlayerMoveLimitScript : public Script
	{
	public:
		virtual void Update() override;

		Vector3 GetPlayerRightMaxMove() { return mPlayerRightMaxMove; }
		Vector3 GetPlayerLefttMaxMove() { return mPlayerLeftMaxMove; }

	private:
		Scene* mActiveScene;
		Vector3 mPlayerRightMaxMove;
		Vector3 mPlayerLeftMaxMove;
	};
}
