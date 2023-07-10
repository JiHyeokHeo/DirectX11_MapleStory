#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"
#include "jnsMath.h"

namespace jns
{
	using namespace jns::math;
	class Cursor : public GameObject
	{
	public:
		Cursor();
		~Cursor();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		static __forceinline Vector3 GetCursorPos() { return mCursorPos; }
	private:
		MeshRenderer* mr;
		Transform* tr;
		Vector2 mTextureRatio;
		static Vector3 mCursorPos;
		static Vector3 mUIPos;
	};
}
