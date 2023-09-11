#pragma once
#include "JNSEngine.h"
#include "jnsMath.h"
#include "jnsInput.h"
#include "jnsGameObject.h"

namespace jns
{
	class SkillData
	{
	public:
		SkillData() {};
		SkillData(std::wstring skillname, int dmg, float cool, int dmgcnt, eKeyCode keyState)
			: skillName(skillname)
			, damage(dmg)
			, cooldown(cool)
			, damagecnt(dmgcnt)
			, keystate(keyState)
			, isLearn(false)
		{};
		~SkillData() {};

	public:
		std::wstring GetSkillName() { return skillName; }
		int GetSkillDamage() { return damage; }
		int GetSkillDamageCnt() { return damagecnt; }
		int GetSkillCoolDown() { return cooldown; }
		eKeyCode GetSkillKeyState() { return keystate; }
		bool GetSkillLearn() { return isLearn; }

		void SetSkillName(std::wstring skillname) { skillName = skillname; }
		void SetSkillDamage(int dmg) { damage = dmg; }
		void SetSkillCoolDown(float skillcool) { cooldown = skillcool; }
		void SetSkillKeyState(eKeyCode keyset) { keystate = keyset; }
		void SetSkillLearn(bool islearn) { isLearn = islearn; }


	private:
		std::wstring skillName = L" ";
		int damage = 0;
		int damagecnt = 1;
		bool isLearn = false;
		float cooldown = 0.0f;
		eKeyCode keystate = eKeyCode::END;
	};

	class SkillManager
	{
	public:
		static void Initialize();
		static void AddSkill(const std::wstring& key, GameObject* skill);
		static GameObject* FindSkill(const std::wstring& key);

		static SkillData* FindSkillData(const std::wstring& key);
		static void Release();
	private:
		// 생성자 자체를 막기
		SkillManager() {};
		SkillManager(const SkillManager& obj) {};
		SkillManager& operator=(const SkillManager& manager) {};
		~SkillManager() {};


		static std::unordered_map<std::wstring, GameObject*> mSkills;
		static std::unordered_map<std::wstring, SkillData*> mSkillData;
	};
}