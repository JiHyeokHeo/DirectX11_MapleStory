#pragma once
#include "jnsComponent.h"
#include "jnsGraphics.h"


namespace jns
{
	class Camera : public Component
	{
	public:
		enum class eProjectionType
		{
			Perpective, // 3D 원근감
			OrthoGraphic, // 2D 원근감 X
			None,
		};

		static Matrix GetViewMatrix() { return mView; }
		static Matrix GetProjectionMatrix() { return mProjection; }

		Camera();
		~Camera();
	
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		bool CreateViewMatrix();
		bool CreateProjectionMatrix(eProjectionType type);
		void RegisterCameraInRenderer();

		void TurnLayerMask(eLayerType type, bool enable = true);
		void EnableLayerMasks() { mLayerMask.set(); }
		void DisableLayerMasks() { mLayerMask.reset(); }

		void SortGameObjects();
		void RenderOpaque();
		void RenderCutOut();
		void RenderTransparent();


	private:
		static Matrix mView;
		static Matrix mProjection;

		eProjectionType mType;
		float mAspectRatio;
		float mNear;
		float mFar;
		float mSize;

		std::bitset<(UINT)eLayerType::End> mLayerMask;
		std::vector<GameObject*> mOpaqueGameObjects;
		std::vector<GameObject*> mCutOutGameObjects;
		std::vector<GameObject*> mTransparentGameObjects;
	};
}
