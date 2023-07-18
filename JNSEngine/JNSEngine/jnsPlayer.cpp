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
		SetName(L"Zelda");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
		Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
		GetComponent<Transform>()->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
		//GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, DegreeToRadian(-60.0f)));
		//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 1.0f, 1.0001f));
		
		AddComponent<PlayerScript>();

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