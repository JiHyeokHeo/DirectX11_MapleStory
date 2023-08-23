#include "jnsLightScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void LightScript::Initialize()
	{
		mPrevScene = nullptr;
		mOpacity = 0.0f;
	}
	void LightScript::Update()
	{
		mActiveScene = SceneManager::GetActiveScene();

		if (mDarkTime <= 0.3f)
		{
			chageScene = true;
			mDarkTime += Time::DeltaTime();
			if (SceneManager::GetPrevScene() != SceneManager::GetActiveScene())
			{
				mOpacity = 0.0f;
			}
		}

		if (mDarkTime >= 0.3f)
		{
			if (mOpacity < 1.0f )
			{
				mOpacity += Time::DeltaTime();
			}
			else
			{
				mOpacity = 1.0f;
			}
		}

		if (chageScene == false)
		{
			if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()
				->GetIsNormalHit() == true)
			{
				mOpacity = 0.0f;
			}
			else
			{
				mOpacity = 1.0f;
			}
		}


		this->GetOwner()->GetComponent<Light>()->SetColor(Vector4(0.8f * mOpacity, 0.8f * mOpacity, 0.8f * mOpacity, 1.0f));
	}

}