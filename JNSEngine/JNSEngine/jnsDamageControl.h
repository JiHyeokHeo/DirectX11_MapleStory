#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class DamageControl : public GameObject
	{
	public:
		enum class DamageType
		{
			Thousands,
			Hundreds,
			Tens,
			Ones,
			None,
		};
		DamageControl();
		~DamageControl();


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetSkillDamage(int dmg) { setSkillDamage = dmg; }
	private:
		class Animator* ani;
		int setSkillDamage;
		DamageType mType;
	};

}

