#include "jnsMonsterBase.h"
#include "jnsAnimator.h"


namespace jns
{
	MonsterBase::MonsterBase()
	{
		mr = AddComponent<MeshRenderer>();
		at = AddComponent<Animator>();
		tr = GetComponent<Transform>();
	}
	MonsterBase::~MonsterBase()
	{
	}
	void MonsterBase::Initialize()
	{
	}
	void MonsterBase::Update()
	{
		GameObject::Update();
	}
	void MonsterBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void MonsterBase::Render()
	{
		GameObject::Render();
	}
}