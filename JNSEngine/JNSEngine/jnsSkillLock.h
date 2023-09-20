#pragma once
#include "jnsEffectBase.h"

namespace jns
{
	class SkillLock : public EffectBase
	{
	public:
		SkillLock();
		~SkillLock();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void ResetTime();
		void ActivateToPlayer(Vector3 effectoffset, GameObject* chaseobj);
	private:
		float skillLockOnTime;
		
	};

}


