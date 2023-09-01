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
		AudioListener,
		AudioSource,
		End,
	};

	enum class eSceneType
	{
		LoadingScene,
		Login,
		Select,
		CharactorMake,
		StartScene1,
		RutabysMain,
		RutabysMob,
		RutabysBoss,
	};

	enum class eLayerType
	{
		Particle,
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
		Tomb,
		End = 16,
	};



	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		ComputeShader,
		Image,
		AudioClip,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		Line,
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