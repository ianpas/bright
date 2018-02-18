#pragma once
#include "IMesh.h"
#include "Component.h"

namespace pasha
{

	class Mesh :public IMesh, public Component
	{
	protected:
		int									 m_IndexAmount{ 0 };

	public:
		Mesh(IGameObject* game_object, std::string const& mesh_path);

	public:
		int GetIndexAmount() const override;

	};

}