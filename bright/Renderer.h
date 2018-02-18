#pragma once
#include "IRenderer.h"
#include "Component.h"
#include "Rasterizer.h"

namespace pasha
{
	class Renderer : public IRenderer, public Component
	{
	private :
		std::unique_ptr<IRasterizer> m_Rasterizer;

	public:
		Renderer(IGameObject* game_object);

	public:
		void Render() override;
	};
}