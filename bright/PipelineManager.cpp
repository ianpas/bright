#include "stdafx.h"
#include "PipelineManager.h"

namespace pasha
{
	D3D11_VIEWPORT									PipelineManager::m_Viewport;
	std::vector<Vertex>								PipelineManager::m_VertexBuffer;
	std::vector<unsigned int>						PipelineManager::m_IndexBuffer;
	std::vector<PipelineManager::VSOutput>			PipelineManager::m_VSOut;
	PipelineManager::cbObject						PipelineManager::m_cbObject;
	PipelineManager::cbCamera						PipelineManager::m_cbCamera;
	std::vector<unsigned char>						PipelineManager::m_BackBuffer;

	DirectX::XMVECTOR XM_CALLCONV PipelineManager::float4(DirectX::XMFLOAT3 v, float w)
	{
		return DirectX::XMVectorSet(v.x, v.y, v.z, w);
	}

	DirectX::XMFLOAT4 XM_CALLCONV PipelineManager::float4(DirectX::FXMVECTOR v)
	{
		DirectX::XMFLOAT4 value;
		DirectX::XMStoreFloat4(&value, v);
		return value;
	}

	DirectX::XMVECTOR XM_CALLCONV PipelineManager::mul(DirectX::FXMVECTOR v, DirectX::FXMMATRIX m)
	{
		return DirectX::XMVector4Transform(v, m);
	}

	DirectX::XMVECTOR XM_CALLCONV PipelineManager::mul(DirectX::FXMVECTOR v, DirectX::XMFLOAT4X4 m)
	{
		return mul(v, DirectX::XMLoadFloat4x4(&m));
	}
	DirectX::XMVECTOR XM_CALLCONV PipelineManager::mul(DirectX::XMFLOAT4 v, DirectX::XMFLOAT4X4 m)
	{
		return mul(DirectX::XMLoadFloat4(&v), m);
	}

	void PipelineManager::InitializeBackBuffer(int size)
	{
		m_BackBuffer.resize(size, 0);
	}

	void PipelineManager::WriteBackBuffer(int x, int y, D2D1::ColorF color)
	{
		try
		{
			int base = (y * static_cast<int>(m_Viewport.Width) + x) * 4;

			m_BackBuffer.at(base) = static_cast<unsigned char>(color.r * 255);
			m_BackBuffer.at(base + 1) = static_cast<unsigned char>(color.g * 255);
			m_BackBuffer.at(base + 2) = static_cast<unsigned char>(color.b * 255);
			m_BackBuffer.at(base + 3) = static_cast<unsigned char>(color.a * 255);
		}
		catch (const std::exception&)
		{

		}

	}

	D2D1::ColorF PipelineManager::ReadBackBuffer(int x, int y)
	{
		try
		{
			int base = (y * static_cast<int>(m_Viewport.Width) + x) * 4;

			float r = m_BackBuffer.at(base) / 255.f;
			float g = m_BackBuffer.at(base + 1) / 255.f;
			float b = m_BackBuffer.at(base + 2) / 255.f;
			float a = m_BackBuffer.at(base + 3) / 255.f;

			return D2D1::ColorF(r, g, b, a);
		}
		catch (const std::exception&)
		{
			return D2D1::ColorF::Black;
		}

	}
}
