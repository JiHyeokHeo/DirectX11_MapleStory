#include "jnsInventoryScript.h"
#include "CommonSceneInclude.h"

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

	}
	void InventoryScript::Update()
	{
		if (isTouched)
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();

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