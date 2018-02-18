#pragma once
#include "IVertexShader.h"
#include "Component.h"

namespace pasha
{
	

	class VertexShader : public IVertexShader, public Component
	{
	private:
		using VSInput = Vertex;
		using VSOutput = PipelineManager::VSOutput;
	public:
		VertexShader(IGameObject* game_object);

	public:
		void VSMain() override;

	private:
		VSOutput OnVSMain(VSInput const& vsi);
	};
}
