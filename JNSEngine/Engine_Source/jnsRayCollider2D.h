#pragma once
#include "jnsComponent.h"

namespace jns
{
	class RayCollider2D : public Component
	{
	public:
		RayCollider2D();
		~RayCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
	};

}
