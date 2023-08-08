#pragma once
#include "jnsSkillBase.h"


namespace jns
{
	class AssainHit01 : public SkillBase
	{
	public:
		AssainHit01();
		~AssainHit01();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void CompleteSkillAnimation() override;
		virtual void StartSkillAnimation() override;
	private:
		class Collider2D* cd;
	};

}
