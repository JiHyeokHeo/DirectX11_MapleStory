#pragma once
#include "jnsGameObject.h"
#include "jnsSceneManager.h"

struct MapDeathCntData
{
	std::map<jns::enums::eSceneType, int> deathcnt;
	std::map<jns::enums::eSceneType, jns::enums::eSceneType> diedestination;
};

namespace jns
{
	class GameManager
	{
	public:

		GameManager() {};
		~GameManager() {};
		static GameManager& GetInstance()
		{
			static std::unique_ptr<GameManager> instance = std::make_unique<GameManager>();
			return *instance;
		}

		void InitializeMapData();

		void SetDeathCount(int dcnt);
		int GetDeathCount();

		void SetBossPlayTime(int maxtime);
		int GetBossPlayTime();

		MapDeathCntData GetMapData() { return mapdata; }

		void SetIsDrag(bool drag) { isDragging = drag; }
		bool GetIsDrag() { return isDragging; }
	private:
		static int deathCount;
		static int bossPlayTime;
		MapDeathCntData mapdata;
		static bool isDragging;
	};

}

