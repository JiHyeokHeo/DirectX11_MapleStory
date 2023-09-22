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
		for (Component* comp : mComponents)
		{
			if (mState == eState::Paused)
				return;
			comp->Update();
		}

		for (Script* script : mScripts)
		{
			if (mState == eState::Paused)
				return;
			script->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (mState == eState::Paused)
				return;
			comp->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			if (mState == eState::Paused)
				return;
			script->LateUpdate();
		}
	}
	void GameObject::Render()
	{
		for (Component* comp : mComponents)
		{
			if (mState == eState::Paused)
				return;
			comp->Render();
		}

		for (Script* script : mScripts)
		{
			if (mState == eState::Paused)
				return;
			script->Render();
		}
	}
	void GameObject::Activate()
	{
	}
	void GameObject::DeActivate()
	{
	}
	void GameObject::SetPosition(Vector3 pos)
	{
	}
}