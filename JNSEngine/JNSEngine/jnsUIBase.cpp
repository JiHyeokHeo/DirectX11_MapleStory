#include "jnsUIBase.h"
#include "jnsPlayer.h"
#include "jnsSceneManager.h"

namespace jns
{
	UIBase::UIBase()
		: mType(eLayerType::UI)
		, mr(nullptr)
		, tr(nullptr)
	{
		mr = AddComponent<MeshRenderer>();
		tr = GetComponent<Transform>();
	
	}
	UIBase::~UIBase()
	{
	}
	void UIBase::Initialize()
	{
		GameObject::Initialize();
	}
	void UIBase::Update()
	{
		GameObject::Update();
	}
	void UIBase::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void UIBase::Render()
	{
		GameObject::Render();
	}
	void UIBase::MouseBTNClick()
	{
	}
	void UIBase::MouseBTNClickOff()
	{
	}

}