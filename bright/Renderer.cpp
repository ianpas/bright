#include "stdafx.h"
#include "Renderer.h"
#include "IMesh.h"
#include "ITransform.h"
#include "ICamera.h"
#include "IVertexShader.h"

namespace pasha
{
	Renderer::Renderer(IGameObject* game_object)
		:Component(game_object)
	{
		m_Rasterizer = std::make_unique<Rasterizer>();
	}

	void Renderer::Render()
	{
		auto& transform{ GetComponent<ITransform>() };
		auto& camera{ GetComponent<ICamera>() };

		PipelineManager::m_cbObject.m_World = transform.GetWorldMatrix();
		PipelineManager::m_cbCamera.m_View = camera.GetViewMatrix();
		PipelineManager::m_cbCamera.m_Proj = camera.GetProjectionMatrix();

		auto& vertex_shader{ GetComponent<IVertexShader>() };
		vertex_shader.VSMain();

		m_Rasterizer->Rasterize();
	}



}