#include "jnsInventoryScript.h"
#include "CommonSceneInclude.h"
#include "jnsApplication.h"

constexpr auto INVENTORY_XDIFFERNCE = 10.0f;
constexpr auto INVENTORY_YDIFFERNCE = 50.0f;

constexpr auto INVENTORY_SIZE = 30.0f;



namespace jns
{
	std::map<ItemResources::eItemType, ItemInfo> InventoryScript::mInventory;
	std::vector<std::vector<bool>> InventoryScript::indexOn;
	InventoryScript::InventoryScript()
	{
		indexOn.resize(6, std::vector<bool>(4));
	}
	InventoryScript::~InventoryScript()
	{
	}
	void InventoryScript::Initialize()
	{
	}
	void InventoryScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 mPos = tr->GetPosition();
		Vector3 mUIPos = Input::GetUIMousePos();

		Vector3 mLeftTop = Vector3(mPos.x - 100.0f, mPos.y + 190.0f, 0.0f);
		Vector3 mLeftBottom = Vector3(mPos.x - 100.0f, mPos.y + 170.0f, 0.0f);

		Vector3 mRightTop = Vector3(mPos.x + 100.0f, mPos.y + 190.0f, 0.0f);
		Vector3 mRightBottom = Vector3(mPos.x + 100.0f, mPos.y + 170.0f, 0.0f);

		if (Input::GetKeyDown(eKeyCode::LBUTTON) 
			&& mUIPos.x >= mLeftTop.x && mUIPos.x <= mRightBottom.x
			&& mUIPos.y <= mLeftTop.y && mUIPos.y >= mRightBottom.y)
		{
			isDragging = true;
			initialMousePos = mUIPos;
			initialObjectPos = mPos;
		}

		if (isDragging && Input::GetKey(eKeyCode::LBUTTON))
		{
			int xOffset = mUIPos.x - initialMousePos.x;
			int yOffset = mUIPos.y - initialMousePos.y;

			
			mPos.x = initialObjectPos.x + xOffset;
			mPos.y = initialObjectPos.y + yOffset;

			tr->SetPosition(mPos);
		}
		else if(Input::GetKeyUp(eKeyCode::LBUTTON))
		{
			isDragging = false;
		}


		if (Input::GetKeyDown(eKeyCode::LBUTTON))
		{
			Vector3 mUIMousePos = Input::GetUIMousePos();
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 mSize = tr->GetScale();
			Vector3 mPos = tr->GetPosition();
			Vector3 mLeftTop = Vector3(mPos.x - mSize.x / 2, mPos.y + mSize.y / 2, mPos.z);
			Vector3 mRightBottom = Vector3(mPos.x + mSize.x / 2, mPos.y - mSize.y / 2, mPos.z);

			// 정확하게 위치 잡아주는 중
			mLeftTop += Vector3(13.0f, -INVENTORY_YDIFFERNCE, 0.0f);
			mRightBottom += Vector3(-25.0f, 84.0f, mPos.z);

			float invenWidth = abs(mLeftTop.x - mRightBottom.x);
			float invenHeight = abs(mLeftTop.y - mRightBottom.y);

			Vector3 checkPos = Vector3(mUIMousePos.x - mLeftTop.x, mLeftTop.y - mUIMousePos.y, mPos.z);

			if (checkPos.x < 0.0f || checkPos.x >invenWidth || checkPos.y > invenHeight || checkPos.y < 0.0f)
				return;


			int xidx = checkPos.x / (INVENTORY_SIZE + 10);
			int yidx = checkPos.y / (INVENTORY_SIZE + 10);

			if (xidx >= 4 || yidx >= 6)
				return;
			
			Vector3 mItemSetPos = Vector3((xidx) * (INVENTORY_SIZE)+(12.5f * xidx) + (INVENTORY_SIZE / 2), (yidx) * (INVENTORY_SIZE)+(12.5f * yidx) + (INVENTORY_SIZE / 2), mPos.z);
			Vector3 mItemFinalPos = Vector3(mItemSetPos.x + mLeftTop.x, mLeftTop.y - mItemSetPos.y, 3.5f);

			Inventory* inven = dynamic_cast<Inventory*>(GetOwner());
			QuickSlotUI* slot = inven->GetQuickSlotUI();



			if (indexOn[yidx][xidx])
			{
				
			}
			else
			{

			}
			
			
		/*	ItemInfo info = {};
			info.idx = Vector2(xidx, yidx);
			info.mItemCnt = 0;
			info.mItemFinalPos = mItemFinalPos;
			mInventory.insert(std::make_pair(ItemResources::eItemType::PowerPotion, info));*/
		}
		
	}
	void InventoryScript::LateUpdate()
	{
	}
	void InventoryScript::Render()
	{
		//std::map<ItemResources::eItemType, ItemInfo>::iterator iter
		//	= mInventory.begin();

		//for (iter; iter != mInventory.end(); iter++)
		//{
		//	Vector2 idx = iter->second.idx;
		//	int cnt = iter->second.mItemCnt;
		//	Vector3 finalPos = iter->second.mItemFinalPos;
		//	
		//	std::wstring num = std::to_wstring(cnt); // wstring으로 변환

		//	float adjustedX = finalPos.x + (application.GetMetaDataWidth() / 2.0f);
		//	float adjustedY = (application.GetMedtaDataHeight() / 2.0f) - finalPos.y;;

		//	const wchar_t* wcs = num.c_str();
		//	FontWrapper::DrawFont(wcs, adjustedX, adjustedY, 35, FONT_RGBA(0, 0, 0, 255));
		//}

	}
	void InventoryScript::OnCollisionEnter(Collider2D* other)
	{
		
	}
	void InventoryScript::OnCollisionStay(Collider2D* other)
	{
	}
	void InventoryScript::OnCollisionExit(Collider2D* other)
	{
		
	}
	void InventoryScript::CheckItems(ItemResources::eItemType type)
	{
		Vector2 idx = SearchALLItemsToFindIndex(type);
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 mPos = tr->GetPosition();
		Vector3 mSize = tr->GetScale();
		Vector3 mLeftTop = Vector3(mPos.x - mSize.x / 2, mPos.y + mSize.y / 2, mPos.z);
		mLeftTop += Vector3(13.0f, -INVENTORY_YDIFFERNCE, 0.0f);
		Vector3 mItemSetPos = Vector3((idx.x) * (INVENTORY_SIZE)+(12.5f * idx.x) + (INVENTORY_SIZE / 2), (idx.y) * (INVENTORY_SIZE)+(12.5f * idx.y) + (INVENTORY_SIZE / 2), mPos.z);
		Vector3 mItemFinalPos = Vector3(mItemSetPos.x + mLeftTop.x, mLeftTop.y - mItemSetPos.y, 3.5f);


		if (indexOn[idx.y][idx.x] == false)
		{
			int itemnum = object::InstantiateItem<ItemResources>(eLayerType::Item, type, mItemFinalPos)->GetItemType();
			indexOn[idx.y][idx.x] = true;

			ItemInfo info = {};
			info.idx = idx;
			info.mItemCnt = 1;
			info.mItemFinalPos = mItemFinalPos;
			info.itemnum = itemnum;
			
			mInventory.insert(std::make_pair(type, info));
		}
		else if (indexOn[idx.y][idx.x] == true)
		{
			std::map<ItemResources::eItemType, ItemInfo>::iterator iter
				= mInventory.find(type);
			iter->second.mItemCnt++;

		}

	}
	Vector2 InventoryScript::SearchALLItemsToFindIndex(ItemResources::eItemType type)
	{
		for (int y = 0; y < 6; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (indexOn[y][x] == false)	
				{
					// 처음에 false 걸리면 바로 탈출
					return Vector2(y, x);
				}

				if (indexOn[y][x] == true)
				{
					// 일단 존재하면 한번 더 검색
					std::map<ItemResources::eItemType, ItemInfo>::iterator iter
						= mInventory.find(type);

					return Vector2(y, x);
				}
			}
		}
	}
	//void InventoryScript::CheckItem(ItemResources* item)
	//{
	//	std::map<std::wstring, ItemInfo>::iterator iter
	//		= mInventory.find(item->GetName());

	//	if(iter == mInventory.end())
	//		//mInventory.insert	

	//}
}