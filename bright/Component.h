#pragma once
#include "IComponent.h"
#include "IGameObject.h"

namespace pasha
{
	class Component : public IComponent
	{
	public:
		Component(IGameObject* game_object);

	public:
		template<typename ComponentType>
		ComponentType& GetComponent()const;

	private:
		IGameObject * m_GameObject;

		
	};


	template<typename ComponentType>
	ComponentType& Component::GetComponent() const
	{
		return m_GameObject->GetComponent<ComponentType>();
	}

}
