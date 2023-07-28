#pragma once
#include "jnsSkillBase.h"


namespace jns
{
	class JumpSkill : public SkillBase
	{
	public:
		JumpSkill();
		~JumpSkill();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	private:

	};

}
