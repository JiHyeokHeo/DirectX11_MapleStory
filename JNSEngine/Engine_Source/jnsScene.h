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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(enums::eLayerType type, GameObject* gameObj);

	private:
		std::vector<Layer> mLayers;
	};
}	
