#pragma once
#include "jnsEffectBase.h"

namespace jns
{
	class AttackReflection : public EffectBase
	{
	public:
		AttackReflection();
		~AttackReflection();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void ResetTime();
	private:
		float reflectionOnTime;
		bool isEffectOn;
	};

}
