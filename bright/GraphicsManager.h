#pragma once

namespace pasha
{
	class GraphicsManager
	{
	public:
		void												Render(std::function<void()> __render) const;

		ID2D1HwndRenderTarget*								GetDeviceContext()const;
		float												GetAspectRatio()const;
		float												GetRenderTargetWidth()const;
		float												GetRenderTargetHeight()const;

		void												DrawPixel(int x, int y, D2D1::ColorF color) const;
		void												SetViewport();

	private:
		void												BeginScene()const;
		void												EndScene()const;

	public:
		GraphicsManager(GraphicsManager const&) = delete;
		GraphicsManager& operator=(GraphicsManager const&) = delete;
		static GraphicsManager& GetSingleton();

	private:
		GraphicsManager();
		static std::unique_ptr<GraphicsManager> Singleton;
		static std::once_flag OnceFlag;
	};
}