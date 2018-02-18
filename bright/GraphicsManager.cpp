#include "stdafx.h"
#include "GraphicsManager.h"

namespace pasha
{
	std::unique_ptr<GraphicsManager> GraphicsManager::Singleton;
	std::once_flag GraphicsManager::OnceFlag;

	GraphicsManager& GraphicsManager::GetSingleton()
	{
		std::call_once(GraphicsManager::OnceFlag, [&]()
		{
			GraphicsManager::Singleton.reset(new GraphicsManager{});
		});

		return *GraphicsManager::Singleton;
	}

	GraphicsManager::GraphicsManager()
	{
		SetViewport();
	}

	ID2D1HwndRenderTarget* GraphicsManager::GetDeviceContext() const
	{
		auto const& device_manager{ D2DManager::GetSingleton() };
		return device_manager.m_DeviceContext.Get();
	}

	float GraphicsManager::GetAspectRatio() const
	{
		return GetRenderTargetWidth() / GetRenderTargetHeight();
	}

	float GraphicsManager::GetRenderTargetWidth() const
	{
		auto const& device_manager{ D2DManager::GetSingleton() };
		RECT client;
		GetClientRect(device_manager.m_WindowHandle, &client);
		return client.right - client.left;
	}

	float GraphicsManager::GetRenderTargetHeight() const
	{
		auto const& device_manager{ D2DManager::GetSingleton() };
		RECT client;
		GetClientRect(device_manager.m_WindowHandle, &client);
		return client.bottom - client.top;
	}

	void GraphicsManager::DrawPixel(int x, int y, D2D1::ColorF color)const
	{
		PipelineManager::WriteBackBuffer(x, y, color);
	}

	void GraphicsManager::SetViewport()
	{
		auto& viewport = PipelineManager::m_Viewport;
		std::memset(&viewport, 0, sizeof(viewport));
		viewport.TopLeftX = 0;
		viewport.TopLeftY = 0;
		viewport.Width = GetRenderTargetWidth();
		viewport.Height = GetRenderTargetHeight();
		viewport.MinDepth = 0.f;
		viewport.MaxDepth = 1.f;

		// important:multiply 4
		int size = static_cast<int>(viewport.Width)*static_cast<int>(viewport.Height) * 4;
		PipelineManager::InitializeBackBuffer(size);

	}

	void GraphicsManager::BeginScene() const
	{

		for (int x = 0; x < static_cast<int>(PipelineManager::m_Viewport.Width); ++x)
		{
			for (int y = 0; y < static_cast<int>(PipelineManager::m_Viewport.Height); ++y)
			{
				DrawPixel(x, y, D2D1::ColorF::White);
			}
		}
	}

	void GraphicsManager::EndScene() const
	{
		auto draw = [&](int x, int y, D2D1::ColorF const& color)
		{
			Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;

			auto result = GetDeviceContext()->CreateSolidColorBrush
			(
				color,
				&brush
			);

			if (FAILED(result))
			{
				throw std::exception{ "Create Color Brush Failed." };
			}

			// actually draw 2 pixel.
			GetDeviceContext()->DrawLine
			(
				D2D1::Point2F(static_cast<float>(x), static_cast<float>(y)),
				D2D1::Point2F(static_cast<float>(x + 1), static_cast<float>(y)),
				brush.Get()
			);
		};

		for (int x = 0; x < static_cast<int>(PipelineManager::m_Viewport.Width); ++x)
		{
			for (int y = 0; y < static_cast<int>(PipelineManager::m_Viewport.Height); ++y)
			{
				auto color = PipelineManager::ReadBackBuffer(x, y);
				draw(x, y, color);
			}
		}
	}


	void GraphicsManager::Render(std::function<void()> __render) const
	{
		auto const& device_context{ GetDeviceContext() };

		device_context->BeginDraw();
		device_context->Clear(D2D1::ColorF(D2D1::ColorF::White));

		BeginScene();

		__render();

		EndScene();
		device_context->EndDraw();
	}
}