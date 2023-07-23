#include "jnsPlayer.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Player::Player()
		:hp(100)
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
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProne", 0.1f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharProneStab", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharRope", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharStab", 0.2f);
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharSummon", 0.1f);
		at->PlayAnimation(L"CharactorCharIdle", true);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharWalk");
		//at->PlayAnimation(L"CharactorCharWalk", true);

		//Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(300.0f, 300.0f, 1.0f));
		//GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, DegreeToRadian(-60.0f)));
		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 1.0f, 1.0001f));
		
		//AddComponent<PlayerScript>();

		GameObject::Initialize();
	}

	void Player::Update()
	{
		hp -= 1 * Time::DeltaTime();


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