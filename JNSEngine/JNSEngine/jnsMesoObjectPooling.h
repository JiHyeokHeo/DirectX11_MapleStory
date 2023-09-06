#pragma once
#include "jnsBloodyMeso.h"

namespace jns::MesoPooling
{
	class MesoObjectPooling
	{
	private:
		MesoObjectPooling(const MesoObjectPooling& ref) {}
		MesoObjectPooling& operator=(const MesoObjectPooling& ref) {}

	public:
		MesoObjectPooling() {};
		~MesoObjectPooling() {};

		static MesoObjectPooling*& GetInstance()
		{
			static MesoObjectPooling* instance = nullptr;
			return instance;
		}

		void InitializePool()
		{
			if (isInitialized == false)
			{
				for (int i = 0; i < maxPoolSize; ++i)
				{
					BloodyMeso* meso = new BloodyMeso();
					meso->Initialize();
					mesoPool.push_back(std::shared_ptr<GameObject>(meso));
				}
				isInitialized = true;
			}
		}

		GameObject* CreateMesoObject();
		void RecycleMesoObject(GameObject* gameObject);
	private:
		bool isInitialized = false;
		int maxPoolSize = 20;
		int defaultCapacity = 15;
		std::list<std::shared_ptr<GameObject>> mesoPool;
	};
}
