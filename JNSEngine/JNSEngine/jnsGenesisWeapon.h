#pragma once
#include "jnsWeaponBase.h"

namespace jns
{
	class GenesisWeapon : public WeaponBase
	{
	public:
		GenesisWeapon();
		~GenesisWeapon();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};


}