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

	 void SetupState()
	 {
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

		 //Sampler State
		 D3D11_SAMPLER_DESC desc = {};
		 desc.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_WRAP;
		 desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		 GetDevice()->CreateSampler(&desc, samplerState[(UINT)eSamplerType::Point].GetAddressOf());
		 GetDevice()->BindSampler(eShaderStage::PS, 0, samplerState[(UINT)eSamplerType::Point].GetAddressOf());

		 desc.Filter = D3D11_FILTER_ANISOTROPIC;
		 GetDevice()->CreateSampler(&desc, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());
		 GetDevice()->BindSampler(eShaderStage::PS, 1, samplerState[(UINT)eSamplerType::Anisotropic].GetAddressOf());

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

		 std::shared_ptr<Texture> texture
			 = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");
		 texture
			 = Resources::Load<Texture>(L"Link", L"..\\Resources\\Texture\\Link.png");


		 texture->BindShader(eShaderStage::PS, 0);
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

