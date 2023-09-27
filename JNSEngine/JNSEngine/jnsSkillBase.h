#pragma once
#include "jnsGameObject.h"
#include "jnsMeshRenderer.h"
#include "jnsTransform.h"
#include "jnsResources.h"
#include "jnsAnimator.h"
#include "jnsPlayerScript.h"
#include "jnsAudioSource.h"

namespace jns
{
	class SkillBase : public GameObject
	{
	public:
		enum class eSkillType
		{
			AssainHit01,
			AssainHit02,
			BloodyMeso,
			Jump,
			None,
		};


		SkillBase(eSkillType type);
		~SkillBase();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void CompleteSkillAnimation() = 0;
		virtual void StartSkillAnimation() = 0;

		virtual void Activate() override;

		bool GetIsRenderOn() { return isRenderOn; }

		virtual void SetSkillMode(bool isRender)
		{
			isRenderOn = isRender;
		}

		virtual void SetSkillPlay(bool isPlay)
		{
			isPlayPossible = isPlay;
		}

		virtual void SetDirection()
		{
			int mDir = (int)mPlayerScript->GetPlayerDirection();

			if (at->GetActiveAnimation() != nullptr)
			{
				if (mDir == -1)
				{
					at->GetActiveAnimation()->SetAniDirection(false);
				}
				else
				{
					at->GetActiveAnimation()->SetAniDirection(true);
				}
			}
		}


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

		eSkillType GetSkillType() { return mSkillType; }
		
	protected:
		Animator* at;
		Transform* tr;
		MeshRenderer* mr;
		AudioSource* as;
		Vector2 mTextureSize;
		Vector2 mSize;

		eLayerType mType;

		GameObject* mPlayer;
		PlayerScript* mPlayerScript;

		bool isRenderOn;
		bool isPlayPossible;

		eSkillType mSkillType;
	};
}



