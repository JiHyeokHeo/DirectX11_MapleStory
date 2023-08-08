#pragma once
#include "jnsComponent.h"
#include "jnsCollider2D.h"

namespace jns
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) {};
		virtual void OnCollisionStay(Collider2D* other) {};
		virtual void OnCollisionExit(Collider2D* other) {};

		void SetColNum(int num) { mColliderNum = num; }
		int GetColNum() { return mColliderNum; }
	private:
		int mColliderNum;
	};
}