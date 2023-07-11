#include "guiEditor.h"
#include "jnsMesh.h"
#include "jnsResources.h"
#include "jnsTransform.h"
#include "jnsMeshRenderer.h"
#include "jnsMaterial.h"
#include "jnsGridScrpt.h"
#include "jnsRenderer.h"


namespace gui
{
	using namespace jns::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<jns::Mesh> mesh
			= jns::Resources::Find<jns::Mesh>(L"DebugRect");
		std::shared_ptr<jns::Material> material
			= jns::Resources::Find<jns::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<jns::Transform>();
		jns::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<jns::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);

		EditorObject* grid = new EditorObject();
		grid->SetName(L"Grid");

		mr = grid->AddComponent<jns::MeshRenderer>();
		mr->SetMesh(jns::Resources::Find<jns::Mesh>(L"RectMesh"));
		mr->SetMaterial(jns::Resources::Find<jns::Material>(L"GridMaterial"));
		jns::GridScript* gridSc = grid->AddComponent<jns::GridScript>();
		gridSc->SetCamera(renderer::cameras[0]);

		mEditorObjects.push_back(grid);


	}
	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Editor::Update()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}
	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}
	void Editor::Render()
	{
		//Microsoft::WRL::ComPtr<ID3D11DepthStencilState> ds
		//	= renderer::depthStencilStates[(UINT)ya::graphics::eDSType::Less];
		//ya::graphics::GetDevice()->BindDepthStencilState(ds.Get());
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const jns::graphics::DebugMesh& mesh
			: renderer::debugMeshes)
		{
			DebugRender(mesh);
		}
	}
	void Editor::Release()
	{
	}
	void Editor::DebugRender(const jns::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// 위치 크기 회전 정보를 받아와서
		// 해당 게임오브젝트위에 그려주면된다.
		debugObj->Render();
	}
}