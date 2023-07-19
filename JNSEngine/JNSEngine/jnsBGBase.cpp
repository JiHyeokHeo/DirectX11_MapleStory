#include "jnsBGBase.h"

namespace jns
{
	BGBase::BGBase()
		: mType(eLayerType::BG)
		, mr(nullptr)
	    , tr(nullptr)
	{
		mr = AddComponent<MeshRenderer>();
		tr = GetComponent<Transform>();
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