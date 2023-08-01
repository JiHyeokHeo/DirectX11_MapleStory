#include "jnsSkillManager.h"


namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, SkillData*> SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		mSkillData[L"Normal_Assain_First_Attack"] = new SkillData{ L"Normal_Assain_First_Attack", 50.0f, 0.5f, eKeyCode::LCTRL };
		mSkillData[L"Normal_Assain_Second_Attack"] = new SkillData{ L"Normal_Assain_Second_Attack", 50.0f, 1.0f, eKeyCode::LCTRL };

	}

	void SkillManager::AddSkill(const std::wstring& key, GameObject* skill)
	{
		mSkills.insert(std::make_pair(key, skill));
	}

	GameObject& SkillManager::FindSkill(const std::wstring& key)
	{
		std::unordered_map<std::wstring, GameObject*>::iterator iter
			= mSkills.find(key);
		
		if (iter != mSkills.end())
			return *iter->second;
	}

	SkillData& SkillManager::FindSkillData(const std::wstring& key)
	{
		return* mSkillData[key];
	}

	void SkillManager::Release()
	{
		for (auto& pair : mSkillData)
		{
			delete pair.second;
		}
		mSkillData.clear();
	}

}