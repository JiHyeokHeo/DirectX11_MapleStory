#pragma once
#include <string>
#include "jnsGameObject.h"
#include "jnsDamageControl.h"
#include "jnsSceneManager.h"
#include <random>
#include "jnsMonsterCommonInfo.h"
#include "jnsSkillBase.h"
#include "jnsTransform.h"
#include "jnsPlayerScript.h"

namespace jns
{
	class DamageDisplay
	{
	public:
		static void DisplayDamage(int damage, const Vector3& position,  const Vector2& offsetYCord = Vector2::Zero, int damagecnt = 1)
		{
			std::string damageStr = std::to_string(damage);
			CreateDamageControls(damageStr, position, damagecnt, offsetYCord);
		}

		static void DamageToMonsterWithSkill(MonsterCommonInfo& info, Collider2D* other, Transform* tr)
		{
			SkillDamage(info, other, tr);
		}

		static void DamageToPlayer(MonsterCommonInfo& monsterinfo, Collider2D* other, bool isskilldmg = false)
		{
			PlayerDamage(monsterinfo, other, isskilldmg);
		}
	private:
		static void CreateDamageControls(const std::string& damageStr, const Vector3& position, int damagecnt, const Vector2& offsetYCord)
		{
			float xOffset = 0.0f;
			float yOffset = 0.0f;
			int strLength = -99;
			strLength = damageStr.size();

			int remain = strLength % 2;
			if (remain == 0)
			{
				xOffset = 0.0f;
			}
			else
			{
				int cnt = strLength / 2;
				
				while (cnt < 0)
				{
					xOffset -= 35.0f;
				}
			}

			for (int i = 0; i < damagecnt; i++)
			{
				for (char digitChar : damageStr)
				{
					int digit = digitChar - '0';
					DamageControl* digitControl = new DamageControl();
					Scene* scene = SceneManager::GetActiveScene();
					scene->AddGameObject(eLayerType::MapEffect, digitControl);
					digitControl->SetDamageDigit(digit);

					Transform* digitTransform = digitControl->GetComponent<Transform>();
					digitTransform->SetPosition(Vector3(position.x + xOffset + offsetYCord.x, yOffset + position.y + offsetYCord.y, 1.0f));

					xOffset += 30.0f;
					float delayTime = 0.2f * i;
					digitControl->SetDelayRenderTime(delayTime);
					digitControl->Initialize();
				}
				srand(time(NULL));
				float t = rand() % 20;
				xOffset = t;
				yOffset += 40.0f;
			}
		}

		static void SkillDamage(MonsterCommonInfo& info, Collider2D* other, Transform* tr)
		{
			SkillBase* skillbase = dynamic_cast<SkillBase*>(other->GetOwner());

			SkillBase::eSkillType skillType = skillbase->GetSkillType();
			int skillDmg = 0;
			int skillCnt = 0;
			if (skillType == SkillBase::eSkillType::AssainHit01)
			{
				skillDmg = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamage();
				skillCnt = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamageCnt();
			}
			else if (skillType == SkillBase::eSkillType::AssainHit02) {
				skillDmg = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamage();
				skillCnt = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamageCnt();
			}

			// 추후에 연산 추가합시다~ 방어력 + 알파
			info.hp -= skillDmg * 10;
			info.isChasing = true;
			DamageDisplay::DisplayDamage(skillDmg / skillCnt, tr->GetPosition(), Vector2(0.0f, 50.0f), skillCnt);
		}

		static void PlayerDamage(MonsterCommonInfo& monsterinfo, Collider2D* other, bool isskilldmg)
		{
			PlayerScript* playerScript = other->GetOwner()->GetComponent<PlayerScript>();
			PlayerScript::PlayerInfo playerInfo = playerScript->GetPlayerInfo();

			if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Die)
				return;

			
			if (playerInfo.invisibilityTime <= 0.0f) 
			{
				playerScript->SetPlayerState(PlayerScript::ePlayerState::Hitted);
				
				if (isskilldmg)
				{
					playerScript->PlayerDamaged(monsterinfo.skilldmg);
					DamageDisplay::DisplayDamage(monsterinfo.skilldmg, other->GetOwner()->GetComponent<Transform>()->GetPosition(), Vector2(0.0f, 50.0f));
				}
				else
				{
					playerScript->PlayerDamaged(monsterinfo.dmg);
					DamageDisplay::DisplayDamage(monsterinfo.dmg, other->GetOwner()->GetComponent<Transform>()->GetPosition(), Vector2(0.0f, 50.0f));
				}
			}

		}
	};
}