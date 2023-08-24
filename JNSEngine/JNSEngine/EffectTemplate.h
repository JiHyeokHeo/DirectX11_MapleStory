#pragma once
#include "jnsMonsterBase.h"
#include "jnsEffectBase.h"

namespace effect::tem
{
	using namespace jns;
	template <typename T>
	MonsterBase::EffectType GetMonsterEffectState(T* obj)
	{
		MonsterBase* gameobj = dynamic_cast<MonsterBase*>(obj);
		MonsterBase::EffectType type = gameobj->GetEffectType();

		return type;
	}

	template <typename T>
	bool GetMonsterEffectIsOn(T* obj)
	{
		MonsterBase* gameobj = dynamic_cast<MonsterBase*>(obj);
		bool type = gameobj->GetIsEffectOn();

		return type;
	}

	template <typename T>
	void SetMonsterEffectIsOn(T* obj, bool isOn)
	{
		MonsterBase* gameobj = dynamic_cast<MonsterBase*>(obj);
		gameobj->SetIsEffectOn(isOn);
	}

	template <typename T>
	void SetMonsterEffectState(T* obj, MonsterBase::EffectType type)
	{
		MonsterBase* gameobj = dynamic_cast<MonsterBase*>(obj);
		gameobj->SetEffectType(type);
	}
}