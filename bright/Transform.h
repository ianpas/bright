#pragma once
#include "ITransform.h"
#include "Component.h"

namespace pasha
{
	class Transform :public ITransform, public Component
	{
	private:
		DirectX::XMFLOAT3 m_Position;
		DirectX::XMFLOAT3 m_Rotation;
		DirectX::XMFLOAT3 m_Scale;

	public:
		Transform(IGameObject* game_object);

	public:
		DirectX::XMFLOAT4X4 GetWorldMatrix() const override;


	};
}