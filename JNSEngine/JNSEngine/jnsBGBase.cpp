#include "jnsBGBase.h"

namespace jns
{
	BGBase::BGBase()
		: mType(eLayerType::BG)
		, mr(nullptr)
	    , tr(nullptr)
	{
		AddComponent<MeshRenderer>();
	}
	BGBase::~BGBase()
	{
	}
	void BGBase::Initialize()
	{
		GameObject::Initialize();
	}
	void BGBase::Update()
	{
		GameObject::Update();
	}
	void BGBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BGBase::Render()
	{
		GameObject::Render();
	}

}