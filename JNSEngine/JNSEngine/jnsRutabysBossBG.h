#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class RutabysBossBG : public BGBase
	{
	public:
		RutabysBossBG();
		~RutabysBossBG();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
	};

}




