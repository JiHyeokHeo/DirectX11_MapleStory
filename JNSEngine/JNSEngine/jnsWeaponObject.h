#pragma once
#include "jnsWeaponBase.h"

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

		void SetPlayerScript(class PlayerScript* script) { playerScript = script; }

	private:
		GameObject* weapon;
		class PlayerScript* playerScript;
		Transform* tr;
		
	};
}
