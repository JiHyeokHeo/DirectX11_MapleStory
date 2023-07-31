#pragma once
#include "jnsScript.h"
#include "jnsScene.h"

namespace jns
{
	class LightScript : public Script
	{
	public:
		virtual void Initialize();
		virtual void Update();

	private:
		Scene* mPrevScene;
		Scene* mActiveScene;
		float mOpacity;
	};

}
