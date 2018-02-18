#include "stdafx.h"
#include "VertexShader.h"

namespace pasha
{
	VertexShader::VertexShader(IGameObject* game_object)
		:Component(game_object)
	{

	}

	void VertexShader::VSMain()
	{
		for (auto& vsi : PipelineManager::m_VertexBuffer)
		{
			PipelineManager::m_VSOut.push_back(OnVSMain(vsi));
		}
	}

	PipelineManager::VSOutput VertexShader::OnVSMain(VSInput const& vsi)
	{
		auto local_pos = PipelineManager::float4(vsi.m_Position, 1.f);
		auto world_pos = PipelineManager::mul(local_pos, PipelineManager::m_cbObject.m_World);
		auto view_pos = PipelineManager::mul(world_pos, PipelineManager::m_cbCamera.m_View);
		auto proj_pos = PipelineManager::mul(view_pos, PipelineManager::m_cbCamera.m_Proj);

		VSOutput vso{};
		vso.m_Pos = PipelineManager::float4(proj_pos);
		vso.m_Color = vsi.m_Color;
		return vso;
	}



}
