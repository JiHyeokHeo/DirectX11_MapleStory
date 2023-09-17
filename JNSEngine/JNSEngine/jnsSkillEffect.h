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

		void CompleteHitEffect();

	private:
		SkillBase::eSkillType skillType;
	};

}
