#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class CharactorMakeBG : public BGBase
	{
	public:
		CharactorMakeBG();
		virtual ~CharactorMakeBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


