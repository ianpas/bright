#pragma once

namespace pasha
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() = default;

	public:
		virtual void  Render() = 0;

	};
}