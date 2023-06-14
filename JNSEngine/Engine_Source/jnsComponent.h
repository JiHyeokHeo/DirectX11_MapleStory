#pragma once
#include "jnsEntity.h"

namespace jns
{
	using namespace jns::enums;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:
		const eComponentType mType;

	};

}
