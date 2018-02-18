#pragma once

namespace pasha
{
	class IRasterizer
	{
	public:
		virtual ~IRasterizer() = default;

	public:
		virtual void Rasterize() = 0;

	};
}