#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"

namespace jns
{
	class Smoke : public GameObject	
	{
	public:
		Smoke();
		Smoke(Vector3 mPos);
		virtual ~Smoke();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		MeshRenderer* mr;
	};
}