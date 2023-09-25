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
		void InitializePool();

		void ActiveMesoObject();

		void Release();

		GameObject* CreateMesoObject();
		GameObject* CreateMesoEffect();

		void RecycleMesoObject(GameObject* gameObject);
		void RecycleMesoEffect(GameObject* gameObject);

	private:
		bool isInitialized = false;
		int maxPoolSize = 50;
		int defaultCapacity = 15;
		std::list<GameObject*> mesoPool;
		std::list<GameObject*> mesoEffects;
	};
}
