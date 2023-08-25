#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"
#include "jnsResources.h"

namespace jns
{
	class PortalBase : public GameObject
	{
	public:
		PortalBase();
		~PortalBase();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void SetMesh(const std::wstring& name)
		{
			std::shared_ptr<Mesh> mMesh = Resources::Find<Mesh>(name);
			if (mMesh == nullptr)
				return;

			this->mr = GetComponent<MeshRenderer>();

			if (this->mr == nullptr)
				return;

			mr->SetMesh(mMesh);
		}

		virtual void SetMaterial(const std::wstring& name)
		{
			std::shared_ptr<Material> mMaterial = Resources::Find<Material>(name);
			if (mMaterial == nullptr)
				return;

			this->mr = GetComponent<MeshRenderer>();

			if (this->mr == nullptr)
				return;

			mr->SetMaterial(mMaterial);
		}

		virtual void SetPosition(Vector3 position)
		{
			if (tr == nullptr)
				return;

			tr->SetPosition(position);
		}

		virtual void SetRotation(int degree)
		{
			if (tr == nullptr)
				return;

			tr->SetRotation(Vector3(1.0f, 1.0f, DegreeToRadian(degree)));
		}

		virtual void SetScaleWhenParentOn(Vector3 scale)
		{
			if (tr == nullptr)
				return;
			mTextureSize = mr->GetMaterial()->GetTexture()->GetTextureRatio();
			tr->SetScale(Vector3(mTextureSize.x * scale.x, mTextureSize.y * scale.y, 1.0f));
		}

		virtual void SetScaleWithOriginalImageScale(Vector2 scale = Vector2::One)
		{
			if (tr == nullptr)
				return;
			mTextureSize = mr->GetMaterial()->GetTexture()->GetTextureSize();
			tr->SetScale(Vector3(mTextureSize.x * scale.x, mTextureSize.y * scale.y, 1.0f));
		}

		std::wstring GetPortalName() { return mPortalName; }
		Vector3 GetsetPlayerPos() { return setPlayerPos; }

	protected:
		eLayerType mType;
		MeshRenderer* mr;
		Transform* tr;
		Vector2 mTextureSize;
		Vector2 mSize;
		std::wstring mPortalName;
		Vector3 setPlayerPos;
		
	};
}
