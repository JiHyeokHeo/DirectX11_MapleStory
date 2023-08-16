#include "jnsRenderer.h"
#include "jnsTexture.h"
#include "jnsResources.h"
#include "jnsMaterial.h"
#include "jnsStructedBuffer.h"
#include "jnsPaintShader.h"
#include "jnsParticleShader.h"

namespace renderer
{
	using namespace jns;
	using namespace jns::graphics;
	jns::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};

	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End] = {};

	// light
	std::vector<Light*> lights = {};
	StructedBuffer* lightsBuffer = nullptr;

	jns::Camera* mainCamera = nullptr;
	jns::Camera* UICamera = nullptr;
	std::vector<jns::Camera*> cameras = {};
	std::vector<DebugMesh> debugMeshes = {};

	 void SetupState()
	 {
#pragma region InputLayout
		 // Input layout 정점 구조 정보를 넘겨줘야한다.
		 D3D11_INPUT_ELEMENT_DESC arrLayout[3] = {};

		 arrLayout[0].AlignedByteOffset = 0;
		 arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		 arrLayout[0].InputSlot = 0;
		 arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		 arrLayout[0].SemanticName = "POSITION";
		 arrLayout[0].SemanticIndex = 0;

		 arrLayout[1].AlignedByteOffset = 12;
		 arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		 arrLayout[1].InputSlot = 0;
		 arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		 arrLayout[1].SemanticName = "COLOR";
		 arrLayout[1].SemanticIndex = 0;

		 arrLayout[2].AlignedByteOffset = 28;
		 arrLayout[2].Format = DXGI_FORMAT_R32G32_FLOAT;
		 arrLayout[2].InputSlot = 0;
		 arrLayout[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		 arrLayout[2].SemanticName = "TEXCOORD";
		 arrLayout[2].SemanticIndex = 0;
		 
		 
		 std::shared_ptr<Shader> shader = jns::Resources::Find<Shader>(L"halfShader");
		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"SpriteShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"MoveShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"GridShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"DebugShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"DebugCircleShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"PlayerHPShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"PlayerMPShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());


		 shader = jns::Resources::Find<Shader>(L"PlayerEXPShader");

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"SpriteAnimationShader");
		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"SpriteAnimationAlphaShader");
		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"ParticleShader");
		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());
#pragma endregion


#pragma region Sampler State

		 //Sampler State
		 D3D11_SAMPLER_DESC desc = {};
		 desc.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		 GetDevice()->CreateSamplerState(&desc, samplerState[(UINT)eSamplerType::Point].GetAddressOf());
		 GetDevice()->BindSampler(eShaderStage::PS, 0, samplerState[(UINT)eSamplerType::Point].GetAddressOf());

		 desc.Filter = D3D11_FILTER_ANISOTROPIC;
		 GetDevice()->CreateSamplerState(&desc, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
		 GetDevice()->BindSampler(eShaderStage::PS, 1, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
#pragma endregion
#pragma region Rasterizer State

		 D3D11_RASTERIZER_DESC rasterizerDesc = {};
		 rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		 rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_BACK;
		 GetDevice()->CreateRasterizeState(&rasterizerDesc
			 , rasterizerStates[(UINT)eRSType::SolidBack].GetAddressOf());

		 rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		 rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_FRONT;
		 GetDevice()->CreateRasterizeState(&rasterizerDesc
			 , rasterizerStates[(UINT)eRSType::SolidFront].GetAddressOf());

		 rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
		 rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		 GetDevice()->CreateRasterizeState(&rasterizerDesc
			 , rasterizerStates[(UINT)eRSType::SolidNone].GetAddressOf());

		 rasterizerDesc.FillMode = D3D11_FILL_MODE::D3D11_FILL_WIREFRAME;
		 rasterizerDesc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
		 GetDevice()->CreateRasterizeState(&rasterizerDesc
			 , rasterizerStates[(UINT)eRSType::WireframeNone].GetAddressOf());
#pragma endregion
#pragma region Depth Stencil State
		
		 D3D11_DEPTH_STENCIL_DESC depthStencilDesc = {};

		 //less
		 depthStencilDesc.DepthEnable = true;
		 depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		 depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		 depthStencilDesc.StencilEnable = false;

		 GetDevice()->CreateDepthStencilState(&depthStencilDesc
			 , depthStencilStates[(UINT)eDSType::Less].GetAddressOf());

		 //Greater
		 depthStencilDesc.DepthEnable = true;
		 depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_GREATER;
		 depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		 depthStencilDesc.StencilEnable = false;

		 GetDevice()->CreateDepthStencilState(&depthStencilDesc
			 , depthStencilStates[(UINT)eDSType::Greater].GetAddressOf());

		 //No Write
		 depthStencilDesc.DepthEnable = true;
		 depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		 depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		 depthStencilDesc.StencilEnable = false;

		 GetDevice()->CreateDepthStencilState(&depthStencilDesc
			 , depthStencilStates[(UINT)eDSType::NoWrite].GetAddressOf());

		 //None
		 depthStencilDesc.DepthEnable = false;
		 depthStencilDesc.DepthFunc = D3D11_COMPARISON_FUNC::D3D11_COMPARISON_LESS;
		 depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
		 depthStencilDesc.StencilEnable = false;

		 GetDevice()->CreateDepthStencilState(&depthStencilDesc
			 , depthStencilStates[(UINT)eDSType::None].GetAddressOf());
#pragma endregion
#pragma region Blend State
		 
		 D3D11_BLEND_DESC blendDesc = {};

		 //default
		 blendStates[(UINT)eBSType::Default] = nullptr;

		 // Alpha Blend
		 blendDesc.AlphaToCoverageEnable = false;
		 blendDesc.IndependentBlendEnable = false;
		 blendDesc.RenderTarget[0].BlendEnable = true;
		 blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		 blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		 blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		 blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		 blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		 blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		 blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		 GetDevice()->CreateBlendState(&blendDesc
			 , blendStates[(UINT)eBSType::AlphaBlend].GetAddressOf());

		 // one one
		 blendDesc.AlphaToCoverageEnable = false;
		 blendDesc.IndependentBlendEnable = false;

		 blendDesc.RenderTarget[0].BlendEnable = true;
		 blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP::D3D11_BLEND_OP_ADD;
		 blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		 blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
		 blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		 GetDevice()->CreateBlendState(&blendDesc
			 , blendStates[(UINT)eBSType::OneOne].GetAddressOf());

#pragma endregion


	 }

	 void LoadMesh()
	 {
		 std::vector<Vertex> vertexes = {};
		 std::vector<UINT> indexes = {};

		 // PointMesh
		 Vertex v = {};
		 v.pos = Vector3(0.0f, 0.0f, 0.0f);
		 vertexes.push_back(v);
		 indexes.push_back(0);
		 std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		 mesh->CreateVertexBuffer(vertexes.data(), vertexes.size());
		 mesh->CreateIndexBuffer(indexes.data(), indexes.size());
		 Resources::Insert(L"PointMesh", mesh);

		 vertexes.clear();
		 indexes.clear();

		 //RECT
		 vertexes.resize(4);
		 vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		 vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		 vertexes[0].uv = Vector2(0.0f, 0.0f);

		 vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		 vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		 vertexes[1].uv = Vector2(1.0f, 0.0f);

		 vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		 vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		 vertexes[2].uv = Vector2(1.0f, 1.0f);

		 vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		 vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		 vertexes[3].uv = Vector2(0.0f, 1.0f);

		 // Vertex Buffer
		 mesh = std::make_shared<Mesh>();
		 Resources::Insert(L"RectMesh", mesh);

		 mesh->CreateVertexBuffer(vertexes.data(), vertexes.size());

		 indexes.push_back(0);
		 indexes.push_back(1);
		 indexes.push_back(2);

		 indexes.push_back(0);
		 indexes.push_back(2);
		 indexes.push_back(3);
		 mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		 // Rect Debug Mesh
		 std::shared_ptr<Mesh> rectDebug = std::make_shared<Mesh>();
		 Resources::Insert(L"DebugRect", rectDebug);
		 rectDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		 rectDebug->CreateIndexBuffer(indexes.data(), indexes.size());

		 // Circle Debug Mesh
		 vertexes.clear();
		 indexes.clear();

		 Vertex center = {};
		 center.pos = Vector3(0.0f, 0.0f, 0.0f);
		 center.color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		 vertexes.push_back(center);

		 int iSlice = 40;
		 float fRadius = 0.5f;
		 float fTheta = XM_2PI / (float)iSlice;

		 for (int i = 0; i < iSlice; ++i)
		 {
			 center.pos = Vector3(fRadius * cosf(fTheta * (float)i)
				 , fRadius * sinf(fTheta * (float)i)
				 , 0.0f);
			 center.color = Vector4(0.0f, 1.0f, 0.0f, 1.f);
			 vertexes.push_back(center);
		 }

		 //for (UINT i = 0; i < (UINT)iSlice; ++i)
		 //{
		 //	indexes.push_back(0);
		 //	if (i == iSlice - 1)
		 //	{
		 //		indexes.push_back(1);
		 //	}
		 //	else
		 //	{
		 //		indexes.push_back(i + 2);
		 //	}
		 //	indexes.push_back(i + 1);
		 //}

		 for (int i = 0; i < vertexes.size() - 2; ++i)
		 {
			 indexes.push_back(i + 1);
		 }
		 indexes.push_back(1);

		 std::shared_ptr<Mesh> circleDebug = std::make_shared<Mesh>();
		 Resources::Insert(L"DebugCircle", circleDebug);
		 circleDebug->CreateVertexBuffer(vertexes.data(), vertexes.size());
		 circleDebug->CreateIndexBuffer(indexes.data(), indexes.size());
	 }

	 void LoadBuffer()
	 {
		 // Constant Buffer
		 constantBuffer[(UINT)eCBType::Transform] = new ConstantBuffer(eCBType::Transform);
		 constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));

		 constantBuffer[(UINT)eCBType::Move] = new ConstantBuffer(eCBType::Move);
		 constantBuffer[(UINT)eCBType::Move]->Create(sizeof(ObjectTypeMoveCB));

		 // Grid Buffer
		 constantBuffer[(UINT)eCBType::Grid] = new ConstantBuffer(eCBType::Grid);
		 constantBuffer[(UINT)eCBType::Grid]->Create(sizeof(GridCB));

		 constantBuffer[(UINT)eCBType::Player] = new ConstantBuffer(eCBType::Player);
		 constantBuffer[(UINT)eCBType::Player]->Create(sizeof(PlayerCB));


		 constantBuffer[(UINT)eCBType::Animator] = new ConstantBuffer(eCBType::Animator);
		 constantBuffer[(UINT)eCBType::Animator]->Create(sizeof(AnimatorCB));
		 
		 //ParticleCB
		 constantBuffer[(UINT)eCBType::Particle] = new ConstantBuffer(eCBType::Particle);
		 constantBuffer[(UINT)eCBType::Particle]->Create(sizeof(ParticleCB));

		 //NoiseCB
		 constantBuffer[(UINT)eCBType::Noise] = new ConstantBuffer(eCBType::Noise);
		 constantBuffer[(UINT)eCBType::Noise]->Create(sizeof(NoiseCB));

		 // light structed buffer
		 lightsBuffer = new StructedBuffer();
		 lightsBuffer->Create(sizeof(LightAttribute), 2, eViewType::SRV, nullptr, true);
		 


		 // 추가 상수 버퍼
		 //colorConstanttBuffer = new jns::graphics::ConstantBuffer(eCBType::Color);
		 //colorConstanttBuffer->Create(sizeof(Vector4));

		 //Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		 //constantBuffer->SetData(&pos);
		 //constantBuffer->Bind(eShaderStage::VS);

	 }

	 void LoadShader()
	 {
		 std::shared_ptr<Shader> halfshader = std::make_shared<Shader>();
		 halfshader->Create(eShaderStage::VS, L"MoveVS.hlsl", "main");
		 halfshader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		 jns::Resources::Insert(L"halfShader", halfshader);

		 std::shared_ptr<Shader> spriteShader = std::make_shared<Shader>();
		 spriteShader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		 spriteShader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		 jns::Resources::Insert(L"SpriteShader", spriteShader);

		 std::shared_ptr<Shader> moveShader = std::make_shared<Shader>();
		 moveShader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		 moveShader->Create(eShaderStage::PS, L"MovePS.hlsl", "main");
		 jns::Resources::Insert(L"MoveShader", moveShader);

		 std::shared_ptr<Shader> spriteAniShader = std::make_shared<Shader>();
		 spriteAniShader->Create(eShaderStage::VS, L"SpriteAnimationVS.hlsl", "main");
		 spriteAniShader->Create(eShaderStage::PS, L"SpriteAnimationPS.hlsl", "main");
		 jns::Resources::Insert(L"SpriteAnimationShader", spriteAniShader);

		 std::shared_ptr<Shader> spriteAniAlphaShader = std::make_shared<Shader>();
		 spriteAniAlphaShader->Create(eShaderStage::VS, L"SpriteAnimationAlphaVS.hlsl", "main");
		 spriteAniAlphaShader->Create(eShaderStage::PS, L"SpriteAnimationAlphaPS.hlsl", "main");
		 jns::Resources::Insert(L"SpriteAnimationAlphaShader", spriteAniAlphaShader);

		 std::shared_ptr<Shader> gridShader = std::make_shared<Shader>();
		 gridShader->Create(eShaderStage::VS, L"GridVS.hlsl", "main");
		 gridShader->Create(eShaderStage::PS, L"GridPS.hlsl", "main");
		 jns::Resources::Insert(L"GridShader", gridShader);

		 std::shared_ptr<Shader> debugShader = std::make_shared<Shader>();
		 debugShader->Create(eShaderStage::VS, L"DebugVS.hlsl", "main");
		 debugShader->Create(eShaderStage::PS, L"DebugPS.hlsl", "main");
		 debugShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		 debugShader->SetRSState(eRSType::WireframeNone);
		 //debugShader->SetDSState(eDSType::NoWrite);
		 jns::Resources::Insert(L"DebugShader", debugShader);

		 std::shared_ptr<Shader> debugCircleShader = std::make_shared<Shader>();
		 debugCircleShader->Create(eShaderStage::VS, L"DebugVS.hlsl", "main");
		 debugCircleShader->Create(eShaderStage::PS, L"DebugPS.hlsl", "main");
		 debugCircleShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
		 debugCircleShader->SetRSState(eRSType::WireframeNone);
		 //debugShader->SetDSState(eDSType::NoWrite);
		 jns::Resources::Insert(L"DebugCircleShader", debugCircleShader);

		 std::shared_ptr<Shader> playerUIShader = std::make_shared<Shader>();
		 playerUIShader->Create(eShaderStage::VS, L"PlayerHPVS.hlsl", "main");
		 playerUIShader->Create(eShaderStage::PS, L"PlayerHPPS.hlsl", "main");
		 jns::Resources::Insert(L"PlayerHPShader", playerUIShader);

		 playerUIShader = std::make_shared<Shader>();
		 playerUIShader->Create(eShaderStage::VS, L"PlayerMPVS.hlsl", "main");
		 playerUIShader->Create(eShaderStage::PS, L"PlayerMPPS.hlsl", "main");
		 jns::Resources::Insert(L"PlayerMPShader", playerUIShader);

		 playerUIShader = std::make_shared<Shader>();
		 playerUIShader->Create(eShaderStage::VS, L"PlayerEXPVS.hlsl", "main");
		 playerUIShader->Create(eShaderStage::PS, L"PlayerEXPPS.hlsl", "main");
		 jns::Resources::Insert(L"PlayerEXPShader", playerUIShader);

		 std::shared_ptr<PaintShader> paintShader = std::make_shared<PaintShader>();
		 paintShader->Create(L"PaintCS.hlsl", "main");
		 jns::Resources::Insert(L"PaintShader", paintShader);

		 std::shared_ptr<ParticleShader> psSystemShader = std::make_shared<ParticleShader>();
		 psSystemShader->Create(L"ParticleCS.hlsl", "main");
		 jns::Resources::Insert(L"ParticleSystemShader", psSystemShader);

		 std::shared_ptr<Shader> paritcleShader = std::make_shared<Shader>();
		 paritcleShader->Create(eShaderStage::VS, L"ParticleVS.hlsl", "main");
		 paritcleShader->Create(eShaderStage::GS, L"ParticleGS.hlsl", "main");
		 paritcleShader->Create(eShaderStage::PS, L"ParticlePS.hlsl", "main");
		 paritcleShader->SetRSState(eRSType::SolidNone);
		 paritcleShader->SetDSState(eDSType::NoWrite);
		 paritcleShader->SetBSState(eBSType::AlphaBlend);
		 paritcleShader->SetTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D_PRIMITIVE_TOPOLOGY_POINTLIST);
		 jns::Resources::Insert(L"ParticleShader", paritcleShader);

		 //{
			// std::shared_ptr<Texture> texture
			//	 = Resources::Load<Texture>(L"RutabysMain", L"..\\Resources\\Map\\Rutabys\\rutabys.png");
			// std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			// spriteMateiral->SetShader(spriteShader);
			// spriteMateiral->SetTexture(texture);
			// Resources::Insert(L"RutabysMainMaterial", spriteMateiral);
		 //}

	 }


	 void LoadTexture()
	 {
		 //paint texture
		 std::shared_ptr<Texture> uavTexture = std::make_shared<Texture>();
		 uavTexture->Create(1024, 1024, DXGI_FORMAT_R8G8B8A8_UNORM, D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS);
		 jns::Resources::Insert(L"PaintTexture", uavTexture);

		 std::shared_ptr<Texture> particle = std::make_shared<Texture>();
		 Resources::Load<Texture>(L"CartoonSmoke", L"..\\Resources\\Particle\\CartoonSmoke.png");
		 Resources::Load<Texture>(L"SkillParticle", L"..\\Resources\\Particle\\SkillParticle.png");

		 Resources::Load<Texture>(L"Noise01", L"..\\Resources\\noise\\noise_01.png");
		 Resources::Load<Texture>(L"Noise02", L"..\\Resources\\noise\\noise_02.png");
		 Resources::Load<Texture>(L"Noise03", L"..\\Resources\\noise\\noise_03.png");
	 }


	 void LoadMaterial()
	 {
		 std::shared_ptr<Shader> spriteShader
			 = Resources::Find<Shader>(L"SpriteShader");
		 std::shared_ptr<Shader> halfshader
			 = Resources::Find<Shader>(L"halfShader");
		 std::shared_ptr<Shader> moveShader
			 = Resources::Find<Shader>(L"MoveShader");
		 std::shared_ptr<Shader> gridShader
			 = Resources::Find<Shader>(L"GridShader");
		 std::shared_ptr<Shader> playerHPShader
			 = Resources::Find<Shader>(L"PlayerHPShader");
		 std::shared_ptr<Shader> playerMPShader
			 = Resources::Find<Shader>(L"PlayerMPShader");
		 std::shared_ptr<Shader> playerEXPShader
			 = Resources::Find<Shader>(L"PlayerEXPShader");
		 std::shared_ptr<Shader> debugShader
			 = Resources::Find<Shader>(L"DebugShader");
		 std::shared_ptr<Shader> debugCircleShader
			 = Resources::Find<Shader>(L"DebugCircleShader");
		 std::shared_ptr<Shader> spriteAniShader
			 = Resources::Find<Shader>(L"SpriteAnimationShader");
		 std::shared_ptr<Shader> spriteAniAlphaShader
			 = Resources::Find<Shader>(L"SpriteAnimationAlphaShader");
		 std::shared_ptr<Shader> particleShader
			 = Resources::Find<Shader>(L"ParticleShader");

		 std::shared_ptr<Material> material = std::make_shared<Material>();
		 material = std::make_shared<Material>();
		 material->SetShader(gridShader);
		 Resources::Insert(L"GridMaterial", material);
		 
	
		 material = std::make_shared<Material>();
		 material->SetShader(spriteAniShader);
		 material->SetRenderingMode(eRenderingMode::Transparent);
		 Resources::Insert(L"SpriteAnimaionMaterial", material);

		 material = std::make_shared<Material>();
		 material->SetShader(spriteAniAlphaShader);
		 material->SetRenderingMode(eRenderingMode::Transparent);
		 Resources::Insert(L"SpriteAnimaionAlphaMaterial", material);

		 material = std::make_shared<Material>();
		 material->SetShader(debugShader);
		 Resources::Insert(L"DebugMaterial", material);

		 material = std::make_shared<Material>();
		 material->SetShader(debugCircleShader);
		 Resources::Insert(L"DebugCircleMaterial", material);

		 particleShader
			 = Resources::Find<Shader>(L"ParticleShader");
		 material = std::make_shared<Material>();
		 material->SetShader(particleShader);
		 material->SetRenderingMode(eRenderingMode::Transparent);

		 std::shared_ptr<Texture> particleTex
			 = Resources::Find<Texture>(L"CartoonSmoke");
		 material->SetTexture(particleTex);
		 Resources::Insert(L"ParticleMaterial", material);

		 material = std::make_shared<Material>();
		 material->SetShader(particleShader);
		 material->SetRenderingMode(eRenderingMode::Transparent);

		 particleTex = Resources::Find<Texture>(L"SkillParticle");
		 material->SetTexture(particleTex);
		 Resources::Insert(L"SkillParticleMaterial", material);
			 

#pragma region TestPlayer
		 LOAD_TEXTURE(L"Link", L"..\\Resources\\Texture\\Link.png", texture);
		 SET_MATERIAL(spriteMaterial, texture, spriteShader);
		 INSERT_MATERIAL(L"SpriteMaterial", spriteMaterial);


		 //texture = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
		 texture = Resources::Find<Texture>(L"PaintTexture");
		 SET_MATERIAL(spriteMaterial1, texture, spriteShader);
		 //texture1->GetTextureSize();
		 //spriteMaterial1->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"SpriteMaterial02", spriteMaterial1);
#pragma endregion

#pragma region BackGround
		 LOAD_TEXTURE(L"RutabysMainBG", L"..\\Resources\\Map\\Rutabys\\rutabys.png", Ruta_BG_Texture);
		 SET_MATERIAL(Ruta_BG_Material, Ruta_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"RutabysMainMaterial", Ruta_BG_Material);

		 LOAD_TEXTURE(L"CharactorMakeBG", L"..\\Resources\\Map\\CharactorMake_BG.png", CharactorMake_BG_Texture);
		 SET_MATERIAL(CharactorMake_BG_Material, CharactorMake_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"CharactorMakeBGMaterial", CharactorMake_BG_Material);

		 LOAD_TEXTURE(L"StartBG", L"..\\Resources\\Map\\Start_BG.png", Start_BG_Texture);
		 SET_MATERIAL(Start_BG_Material, Start_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"StartBGMaterial", Start_BG_Material);

		 LOAD_TEXTURE(L"Start2BG", L"..\\Resources\\Map\\Start2_BG.png", Start2_BG_Texture);
		 SET_MATERIAL(Start2_BG_Material, Start2_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"Start2BGMaterial", Start2_BG_Material);

		 LOAD_TEXTURE(L"Start3BG", L"..\\Resources\\Map\\Start3_BG.png", Start3_BG_Texture);
		 SET_MATERIAL(Start3_BG_Material, Start3_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"Start3BGMaterial", Start3_BG_Material);

		 LOAD_TEXTURE(L"Start4BG", L"..\\Resources\\Map\\Start4_BG.png", Start4_BG_Texture);
		 SET_MATERIAL(Start4_BG_Material, Start4_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"Start4BGMaterial", Start4_BG_Material);

		 LOAD_TEXTURE(L"Start5BG", L"..\\Resources\\Map\\Start5_BG.png", Start5_BG_Texture);
		 SET_MATERIAL(Start5_BG_Material, Start5_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"Start5BGMaterial", Start5_BG_Material);

		 LOAD_TEXTURE(L"LoginBG", L"..\\Resources\\Map\\Login_BG.png", Login_BG_Texture);
		 SET_MATERIAL(Login_BG_Material, Login_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"LoginBGMaterial", Login_BG_Material);

		 LOAD_TEXTURE(L"SelectBG", L"..\\Resources\\Map\\Select_BG.png", Select_BG_Texture);
		 SET_MATERIAL(Select_BG_Material, Select_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"SelectBGMaterial", Select_BG_Material);

		 LOAD_TEXTURE(L"WorldSelectBG", L"..\\Resources\\Map\\WorldSelect_BG.png", WorldSelect_BG_Texture);
		 SET_MATERIAL(WorldSelect_BGMaterial, WorldSelect_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"WorldSelectBGMaterial", WorldSelect_BGMaterial);

		 LOAD_TEXTURE(L"RutabysBossBG", L"..\\Resources\\Map\\Rutabys\\rutabys_boss.png", RutaBoss_BG_Texture);
		 SET_MATERIAL(RutaBoss_BG_Material, RutaBoss_BG_Texture, spriteShader);
		 INSERT_MATERIAL(L"RutabysBossBGMaterial", RutaBoss_BG_Material);

		 LOAD_TEXTURE(L"Rutabysqueen1", L"..\\Resources\\Map\\Rutabys\\rutabys_queen1.png", Rutabysqueen1_BG_Texture);
		 SET_MATERIAL(Rutabysqueen1_BG_Material, Rutabysqueen1_BG_Texture, spriteShader);

		 INSERT_MATERIAL(L"Rutabysqueen1Material", Rutabysqueen1_BG_Material);

		 LOAD_TEXTURE(L"Rutabysqueen2", L"..\\Resources\\Map\\Rutabys\\rutabys_queen2.png", Rutabysqueen2_BG_Texture);
		 SET_MATERIAL(Rutabysqueen2_BG_Material, Rutabysqueen2_BG_Texture, spriteShader);
		 Rutabysqueen2_BG_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"Rutabysqueen2Material", Rutabysqueen2_BG_Material);
#pragma endregion

#pragma region UI
		 // exp 
		 LOAD_TEXTURE(L"ExpBar", L"..\\Resources\\UI\\Status\\ExpBar.png", ExpBar_UI_Texture); // 흰색 투명
		 SET_MATERIAL(ExpBar_UI_Material, ExpBar_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"ExpBarUIMaterial", ExpBar_UI_Material);

		 LOAD_TEXTURE(L"ExpMaxBar", L"..\\Resources\\UI\\Status\\ExpMaxBar.png", ExpMaxBar_UI_Texture); // 노랑
		 SET_MATERIAL(ExpMaxBar_UI_Material, ExpMaxBar_UI_Texture, playerEXPShader);
		 //ExpMaxBar_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"ExpMaxBarMaterial", ExpMaxBar_UI_Material);

		 // status
		 LOAD_TEXTURE(L"SkillQuickSlotBackLayer", L"..\\Resources\\UI\\Status\\SkillQuickSlotBackLayer.png", SkillQuickSlotBackLayer_UI_Texture);
		 SET_MATERIAL(SkillQuickSlotBackLayer_UI_Material, SkillQuickSlotBackLayer_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"SkillQuickSlotBackMaterial", SkillQuickSlotBackLayer_UI_Material);

		 LOAD_TEXTURE(L"SkillQuickSlotFrontLayer", L"..\\Resources\\UI\\Status\\SkillQuickSlotFrontLayer.png", SkillQuickSlotFrontLayer_UI_Texture);
		 SET_MATERIAL(SkillQuickSlotFrontLayer_UI_Material, SkillQuickSlotFrontLayer_UI_Texture, spriteShader);
		 //SkillQuickSlotFrontLayer_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"SkillQuickSlotFrontMaterial", SkillQuickSlotFrontLayer_UI_Material);

		 LOAD_TEXTURE(L"SkillSlotExtension", L"..\\Resources\\UI\\Status\\SkillSlotExtension.png", SkillSlotExtension_UI_Texture);
		 SET_MATERIAL(SkillSlotExtension_UI_Material, SkillSlotExtension_UI_Texture, spriteShader);
		 //SkillSlotExtension_UI_Material->SetRenderingMode(eRenderingMode::CutOut);
		 INSERT_MATERIAL(L"SkillSlotExtensionMaterial", SkillSlotExtension_UI_Material);

		 LOAD_TEXTURE(L"HpBar", L"..\\Resources\\UI\\Status\\HpBar.png", HpBar_UI_Texture);
		 SET_MATERIAL(HpBar_UI_Material, HpBar_UI_Texture, playerHPShader);
		 //HpBar_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"HpBarMaterial", HpBar_UI_Material);

		 LOAD_TEXTURE(L"MpBar", L"..\\Resources\\UI\\Status\\MpBar.png", MpBar_Texture);
		 SET_MATERIAL(MpBar_UI_Material, MpBar_Texture, playerMPShader);
		 //MpBar_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"MpBarMaterial", MpBar_UI_Material);

		 LOAD_TEXTURE(L"Option", L"..\\Resources\\UI\\Status\\OptionBar.png", OptionBar_UI_Texture);
		 SET_MATERIAL(OptionBar_UI_Material, OptionBar_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"OptionBarMaterial", OptionBar_UI_Material);

		 LOAD_TEXTURE(L"Sound", L"..\\Resources\\UI\\Status\\SoundBar.png", SoundBar_UI_Texture);
		 SET_MATERIAL(SoundBar_UI_Material, SoundBar_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"SoundBarMaterial", SoundBar_UI_Material);

		 LOAD_TEXTURE(L"StatusMainBar", L"..\\Resources\\UI\\Status\\StatusMainBar.png", StatusMainBar_UI_Texture);
		 SET_MATERIAL(StatusMainBar_UI_Material, StatusMainBar_UI_Texture, spriteShader);
		 StatusMainBar_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"StatusMainBarMaterial", StatusMainBar_UI_Material);


		 // Shop
		 LOAD_TEXTURE(L"ShopBackGround", L"..\\Resources\\UI\\ShopUI\\UIWindow2.img.Shop2.backgrnd.png", ShopBackGround_UI_Texture);
		 SET_MATERIAL(ShopBackGround_UI_Material, ShopBackGround_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"ShopBackGroundMaterial", ShopBackGround_UI_Material);

		 LOAD_TEXTURE(L"ShopBackGround2", L"..\\Resources\\UI\\ShopUI\\UIWindow2.img.Shop2.backgrnd2.png", ShopBackGround2_UI_Texture);
		 SET_MATERIAL(ShopBackGround2_UI_Material, ShopBackGround2_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"ShopBackGround2Material", ShopBackGround2_UI_Material);

		 LOAD_TEXTURE(L"ShopBackGround3", L"..\\Resources\\UI\\ShopUI\\UIWindow2.img.Shop2.backgrnd3.png", ShopBackGround3_UI_Texture);
		 SET_MATERIAL(ShopBackGround3_UI_Material, ShopBackGround3_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"ShopBackGround3Material", ShopBackGround3_UI_Material);

		  
		 LOAD_TEXTURE(L"Mist01", L"..\\Resources\\Effect\\particle.img.adele_castle_mist.texture.png", Mist01_UI_Texture);
		 SET_MATERIAL(Mist01_UI_Material, Mist01_UI_Texture, moveShader);
		 Mist01_UI_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"Mist01Material", Mist01_UI_Material);

		 // Inventory
		 LOAD_TEXTURE(L"Inventory", L"..\\Resources\\UI\\Inventory\\InventoryBG.png", Inventory_UI_Texture);
		 SET_MATERIAL(Inventory_UI_Material, Inventory_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"InventoryMaterial", Inventory_UI_Material);
		 
		 LOAD_TEXTURE(L"InventoryBG", L"..\\Resources\\UI\\Inventory\\Item.backgrnd3.png", Inventory_UI2_Texture);
		 SET_MATERIAL(Inventory_UI2_Material, Inventory_UI2_Texture, spriteShader);
		 INSERT_MATERIAL(L"InventoryBGMaterial", Inventory_UI2_Material);

		 LOAD_TEXTURE(L"CharacSelectUI", L"..\\Resources\\UI\\Button\\CharSelect.adventure.0.png", CharacSelect_UI_Texture);
		 SET_MATERIAL(CharacSelect_UI_Material, CharacSelect_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"CharacSelectMaterial", CharacSelect_UI_Material);

		 LOAD_TEXTURE(L"CharacSelectInfoUI", L"..\\Resources\\UI\\Button\\CharSelect.charInfo1.png", CharacSelectInfo_UI_Texture);
		 SET_MATERIAL(CharacSelectInfo_UI_Material, CharacSelectInfo_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"CharacSelectInfoMaterial", CharacSelectInfo_UI_Material);


		 LOAD_TEXTURE(L"CharSelectBtSelectUI", L"..\\Resources\\UI\\Button\\CharSelect.BtSelect.normal.0.png", CharSelectBtSelect_UI_Texture);
		 SET_MATERIAL(CharSelectBtSelect_UI_Material, CharSelectBtSelect_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"CharSelectBtSelectMaterial", CharSelectBtSelect_UI_Material);

		 LOAD_TEXTURE(L"CharSelectBtNewUI", L"..\\Resources\\UI\\Button\\CharSelect.BtNew.normal.0.png", CharSelectBtNew_UI_Texture);
		 SET_MATERIAL(CharSelectBtNew_UI_Material, CharSelectBtNew_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"CharSelectBtNewMaterial", CharSelectBtNew_UI_Material);

		 LOAD_TEXTURE(L"CommonBtPreviewUI", L"..\\Resources\\UI\\Button\\Common.BtPreview.normal.0.png", CommonBtPreview_UI_Texture);
		 SET_MATERIAL(CommonBtPreview_UI_Material, CommonBtPreview_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"CommonBtPreviewMaterial", CommonBtPreview_UI_Material);

		 LOAD_TEXTURE(L"LoginButtonUI", L"..\\Resources\\UI\\Button\\LoginUIButton.png", LoginButton_UI_Texture);
		 SET_MATERIAL(LoginButton_UI_Material, LoginButton_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"LoginButtonMaterial", LoginButton_UI_Material);

		 LOAD_TEXTURE(L"WorldSelectButtonUI", L"..\\Resources\\UI\\Button\\WorldSelectButton.png", WorldSelectButton_UI_Texture);
		 SET_MATERIAL(WorldSelectButton_UI_Material, WorldSelectButton_UI_Texture, spriteShader);
		 INSERT_MATERIAL(L"WorldSelectButtonMaterial", WorldSelectButton_UI_Material);

#pragma endregion

#pragma region Cursor
		 LOAD_TEXTURE(L"CursorSpirte0", L"..\\Resources\\UI\\CursorUI\\BasicCursor0.png", CursorSprite0_Texture);
		 SET_MATERIAL(CursorSpirte0_Material, CursorSprite0_Texture, spriteShader);
		 CursorSpirte0_Material->SetRenderingMode(eRenderingMode::Transparent);
		 INSERT_MATERIAL(L"CursorSpirte0Material", CursorSpirte0_Material);
#pragma endregion

		 LOAD_TEXTURE(L"HP_MP_Potion", L"..\\Resources\\Item\\0553.img.05530006.info.icon.png", HP_MP_Potion_Texture);
		 SET_MATERIAL(HP_MP_Potion_Material, HP_MP_Potion_Texture, spriteShader);
		 INSERT_MATERIAL(L"HP_MP_PotionMaterial", HP_MP_Potion_Material);

	 }

	 void Initialize()
	 {
		 LoadMesh();
		 LoadBuffer();
		 LoadShader();
		 SetupState();
		 LoadTexture();
		 LoadMaterial();
	 }

	 void BindNoiseTexture()
	 {
		 std::shared_ptr<Texture> texture
			 = Resources::Find<Texture>(L"Noise01");

		 texture->BindShaderResource(eShaderStage::VS, 15);
		 texture->BindShaderResource(eShaderStage::HS, 15);
		 texture->BindShaderResource(eShaderStage::DS, 15);
		 texture->BindShaderResource(eShaderStage::GS, 15);
		 texture->BindShaderResource(eShaderStage::PS, 15);
		 texture->BindShaderResource(eShaderStage::CS, 15);

		 ConstantBuffer* cb = constantBuffer[(UINT)eCBType::Noise];
		 NoiseCB data = {};
		 data.size.x = texture->GetWidth();
		 data.size.y = texture->GetHeight();

		 cb->SetData(&data);
		 cb->Bind(eShaderStage::VS);
		 cb->Bind(eShaderStage::GS);
		 cb->Bind(eShaderStage::PS);
		 cb->Bind(eShaderStage::CS);
	 }

	 void Render()
	 {
		 BindNoiseTexture();
		 BindLights();
		 mainCamera = cameras[0];
		 for (Camera* cam : cameras)
		 {
			 if (cam == nullptr)
				 continue;

			 cam->Render();
		 }

		 cameras.clear();
		 lights.clear();
	 }

	 void Release()
	 {
		 for (ConstantBuffer* buff : constantBuffer)
		 {
			 if (buff == nullptr)
				 continue;

			 delete buff;
			 buff = nullptr;
		 }

		 delete lightsBuffer;
		 lightsBuffer = nullptr;
	 }

	 void PushDebugMeshAttribute(DebugMesh& mesh)
	 {
		 debugMeshes.push_back(mesh);
	 }

	 void BindLights()
	 {
		 std::vector<LightAttribute> lightsAttributes = {};
		 for (Light* light : lights)
		 {
			 LightAttribute attribute = light->GetAttribute();
			 lightsAttributes.push_back(attribute);
		 }

		 lightsBuffer->SetData(lightsAttributes.data(), lightsAttributes.size());
		 lightsBuffer->BindSRV(eShaderStage::VS, 13);
		 lightsBuffer->BindSRV(eShaderStage::PS, 13);
	 }

	
}

