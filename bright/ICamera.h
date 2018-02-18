#pragma once

namespace pasha
{
	class ICamera
	{
	public:
		virtual ~ICamera() = default;

		virtual DirectX::XMFLOAT4X4 GetViewMatrix()const = 0;
		virtual DirectX::XMFLOAT4X4 GetProjectionMatrix()const = 0;

		virtual void SetEye(DirectX::XMFLOAT3 const& pos) = 0;
		virtual void SetFocus(DirectX::XMFLOAT3 const& pos) = 0;
		virtual void SetAspectRatio(float ratio) = 0;
		virtual void SetRange(float __near, float __far) = 0;
		virtual void SetFovAngle(float angle) = 0; // angle is in radian

	};
}