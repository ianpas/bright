#pragma once

namespace pasha
{

	class PipelineManager
	{
	public:
		class VSOutput
		{
		public:
			DirectX::XMFLOAT4 m_Pos;
			DirectX::XMFLOAT4 m_Color;
		};

		class cbObject
		{
		public:
			DirectX::XMFLOAT4X4 m_World;
		};

		class cbCamera
		{
		public:
			DirectX::XMFLOAT4X4 m_View;
			DirectX::XMFLOAT4X4 m_Proj;
		};

	public:
		//
		static D3D11_VIEWPORT				m_Viewport;

		//
		static std::vector<Vertex>			m_VertexBuffer;
		static std::vector<unsigned int>	m_IndexBuffer;

		//
		static std::vector<VSOutput>		m_VSOut;

		//
		static cbObject						m_cbObject;
		static cbCamera						m_cbCamera;

	public:
		static DirectX::XMVECTOR XM_CALLCONV float4(DirectX::XMFLOAT3 v, float w);
		static DirectX::XMFLOAT4 XM_CALLCONV float4(DirectX::FXMVECTOR v);

		static DirectX::XMVECTOR XM_CALLCONV mul(DirectX::FXMVECTOR v, DirectX::FXMMATRIX m);
		static DirectX::XMVECTOR XM_CALLCONV mul(DirectX::FXMVECTOR v, DirectX::XMFLOAT4X4 m);
		static DirectX::XMVECTOR XM_CALLCONV mul(DirectX::XMFLOAT4 v, DirectX::XMFLOAT4X4 m);

	private:
		static std::vector<unsigned char>	m_BackBuffer;

	public:
		static void							WriteBackBuffer(int x, int y, D2D1::ColorF color);
		static D2D1::ColorF					ReadBackBuffer(int x, int y);
		static void							InitializeBackBuffer (int size);
	};



}

