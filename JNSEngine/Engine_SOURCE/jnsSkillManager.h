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
		std::wstring skillName;
		float damage;
		float cooldown;
		eKeyCode keystate;
	};

	class SkillManager
	{
	public:
		static void Initialize();
		static void AddSkill(const std::wstring& key, GameObject* skill);
		static GameObject& FindSkill(const std::wstring& key);
		static SkillData& FindSkillData(const std::wstring& key);
		static void Release();
	private:
		static std::unordered_map<std::wstring, GameObject*> mSkills;
		static std::unordered_map<std::wstring, SkillData*> mSkillData;
	};
}