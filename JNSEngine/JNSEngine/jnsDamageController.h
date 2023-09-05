#pragma once
#include "JNSEngine.h"
#include "jnsGameObject.h"
#include "jnsCollider2D.h"
#include "jnsMonsterBase.h"

namespace jns
{
	class DamageController
	{
	public:
		static void HitPlayer(Collider2D* targetcol, MonsterBase* monster) 
		{ 
			if (targetcol->GetColNum() == 1)
			{
				monster->GetMonsterStatus();
			}
		}

		static void HitMonster(Collider2D* targetcol, MonsterBase* skillbase)
		{

		}


	private:
		MonsterBase* monster;
	};


}