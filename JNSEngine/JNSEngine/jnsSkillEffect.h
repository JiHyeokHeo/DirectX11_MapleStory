#pragma once
#include "jnsEffectBase.h"
#include "jnsSkillBase.h"

namespace jns
{
	class SkillEffect : public EffectBase
	{
	public:
		SkillEffect(SkillBase::eSkillType skilltype);
		~SkillEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
		SkillBase::eSkillType skillType;
		float transparecny = 0.0f;
		float renderDelayTime;
		float renderDelayMaxTime = 0.0f;
		float renderTime = 0.0f;
		std::wstring animationname = {};
		class Animator* at;
	};

}
