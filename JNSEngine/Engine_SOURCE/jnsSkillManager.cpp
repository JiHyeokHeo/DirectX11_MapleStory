#include "jnsSkillManager.h"


namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, SkillData*> SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		mSkillData[L"Normal_Assain_First_Attack"] = new SkillData{ L"Normal_Assain_First_Attack", 50, 0.5f, eKeyCode::LCTRL };
		mSkillData[L"Normal_Assain_Second_Attack"] = new SkillData{ L"Normal_Assain_Second_Attack", 50, 1.0f, eKeyCode::LCTRL };
		mSkillData[L"Rogue_SkillflashJump_01"] = new SkillData{ L"Rogue_SkillflashJump_01", 0, 1.0f, eKeyCode::C };
		mSkillData[L"Rogue_SkillflashJump_02"] = new SkillData{ L"Rogue_SkillflashJump_02", 0, 1.0f, eKeyCode::C };
		
	
	}

	void SkillManager::AddSkill(const std::wstring& key, GameObject* skill)
	{
		mSkills.insert(std::make_pair(key, skill));
	}

	GameObject* SkillManager::FindSkill(const std::wstring& key)
	{
		std::unordered_map<std::wstring, GameObject*>::iterator iter
			= mSkills.find(key);
		
		if (iter != mSkills.end())
			return iter->second;


		return nullptr;
	}

	SkillData* SkillManager::FindSkillData(const std::wstring& key)
	{
		return mSkillData[key];
	}

	void SkillManager::Release()
	{
		for (auto& mDatas : mSkillData)
		{
			delete mDatas.second;
		}
		mSkillData.clear();
	}

}