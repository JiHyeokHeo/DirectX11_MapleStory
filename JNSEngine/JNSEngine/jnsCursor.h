#pragma once
#include "jnsGameObject.h"


namespace jns
{
	class Cursor : public GameObject
	{
	public:
		Cursor();
		~Cursor();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:

	};
}
