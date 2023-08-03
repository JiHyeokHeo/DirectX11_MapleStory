#include "jnsBloodyQueen.h"
#include "CommonSceneInclude.h"


namespace jns
{
	BloodyQueen::BloodyQueen()
	{
	}
	BloodyQueen::~BloodyQueen()
	{
	}
	void BloodyQueen::Initialize()
	{
		SetName(L"BloodyQueen");
		
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQIdle", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttack", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 700, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 700, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 700, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 700, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenHitMotion", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress1", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress2", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress3", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress4", 700, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff", 700, 0.15f);
		
		at->PlayAnimation(L"NormalBloodyQueenNBQDebuff", true);
		//GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2000.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(800.0f, 800.0f, 1.0f));
	}
	void BloodyQueen::Update()
	{
		MonsterBase::Update();
	}
	void BloodyQueen::LateUpdate()
	{
		MonsterBase::LateUpdate();
	}
	void BloodyQueen::Render()
	{
		MonsterBase::Render();
	}
}