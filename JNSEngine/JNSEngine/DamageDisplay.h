#pragma once
#include <string>
#include "jnsGameObject.h"
#include "jnsDamageControl.h"
#include "jnsSceneManager.h"

namespace jns
{
	class DamageDisplay
	{
	public:
		static void DisplayDamage(int damage, const Vector3& position, const Vector2& offsetYCord = Vector2::Zero)
		{
			std::string damageStr = std::to_string(damage);
			CreateDamageControls(damageStr, position, offsetYCord);
		}

	private:
		static void CreateDamageControls(const std::string& damageStr, const Vector3& position, const Vector2& offsetYCord)
		{
			float xOffset = 0.0f;
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

			for (char digitChar : damageStr)
			{
				int digit = digitChar - '0';
				DamageControl* digitControl = new DamageControl();
				Scene* scene = SceneManager::GetActiveScene();
				scene->AddGameObject(eLayerType::MapEffect, digitControl);
				digitControl->SetDamageDigit(digit);

				Transform* digitTransform = digitControl->GetComponent<Transform>();
				digitTransform->SetPosition(Vector3(position.x + xOffset + offsetYCord.x, position.y + offsetYCord.y, 1.0f));
				
				xOffset += 30.0f;

				digitControl->Initialize();
			}
		}
	};
}