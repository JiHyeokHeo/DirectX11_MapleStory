#include "jnsPortalBase.h"

namespace jns
{
	PortalBase::PortalBase()
		: mType(eLayerType::Portal)
		, mr(nullptr)
		, tr(nullptr)
	{
		mr = AddComponent<MeshRenderer>();
		tr = GetComponent<Transform>();
	}
	PortalBase::~PortalBase()
	{
	}
	void PortalBase::Initialize()
	{
		GameObject::Initialize();
	}
	void PortalBase::Update()
	{
		GameObject::Update();
	}
	void PortalBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void PortalBase::Render()
	{
		GameObject::Render();
	}
}