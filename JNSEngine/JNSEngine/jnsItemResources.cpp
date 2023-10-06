#include "jnsItemResources.h"
#include "CommonSceneInclude.h"
#include "InventoryBTN.h"

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
			itemType = 2;
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
		Inventory* inven = GameManager::GetInstance().GetInventory();
		bool isDragging = inven->GetComponent<InventoryScript>()->GetIsDrag();

		Vector3 mMousePos = Input::GetUIMousePos();
		Transform* tr = GetComponent<Transform>();
		Vector3 mPos = tr->GetPosition();

		// 드래그 관련
		if (isDragging == true && isInitDrag == false)
		{
			isInitDrag = true;
			initialMousePos = Input::GetUIMousePos();
			initialObjectPos = tr->GetPosition();
		}

		if (isDragging == true && isitItem == false)
		{
			int xOffset = mMousePos.x - initialMousePos.x;
			int yOffset = mMousePos.y - initialMousePos.y;

			mPos.x = initialObjectPos.x + xOffset;
			mPos.y = initialObjectPos.y + yOffset;

			std::map<ItemResources::eItemType, ItemInfo>::iterator iter
				= InventoryScript::GetInvenInfo().find(mItemType);

			if (iter != InventoryScript::GetInvenInfo().end())
			{
				iter->second.mItemFinalPos = mPos;
			}
			tr->SetPosition(mPos);
		}
		else
		{
			isInitDrag = false;
		}

		// 랜더 관련
		if (Input::GetKeyDown(eKeyCode::I) && isitItem == false)
		{
			if (isRender == false)
			{
				isIconRender = true;
				isRender = true;
			}
			else
			{
				isIconRender = false;
				isRender = false;
			}
		}

		if (inven->GetInventoryBG() != nullptr)
		{
			std::map<ItemResources::eItemType, ItemInfo>::iterator iter
				= inven->GetComponent<InventoryScript>()->GetInvenInfo().find(mItemType);

			if (iter == inven->GetComponent<InventoryScript>()->GetInvenInfo().end())
			{

			}
			else
			{
				if (iter->second.mItemCnt <= 0 && isitItem == false)
				{
					isIconRender = false;
				}
				else if (iter->second.mItemCnt >= 1 && isitItem == false && isRender == true)
				{
					isIconRender = true;
				}

			}

		}

		if (isRender)
		{
			if (isitItem == false)
			{
				if (InventoryBTN::GetPushedInvenNumber() == itemType)
				{
					std::map<ItemResources::eItemType, ItemInfo>::iterator iter
						= inven->GetComponent<InventoryScript>()->GetInvenInfo().find(mItemType);
					if (iter->second.mItemCnt >= 1)
					{
						isIconRender = true;
					}
				}
				else
				{
					isIconRender = false;
				}
			}
		}


		// 필드 아이템인지, 혹은 그냥 아이템창 아이템인지 
		if (isitItem)
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
		}


		GameObject::Update();
	}
	void ItemResources::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ItemResources::Render()
	{
		if ((isRender == true && isitItem == true) || (isRender == true && isIconRender == true && isitItem == false))
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