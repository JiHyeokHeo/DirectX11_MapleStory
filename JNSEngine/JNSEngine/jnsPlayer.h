#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Player : public GameObject 
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Prone,
			Move,
			Attack,

		};
		Player();
		~Player();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		int hp;
	};

}

