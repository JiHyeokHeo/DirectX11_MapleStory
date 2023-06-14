#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();
		//struct PlayerData
		//{
		//	float mDataScale;
		//};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	public:
		void mouseposition();
		void mousemove(float power);
	private:
		Vector2 mousePos;
		Vector2 mCenterPos;
		float mScale;
		
		struct PlayerData
		{
			float mDataScale;
		};
		PlayerData mData;
	};
}
