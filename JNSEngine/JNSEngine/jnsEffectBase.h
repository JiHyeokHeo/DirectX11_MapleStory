#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"

namespace jns
{
	class EffectBase : public GameObject
	{
	public:
		EffectBase();
		virtual ~EffectBase();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetChaseObject(GameObject* obj) { chaseObject = obj; }
		GameObject* GetChaseObject() { return chaseObject; }
	protected:
		MeshRenderer* mr;
		Transform* tr;
		GameObject* chaseObject;
		bool isEffectOn;
		Vector3 Offeset;
	private:
	};
}
