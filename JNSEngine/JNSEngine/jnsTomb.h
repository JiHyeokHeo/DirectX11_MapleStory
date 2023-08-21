#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Tomb : public GameObject
	{
	public:
		Tomb();
		~Tomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetIsDone(bool done) { isSetDone = done; }
	private:
		class Transform* tr;
		bool isRenderOn;
		bool isSetDone;
		bool isInitPos;
		class RigidBody* rb;
	};

}

