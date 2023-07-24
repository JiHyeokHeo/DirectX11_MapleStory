#include "jnsItemResourcesScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ItemResourcesScript::ItemResourcesScript()
		: isPicked(false)
	{
	}
	ItemResourcesScript::~ItemResourcesScript()
	{
	}
	void ItemResourcesScript::Initialize()
	{

	}
	void ItemResourcesScript::Update()
	{
		if (isPicked)
			ItemMove();


		Script::Update();
	}
	void ItemResourcesScript::LateUpdate()
	{
		Script::LateUpdate();
	}
	void ItemResourcesScript::Render()
	{
		Script::Render();
	}

	void ItemResourcesScript::OnCollisionEnter(Collider2D* other)
	{

	}

	void ItemResourcesScript::OnCollisionStay(Collider2D* other)
	{
		if (Input::GetKey(eKeyCode::LBUTTON))
			isPicked = true;

	}

	void ItemResourcesScript::OnCollisionExit(Collider2D* other)
	{
	}

	void ItemResourcesScript::ItemMove()
	{
		Vector3 mUIMousePos = Input::GetUIMousePos();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(mUIMousePos);

	}

}
