#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"

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
		MeshRenderer* mr;
		Transform* tr;
		Vector2 mTextureRatio;
	};
}
