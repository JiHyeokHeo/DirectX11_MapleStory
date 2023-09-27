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
		static float GetOpacity() { return mOpacity; }
	private:
		Scene* mPrevScene;
		Scene* mActiveScene;
		float mOwnOpacity;
		static float mOpacity;
		float mDarkTime;
		bool chageScene = false;
	};

}
