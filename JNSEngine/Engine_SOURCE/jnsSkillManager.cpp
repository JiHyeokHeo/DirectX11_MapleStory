#include "jnsSkillManager.h"
#include "..\\JNSEngine\\jnsSkillResources.h"

namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, SkillData*> SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		// 만약 추후에 파싱을 하게 된다면 이름이든 이런식으로 연결해서 정보를 생성할수 있을듯 싶다. // 아직 할 계획은 없지만 추후에 여력 있으면 해볼 예정
		mSkillData[L"Normal_Assain_First_Attack"] = new SkillData{ L"Normal_Assain_First_Attack", 5, 0.5f, eKeyCode::NONE };
		mSkillData[L"Normal_Assain_Second_Attack"] = new SkillData{ L"Normal_Assain_Second_Attack", 5, 1.0f, eKeyCode::NONE };
		mSkillData[L"BloodyMeso"] = new SkillData{ L"BloodyMeso", 5, 1.0f, eKeyCode::NONE };
		mSkillData[L"Rogue_SkillflashJump_01"] = new SkillData{ L"Rogue_SkillflashJump_01", 0, 1.0f, eKeyCode::NONE };
		mSkillData[L"Rogue_SkillflashJump_02"] = new SkillData{ L"Rogue_SkillflashJump_02", 0, 1.0f, eKeyCode::NONE };
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
		std::unordered_map<std::wstring, SkillData*>::iterator iter
			= mSkillData.find(key);
		if (iter != mSkillData.end()) 
			return iter->second;
		
		return nullptr;
	}

	void SkillManager::Release()
	{
		// 세이브 로드
		for (auto& mDatas : mSkillData)
		{
			delete mDatas.second;
			mDatas.second = nullptr;
		}
		mSkillData.clear();
	}

}