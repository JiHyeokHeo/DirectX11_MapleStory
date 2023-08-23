#include "jnsCollider2D.h"
#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsInput.h"
#include "jnsCollisionManager.h"

namespace jns
{
	UINT Collider2D::mColliderNumber = 0;
	Collider2D::Collider2D()
		: Component(eComponentType::Collider2D)
		, mTransform(nullptr)
		, mSize(Vector2::One)
		, mCenter(Vector2::Zero)
		, isColliding(false)
		, isColliderON(true)
		, mStart(Vector3::Zero)
		, mEnd(Vector3::Zero)
		, mType(enums::eColliderType::Rect)
	{
		mColliderNumber++;
		mColliderID = mColliderNumber;
	}
	Collider2D::~Collider2D()
	{
	}
	void Collider2D::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}
	void Collider2D::Update()
	{
	}
	void Collider2D::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		eLayerType mLayertype = GetOwner()->GetLayerType();

		mScale = tr->GetScale();
		mScale.x *= mSize.x;
		mScale.y *= mSize.y;

		Vector3 pos = Vector3::Zero;
		if (tr->GetOwner()->GetLayerType() == eLayerType::Cursor)
		{
			pos = Input::GetWorldMousePos();
		}
		else
		{
			pos = tr->GetPosition();
		}
		pos.x += mCenter.x;
		pos.y += mCenter.y;

		mPosition = pos;

		graphics::DebugMesh mesh = {};
		mesh.position = mPosition;
		mesh.scale = mScale;	
		mesh.rotation = tr->GetRotation();
		mesh.type = mType;
		mesh.layertype = mLayertype;
		mesh.isCollide = isColliding;
		
		renderer::PushDebugMeshAttribute(mesh);

		if (mType == eColliderType::Line)
		{
			mStart = mPosition;
			mEnd = mPosition;
			mStart.x = mPosition.x - (mScale.x / 2);
			mEnd.x = mPosition.x + (mScale.x / 2);
		}
	}

	void Collider2D::Render()
	{
	}
	void Collider2D::OnCollisionEnter(Collider2D* other)
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
			return;

		isColliding = true;
		const std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			if (script->GetColNum() != this->GetColNum())
				continue;
			script->OnCollisionEnter(other);
		}
	}
	void Collider2D::OnCollisionStay(Collider2D* other)
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
			return;


		isColliding = true;
		const std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			if (script->GetColNum() != this->GetColNum())
				continue;
			script->OnCollisionStay(other);
		}
	}
	void Collider2D::OnCollisionExit(Collider2D* other)
	{
		if (this->GetOwner()->GetState() == GameObject::eState::Paused)
			return;


		const std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			if (script->GetColNum() != this->GetColNum())
				continue;
			script->OnCollisionExit(other);
		}
		isColliding = false;
	}
}