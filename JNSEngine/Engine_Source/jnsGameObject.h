#pragma once
#include "jnsEntity.h"

namespace jns
{
	using namespace math;
	class GameObject : public Entity
	{
	public:
		struct mGameObjectStatus
		{
			float mScale;
			Vector2 mPos;
			float dummy;
		};

		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();
	
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		

		//------------------------------------------------
		void SetPos(Vector2 pos) { mStatus.mPos = pos; }
		void SetScale(float scale) { mStatus.mScale = scale; }
		void SetRGB(Vector3 rgb) { mRGB = rgb; }
		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }
		void SetCol(bool isCol) { isCollider = isCol; }

		mGameObjectStatus GetStatus () { return mStatus; }
		Vector2 GetPos() { return mStatus.mPos; }
		float GetScale() { return mStatus.mScale; }

		bool GetIsCol() { return isCollider; }
		void SetIsCol(bool isCol) { isCollider = isCol; }
		
		float GetTime() { return mTime; }
	public:
		void PipeLineRender();
		bool CheckTime();
		void CheckPauseTime();
		void SetScaleAndPostion();

	private:
		eState mState;
		mGameObjectStatus mStatus;
		Vector3 mRGB;
		float mTime;
		
		
		bool isCollider;
		bool isChanged;
		//std::vector<Component*> mComponents;
	};

}
