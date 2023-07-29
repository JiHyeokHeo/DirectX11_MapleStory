#include "jnsSkillManager.h"


namespace jns
{

	void SkillManager::Initialize()
	{
		SkillData assainAttack = { L"Normal_Assain_First_Attack", 50.0f, 0.5f , eKeyCode::LALT };
		SkillData assainAttack2 = { L"Normal_Assain_Second_Attack", 50.0f, 1.0f, eKeyCode::LALT };
	}

	void SkillManager::AddSkill(const std::string& key, const SkillData& skillData)
	{
	}

	void SkillManager::ActivateSkill(const std::string& key)
	{
	}

	bool SkillManager::IsSkillAvailable(const std::string& key)
	{
		return false;
	}

	void SkillManager::UpdateCooldowns(float deltaTime)
	{
	}

	void SkillManager::Release()
	{
	}

	//	void SkillManager::AddSkill(const std::string& key, const SkillData& skillData)
	//	{
	//	}

	//	void SkillManager::ActivateSkill(const std::string& key)
	//	{
	//	}

	//	bool SkillManager::IsSkillAvailable(const std::string& key)
	//	{

	//		return false;
	//	}

	//	void SkillManager::UpdateCooldowns(float deltaTime)
	//	{
	//	}

	//	void SkillManager::Release()
	//	{

	//	}

}