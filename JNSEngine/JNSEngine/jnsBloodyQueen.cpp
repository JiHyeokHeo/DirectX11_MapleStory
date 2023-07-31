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

		
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQIdle", 1000, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttack", 1000, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQChangeType", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQAttract", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\AttractionBloodyQueen\\ATBQWalk", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die1", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die2", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Boss\\BloodyQueenDie\\Die3", 100, 0.1f);

		at->PlayAnimation(L"AttractionBloodyQueenATBQAttack", true);
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