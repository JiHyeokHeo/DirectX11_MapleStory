#include "jnsItemResourcesScript.h"

namespace jns
{
	ItemResourcesScript::ItemResourcesScript(eItemType type)
		: mItemType(type)
	{
	}
	ItemResourcesScript::~ItemResourcesScript()
	{
	}
	void ItemResourcesScript::Initialize()
	{
		switch (mItemType)
		{
		case eItemType::PowerPotion:
			SetPowerPotion();
			break;
		}

	}
	void ItemResourcesScript::Update()
	{
	}
	void ItemResourcesScript::LateUpdate()
	{
	}
	void ItemResourcesScript::Render()
	{
	}
	void ItemResourcesScript::SetPowerPotion()
	{

	}
}
