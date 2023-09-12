#pragma once
#include "..\\Engine_Source\\jnsGameObject.h"
#include "..\\Engine_Source\\jnsMeshRenderer.h"
#include "..\\Engine_Source\\jnsTransform.h"
#include "..\\Engine_Source\\jnsMath.h"
#include "jnsCameraObject.h"

namespace jns
{
	using namespace math;
	class Cursor : public GameObject
	{
	public:
		Cursor();
		~Cursor();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void SetMainCameraToCursor(CameraObject* obj) { mainCamera = obj; }
		void SetUICameraToCursor(CameraObject* obj) { uiCamera = obj; }
		static __forceinline Vector3 GetCursorPos() { return mCursorPos; }
		static __forceinline Vector3 GetCursorWorldPos() { return mCursorWorldPos; }
	private:
		MeshRenderer* mr;
		Transform* tr;
		Vector2 mTextureRatio;
		CameraObject* uiCamera;
		CameraObject* mainCamera;
		static Vector3 mCursorPos;
		static Vector3 mCursorEndPos;
		static Vector3 mCursorWorldPos;
	};
}
