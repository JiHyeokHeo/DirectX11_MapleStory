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

		void SetDarkTime(float time) { mDarkTime = time; }
		
	private:
		Scene* mPrevScene;
		Scene* mActiveScene;
		float mOpacity = 1.0f;
		float mDarkTime;
		bool chageScene = false;
	};

}
