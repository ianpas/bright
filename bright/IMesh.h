#pragma once

namespace pasha
{
	class IMesh
	{
	public:
		virtual ~IMesh() = default;

	public:
		virtual int	GetIndexAmount() const = 0;

	};
}