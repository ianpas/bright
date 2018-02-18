#include "stdafx.h"
#include "Camera.h"

namespace pasha
{
	Camera::Camera(IGameObject* game_object)
		:Component(game_object)
	{
		SetFovAngle(DirectX::XM_PIDIV4);
		SetRange(0.01f, 1000.f);
		SetEye(DirectX::XMFLOAT3{ 3.f,3.f,3.f });
		SetFocus(DirectX::XMFLOAT3{ 0.f,0.f,0.f });
		SetAspectRatio(GraphicsManager::GetSingleton().GetAspectRatio());
	}

	void Camera::SetFocus(DirectX::XMFLOAT3 const& pos)
	{
		m_Focus = pos;
	}
	void Camera::SetEye(DirectX::XMFLOAT3 const& pos)
	{
		m_Eye = pos;
	}

	void Camera::SetAspectRatio(float ratio)
	{
		m_AspectRatio = ratio;
	}

	void Camera::SetRange(float __near, float __far)
	{
		m_Near = __near;
		m_Far = __far;
	}

	void Camera::SetFovAngle(float angle)
	{
		m_FovAngle = angle;
	}

	DirectX::XMFLOAT4X4 Camera::GetViewMatrix() const
	{
		auto view = DirectX::XMMatrixLookAtLH
		(
			DirectX::XMLoadFloat3(&m_Eye),
			DirectX::XMLoadFloat3(&m_Focus),
			DirectX::XMVectorSet(0, 1, 0, 0)
		);

		DirectX::XMFLOAT4X4 m;
		DirectX::XMStoreFloat4x4(&m, view);
		return m;
	}

	DirectX::XMFLOAT4X4 Camera::GetProjectionMatrix() const
	{
		auto proj= DirectX::XMMatrixPerspectiveFovLH
		(
			m_FovAngle,
			m_AspectRatio,
			m_Near,
			m_Far
		);

		DirectX::XMFLOAT4X4 m;
		DirectX::XMStoreFloat4x4(&m, proj);
		return m;
	}
}