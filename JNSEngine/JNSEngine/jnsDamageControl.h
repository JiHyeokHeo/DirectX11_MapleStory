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
		void SetDamageDigit(int digit) { this->digit = digit; }
		void SetDelayRenderTime(float time) { renderDelayMaxTime = time; }

	private:
		class Animator* ani;
		int setSkillDamage;
		DamageType mType;
		Transform* tr;
		std::map<int, std::wstring> digitAnimations;
		float xCorOffSet;

		float transparecny = 1.0f;
		std::wstring digitname = {};
		int digit;
		float renderTime;
		float renderDelayTime;
		float renderDelayMaxTime = 0.0f;
	};

}

