#include "stdafx.h"
#include "D2DManager.h"

namespace pasha
{
	std::unique_ptr<D2DManager> D2DManager::Singleton;
	std::once_flag D2DManager::OnceFlag;

	D2DManager& D2DManager::GetSingleton()
	{
		return *D2DManager::Singleton;
	}

	D2DManager& D2DManager::GetSingleton(HWND handle)
	{
		std::call_once(D2DManager::OnceFlag, [&]()
		{
			D2DManager::Singleton.reset(new D2DManager{ handle });
		});

		return *D2DManager::Singleton;
	}

	D2DManager::D2DManager(HWND handle)
	{
		m_WindowHandle = handle;

		auto result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, m_Device.ReleaseAndGetAddressOf());
		if (FAILED(result))
		{
			throw std::exception{ "Initialize D3D11 Failed," };
		}

		RECT client;
		GetClientRect(m_WindowHandle, &client);

		result = m_Device->CreateHwndRenderTarget
		(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(handle, D2D1::SizeU(client.right - client.left, client.bottom - client.top)),
			&m_DeviceContext
		);

		if (FAILED(result))
		{
			throw std::exception{ "Create Render Target Failed." };
		}
	}
}