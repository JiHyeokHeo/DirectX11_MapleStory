#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class DeathCountUI : public GameObject
	{
	public:
		DeathCountUI();
		~DeathCountUI();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Activate() override;
		virtual void DeActivate() override;
		virtual void SetPosition(Vector3 pos) override;

		void CheckDeathCount();

	private:
		class Transform* tr;
		class Animator* ani;
		std::map<int, std::wstring> digitAnimations;
	};

	class DeathCount : public GameObject
	{
	public:
		DeathCount();
		~DeathCount();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Activate() override;
		virtual void DeActivate() override;
		virtual void SetPosition(Vector3 pos) override;


	private:
		class Transform* tr;
		class Animator* ani;
	};

}
