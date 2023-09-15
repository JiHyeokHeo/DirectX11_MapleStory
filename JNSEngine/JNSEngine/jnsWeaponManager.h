#pragma once
#include "..\\Engine_SOURCE\jnsGameObject.h"

class WeaponData
{
public:
	WeaponData() {};
	WeaponData(std::wstring weaponname, int dmg)
		: weaponName(weaponname)
		, damage(dmg)
	{};
	~WeaponData() {};

public:
	std::wstring GetWeaponName() { return weaponName; }
	int GetWeaponDamage() { return damage; }

private:
	std::wstring weaponName = L" ";
	int damage = 0;
};

namespace jns
{
	class WeaponManager
	{
	public:
		static void Initialize();
		static void AddWeapon(const std::wstring& key, GameObject* weapon);
		static GameObject* FindWeapon(const std::wstring& key);
		static std::shared_ptr<WeaponData>FindWeaponData(const std::wstring& key);
		static void Release();

	private:
		static std::unordered_map<std::wstring, GameObject*> mWeapons;
		static std::unordered_map<std::wstring, std::shared_ptr<WeaponData>> mWeaponData;
	};
	}
