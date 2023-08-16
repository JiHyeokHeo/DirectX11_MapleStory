#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsTransform.h"

namespace jns
{
	GameObject::GameObject()
		:mState(GameObject::eState::Active)
	{
		mOnlyOne = false;
		AddComponent<Transform>();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			delete script;
			script = nullptr;
		}

	}
	void GameObject::Initialize()
	{

	}
	void GameObject::Update()
	{
		if (mState == eState::Paused)
			return;
		for (Component* comp : mComponents)
		{
			comp->Update();
		}

		for (Script* script : mScripts)
		{
			script->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		if (mState == eState::Paused)
			return;
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			script->LateUpdate();
		}
	}
	void GameObject::Render()
	{
		if (mState == eState::Paused)
			return;
		for (Component* comp : mComponents)
		{
			comp->Render();
		}

		for (Script* script : mScripts)
		{
			script->Render();
		}
	}
}