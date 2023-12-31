#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsMesh.h"
#include "jnsShader.h"
#include "jnsConstantBuffer.h"
#include "jnsCamera.h"
#include "jnsLight.h"

using namespace jns::math;
using namespace jns::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Matrix mWorld;
		Matrix mView;
		Matrix mProjection;
	};

	CBUFFER(GridCB, CBSLOT_GRID)
	{
		Vector4 CameraPosition;
		Vector2 CameraScale;
		Vector2 Resolution;
	};

	CBUFFER(ObjectTypeMoveCB, CBSLOT_MOVE)
	{	
		int mtype;
		Vector3 mTime;
	};

	CBUFFER(PlayerCB, CBSLOT_PLAYER)
	{
		int hp;
		int mp;
		int exp;
		int type;
		int maxhp;
	};

	CBUFFER(AnimatorCB, CBSLOT_ANIMATION2D)
	{
		Vector2 spriteLeftTop;
		Vector2 spriteSize;
		Vector2 spriteOffset;
		Vector2 atlasSize;
		UINT animationType;
		float transparency = 1.0f;
	};

	CBUFFER(ParticleCB, CBSLOT_PARTICLE)
	{
		UINT elementCount;
		float elpasedTime;
		float deltaTime;
		int padd2;
	};

	CBUFFER(NoiseCB, CBSLOT_NOISE)
	{
		Vector4 size;
	};

	extern jns::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[];


	extern std::vector<jns::Light*> lights;
	extern jns::Camera* mainCamera;
	extern jns::Camera* UICamera;
	extern std::vector<jns::Camera*> cameras;
	extern std::vector<DebugMesh> debugMeshes;

	void Initialize();
	void BindLights();
	void Render();
	void Release();

	void PushDebugMeshAttribute(DebugMesh& mesh);

}


