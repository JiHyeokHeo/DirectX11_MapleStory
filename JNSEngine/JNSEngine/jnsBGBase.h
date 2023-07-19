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

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	protected:
		eLayerType mType;
		MeshRenderer* mr;
		Transform* tr; 
		Vector2 mSize; 
		Vector2 mTextureRatio;
	};
}

