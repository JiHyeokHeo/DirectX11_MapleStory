#include "jnsItemResources.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ItemResources::ItemResources(eItemType type)
		: mItemType(type)
	{
	}
	ItemResources::~ItemResources()
	{
	}
	void ItemResources::Initialize()
	{
	}
	void ItemResources::Update()
	{
		GameObject::Update();
	}
	void ItemResources::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ItemResources::Render()
	{
		GameObject::Render();
	}
}