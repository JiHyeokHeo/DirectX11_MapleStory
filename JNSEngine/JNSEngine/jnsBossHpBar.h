#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class BossHpBar : public GameObject
	{
	public:
		BossHpBar();
		~BossHpBar();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetBossTarget(GameObject* target) { bossTarget = target; }
		GameObject* GetBossTarget() { return bossTarget; }

	private:
		GameObject* bossTarget;
		Vector3 bossPrevHp;
		Vector3 interpolatedHp;
	};

}
