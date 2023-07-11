#pragma once
namespace jns::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		RayCollider2D,
		Particle,
		MeshRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Grid,
		BG,
		Player,
		Monster,
		UI,
		Camera,
		Cursor,
		MapEffect,
		End,
	};



	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};
}