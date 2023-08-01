#include "jnsSkillBase.h"
#include "CommonSceneInclude.h"
#include "jnsPlayerScript.h"
#include "jnsSceneManager.h"

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
		mPlayer = SceneManager::GetPlayer();
		mPlayerScript = mPlayer->GetComponent<PlayerScript>();
		GameObject::Initialize();
	}
	void SkillBase::Update()
	{
		if (this->GetState() == eState::Paused)
			return;
		GameObject::Update();
	}
	void SkillBase::LateUpdate()
	{
		if (this->GetState() == eState::Paused)
			return;
		GameObject::LateUpdate();
	}
	void SkillBase::Render()
	{
		if (this->GetState() == eState::Paused)
			return;
		GameObject::Render();
	}
	
}