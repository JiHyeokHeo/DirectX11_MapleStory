#include "jnsEffectBase.h"
#include "jnsMeshRenderer.h"

namespace jns
{
	EffectBase::EffectBase()
	{
		mr = AddComponent<MeshRenderer>();
		tr = GetComponent<Transform>();
	}
	EffectBase::~EffectBase()
	{
	}
	void EffectBase::Initialize()
	{
		GameObject::Initialize();
	}
	void EffectBase::Update()
	{
		GameObject::Update();
	}
	void EffectBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void EffectBase::Render()
	{
		GameObject::Render();
	}
}