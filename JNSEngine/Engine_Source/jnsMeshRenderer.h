#pragma once
#include "jnsComponent.h"
#include "jnsMesh.h"
#include "jnsShader.h"

namespace jns
{
	class MeshRenderer : public Component
	{
	public:
		MeshRenderer();
		~MeshRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Mesh* mMesh;
		Shader* mShader;
	};
}