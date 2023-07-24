#include "jnsInventoryScript.h"
#include "CommonSceneInclude.h"

constexpr auto INVENTORY_XDIFFERNCE = 10.0f;
constexpr auto INVENTORY_YDIFFERNCE = 50.0f;

constexpr auto INVENTORY_SIZE = 30.0f;

namespace jns
{
	bool InventoryScript::isTouched = false;
	std::vector<std::vector<ItemResources*>> InventoryScript::mInventory;
	
	InventoryScript::InventoryScript()
	{
		mInventory.resize(10, std::vector<ItemResources*>(4));
	}
	InventoryScript::~InventoryScript()
	{
	}
	void InventoryScript::Initialize()
	{

	}
	void InventoryScript::Update()
	{
		if (isTouched)
		{
			Vector3 mUIMousePos = Input::GetUIMousePos();
			
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 mSize = tr->GetScale();
			Vector3 mPos = tr->GetPosition();
			Vector3 mLeftTop = Vector3(mPos.x - mSize.x / 2 , mPos.y + mSize.y / 2, mPos.z);
			Vector3 mRightBottom= Vector3(mPos.x + mSize.x / 2, mPos.y - mSize.y / 2, mPos.z);

			// 정확하게 위치 잡아주는 중
			mLeftTop += Vector3(INVENTORY_XDIFFERNCE, -INVENTORY_YDIFFERNCE, 0.0f);
			mRightBottom += Vector3(-INVENTORY_XDIFFERNCE, 87.0f, mPos.z);

			float invenWidth = abs(mLeftTop.x - mRightBottom.x);
			float invenHeight = abs(mLeftTop.y - mRightBottom.y);
			
			Vector3 checkPos = mUIMousePos - mLeftTop;

		/*	if(checkPos.x 
				)*/

			int xidx = checkPos.x / (INVENTORY_SIZE + 10);
			int yidx = checkPos.y / (INVENTORY_SIZE + 10);

			mInventory[yidx][; ]

			isTouched = false;
			int a = 0;
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
		if (Input::GetKey(eKeyCode::LBUTTON))
			isTouched = true;
	}
	void InventoryScript::OnCollisionExit(Collider2D* other)
	{
	}
}