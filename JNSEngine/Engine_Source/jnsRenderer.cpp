#include "jnsRenderer.h"
#include "jnsTexture.h"
#include "jnsResources.h"
#include "jnsMaterial.h"

namespace renderer
{
	using namespace jns;
	using namespace jns::graphics;
	Vertex vertexes[4] = {};
	jns::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End] = {};

	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[(UINT)eSamplerType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDSType::End] = {};
	Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBSType::End] = {};

	std::vector<jns::Camera*> cameras;

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
		 
		 
		 std::shared_ptr<Shader> shader = jns::Resources::Find<Shader>(L"TriangleShader");
		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());

		 shader = jns::Resources::Find<Shader>(L"SpriteShader");

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

	 void LoadBuffer()
	 {
		 // Vertex Buffer
		 std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>();
		 Resources::Insert(L"RectMesh", mesh);

		 mesh->CreateVertexBuffer(vertexes, 4);

		 std::vector<UINT> indexes = {};

		 indexes.push_back(0);
		 indexes.push_back(1);
		 indexes.push_back(2);

		 indexes.push_back(0);
		 indexes.push_back(2);
		 indexes.push_back(3);
		 mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		 // Constant Buffer
		 constantBuffer[(UINT)eCBType::Transform] = new ConstantBuffer(eCBType::Transform);
		 constantBuffer[(UINT)eCBType::Transform]->Create(sizeof(TransformCB));


		 // 추가 상수 버퍼
		 //colorConstanttBuffer = new jns::graphics::ConstantBuffer(eCBType::Color);
		 //colorConstanttBuffer->Create(sizeof(Vector4));

		 //Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		 //constantBuffer->SetData(&pos);
		 //constantBuffer->Bind(eShaderStage::VS);

	 }

	 void LoadShader()
	 {
		 std::shared_ptr<Shader> shader = std::make_shared<Shader>();
		 shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		 shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
		 jns::Resources::Insert(L"TriangleShader", shader);

		 std::shared_ptr<Shader> spriteShader = std::make_shared<Shader>();
		 spriteShader->Create(eShaderStage::VS, L"SpriteVS.hlsl", "main");
		 spriteShader->Create(eShaderStage::PS, L"SpritePS.hlsl", "main");
		 jns::Resources::Insert(L"SpriteShader", spriteShader);


		 //LOAD_TEXTURE(L"Smile", L"..\\Resources\\Texture\\Smile.png", texture1);
		 //SET_MATERIAL(spriteMaterial1, texture1);
		 //spriteMaterial1->SetRenderingMode(eRenderingMode::Transparent);
		 //INSERT_MATERIAL(L"SpriteMaterial02" ,spriteMaterial1);

		 //LOAD_TEXTURE(L"RutabysMain", L"..\\Resources\\Map\\Rutabys\\rutabys.png", texture2);
		 //SET_MATERIAL(spriteMaterial2, texture2);
		 //INSERT_MATERIAL(L"RutabysMainMaterial", spriteMaterial2);
		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"Link", L"..\\Resources\\Texture\\Link.png");

			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"SpriteMaterial", spriteMateiral);
		 }
		 
		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			 Resources::Insert(L"SpriteMaterial02", spriteMateiral);
		 }

		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"RutabysMain", L"..\\Resources\\Map\\Rutabys\\rutabys.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"RutabysMainMaterial", spriteMateiral);
		 }

		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"CharactorMakeBG", L"..\\Resources\\Map\\CharactorMake_BG.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"CharactorMakeMaterial", spriteMateiral);
		 }

		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"LoginBG", L"..\\Resources\\Map\\Login_BG.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"LoginBGMaterial", spriteMateiral);
		 }

		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"SelectBG", L"..\\Resources\\Map\\Select_BG.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"SelectBGMaterial", spriteMateiral);
		 }

		 {
			 std::shared_ptr<Texture> texture
				 = Resources::Load<Texture>(L"WorldSelectBG", L"..\\Resources\\Map\\WorldSelect_BG.png");
			 std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			 spriteMateiral->SetShader(spriteShader);
			 spriteMateiral->SetTexture(texture);
			 Resources::Insert(L"WorldSelectBGMaterial", spriteMateiral);
		 }
	 }

	 void Initialize()
	 {
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

		 LoadBuffer();
		 LoadShader();
		 SetupState();

	/*	 std::shared_ptr<Texture> texture
			 = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
		 texture
			 = Resources::Load<Texture>(L"Link", L"..\\Resources\\Texture\\Link.png");


		 texture->BindShader(eShaderStage::PS, 0);*/
	 }

	 void Render()
	 {
		 for (Camera* cam : cameras)
		 {
			 if (cam == nullptr)
				 continue;

			 cam->Render();
		 }

		 cameras.clear();
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
	 }

	
}

