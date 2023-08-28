#pragma once
#include "jnsGameObject.h"
#include "jnsAnimator.h"
namespace jns
{
	class MeshRenderer;
	class Transform;
	class WeaponBase : public GameObject
	{
	public:
		WeaponBase();
		~WeaponBase();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	protected:
		MeshRenderer* mr;
		Transform* tr;
		Animator* at;
	};

}
