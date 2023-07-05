#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"

namespace jns
{
	class UIBase : public GameObject
	{
	public:
		UIBase();
		~UIBase();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	protected:
		eLayerType mType;
		MeshRenderer* mr;
		Transform* tr;
		Vector2 mTextureRatio;
		Vector2 mSize;
	};
}
