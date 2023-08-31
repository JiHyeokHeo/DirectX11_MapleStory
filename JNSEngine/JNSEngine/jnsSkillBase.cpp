#include "jnsSkillBase.h"
#include "CommonSceneInclude.h"

namespace jns
{
	SkillBase::SkillBase(eSkillType type)
		: mSkillType(type)
		, mType(eLayerType::Skill)
		, isRenderOn(false)
		, isPlayPossible(true)
		, mPlayer(nullptr)
		, mPlayerScript(nullptr)
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
		GameObject::Update();
	}
	void SkillBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillBase::Render()
	{
		if (isRenderOn == false)
			return;
		GameObject::Render();
	}
}
