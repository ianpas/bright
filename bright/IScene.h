#pragma once

namespace pasha
{
	class IScene
	{
	public:
		virtual ~IScene() = default;

	public:
		virtual void Render() = 0;

	};
}