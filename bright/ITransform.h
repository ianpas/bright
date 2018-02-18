#pragma once

namespace pasha
{
	class ITransform
	{
	public:
		virtual ~ITransform() = default;

	public:
		virtual DirectX::XMFLOAT4X4 GetWorldMatrix() const = 0;
	};
}