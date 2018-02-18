#include "stdafx.h"
#include "Scene.h"


namespace pasha
{
	Scene::Scene()
	{
		
	}

	void Scene::Render()
	{
		auto const& graphics_manager{ GraphicsManager::GetSingleton() };
		graphics_manager.Render([&] {OnRender(); });
	}

	void Scene::OnRender()
	{
		for (auto& each : m_GameObjects)
		{
			each->Render();
		}
	}
}