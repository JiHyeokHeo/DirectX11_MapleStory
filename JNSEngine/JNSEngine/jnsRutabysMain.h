#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class RutabysMain : public BGBase
	{
	public:
		RutabysMain();
		~RutabysMain();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
	};

}

