#include "jnsInvenBG.h"
#include "jnsInventoryScript.h"
#include "jnsInput.h"
#include "CommonSceneInclude.h"
#include "jnsApplication.h"
#include "InventoryBTN.h"

extern jns::Application application;
namespace jns
{
	InventoryBG::InventoryBG()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	InventoryBG::~InventoryBG()
	{
	}
	void InventoryBG::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"InventoryBGMaterial");

		//mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);
		SetPosition(Vector3(0.0f, 0.01f, -0.1f));
		tr->SetScale(Vector3(0.92f, 0.77f, 1.0f));
		
		//AddComponent<Collider2D>();
		//mInventoryIn->SetPosition(Vector3(0.0f, 200.0f, 4.5f));
		UIBase::Initialize();
	}
	void InventoryBG::Update()
	{
		SetPosition(Vector3(0.0f, 0.01f, -0.1f));
		if (Input::GetKeyDown(eKeyCode::I))
		{
			if (isRender == false)
			{
				isRender = true;
			}
			else
			{
				isRender = false;
			}
		}
		UIBase::Update();
	}
	void InventoryBG::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void InventoryBG::Render()
	{
		if (isRender)
		{
			UIBase::Render();

			std::map<ItemResources::eItemType, ItemInfo>::iterator iter
				= InventoryScript::GetInvenInfo().begin();

			for (iter; iter != InventoryScript::GetInvenInfo().end(); iter++)
			{
				Vector2 idx = iter->second.idx;
				int cnt = iter->second.mItemCnt;
				Vector3 finalPos = iter->second.mItemFinalPos;


				std::wstring num = std::to_wstring(cnt); // wstring으로 변환
				float adjustedX = finalPos.x + (application.GetMetaDataWidth() / 2.0f);
				float adjustedY = (application.GetMedtaDataHeight() / 2.0f) - finalPos.y;;

				adjustedX += 10.0f;
				adjustedY -= 20.0f;
				const wchar_t* wcs = num.c_str();

			

				if (InventoryBTN::GetPushedInvenNumber() == iter->second.itemnum)
				{
					if (cnt > 0)
					{
						FontWrapper::DrawFont(wcs, adjustedX, adjustedY, 15, FONT_RGBA(0, 0, 0, 255));
					}
				}
			}
		}
	}
}