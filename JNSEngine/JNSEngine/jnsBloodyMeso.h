#pragma once
#include "jnsSkillBase.h"


namespace jns
{
	class BloodyMeso : public SkillBase
	{
	public:
		BloodyMeso();
		~BloodyMeso();

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
