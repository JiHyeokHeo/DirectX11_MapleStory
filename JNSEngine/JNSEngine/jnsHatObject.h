#pragma once
#include "jnsGameObject.h"


namespace jns
{
	class HatObject : public GameObject
	{
	public:
		enum class HatType
		{
			None,
			Blue,
			Red,
		};
		HatObject();
		~HatObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetHatType(HatType type) { hattype = type; }
		HatType GetHatType() { return hattype; }
		void Activate();
	private:
		class Animator* at;
		HatType hattype;
		HatType prevtype;
	};

}
