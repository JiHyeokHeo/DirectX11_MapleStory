#include "jnsPierreBoss.h"
#include "CommonSceneInclude.h"

namespace jns
{
	PierreBoss::PierreBoss()
	{
	}
	PierreBoss::~PierreBoss()
	{
	}
	void PierreBoss::Initialize()
	{
		SetName(L"Pierre");

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetSize(Vector2(0.25f, 0.35f));
		cd->SetCenter(Vector2(0.0f, 10.0f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\ATBQIdle", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 1500, 0.2f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 1500, 0.15f, Vector2(-0.01f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 1500, 0.15f, Vector2(0.020f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 1500, 0.15f, Vector2(0.0f, 0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenHitMotion", 1500, 0.15f);
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress1", 1500, 0.10f, Vector2(-0.03f, -0.005f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress2", 1500, 0.10f, Vector2(-0.03f, -0.005f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress3", 1500, 0.14f, Vector2(-0.04f, -0.005f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQBress4", 1500, 0.14f, Vector2(-0.042f, -0.005f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff1", 1500, 0.15f, Vector2(0.012f, -0.008f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQDebuff2", 1500, 0.15f, Vector2(0.012f, -0.008f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQIdle", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQChangeType", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\NormalBloodyQueen\\NBQWalk", 1500, 0.15f, Vector2(0.020f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQChangeType", 1500, 0.2f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff1", 1500, 0.15f, Vector2(-0.0265f, -0.085f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff2", 1500, 0.15f, Vector2(-0.0303f, -0.085f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQDebuff3", 1500, 0.15f, Vector2(-0.0265f, -0.085f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQIdle", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQWalk", 1500, 0.15f, Vector2(0.020f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQReflect1", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQReflect2", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\ReflectBloodyQueen\\RFBQReflect3", 1500, 0.15f, Vector2(0.0f, -0.010f));

		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQChangeType", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQIdle", 1500, 0.15f, Vector2(0.0f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQNormalAttack", 1500, 0.15f, Vector2(-0.01f, -0.03f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSummon1", 1500, 0.15f, Vector2(-0.024f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSummon2", 1500, 0.15f, Vector2(-0.024f, -0.010f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallow1", 1500, 0.15f, Vector2(-0.025f, -0.065f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallow2", 1500, 0.15f, Vector2(-0.025f, -0.065f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQSwallow3", 1500, 0.15f, Vector2(-0.025f, -0.065f));
		at->CreateAnimations(L"..\\Resources\\Boss\\SmileBloodyQueen\\SMBQWalk", 1500, 0.15f, Vector2(0.020f, -0.010f));

		//GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2000.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(1500.0f, 1500.0f, 1.0f));
		GameObject::Initialize();
	}
	void PierreBoss::Update()
	{
		GameObject::Update();
	}
	void PierreBoss::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void PierreBoss::Render()
	{
		GameObject::	void PierreBoss::Render()
			();
	}
}