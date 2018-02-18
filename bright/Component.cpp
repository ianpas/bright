#include "stdafx.h"
#include "Component.h"

namespace pasha
{
	Component::Component(IGameObject* game_object)
	{
		m_GameObject = game_object;
	}

}
