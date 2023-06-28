#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"

namespace jns
{
	class BGBase : public GameObject
	{
	public:
		BGBase();
		~BGBase();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	protected:
		eLayerType mType;
		MeshRenderer* mr;
		Transform* tr;
	};
}

