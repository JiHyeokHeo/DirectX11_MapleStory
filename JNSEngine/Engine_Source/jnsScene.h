#pragma once
#include "jnsEntity.h"
#include "jnsGameObject.h"

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

			

	public:
		void CollisionCheck(GameObject* Target);
		void FindTarget(GameObject* Target) { mTarget = Target; }
		void InterSect(GameObject* Target, GameObject* CheckList);

		void CollisionEnter(GameObject* Target);
		void CollisionOut(GameObject* Target);


		void SetRandomPos();


	private:
		std::vector<GameObject*> mGameObjects;
		float mTime;
		GameObject* mTarget;
	};
}	
