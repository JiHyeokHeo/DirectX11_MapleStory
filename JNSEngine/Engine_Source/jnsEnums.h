#pragma once
namespace jns::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Particle,
		MeshRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		BG,
		Player,
		Monster,
		UI,
		Camera,
		Cursor,
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

}