#pragma once
#include <combaseapi.h>


interface ISkillDamage
{
public:
	virtual ~ISkillDamage();
	virtual void SkillAttackDamage() = 0;
	virtual void SkillAttackedDamage() = 0;
};