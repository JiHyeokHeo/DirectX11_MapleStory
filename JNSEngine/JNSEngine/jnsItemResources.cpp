#include "jnsItemResources.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ItemResources::ItemResources(eItemType type, bool isItem)
		: mItemType(type)
		, isitItem(isItem)
	{
		if (isItem)
		{

		}
		else
		{
			SetIsOnlyOne(true);
			SetState(GameObject::eState::DontDestroy);
		}
	}
	ItemResources::~ItemResources()
	{
	}
	void ItemResources::Initialize()
	{
		SetName(L"Item");
		//AddComponent<ItemResourcesScript>();
		switch (mItemType)
		{
		case eItemType::PowerPotion:
			SetPowerPotion();
			break;
		}


		if (isitItem)
		{
			RigidBody* rb = AddComponent<RigidBody>();
			Collider2D* cd = AddComponent<Collider2D>();
			cd->SetSize(Vector2(1.0f, 1.0f));
			cd->SetColliderOn(false);
		}

	}
	void ItemResources::Update()
	{
		RigidBody* rb = GetComponent<RigidBody>();
		if (rb->GetGround() == false)
		{
			Collider2D* cd = GetComponent<Collider2D>();
			cd->SetColliderOn(true);
			rb->SetIsRigidBodyOn(false);
			Transform* tr = GetComponent<Transform>();
			Vector3 mesoPos = tr->GetPosition();
			mAirTime += Time::DeltaTime();

			if (mAirTime <= airMaxTime)
			{
				Vector3 mVelocity = rb->GetVelocity();
				mVelocity.y -= 300.0f * Time::DeltaTime();
				rb->SetVelocity(mVelocity);
				mesoPos.y += 50.0f * Time::DeltaTime();
				tr->SetPosition(mesoPos);
			}
			else
			{
				rb->SetIsRigidBodyOn(true);
			}
		}
		else
		{
			mAirTime = 999.0f;
		}
		GameObject::Update();
	}
	void ItemResources::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ItemResources::Render()
	{
		GameObject::Render();
	}
	void ItemResources::SetPowerPotion()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"HP_MP_PotionMaterial"));
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);


		Vector2 mSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
		//GetComponent<Transform>()->SetPosition(Vector3(300.0f, 250.0f, 3.0f));
		GetComponent<Transform>()->SetScale(Vector3(mSize.x , mSize.y , 1.0f));
	}
}