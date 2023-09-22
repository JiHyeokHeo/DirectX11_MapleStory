#pragma once
#include "jnsBloodyMeso.h"
#include "jnsSceneManager.h"

namespace jns::MesoPooling
{
	class MesoObjectPooling
	{
	public:
		MesoObjectPooling() {};
		~MesoObjectPooling() {};

		static MesoObjectPooling& GetInstance()
		{
			static std::unique_ptr<MesoObjectPooling> instance = std::make_unique<MesoObjectPooling>();
			return *instance;
		}
		void InitializePool()
		{
			if (isInitialized == false)
			{
				for (int i = 0; i < maxPoolSize; ++i)
				{
					/*BloodyMeso* meso = new BloodyMeso();
					meso->Initialize();
					mesoPool.push_back(meso);*/
				}
				isInitialized = true;
			}
		}

		void ActiveMesoObject();

		void Release();

		GameObject* CreateMesoObject();
		void RecycleMesoObject(GameObject* gameObject);
		

	private:
		bool isInitialized = false;
		int maxPoolSize = 20;
		int defaultCapacity = 15;
		std::list<GameObject*> mesoPool;
	};
}
