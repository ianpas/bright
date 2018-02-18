#pragma once
#include "IScene.h"
#include "GameObject.h"

namespace pasha
{
	class Scene :public IScene
	{
	protected:
		std::vector<std::shared_ptr<IGameObject>> m_GameObjects;

	public:
		Scene();

	public:
		void Render() override;

	private:
		void OnRender();
	};
}