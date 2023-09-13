#pragma once
#include "jnsMonsterBase.h"

namespace jns
{
	class PierreBoss : public MonsterBase
	{
	public:
		PierreBoss();
		~PierreBoss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
	};

}
