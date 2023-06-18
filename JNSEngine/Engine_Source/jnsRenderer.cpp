#include "jnsRenderer.h"
#include "jnsTexture.h"
#include "jnsResources.h"

namespace renderer
{
	using namespace jns;
	using namespace jns::graphics;
	Vertex vertexes[4] = {};
	jns::Mesh* mesh = nullptr;
	jns::Shader* shader = nullptr;
	jns::graphics::ConstantBuffer* transformconstantBuffer;
	//jns::graphics::ConstantBuffer* colorConstanttBuffer;

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

		 jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 3
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());
	 }

	 void LoadBuffer()
	 {
		 // Vertex Buffer
		 mesh = new jns::Mesh();
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
		 transformconstantBuffer = new jns::graphics::ConstantBuffer(eCBType::Transform);
		 transformconstantBuffer->Create(sizeof(Vector4));


		 // 추가 상수 버퍼
		 //colorConstanttBuffer = new jns::graphics::ConstantBuffer(eCBType::Color);
		 //colorConstanttBuffer->Create(sizeof(Vector4));

		 //Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		 //constantBuffer->SetData(&pos);
		 //constantBuffer->Bind(eShaderStage::VS);

	 }

	 void LoadShader()
	 {
		 shader = new jns::Shader();
		 shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		 shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
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

		 Texture* texture
			 = Resources::Load<Texture>(L"Smile", L"..\\Resources\\Texture\\Smile.png");

		 texture->BindShader(eShaderStage::PS, 0);
	 }

	 void Release()
	 {
		 delete mesh;
		 delete shader;
		 delete transformconstantBuffer;
		// delete colorConstanttBuffer;
	 }

	
}

