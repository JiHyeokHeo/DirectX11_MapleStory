#include "jnsLightScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	float LightScript::mOpacity = 1.0f;
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
			if (SceneManager::GetPrevScene() != SceneManager::GetActiveScene() && SceneManager::isLoading == false)
			{
				mOwnOpacity = 0.0f;
			}
		}

		if (mDarkTime >= 0.3f)
		{
			if (mOwnOpacity < 1.0f )
			{
				mOwnOpacity += Time::DeltaTime();
			}
			else
			{
				mOwnOpacity = 1.0f;
				chageScene = false;
			}
		}

		if (chageScene == false)
		{
			if (SceneManager::GetPlayer() != nullptr)
			{
				bool t = SceneManager::GetPlayer()->GetComponent<PlayerScript>()
					->GetIsNormalHit();
				if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()
					->GetIsNormalHit() == true)
				{
					mOwnOpacity = 0.0f;
				}
				else
				{
					mOwnOpacity = 1.0f;
				}
			}
		}


		this->GetOwner()->GetComponent<Light>()->SetColor(Vector4(0.8f * mOwnOpacity, 0.8f * mOwnOpacity, 0.8f * mOwnOpacity, 1.0f));

		mOpacity = mOwnOpacity;
	}

}