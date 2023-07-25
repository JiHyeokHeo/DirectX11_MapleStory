#include "jnsPlayer.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Player::Player()
	{
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		SetName(L"Player");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));

		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharWalk" , 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain1Hit", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain2Hit", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharBuff", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharDead", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharHit", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharIdle", 0.3f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharJump", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharLadder", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProne", 0.1f, Vector2(0.0f, 0.15f));
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProneStab", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharRope", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharStab", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharSummon", 0.1f);
		
		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(150.0f, 150.0f, 1.0f));
		
		AddComponent<PlayerScript>();
		Collider2D* col = AddComponent<Collider2D>();
		col->SetSize(Vector2(0.5f, 0.8f));
		RigidBody* rb = AddComponent<RigidBody>();
		rb->SetMass(1.0f);
		GameObject::Initialize();
	}

	void Player::Update()
	{

		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render()
	{
		GameObject::Render();
	}

}