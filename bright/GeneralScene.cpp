#include "stdafx.h"
#include "GeneralScene.h"
#include "Cube.h"

namespace pasha
{
	GeneralScene::GeneralScene()
	{
		m_GameObjects.push_back(std::make_shared<Cube>());
	}
}