#include "jnsInventoryScript.h"
#include "CommonSceneInclude.h"

constexpr auto INVENTORY_XDIFFERNCE = 10.0f;
constexpr auto INVENTORY_YDIFFERNCE = 50.0f;

constexpr auto INVENTORY_SIZE = 30.0f;

namespace jns
{
	InventoryScript::InventoryScript()
	{
	}
	InventoryScript::~InventoryScript()
	{
	}
	void InventoryScript::Initialize()
	{
		//GetOwner()->SetState(GameObject::eState::Paused);
	}
	void InventoryScript::Update()
	{
		if (Input::GetKeyDown(eKeyCode::LBUTTON) && GetOwner()->GetState() == GameObject::eState::Active)
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

			object::InstantiateItem<ItemResources>(eLayerType::Item, ItemResources::eItemType::PowerPotion, mItemFinalPos);
			ItemInfo info = {};
			info.mItemCnt = 0;
			info.mItemFinalPos = mItemFinalPos;
			info.isPicked = true;
			
			mInventory.insert(std::make_pair(L"PowerPotion", info));
		}
		
	}
	void InventoryScript::LateUpdate()
	{
	}
	void InventoryScript::Render()
	{
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
	//void InventoryScript::CheckItem(ItemResources* item)
	//{
	//	std::map<std::wstring, ItemInfo>::iterator iter
	//		= mInventory.find(item->GetName());

	//	if(iter == mInventory.end())
	//		//mInventory.insert	

	//}
}