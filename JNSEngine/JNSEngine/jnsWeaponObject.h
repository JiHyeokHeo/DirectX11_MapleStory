#pragma once
#include "jnsWeaponBase.h"
#include "jnsPlayerScript.h"

namespace jns
{
	class WeaponObject : public GameObject
	{
	public:
		enum class weaponFSM
		{
			Stand,
			Prone,
			Walk,
			Swing01,
			Swing02,
			Swing03,
		};

		WeaponObject();
		~WeaponObject();
				
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		GameObject* weapon;
		PlayerScript* playerScript;
		Transform* tr;
		PlayerScript::ePlayerState playerChangeState;
		GameObject* equipweapon;
		std::wstring weaponFrontName;
	};
}
