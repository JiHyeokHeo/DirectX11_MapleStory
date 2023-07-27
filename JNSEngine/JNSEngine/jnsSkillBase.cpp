#include "jnsSkillBase.h"
#include "CommonSceneInclude.h"

namespace jns
{
	SkillBase::SkillBase()
	{
		mr = AddComponent<MeshRenderer>();
		at = AddComponent<Animator>();
		tr = GetComponent<Transform>();
	}
	SkillBase::~SkillBase()
	{
	}
	void SkillBase::Initialize()
	{
		GameObject::Initialize();
	}
	void SkillBase::Update()
	{
		GameObject::Update();
	}
	void SkillBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillBase::Render()
	{
		GameObject::Render();
	}
}