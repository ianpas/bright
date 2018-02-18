#include "stdafx.h"
#include "Rasterizer.h"


namespace pasha
{
	Rasterizer::Rasterizer()
	{
	}
	void Rasterizer::Rasterize()
	{
		AssembleInput();
		Clip();
		PerspectiveDivide();
		CullBackface();
		ViewportTransform();
		Interpolate();
	}

	void Rasterizer::AssembleInput()
	{
		auto& vertices = PipelineManager::m_VSOut;
		auto& indices = PipelineManager::m_IndexBuffer;

		for (int i = 0; i < indices.size(); i += 3)
		{
			m_Triangles.push_back
			(
				Triangle
				{
					PipelineManager::VSOutput{ vertices[indices[i]] },
					PipelineManager::VSOutput{ vertices[indices[i + 1]] },
					PipelineManager::VSOutput{ vertices[indices[i + 2]] }
				}
			);
		}
	}

	void Rasterizer::Clip()
	{
		// not implemented
	}
	void Rasterizer::PerspectiveDivide()
	{
		// before:
		// vertex: x,y in [-z,z]
		//		   z in [0,z]
		//		   w = z
		auto divide = [&](DirectX::XMFLOAT4& v)
		{
			v.x /= v.w;
			v.y /= v.w;
			v.z /= v.w;
			v.w = 1;
		};

		for (auto& each : m_Triangles)
		{
			divide(each.m_V1.m_Pos);
			divide(each.m_V2.m_Pos);
			divide(each.m_V3.m_Pos);
		}

		// after:
		// vertex: x, y in [-1,1]
		//		   z in [0,1]
		//		   w = 1
	}

	void Rasterizer::CullBackface()
	{
		auto is_backface = [&](Triangle const& triangle)
		{
			float x1 = triangle.m_V1.m_Pos.x;
			float y1 = triangle.m_V1.m_Pos.y;

			float x2 = triangle.m_V2.m_Pos.x;
			float y2 = triangle.m_V2.m_Pos.y;

			float x3 = triangle.m_V3.m_Pos.x;
			float y3 = triangle.m_V3.m_Pos.y;

			float det = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
			return det > 0;
		};

		m_Triangles.erase(std::remove_if(m_Triangles.begin(), m_Triangles.end(), is_backface), m_Triangles.end());
	}

	void Rasterizer::ViewportTransform()
	{
		auto const& viewport = PipelineManager::m_Viewport;

		static DirectX::XMFLOAT4X4 m =
		{
			viewport.Width / 2						,  0.f										, 0.f										, 0.f,
			0.f										,  -viewport.Height / 2						, 0.f										, 0.f,
			0.f										,  0.f										, viewport.MaxDepth - viewport.MinDepth		, 0.f,
			viewport.TopLeftX + viewport.Width / 2	,  viewport.TopLeftY + viewport.Height / 2	, viewport.MinDepth							, 1.f
		};

		for (auto& each : m_Triangles)
		{
			each.m_V1.m_Pos = PipelineManager::float4(PipelineManager::mul(each.m_V1.m_Pos, m));
			each.m_V2.m_Pos = PipelineManager::float4(PipelineManager::mul(each.m_V2.m_Pos, m));
			each.m_V3.m_Pos = PipelineManager::float4(PipelineManager::mul(each.m_V3.m_Pos, m));
		}
	}

	void Rasterizer::Interpolate()
	{
		for (auto const& each : m_Triangles)
		{
			Interpolator::Interpolate(each);
		}
	}

	void Rasterizer::Interpolator::Interpolate(Triangle const& triangle)
	{
		auto const& graphics_manager{ GraphicsManager::GetSingleton() };

		auto const& v1 = triangle.m_V1;
		auto const& v2 = triangle.m_V2;
		auto const& v3 = triangle.m_V3;

		float width = std::max(std::abs(v2.m_Pos.x - v3.m_Pos.x), std::max(std::abs(v1.m_Pos.x - v2.m_Pos.x), std::abs(v1.m_Pos.x - v3.m_Pos.x)));
		float height = std::max(std::abs(v2.m_Pos.y - v3.m_Pos.y), std::max(std::abs(v1.m_Pos.y - v2.m_Pos.y), std::abs(v1.m_Pos.y - v3.m_Pos.y)));
		
		int accuracy = 2;
		int length = accuracy * static_cast<int>(std::max(width, height));

		for (int x = 0; x <= length; ++x)
		{
			for (int y = 0; y <= length; ++y)
			{
				float f = static_cast<float>(x) / length;
				float g = static_cast<float>(y) / length;

				if (1 - f - g >= 0)
				{
					auto v_point = DirectX::XMVectorBaryCentric
					(
						DirectX::XMLoadFloat4(&v1.m_Pos),
						DirectX::XMLoadFloat4(&v2.m_Pos),
						DirectX::XMLoadFloat4(&v3.m_Pos),
						f,
						g
					);

					auto v_color = DirectX::XMVectorBaryCentric
					(
						DirectX::XMLoadFloat4(&v1.m_Color),
						DirectX::XMLoadFloat4(&v2.m_Color),
						DirectX::XMLoadFloat4(&v3.m_Color),
						f,
						g
					);

					DirectX::XMFLOAT4 point;
					DirectX::XMFLOAT4 color;
					DirectX::XMStoreFloat4(&point, v_point);
					DirectX::XMStoreFloat4(&color, v_color);


					graphics_manager.DrawPixel
					(
						point.x, point.y,
						D2D1::ColorF(color.x, color.y, color.z, color.w)
					);

				}
			}
		}

	}
}
