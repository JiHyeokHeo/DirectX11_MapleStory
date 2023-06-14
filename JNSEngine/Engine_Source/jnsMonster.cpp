#include "jnsMonster.h"


namespace jns
{
	Monster::Monster()
	{
		Vector2 mMonsterPos = {};
		mMonsterPos.x = disX(gen);
		mMonsterPos.y = disY(gen);

		mRGB.x = rangecolorR(gen);
		mRGB.y = rangecolorG(gen);
		mRGB.z = rangecolorB(gen);
		SetRGB(mRGB);
		SetPos(mMonsterPos);
		SetScale(10.0f);
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render()
	{
		GameObject::Render();
	}
}