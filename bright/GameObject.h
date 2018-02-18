#pragma once
#include "IGameObject.h"
#include "IComponent.h"

namespace pasha
{
	class GameObject :public IGameObject
	{
	public:
		virtual void Render() override = 0;
		virtual void Update() override = 0;
		virtual void Awake() override = 0;
	};

	
}

