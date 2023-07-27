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
		Animator,
		Script,
		RigidBody,
		Light,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Grid,
		Ground,
		BG,
		Item,
		Player,
		Monster,
		Skill,
		UI,
		Camera,
		Cursor,
		MapEffect,
		Portal,
		Light,
		End = 16,
	};



	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		Image,
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

	enum class eLightType
	{
		Directional,
		Point,
		Spot,
		End,
	};


}