#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class RootAbyssMain : public BGBase
	{
	public:
		RootAbyssMain();
		~RootAbyssMain();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
	};

}

