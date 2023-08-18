#include "jnsPlayer.h"
#include "CommonSceneInclude.h"


namespace jns
{
	Player::Player()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
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
		AddComponent<AudioListener>();
		Animator* at = AddComponent<Animator>();
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharWalk", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain1Hit",  100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain2Hit", 100, 0.1f, Vector2(0.015f, 0.02f));
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharBuff", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharDead", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharHit", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharIdle", 100, 0.3f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharJump", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharLadder", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProne", 100, 0.1f, Vector2(0.0f, 0.15f));
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProneStab", 100, 0.2f, Vector2(0.0f, 0.15f));
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharRope", 100, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharRopeIdle", 100, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharStab", 100, 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharSummon", 100, 0.1f);
		
		//GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2000.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(150.0f, 150.0f, 1.0f));
		
		Collider2D* col = AddComponent<Collider2D>();
		col->SetSize(Vector2(0.5f, 0.8f));
		RigidBody* rb = AddComponent<RigidBody>();
		rb->SetMass(1.0f);

		// 구조상 스크립트를 맨 마지막에 까는게 좋다.
		AddComponent<PlayerMoveLimitScript>();
		AddComponent<PlayerScript>();
		GameObject::Initialize();
	}

	void Player::Update()
	{
		this;
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