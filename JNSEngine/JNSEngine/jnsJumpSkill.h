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
		
		virtual void CompleteSkillAnimation() override;
		virtual void StartSkillAnimation() override;
		

		void SetSkillJumpNum(int num) { mSkillJumpNum = num; }
		int GetSkillJumpNum() { return mSkillJumpNum; }
	private: 
		bool isClicked;
		bool mIsActivated;
		bool isMaked;

		int mSkillJumpNum;
	};
	
}
