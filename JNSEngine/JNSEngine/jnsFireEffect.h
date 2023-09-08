#pragma once
#include "jnsEffectBase.h"

namespace jns
{
	class FireEffect : public EffectBase
	{
	public:
		FireEffect();
		virtual ~FireEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
		bool isRenderOn;
		float mBurningTime;
		float mLastBurningTime;
		int burningDamage = 10.0f;
	};

}
