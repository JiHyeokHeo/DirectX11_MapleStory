#pragma once
#include "jnsMonsterBase.h"


namespace jns
{
	class BloodyQueen : public MonsterBase
	{
	public:
		BloodyQueen();
		~BloodyQueen();


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}
