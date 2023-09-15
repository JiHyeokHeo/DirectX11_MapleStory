#include "jnsSkillManager.h"
#include "..\\JNSEngine\\jnsSkillResources.h"

namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, std::shared_ptr<SkillData>>  SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		// 만약 추후에 파싱을 하게 된다면 이름이든 이런식으로 연결해서 정보를 생성할수 있을듯 싶다. // 아직 할 계획은 없지만 추후에 여력 있으면 해볼 예정
		mSkillData[L"Normal_Assain_First_Attack"] = std::make_shared<SkillData>(L"Normal_Assain_First_Attack", 10, 0.5f, 4, eKeyCode::NONE );
		mSkillData[L"Normal_Assain_Second_Attack"] = std::make_shared<SkillData>(L"Normal_Assain_Second_Attack", 10, 1.0f, 4, eKeyCode::NONE);
		mSkillData[L"BloodyMeso"] = std::make_shared<SkillData>(L"BloodyMeso", 5, 1.0f, 1, eKeyCode::NONE);
		mSkillData[L"Rogue_SkillflashJump_01"] = std::make_shared<SkillData>(L"Rogue_SkillflashJump_01", 0, 1.0f, 0, eKeyCode::NONE);
		mSkillData[L"Rogue_SkillflashJump_02"] = std::make_shared<SkillData>(L"Rogue_SkillflashJump_02", 0, 1.0f, 0, eKeyCode::NONE);
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

	std::shared_ptr<SkillData> SkillManager::FindSkillData(const std::wstring& key)
	{
		std::unordered_map<std::wstring, std::shared_ptr<SkillData>>::iterator iter
			= mSkillData.find(key);
		if (iter != mSkillData.end()) 
			return iter->second;
		
		return nullptr;
	}

	//
	void SkillManager::Release()
	{
		// 이 타이밍에 파일 입출력으로 데이터 저장 가능할듯함
		// 세이브 로드
		/*for (auto& mDatas : mSkillData)
		{
			delete mDatas.second;
			mDatas.second = nullptr;
		}
		mSkillData.clear();*/
	}

}