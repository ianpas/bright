#pragma once

namespace pasha
{
	class IVertexShader
	{
	public:
		virtual ~IVertexShader() = default;

	public:
		virtual void VSMain() = 0;
	};
}
