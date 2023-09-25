#pragma once
#include "jnsMonsterBase.h"

namespace jns
{
	class DemonMonster : public MonsterBase
	{
	public:
		DemonMonster();
		~DemonMonster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


		virtual void Activate() override;
		virtual void DeActivate() override;

		void SetDirection();
	private:
	};
}

