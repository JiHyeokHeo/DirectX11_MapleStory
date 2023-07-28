#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class PlayerManager
	{
	private:
		PlayerManager() {};
		~PlayerManager() {};
		PlayerManager(const PlayerManager& ref) {}
		PlayerManager& operator=(const PlayerManager& ref) {}

	public:
		static PlayerManager& GetInstance()
		{
			static PlayerManager instance;
			return instance;
		}

		void SetPlayer(GameObject* player) { mMainPlayer = player; }
		GameObject* GetPlayer() { return mMainPlayer; }

	private:
		GameObject* mMainPlayer = nullptr;
	};

}
