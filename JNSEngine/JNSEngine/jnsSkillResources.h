#pragma once
#include "jnsUIBase.h"
#include "jnsAnimator.h"
#include "jnsMeshRenderer.h"

namespace jns
{
	class SkillResources : public UIBase
	{
	public:
		enum class eSkillType
		{
			Assain,
			End,
		};

		SkillResources(eSkillType type);
		~SkillResources();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void MouseBTNClick() override;
		virtual void MouseBTNClickOff() override;

		void SetAssainSkill();

	private:
		SkillResources();
		eSkillType mSkillType;
		bool isMovePossible;
		Animator* at;

	};

}
