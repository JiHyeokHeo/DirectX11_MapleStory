#pragma once
#include "jnsComponent.h"
#include "jnsTransform.h"


namespace jns
{
	class Collider2D : public Component
	{
	public:
		Collider2D(); 
		~Collider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void OnCollisionEnter(Collider2D* other);
		void OnCollisionStay(Collider2D* other);
		void OnCollisionExit(Collider2D* other);

		void SetType(eColliderType type) { mType = type; }
		void SetSize(Vector2 size) { mSize = size; }
		void SetPosition(Vector3 position) { mPosition = position; }
		void SetCenter(Vector2 center) { mCenter = center; }
		UINT GetColliderID() { return mColliderID; }

		Vector3 GetPosition() { return mPosition; }
		Vector2 GetSize() { return mSize; }
		Vector2 GetCenter() { return mCenter; }
		
		Vector3 GetScale() { return mScale; }
	private:
		static UINT mColliderNumber;
		UINT mColliderID;

		eColliderType mType;
		Transform* mTransform;

		Vector3 mPosition;
		Vector2 mSize;
		Vector2 mCenter;

		Vector3 mScale;
		bool isColliding;
	};
}
