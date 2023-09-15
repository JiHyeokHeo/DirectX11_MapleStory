#include "jnsWeaponManager.h"


namespace jns
{
	std::unordered_map<std::wstring, GameObject*> WeaponManager::mWeapons;
	std::unordered_map<std::wstring, std::shared_ptr<WeaponData>> WeaponManager::mWeaponData;
	void WeaponManager::Initialize()
	{
		mWeaponData[L"Genesis_Thief_Weapon"] = std::make_shared<WeaponData>( L"Genesis_Thief_Weapon", 10);


	}

	void WeaponManager::AddWeapon(const std::wstring& key, GameObject* weapon)
	{
		mWeapons.insert(std::make_pair(key, weapon));
	}

	GameObject* WeaponManager::FindWeapon(const std::wstring& key)
	{
		std::unordered_map<std::wstring, GameObject*>::iterator iter
			= mWeapons.find(key);

		if (iter != mWeapons.end())
			return iter->second;


		return nullptr;
	}

	std::shared_ptr<WeaponData> WeaponManager::FindWeaponData(const std::wstring& key)
	{
		return mWeaponData[key];
	}

	void WeaponManager::Release()
	{
		//for (auto& mDatas : mWeaponData)
		//{
		//	delete mDatas.second;
		//}
		//mWeaponData.clear();
	}

}