#include "jnsPlayerMoveLimitScript.h"
#include "jnsSceneManager.h"

namespace jns
{
	void PlayerMoveLimitScript::Update()
	{
		mActiveScene = SceneManager::GetActiveScene();
		

		if (mActiveScene->GetName() == L"Rutabys")
		{
			mPlayerRightMaxMove.x = 525.0f;
			mPlayerRightMaxMove.y = 1000.0f;
			mPlayerLeftMaxMove.x = -525.0f;
			mPlayerLeftMaxMove.y = 1000.0f;
		}

		if (mActiveScene->GetName() == L"RutabysMob")
		{
			mPlayerRightMaxMove.x = 1360.0f;
			mPlayerRightMaxMove.y = -10.0f;
			mPlayerLeftMaxMove.x = -1360.0f;
			mPlayerLeftMaxMove.y = -10.0f;
		}

		if (mActiveScene->GetName() == L"RutabysBoss")
		{
			mPlayerRightMaxMove.x = 525.0f;
			mPlayerRightMaxMove.y = -10.0f;
			mPlayerLeftMaxMove.x = -525.0f;
			mPlayerLeftMaxMove.y = -10.0f;
		}

	}
}