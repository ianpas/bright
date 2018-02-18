#include "stdafx.h"
#include "Transform.h"

namespace pasha
{
	Transform::Transform(IGameObject* game_object)
		:Component(game_object)
	{

	}

	DirectX::XMFLOAT4X4 Transform::GetWorldMatrix() const
	{
		auto world = DirectX::XMMatrixIdentity();

		DirectX::XMFLOAT4X4 m;
		DirectX::XMStoreFloat4x4(&m, world);
		return m;
	}

}