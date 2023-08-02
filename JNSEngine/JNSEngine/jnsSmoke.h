#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"

namespace jns
{
	class Smoke : public GameObject	
	{
	public:
		enum class SmokeType
		{
			UVMode,
			NoneUVMode,
		};

		Smoke();
		Smoke(Vector3 mPos);
		virtual ~Smoke();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		SmokeType mSmokeType;
		MeshRenderer* mr;
		Transform* tr;
		float mTime;
		Vector3 mPos;
		Vector3 mInitialPos;
	};
}
