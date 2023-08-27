#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class BossHp : public GameObject
	{
	public:
		BossHp();
		~BossHp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
	};

}
