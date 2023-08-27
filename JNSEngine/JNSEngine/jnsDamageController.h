#pragma once
#include "JNSEngine.h"
#include "jnsGameObject.h"
#include <queue>

namespace jns
{
	class DamageController
	{
	public:
		static void SetTarget(GameObject* target) { targets.push(target); }
		static GameObject* GetTarget() 
		{
			GameObject* target = targets.front();
			targets.pop();

			return target; 
		}


	private:
		static std::queue<GameObject*> targets;
	};


}