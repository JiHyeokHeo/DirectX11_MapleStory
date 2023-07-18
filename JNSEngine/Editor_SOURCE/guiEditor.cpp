#include "guiEditor.h"
#include "..\\Engine_Source\\jnsMesh.h"
#include "..\\Engine_Source\\jnsMesh.h"
#include "..\\Engine_Source\\jnsResources.h"
#include "..\\Engine_Source\\jnsTransform.h"
#include "..\\Engine_Source\\jnsMeshRenderer.h"
#include "..\\Engine_Source\\jnsMaterial.h"
#include "..\\Engine_Source\\jnsRenderer.h"

#include "jnsGridScrpt.h"


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
		renderer::debugMeshes.clear();
	}
	void Editor::Release()
	{
		for (auto widget : mWidgets)
		{
			delete widget;
			widget = nullptr;
		}

		for (auto editorObj : mEditorObjects)
		{
			delete editorObj;
			editorObj = nullptr;
		}

		for (auto debugObj : mDebugObjects)
		{
			delete debugObj;
			debugObj = nullptr;
		}
	}
	void Editor::DebugRender(const jns::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// 위치 크기 회전 정보를 받아와서
		// 해당 게임오브젝트위에 그려주면된다.
		jns::Transform* tr = debugObj->GetComponent<jns::Transform>();


		Vector3 pos = mesh.position;
		pos.z -= 0.01f;

		tr->SetPosition(pos);
		tr->SetScale(mesh.scale);
		tr->SetRotation(mesh.rotation);

		tr->LateUpdate();

		if (mesh.isCollide == true)
		{
			renderer::ObjectTypeMoveCB colObj = {};

			colObj.mtype = mesh.isCollide;
			colObj.mTime = Vector3(0.0f, 0.0f, 0.0f);
			ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
			cb->SetData(&colObj);
			cb->Bind(eShaderStage::PS);
		}
		else if (mesh.isCollide == false)
		{
			renderer::ObjectTypeMoveCB colObj = {};

			colObj.mtype = mesh.isCollide;
			colObj.mTime = Vector3(0.0f, 0.0f, 0.0f);
			ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
			cb->SetData(&colObj);
			cb->Bind(eShaderStage::PS);
		}

		/*ya::MeshRenderer * mr
			= debugObj->GetComponent<ya::MeshRenderer>();*/
			// main camera
		jns::Camera* mainCamara = renderer::mainCamera;

		jns::Camera::SetGpuViewMatrix(mainCamara->GetViewMatrix());
		jns::Camera::SetGpuProjectionMatrix(mainCamara->GetProjectionMatrix());


		debugObj->Render();
	}
}