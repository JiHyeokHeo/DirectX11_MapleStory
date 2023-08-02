#include "jnsCollider2D.h"
#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsInput.h"

namespace jns
{
	UINT Collider2D::mColliderNumber = 0;
	Collider2D::Collider2D()
		: Component(eComponentType::Collider2D)
		, mTransform(nullptr)
		, mSize(Vector2::One)
		, mCenter(Vector2::Zero)
		, isColliding(false)
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
		mesh.position = pos;
		mesh.scale = mScale;	
		mesh.rotation = tr->GetRotation();
		mesh.type = mType;
		mesh.layertype = mLayertype;
		mesh.isCollide = isColliding;
		
		renderer::PushDebugMeshAttribute(mesh);
	}

	void Collider2D::Render()
	{
	}
	void Collider2D::OnCollisionEnter(Collider2D* other)
	{
		isColliding = true;
		std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			script->OnCollisionEnter(other);
		}

	}
	void Collider2D::OnCollisionStay(Collider2D* other)
	{
		isColliding = true;
		const std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			script->OnCollisionStay(other);
		}
	}
	void Collider2D::OnCollisionExit(Collider2D* other)
	{
		const std::vector<Script*> scripts
			= GetOwner()->GetComponents<Script>();

		for (Script* script : scripts)
		{
			script->OnCollisionExit(other);
		}
		isColliding = false;
	}
}