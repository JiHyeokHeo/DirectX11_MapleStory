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
		void DisplayDamage(int damage, const Vector3& position)
		{
			std::string damageStr = std::to_string(damage);
			CreateDamageControls(damageStr, position);
		}

	private:
		void CreateDamageControls(const std::string& damageStr, const Vector3& position)
		{
			float xOffset = 0.0f;
			for (char digitChar : damageStr)
			{
				int digit = digitChar - '0';
				DamageControl* digitControl = new DamageControl();
				digitControl->Initialize();
				Scene* scene = SceneManager::GetActiveScene();
				scene->AddGameObject(eLayerType::MapEffect, digitControl);
				//digitControl->SetDamageDigit(digit);

				Transform* digitTransform = digitControl->GetComponent<Transform>();
				digitTransform->SetPosition(Vector3(position.x + xOffset, position.y, position.z));

				xOffset += 10.0f;
			}
		}
	};
}