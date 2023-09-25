#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Spawner : public GameObject
	{
	public:
		Spawner();
		~Spawner();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void Activate();
		virtual void DeActivate();
		virtual void SetPosition(Vector3 pos);

	private:
		std::vector<GameObject*> monsters;
	};
}
