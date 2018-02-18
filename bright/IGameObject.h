#pragma once
#include "IComponent.h"

namespace pasha
{
	class IGameObject
	{
	protected:
		std::vector<std::shared_ptr<IComponent>> m_Components;

	public:
		virtual ~IGameObject() = default;

	public:
		virtual void Render() = 0;

	protected:
		virtual void Update() = 0;
		virtual void Awake() = 0;

	public:
		template<typename ComponentType>
		ComponentType& GetComponent()const;

		template<typename ComponentType, typename... Args>
		void AddComponent(Args... args);

	

	};

	template<typename ComponentType>
	ComponentType& IGameObject::GetComponent() const
	{
		for (auto const& each : m_Components)
		{
			auto result = dynamic_cast<ComponentType*>(each.get());
			if (result)
			{
				return *result;
			}
		}

		throw std::exception{ "No such component." };
	}

	template<typename ComponentType, typename... Args>
	void IGameObject::AddComponent(Args... args)
	{
		m_Components.push_back(std::make_shared<ComponentType>(args...));
	}


}