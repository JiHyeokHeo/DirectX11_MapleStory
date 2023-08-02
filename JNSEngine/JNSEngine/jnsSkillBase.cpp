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
		mPlayer = jns::SceneManager::GetPlayer();
		mPlayerScript = mPlayer->GetComponent<PlayerScript>();
		GameObject::Initialize();
	}
	void SkillBase::Update()
	{
		if (isRenderOn == false)
			return;
		GameObject::Update();
	}
	void SkillBase::LateUpdate()
	{
		if (isRenderOn == false)
			return;
		GameObject::LateUpdate();
	}
	void SkillBase::Render()
	{
		if (isRenderOn == false)
			return;
		GameObject::Render();
	}
}
