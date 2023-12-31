#pragma once
#include "jnsEntity.h"
#include "jnsComponent.h"
#include "jnsScript.h"

namespace jns
{
	using namespace math;
	class GameObject : public Entity
	{
	public:
		enum class eState
		{
			Active,
			Paused,
			Dead,
			DontDestroy,
		};

		GameObject();
		virtual ~GameObject();
	
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		
		virtual void Activate();
		virtual void DeActivate();
		virtual void SetPosition(Vector3 pos);

		template <typename T>
		T* GetComponent()
		{
			T* component;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component != nullptr)
					return component;
			}

			for (Script* script : mScripts)
			{
				component = dynamic_cast<T*>(script);
				if (component != nullptr)
					return component;
			}

			return nullptr;
		}

		template <typename T>
		std::vector<T*> GetComponents()
		{
			std::vector<T*> comps;

			T* component;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component != nullptr)
					comps.push_back(component);
			}

			for (Script* script : mScripts)
			{
				component = dynamic_cast<T*>(script);
				if (component != nullptr)
					comps.push_back(component);
			}

			return comps;
		}


		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();

			Component* buff
				= dynamic_cast<Component*>(comp);
			Script* script
				= dynamic_cast<Script*>(buff);

			if (buff == nullptr)
				return nullptr;

			if (script == nullptr)
				mComponents.push_back(buff);
			else
				mScripts.push_back(script);

			comp->SetOwner(this);
			comp->Initialize();
			return comp;
		}

		void SetState(eState state) { mState = state; }
		eState GetState() { return mState; }
		void SetType(eLayerType type) { mLayerType = type; }
		eLayerType GetLayerType() { return mLayerType; }
		bool GetIsOnlyOne() { return mOnlyOne; }
		void SetIsOnlyOne(bool isOne) { mOnlyOne = isOne; }
	private:
		eState mState;
		std::vector<Component*> mComponents;
		std::vector<Script*> mScripts;
		eLayerType mLayerType;
		bool mOnlyOne;
	};

}
