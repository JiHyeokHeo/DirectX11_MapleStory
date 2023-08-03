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
		
		Collider2D* cd =  AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.25f, 0.35f));
		cd->SetCenter(Vector2(0.0f, 10.0f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		

		
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQIdle", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttack", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 1500, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenHitMotion", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress1", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress2", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress3", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress4", 1500, 0.15f, Vector2(-0.03f, 0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff", 1500, 0.15f, Vector2(0.006f, 0.0f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQIdle", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.02f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQChangeType", 1500, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff1", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff2", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff3", 1500, 0.15f, Vector2(-0.02f, -0.09f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQIdle", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQNormalAttack", 700, 0.15f, Vector2(-0.01f, -0.02f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQWalk", 1500, 0.15f, Vector2(0.025f, -0.010f));
		
		at->PlayAnimation(L"NormalBloodyQueenNBQWalk", true);
		//GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2000.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(1700.0f, 1700.0f, 1.0f));
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