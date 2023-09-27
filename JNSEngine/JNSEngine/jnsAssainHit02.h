#pragma once
#include "jnsSkillBase.h"


namespace jns
{
	class AssainHit02 : public SkillBase
	{
	public:
		AssainHit02();
		~AssainHit02();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void CompleteSkillAnimation() override;
		virtual void StartSkillAnimation() override;

		virtual void Activate() override;
		void SkillSetPos();
	private:
		class Collider2D* cd;
	};

}
