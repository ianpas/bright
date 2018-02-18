#include "stdafx.h"
#include "Mesh.h"

namespace pasha
{
	Mesh::Mesh(IGameObject* game_object, std::string const& mesh_path)
		:Component(game_object)
	{
		auto& mesh_manager{ MeshManager::GetSingleton() };

		mesh_manager.ImportMesh(mesh_path);

		PipelineManager::m_VertexBuffer = mesh_manager.GetVertices();
		for (auto& each : PipelineManager::m_VertexBuffer)
		{
			each.m_Color.x = each.m_Position.x*0.5 + 0.5;
			each.m_Color.y = each.m_Position.y*0.5 + 0.5;
			each.m_Color.z = each.m_Position.z*0.5 + 0.5;
			each.m_Color.w = 1.f;
		}

		PipelineManager::m_IndexBuffer = mesh_manager.GetIndices();
		m_IndexAmount = PipelineManager::m_IndexBuffer.size();
	}



	int Mesh::GetIndexAmount() const
	{
		return m_IndexAmount;
	}

}
