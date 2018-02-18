#pragma once

namespace pasha
{
	class D2DManager
	{
		friend class GraphicsManager;

	private:
		Microsoft::WRL::ComPtr<ID2D1Factory>				m_Device;
		Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget>		m_DeviceContext;

		HWND												m_WindowHandle;

	public:
		D2DManager(D2DManager const&) = delete;
		D2DManager& operator=(D2DManager const&) = delete;
		static D2DManager& GetSingleton();
		static D2DManager& GetSingleton(HWND handle);

	private:
		D2DManager(HWND handle);
		static std::unique_ptr<D2DManager> Singleton;
		static std::once_flag OnceFlag;
	};
}