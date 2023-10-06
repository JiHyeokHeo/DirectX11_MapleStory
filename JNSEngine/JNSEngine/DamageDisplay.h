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
#include "jnsSkillEffect.h"
#include "ObjectTemplate.h"
#include "jnsMesoObjectPooling.h"

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

		static void DamageToMonsterWithSkill(MonsterCommonInfo& info, Collider2D* other, Transform* monstertr, Vector2 damageoffset = Vector2(0.0f, 50.0f), bool bosshealthup = false, bool isreflect = false)
		{
			SkillDamage(info, other, damageoffset, monstertr, bosshealthup, isreflect);
		}

		static void DamageToPlayer(MonsterCommonInfo& monsterinfo, Collider2D* other, Vector2 damageoffset = Vector2(0.0f, 50.0f), bool isskilldmg = false, int damagecnt = 1, bool isreflect = false)
		{
			PlayerDamage(monsterinfo, other, damageoffset, isreflect, damagecnt, isskilldmg);
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
					scene->AddGameObject(eLayerType::Particle, digitControl);
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

		static void SkillDamage(MonsterCommonInfo& info, Collider2D* other, Vector2 damageoffset, Transform* tr, bool bosshealthup, bool isreflect)
		{
			// tr 은 몬스터 포지션
			// other 스킬
			SkillBase* skillbase = dynamic_cast<SkillBase*>(other->GetOwner());

			SkillBase::eSkillType skillType = skillbase->GetSkillType();
			int skillDmg = 0;
			int skillCnt = 0;

			bool isCoin = false;

			if (skillType == SkillBase::eSkillType::AssainHit01)
			{
				skillDmg = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamage();
				skillCnt = SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillDamageCnt();
			}
			else if (skillType == SkillBase::eSkillType::AssainHit02) {
				skillDmg = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamage();
				skillCnt = SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->GetSkillDamageCnt();
			}
			else if (skillType == SkillBase::eSkillType::BloodyMeso)
			{
				isCoin = true;
				skillDmg = SkillManager::FindSkillData(L"BloodyMeso")->GetSkillDamage();
				skillCnt = SkillManager::FindSkillData(L"BloodyMeso")->GetSkillDamageCnt();
			}

			skillDmg += SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().dmg;

			if (skillDmg <= 0)
			{
				skillDmg = 1;
			}

			if (isCoin == false)
			{
				DamageCalculate(info, bosshealthup, tr, isreflect, skillDmg);
			}
			else
			{
				BloodyMeso* meso = dynamic_cast<BloodyMeso*>(other->GetOwner());
				
				if (meso->GetIsActive() == true)
				{
					
					DamageCalculate(info, bosshealthup, tr, isreflect, skillDmg);
				}
			}

			srand(time(NULL));
			Vector3 position = other->GetHitColPos();

			
			for (int i = 0; i < skillCnt; i++)
			{
				float t = rand() % 40;
				t -= 20;
				// -10부터 10 사이
				position.x += t;
				position.y += t;
				position.z = 0.5f;
				if (isCoin == false)
				{
					object::SkillHitEffect<SkillEffect>(eLayerType::MapEffect, skillType, position);
				}
				else if (isCoin == true)
				{
					BloodyMeso* meso = dynamic_cast<BloodyMeso*>(other->GetOwner());
					if (meso->GetIsActive() == true)
					{
						meso->SetDamageDone(true);
						
						if (isreflect == false)
						{
							MesoPooling::MesoObjectPooling::GetInstance().CreateMesoEffect()->SetPosition(position);
						}
					}
				}
			}
			

			if (isCoin == false)
			{
				Vector3 monsterPos = tr->GetPosition();
				for (int i = 0; i < skillCnt; i++)
				{
					float t = rand() % 40;
					t -= 20;
					// -10부터 10 사이
					
					monsterPos.x += t;
					monsterPos.y += 10.0f;
					if (isreflect == false)
					{
						MesoPooling::MesoObjectPooling::GetInstance().CreateMesoObject()->SetPosition(monsterPos);
					}
				}
			}
			
			if (isCoin == false)
			{
				if (skillCnt != 0)
				{
					DamageDisplay::DisplayDamage(skillDmg / skillCnt, tr->GetPosition(), damageoffset, skillCnt);
				}
			}
			else
			{
				BloodyMeso* meso = dynamic_cast<BloodyMeso*>(other->GetOwner());
				if (meso->GetIsActive() == true)
				{
					DamageDisplay::DisplayDamage(skillDmg / skillCnt, tr->GetPosition(), damageoffset, skillCnt);
				}
			}
		}

		static void PlayerDamage(MonsterCommonInfo& monsterinfo, Collider2D* other, Vector2 damageoffset, bool isreflect, int damagecnt, bool isskilldmg)
		{
			PlayerScript* playerScript = other->GetOwner()->GetComponent<PlayerScript>();
			PlayerScript::PlayerInfo playerInfo = playerScript->GetPlayerInfo();

			if (playerScript->GetPlayerState() == PlayerScript::ePlayerState::Die)
				return;

			
			if (playerInfo.invisibilityTime <= 0.0f) 
			{
				playerScript->SetPlayerState(PlayerScript::ePlayerState::Hitted);
				
				if (isreflect == false)
				{
					if (isskilldmg)
					{
						playerScript->PlayerDamaged(monsterinfo.skilldmg);
						DamageDisplay::DisplayDamage(monsterinfo.skilldmg, other->GetOwner()->GetComponent<Transform>()->GetPosition(), damageoffset, damagecnt);
					}
					else
					{
						playerScript->PlayerDamaged(monsterinfo.dmg);
						DamageDisplay::DisplayDamage(monsterinfo.dmg, other->GetOwner()->GetComponent<Transform>()->GetPosition(), damageoffset, damagecnt);
					}
				}
				else
				{
					DamageDisplay::DisplayDamage(monsterinfo.skilldmg, other->GetOwner()->GetComponent<Transform>()->GetPosition(), damageoffset, damagecnt);
				}
			}

		}

		static void DamageCalculate(MonsterCommonInfo& info, bool bosshealthup, Transform* tr, bool isreflect, int skillDmg)
		{
			if (bosshealthup == false)
			{
				if (isreflect == false)
				{
					// 추후에 연산 추가합시다~ 방어력 + 알파
					info.hp -= skillDmg;
					info.isChasing = true;
				}
				else if (isreflect == true)
				{
					// 리플렉트 상태이면 플레이어 데미지 적용
					PlayerScript* player = tr->GetOwner()->GetComponent<PlayerScript>();
					// 즉사
					skillDmg *= 1000.0f;
					player->PlayerDamaged(skillDmg);
				}
			}
			else if (bosshealthup)
			{
				if (info.maxhp >= info.hp)
				{
					info.hp += skillDmg;
				}
				info.isChasing = true;
			}
		};
	};


}