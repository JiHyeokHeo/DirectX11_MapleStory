#pragma once
#include "jnsEntity.h"
#include "jnsLayer.h"

namespace jns
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(enums::eLayerType type, GameObject* gameObj);
		void DeleteGameObject(enums::eLayerType type, GameObject* gameObj);


		template <typename T>
		std::vector<T*> FindObjectsOfType()
		{
			std::vector<T*> findObjs = {};
			for (Layer layer : mLayers)
			{
				auto gameObjs = layer.GetGameObjects();

				for (GameObject* obj : gameObjs)
				{
					T* buff = dynamic_cast<T*>(obj);
					
					if (buff != nullptr)
						findObjs.push_back(buff);
				}
			}

			return findObjs;
		}
		Layer& GetLayer(eLayerType type) { return mLayers[(UINT)type]; }
		std::vector<Layer>& GetLayers() { return mLayers; }
	private:
		std::vector<Layer> mLayers;
	};
}	
