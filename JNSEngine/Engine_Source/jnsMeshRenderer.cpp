#include "jnsMeshRenderer.h"
#include "jnsGameObject.h"
#include "jnsTransform.h"
#include "jnsRenderer.h"
#include "jnsAnimator.h"

namespace jns
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
	{
	}
	MeshRenderer::~MeshRenderer()
	{
	}
	void MeshRenderer::Initialize()
	{
		//Vector2 mScale = mMaterial->GetTexture()->GetTextureSize();
		//Transform* tr = GetOwner()->GetComponent<Transform>();

		//tr->SetScaleWithOriginalImgScale(mScale.x, mScale.y, 1.0f);
	}
	void MeshRenderer::Update()
	{
	}
	void MeshRenderer::LateUpdate()
	{
	}
	void MeshRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector3 scale = mMaterial->GetTexture()->GetRatio();
		//tr->SetScaleWithOriginalImgScale(scale);
		tr->BindConstantBuffer();
		
		mMesh->BindBuffer();
		mMaterial->Binds();

		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (animator)
		{
			animator->Binds();
		}

		mMesh->Render();

		mMaterial->Clear();
	}
}