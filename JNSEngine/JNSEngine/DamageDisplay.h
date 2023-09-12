#pragma once
#include <string>
#include "jnsGameObject.h"
#include "jnsDamageControl.h"
#include "jnsSceneManager.h"
#include <random>

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

		static void DamageToMonsterWithSkill(int damage, Collider2D* other)
		{

		}

		static void DamageToPlayer(int damage)
		{

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
	};
}