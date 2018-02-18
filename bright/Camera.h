#pragma once
#include "ICamera.h"
#include "Component.h"

namespace pasha
{
	class Camera :public ICamera, public Component
	{
	private:
		float					m_Far{ 0 };
		float					m_Near{ 0 };
		float					m_FovAngle{ 0 };// Fov: field of view
		float					m_AspectRatio{ 0 };

		DirectX::XMFLOAT3		m_Eye;
		DirectX::XMFLOAT3		m_Focus;

		DirectX::XMFLOAT4X4		m_View;
		DirectX::XMFLOAT4X4		m_Proj;

	public:
		Camera(IGameObject* game_object);

	public:
		 DirectX::XMFLOAT4X4		GetViewMatrix() const override;
		 DirectX::XMFLOAT4X4		GetProjectionMatrix() const override;
		 
		 void						SetEye(DirectX::XMFLOAT3 const & pos) override;
		 void						SetFocus(DirectX::XMFLOAT3 const & pos) override;
		 void						SetAspectRatio(float ratio) override;
		 void						SetRange(float __near, float __far) override;
		 void						SetFovAngle(float angle) override;
		 

	};
}
