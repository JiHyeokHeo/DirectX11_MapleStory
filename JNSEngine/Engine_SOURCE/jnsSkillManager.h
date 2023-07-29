//#pragma once
//#include "JNSEngine.h"
//#include "jnsMath.h"
//#include "jnsInput.h"
//
//
//namespace jns
//{
//	class SkillManager
//	{
//	public:
//		static void AddSkill(const std::wstring name, GameObject* skill);
//		static GameObject* GetSkill(const std::wstring name);
//
//
//	private:
//		static std::map<std::wstring, GameObject*> mSkills;
//	};
//}
//
//namespace jns
//{
//	class SkillData
//	{
//	public:
//		std::wstring skillName;
//		float damage;
//		float cooldown;
//		eKeyCode keystate;
//	};
//
//	class SkillManager
//	{
//	public:
//		static void Initialize();
//		static void AddSkill(const std::string& key, const SkillData& skillData);
//		static void ActivateSkill(const std::string& key);
//		static bool IsSkillAvailable(const std::string& key);
//		static void UpdateCooldowns(float deltaTime);
//
//		static void Release();
//	private:
//		static std::unordered_map<std::wstring, SkillData> skillMap;
//		static std::unordered_map<std::wstring, float> cooldownMap;
//	};
//}