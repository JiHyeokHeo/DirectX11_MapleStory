#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsMesh.h"
#include "jnsShader.h"
#include "jnsConstantBuffer.h"

using namespace jns::math;

namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};


	extern Vertex vertexes[];
	extern jns::Mesh* mesh;
	extern jns::Shader* shader;
	extern jns::graphics::ConstantBuffer* transformconstantBuffer;
	extern jns::graphics::ConstantBuffer* colorConstanttBuffer;

	void Initialize();
	void Release();


}
