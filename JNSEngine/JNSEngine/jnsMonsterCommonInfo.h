#pragma once
#include "jnsScript.h"
#include "jnsMonsterBase.h"

namespace jns
{
	struct MonsterCommonInfo
	{
		int hp;
		float skillCoolDown;
		int dmg;
		int skilldmg;

		MonsterBase::MonsterDir mDir;
		MonsterBase::MonsterDir mPrevDir;

		bool isRight;
		bool isChasing;
		float mMoveSpeed;
		float mHittedTime;
	};

}
